/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:31:40 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/10 17:05:46 by jeongwle         ###   ########.fr       */
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

    public :
        /* from wikipedia */
        node_pointer grandparent(node_pointer node){
            if (node != NULL && node->_parent != NULL){
                return this->_parent->_parent;
            }
            return NULL;
        }

        node_pointer uncle(node_pointer node){
            Node* grandparent = grandparent(node);
            if (grandparent == NULL){
                return NULL;
            }
            if (node->_parent == grandparent->left){
                return grandparent->right;
            }
            else{
                return grandparent->left;
            }
        }

        void insert_case1(node_pointer node){

        }
    };


}

#endif
