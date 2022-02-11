/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:31:40 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/11 14:03:22 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP
#define BLACK 0
#define RED 1
#include <memory>
#include "MapUtils.hpp"

namespace ft {
    template <class T, class Compare, class Alloc = std::allocator<T> >
    class tree {
    public :
        /* typedef */
        typedef T           value_type;
        typedef Compare     value_compare;
        typedef Alloc       allocator_type;

    public :
        /* data structure */
        class Node {
        public :
            value_type  _value;
            Node*       _parent;
            Node*       _left;
            Node*       _right;
            int         _color;

        public :
            Node(void) : _value(value_type()), _parent(NULL), _left(NULL), _right(NULL), _color(RED){

            }

            Node(const Node& copy) : _value(copy._value), _parent(copy._parent), _left(copy._left), _right(copy._right), _color(copy._color){

            }

            ~Node(void){

            }

            Node& operator=(const Node& object){
                this->_value = object._value;
                this->_parent = object._parent;
                this->_left = object._left;
                this->_right = object._right;
                this->_color = object._color;
                return *(this);
            }
        };
        typedef Node*       node_pointer;

    private :
        /* private variables */
        node_pointer _root;
        node_pointer _NIL;

    private :
        /* from wikipedia */
        node_pointer findGrandParent(node_pointer node){
            if (node != NULL && node->_parent != NULL){
                return node->_parent->_parent;
            }
            return NULL;
        }

        node_pointer findUncle(node_pointer node){
            Node* grandparent = findGrandParent(node);
            if (grandparent == NULL){
                return NULL;
            }
            if (node->_parent == grandparent->_left){
                return grandparent->_right;
            }
            else{
                return grandparent->_left;
            }
        }

        node_pointer findSibling(node_pointer node){
            if (node->_parent == NULL){
                return NULL;
            }
            if (node == node->_parent->_left){
                return node->_parent->_right;
            }
            else{
                return node->_parent->_left;
            }
        }

        void rotate_left(node_pointer node){
            node_pointer child = node->_right;
            node_pointer parent = node->_parent;
            if (child->_left != this->_NIL){
                child->_left->_parent = node;
            }
            node->_right = child->_left;
            node->_parent = child;
            child->_parent = parent;
            child->_left = node;
            if (parent != NULL){
                if (parent->_left == node){
                    parent->_left = child;
                }
                else{
                    parent->_right = child;
                }
            }
        }

        void rotate_right(node_pointer node){
            node_pointer child = node->_left;
            node_pointer parent = node->_parent;
            if (child->_right != this->_NIL){
                child->_right->_parent = node;
            }
            node->_left = child->_right;
            node->_parent = child;
            child->_parent = parent;
            child->_right = node;
            if (parent != NULL){
                if (parent->_right == node){
                    parent->_right = child;
                }
                else{
                    parent->_left = child;
                }
            }
        }

        void insert_case1(node_pointer node){
            if (node->_parent == NULL){
                node->_color = BLACK;
            }
            else{
                this->insert_case2(node);
            }
        }

        void insert_case2(node_pointer node){
            if (node->_parent->_color == BLACK){
                return ;
            }
            else {
                this->insert_case3(node);
            }
        }

        void insert_case3(node_pointer node){
            node_pointer uncle = findUncle(node);
            node_pointer grandparent;
            if ((uncle != this->_NIL) && uncle->_color == RED){
                node->_parent->_color = BLACK;
                uncle->_color = BLACK;
                grandparent = findGrandParent(node);
                grandparent->_color = RED;
                this->insert_case1(grandparent);
            }
            else{
                this->insert_case4(node);
            }
        }

        void insert_case4(node_pointer node){
            node_pointer grandparent = findGrandParent(node);
            if ((node == node->_parent->_right) && (node->_parent == grandparent->_left)){
                this->rotate_left(node->_parent);
                node = node->_left;
            }
            else if ((node == node->_parent->left) && (node->_parent == grandparent->_right)){
                this->rotate_right(node->_parent);
                node = node->_right;
            }
            this->insert_case5(node);
        }

        void insert_case5(node_pointer node){
            node_pointer grandparnet = findGrandParent(node);
            node->_parent->_color = BLACK;
            grandparnet->_color = RED;
            if (node == node->_parent->left){
                this->rotate_right(grandparnet);
            }
            else{
                this->rotate_left(grandparnet);
            }
        }
    };


}

#endif
