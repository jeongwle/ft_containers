/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:31:40 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/21 20:06:46 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP
#define BLACK 0
#define RED 1
#include <memory>
#include "MapUtils.hpp"
#include "Utils.hpp"
#include "Iterator.hpp"

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

            Node(const value_type& val) : _value(val), _parent(NULL), _left(NULL), _right(NULL), _color(RED){
            }

            ~Node(void){
            }
        };
        typedef Node*                                           node_pointer;
        typedef typename Alloc::template rebind<Node>::other    node_alloc;

    private :
        /* private variables */
        node_pointer _root;
        node_pointer _NIL;
        node_pointer _NILTemp;
        node_alloc _nodeAlloc;
        Compare _compare;

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
            else {
                this->_root = child;
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
            else {
                this->_root = child;
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
            else if ((node == node->_parent->_left) && (node->_parent == grandparent->_right)){
                this->rotate_right(node->_parent);
                node = node->_right;
            }
            this->insert_case5(node);
        }

        void insert_case5(node_pointer node){
            node_pointer grandparent = findGrandParent(node);
            node->_parent->_color = BLACK;
            grandparent->_color = RED;
            if (node == node->_parent->_left){
                this->rotate_right(grandparent);
            }
            else{
                this->rotate_left(grandparent);
            }
        }

        bool isLastElement(node_pointer node){
            return (node->_left == this->_NIL && node->_right == this->_NIL);
        }

        node_pointer findMinInRight(node_pointer node){
            node_pointer curr = node;
            if (curr->_right == this->_NIL){
                return NULL;
            }
            curr = curr->_right;
            while (curr->_left != this->_NIL){
                curr = curr->_left;
            }
            return curr;
        }
        
        node_pointer findMaxInLeft(node_pointer node){
            node_pointer curr = node;
            if (curr->_left == this->_NIL){
                return NULL;
            }
            curr = curr->_left;
            while (curr->_right != this->_NIL){
                curr = curr->_right;
            }
            return curr;
        }

        void reOrderAfterErase(node_pointer node){
            node_pointer sibling;
            while (node != this->_root && node->_color == BLACK){
                sibling = this->findSibling(node);
                if (node == node->_parent->_left){
                    /* sibling이 red인 경우 */
                    if (sibling->_color == RED){
                        sibling->_color = BLACK;
                        node->_parent->_color = RED;
                        this->rotate_left(node->_parent);
                        sibling = this->findSibling(node);
                    }
                    /* case sibling의 자식이 모두 BLACK */
                    if (sibling->_left->_color == BLACK && sibling->_right->_color == BLACK){
                        sibling->_color = RED;
                        node->_parent->_color = BLACK;
                        node = node->_parent;
                    }
                    else{
                        /* case sibling의 오른쪽 자식이 BLACK*/
                        if (sibling->_right->_color == BLACK){
                            sibling->_left->_color = BLACK;
                            sibling->_color = RED;
                            this->rotate_right(sibling);
                            sibling = this->findSibling(node);
                        }
                        /* case sibling의 자식이 모두 RED */
                        sibling->_color = node->_parent->_color;
                        node->_parent->_color = BLACK;
                        sibling->_right->_color = BLACK;
                        this->rotate_left(node->_parent);
                        break ;
                    }
                }
                else{
                    /* sibling이 red인 경우 */
                    if (sibling->_color == RED){
                        sibling->_color = BLACK;
                        node->_parent->_color = RED;
                        this->rotate_right(node->_parent);
                        sibling = this->findSibling(node);
                    }
                    /* case 2-A */
                    if (sibling->_left->_color == BLACK && sibling->_right->_color == BLACK){
                        sibling->_color = RED;
                        node->_parent->_color = BLACK;
                        node = node->_parent;
                    }
                    else{
                        /* case 2-B */
                        if (sibling->_right->_color == BLACK){
                            sibling->_left->_color = BLACK;
                            sibling->_color = RED;
                            this->rotate_left(sibling);
                            sibling = this->findSibling(node);
                        }
                        /* case 2-C */
                        sibling->_color = node->_parent->_color;
                        node->_parent->_color = BLACK;
                        sibling->_right->_color = BLACK;
                        this->rotate_right(node->_parent);
                        break ;
                    }
                }
            }
            node->_color = BLACK;
        }

        /*
        ** target = matching node
        ** removeNode = actually removed node
        ** doubleBlack = double black node
        */
        node_pointer eraseNode(const value_type& val){
            node_pointer target = this->findNode(val);
            node_pointer removeNode;
            node_pointer doubleBlack;

            if (target == NULL){
                return NULL;
            }

            if (isLastElement(target)){
                removeNode = target;
            }
            else {
                removeNode = this->findMaxInLeft(target);
                target->_value = removeNode->_value;
            }
            doubleBlack = removeNode->_left;
            doubleBlack->_parent = removeNode->_parent;

            if (removeNode->_parent == NULL){
                this->_root = doubleBlack;
            }
            else{
                if (removeNode == removeNode->_parent->_left){
                    removeNode->_parent->_left = doubleBlack;
                }
                else{
                    removeNode->_parent->_right = doubleBlack;
                }
            }

            if (removeNode->_color == BLACK){
                this->reOrderAfterErase(doubleBlack);
            }
            return removeNode;
        }
        
        bool alreadyExist(const value_type& val){
            /*findNode의 return값이 NULL이면 찾는 노드가 없다.*/
            return (this->findNode(val) != NULL);
        }

        node_pointer createNode(const value_type& val){
            if(!this->alreadyExist(val)){
                node_pointer newNode = this->_nodeAlloc.allocate(1);
                this->_nodeAlloc.construct(newNode, Node(val));
                return newNode;
            }
            return NULL;
        }

        void setNewNode(node_pointer curr, node_pointer newNode, std::string direction){
            if (direction == "left"){
                newNode->_parent = curr;
                newNode->_left = this->_NIL;
                newNode->_right = this->_NIL;
                curr->_left = newNode;
            }
            else if (direction == "right"){
                newNode->_parent = curr;
                newNode->_left = this->_NIL;
                newNode->_right = this->_NIL;
                curr->_right = newNode;
            }
        }

        void clearTree(node_pointer root){
            if (root == this->_NIL){
                return ;
            }
            this->clearTree(root->_left);
            this->clearTree(root->_right);
            this->_nodeAlloc.destroy(root);
            this->_nodeAlloc.deallocate(root, 1);
        }

        void copyTree(node_pointer copyRoot, node_pointer newParent, node_pointer copyNIL, bool direction){
            if (copyRoot == copyNIL && direction){
                newParent->_left = this->_NIL;
                return ;
            }
            else if(copyRoot == copyNIL && !direction){
                newParent->_right = this->_NIL;
                return ;
            }
            node_pointer newNode = this->_nodeAlloc.allocate(1);
            this->_nodeAlloc.construct(newNode, Node(copyRoot->_value));
            newNode->_parent = newParent;
            newNode->_color = copyRoot->_color;
            if (!newParent){
                this->_root = newNode;
            }
            if (direction){
                if (newParent){
                    newParent->_left = newNode;
                }
            }
            else{
                if (newParent){
                    newParent->_right = newNode;
                }
            }
            this->copyTree(copyRoot->_left, newNode, copyNIL, 1);
            this->copyTree(copyRoot->_right, newNode, copyNIL, 0);
        }

    public :
        /* Constructor, Destructor */
        tree(const value_compare& comp) : _root(NULL), _NIL(NULL), _NILTemp(NULL), _compare(comp) {
            this->_NIL = this->_nodeAlloc.allocate(1);
            this->_NILTemp = this->_nodeAlloc.allocate(1);
            this->_nodeAlloc.construct(this->_NIL, Node());
            this->_nodeAlloc.construct(this->_NILTemp, Node(ft::make_pair(32766, 542248797)));
            this->_NIL->_color = BLACK;
            this->_NILTemp->_color = BLACK;
            this->_root = this->_NIL;

        }
        
        tree(const tree& copy) : _compare(copy._compare){
            this->_NIL = this->_nodeAlloc.allocate(1);
            this->_NILTemp = this->_nodeAlloc.allocate(1);
            this->_nodeAlloc.construct(this->_NIL, Node());
            this->_nodeAlloc.construct(this->_NILTemp, Node(ft::make_pair(32766, 542248797)));
            this->_NIL->_color = BLACK;
            this->_NILTemp->_color = BLACK;
            this->_root = this->_NIL;
            if (copy._root == copy._NIL){
                return ;
            }
            this->copyTree(copy._root, NULL, copy._NIL, 1);
        }

        ~tree(void){
            this->clear();
            this->_nodeAlloc.destroy(this->_NIL);
            this->_nodeAlloc.destroy(this->_NILTemp);
            this->_nodeAlloc.deallocate(this->_NIL, 1);
            this->_nodeAlloc.deallocate(this->_NILTemp, 1);
        }

    public :
        tree& operator=(const tree& object){
            this->clear();
            if (object._root == object._NIL){
                return *(this);
            }
            this->copyTree(object._root, NULL, object._NIL, 1);
            return *(this);
        }

        bool insert(const value_type& val){
            if (this->_root == this->_NIL){
                this->_root = this->createNode(val);
                this->_root->_left = this->_NIL;
                this->_root->_right = this->_NIL;
                this->insert_case1(this->_root);
                return true;
            }
            node_pointer curr = this->_root;
            node_pointer newNode;
            if ((newNode = this->createNode(val))){
                while (curr != this->_NIL){
                    if (this->_compare(val, curr->_value)){
                        if (curr->_left == this->_NIL){
                            this->setNewNode(curr, newNode, "left");
                            this->insert_case1(newNode);
                            return true;
                        }
                        curr = curr->_left;
                    }
                    else{
                        if (curr->_right == this->_NIL){
                            this->setNewNode(curr, newNode, "right");
                            this->insert_case1(newNode);
                            return true;
                        }
                        curr = curr->_right;
                    }
                }
            }
            return false;
        }

        bool erase(const value_type& val){
            node_pointer removeNode = this->eraseNode(val);
            if (removeNode != NULL){
                this->_nodeAlloc.destroy(removeNode);
                this->_nodeAlloc.deallocate(removeNode, 1);
                return true;
            }
            return false;
        }

        node_pointer findNode(const value_type& val){
            node_pointer curr = this->_root;
            if (curr == this->_NIL){
                return NULL;
            }
            while (curr != this->_NIL){
                if (!(this->_compare(val, curr->_value)) && !(this->_compare(curr->_value, val))){
                    return curr;
                }
                if (this->_compare(val, curr->_value)){
                    curr = curr->_left;
                }
                else{
                    curr = curr->_right;
                }
            }
            return NULL;
        }

        node_pointer findFirstNode(void){
            if (this->_root == this->_NIL){
                return this->_NIL;
            }
            node_pointer curr = this->_root;
            while (curr->_left != this->_NIL){
                curr = curr->_left;
            }
            return curr;
        }

        node_pointer findLastNode(void){
            if (this->_root == this->_NIL){
                return NULL;
            }
            node_pointer curr = this->_root;
            while (curr->_right != this->_NIL){
                curr = curr->_right;
            }
            return curr;
        }

        node_pointer findNextNode(node_pointer node){
            node_pointer curr = node;
            if (curr == this->_NIL){
                return NULL;
            }
            if (curr == this->_NILTemp){
                return this->findFirstNode();
            }
            if (curr == this->findLastNode()){
                return this->_NIL;
            }
            if (curr->_right != this->_NIL){
                return this->findMinInRight(curr);
            }
            while (curr->_parent){
                if (this->_compare(node->_value, curr->_parent->_value)){
                    return curr->_parent;
                }
                curr = curr->_parent;
            }
            return curr;
        }

        node_pointer findPrevNode(node_pointer node){
            node_pointer curr = node;
            if (curr == this->_NILTemp){
                return NULL;
            }
            if (curr == this->_NIL){
                return this->findLastNode();
            }
            if (curr == this->findFirstNode()){
                return this->_NILTemp;
            }
            if (curr->_left != this->_NIL){
                return this->findMaxInLeft(curr);
            }
            while (curr->_parent){
                if (!(this->_compare(node->_value, curr->_parent->_value))){
                    return curr->_parent;
                }
                curr = curr->_parent;
            }
            return curr;
        }

        bool lowerThanFirst(const value_type& val){
            if (this->findFirstNode() == this->_NIL){
                return false;
            }
            if (this->_compare(val, this->findFirstNode()->_value)){
                return true;
            }
            return false;
        }

        node_pointer getNilNode(void) const{
            return this->_NIL;
        }

        node_alloc getNodeAlloc(void) const{
            return this->_nodeAlloc;
        }

        void clear(void){
            this->clearTree(this->_root);
            this->_root = this->_NIL;
        }
        /*
        ** 밑에 두개의 함수는 나중에 지워야 할 것
        */
        void printHelper(node_pointer root, std::string indent, bool last){
            if (root != this->_NIL){
                std::cout << indent;
                if (last) {
                    std::cout << "R----";
                    indent += "     ";
                }
                else{
                    std::cout << "L----";
		            indent += "|    ";
                }
                std::string sColor = root->_color ? "RED" : "BLACK";
                std::cout << root->_value.first << "(" << sColor << ")" << std::endl;
                this->printHelper(root->_left, indent, false);
                this->printHelper(root->_right, indent, true);
            }
        }

        void prettyPrint(void){
            if (this->_root){
                this->printHelper(this->_root, "", true);
            }
        }
    };

    template <class T, class Compare, bool Const>
    class treeIterator {
    public :
        /* typedef */
        typedef T                                                                   value_type;
        typedef Compare                                                             value_compare;
        typedef typename ft::isConst<value_type*, const value_type*, Const>::type   pointer;
        typedef typename ft::isConst<value_type&, const value_type&, Const>::type   reference;
        typedef std::ptrdiff_t                                                      difference_type;
        typedef ft::bidirectional_iterator_tag                                      iterator_category;
        typedef typename ft::tree<value_type, value_compare>                        tree_type;
        typedef tree_type*                                                          tree_pointer;
        typedef typename ft::tree<value_type, value_compare>::Node                  node_type;
        typedef typename ft::isConst<node_type*, const node_type*, Const>::type     node_pointer;
        typedef typename ft::isConst<node_type&, const node_type&, Const>::type     node_reference;

    private :
        /* variables */
        node_pointer _ptr;
        tree_pointer _tree;

    public :
        /* constructor, destructor, getter, setter */
        treeIterator(node_pointer ptr = NULL, tree_pointer tree = NULL) : _ptr(ptr), _tree(tree){
        }

        treeIterator(const treeIterator<value_type, value_compare, false>& copy) : _ptr(copy.getPtr()), _tree(copy.getTree()){
        }

        ~treeIterator(void){
        }

        treeIterator& operator=(const treeIterator& object){
            this->_ptr = object.getPtr();
            this->_tree = object.getTree();
            return *(this);
        }

        node_pointer getPtr(void) const{
            return this->_ptr;
        }

        tree_pointer getTree(void) const{
            return this->_tree;
        }

    public :
        /* operator */
        treeIterator& operator++(void){
            this->_ptr = this->_tree->findNextNode(this->_ptr);
            return *(this);
        }

        treeIterator operator++(int){
            treeIterator temp(*this);
            this->_ptr = this->_tree->findNextNode(this->_ptr);
            return temp;
        }

        treeIterator& operator--(void){
            this->_ptr = this->_tree->findPrevNode(this->_ptr);
            return *(this);
        }

        treeIterator operator--(int){
            treeIterator temp(*this);
            this->_ptr = this->_tree->findPrevNode(this->_ptr);
            return temp;
        }

        bool operator==(const treeIterator<value_type, value_compare, false>& tIter) const{
            return (this->_ptr == tIter.getPtr());
        }

        bool operator==(const treeIterator<value_type, value_compare, true>& tIter) const{
            return (this->_ptr == tIter.getPtr());
        }

        bool operator!=(const treeIterator<value_type, value_compare, false>& tIter) const{
            return (this->_ptr != tIter.getPtr());
        }

        bool operator!=(const treeIterator<value_type, value_compare, true>& tIter) const{
            return (this->_ptr != tIter.getPtr());
        }

        reference operator*(void) const{
            return this->_ptr->_value;
        }

        pointer operator->(void) const{
            return (&(this->_ptr->_value));
        }
    };
}

#endif
