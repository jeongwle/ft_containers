/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:26:38 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/24 14:55:26 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include "RBTree.hpp"

namespace ft {
    template <class Key,
              class T, 
              class Compare = std::less<Key>, 
              class Alloc = std::allocator< ft::pair<const Key, T> >
              >
    class map {
    public :
        /* typedef */
        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>                   value_type;
        typedef Compare                                                 key_compare;
        class value_compare {
        protected :
            Compare comp;
        public :
            value_compare(Compare c) : comp(c){}
            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;
            result_type operator()(const value_type& x, const value_type& y) const{
                return comp(x.first, y.first);
            }
        };
        typedef Alloc                                                               allocator_type;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;
        typedef ft::treeIterator<value_type, value_compare, false>                  iterator;
        typedef ft::treeIterator<value_type, value_compare, true>                   const_iterator;
        typedef ft::reverse_iterator<iterator>                                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type             difference_type;
        typedef size_t                                                              size_type;

    /* 현재 여기 아래 구현한 거 한개도 없음 그냥 틀 잡아놓은 것 */
    private :
        typedef typename Alloc::template rebind<ft::tree<value_type, value_compare, Alloc> >::other   tree_alloc;
        typedef typename ft::tree<value_type, value_compare, Alloc>*                tree_pointer;
        typedef typename ft::tree<value_type, value_compare, Alloc>::node_pointer   node_pointer;
        /* private variables */
        size_type       _size;
        key_compare     _comp;
        allocator_type  _alloc;
        tree_pointer    _tree;

    public :
        /* Constructor, Destructor */
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _comp(comp), _alloc(alloc){
            /* empty container constructor (default) */
            tree_alloc treeAlloc;
            this->_tree = treeAlloc.allocate(1);
            treeAlloc.construct(this->_tree, ft::tree<value_type, value_compare, Alloc>(value_compare(this->_comp)));
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _size(0), _comp(comp), _alloc(alloc){
            /* range constructor */
            tree_alloc treeAlloc;
            this->_tree = treeAlloc.allocate(1);
            treeAlloc.construct(this->_tree, ft::tree<value_type, value_compare, Alloc>(value_compare(this->_comp)));
            this->insert(first, last);
        }

        map(const map& x) : _size(x._size), _comp(x._comp), _alloc(x._alloc){
            /* copy constructor */
            tree_alloc treeAlloc;
            this->_tree = treeAlloc.allocate(1);
            treeAlloc.construct(this->_tree, ft::tree<value_type, value_compare, Alloc>(*(x._tree)));
        }

        ~map(void){
            tree_alloc treeAlloc;
            treeAlloc.destroy(this->_tree);
            treeAlloc.deallocate(this->_tree, 1);
        }

    public :
        /* Memeber Function */
        map& operator=(const map& x){
            this->_size = x._size;
            this->_comp = x._comp;
            this->_alloc = x._alloc;
            *(this->_tree) = *(x._tree);
            return *(this);
        }

        iterator begin(void){
            return iterator(this->_tree->findFirstNode(), this->_tree);
        }

        const_iterator begin(void) const{
            return const_iterator(this->_tree->findFirstNode(), this->_tree);
        }

        iterator end(void){
            return iterator(this->_tree->getNilNode(), this->_tree);
        }

        const_iterator end(void) const{
            return const_iterator(this->_tree->getNilNode(), this->_tree);
        }

        reverse_iterator rbegin(void){
            return reverse_iterator(iterator(this->_tree->getNilNode(), this->_tree));
        }

        const_reverse_iterator rbegin(void) const{
            return const_reverse_iterator(const_iterator(this->_tree->getNilNode(), this->_tree));
        }

        reverse_iterator rend(void){
            return reverse_iterator(iterator(this->_tree->findFirstNode(), this->_tree));
        }

        const_reverse_iterator rend(void) const{
            return const_reverse_iterator(const_iterator(this->_tree->findFirstNode(), this->_tree));
        }

        bool empty(void) const{
            return (this->_size == 0);
        }

        size_type size(void) const{
            return this->_size;
        }

        size_type max_size(void) const{
            return this->_tree->getNodeAlloc().max_size();
        }

        mapped_type& operator[](const key_type& k){
            return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
        }

        pair<iterator, bool> insert(const value_type& val){
            if (this->_tree->insert(val)){
                this->_size++;
                return ft::pair<iterator, bool>(iterator(this->_tree->findNode(val), this->_tree), true);
            }
            return ft::pair<iterator, bool>(iterator(this->_tree->findNode(val), this->_tree), false);
        }

        iterator insert(iterator position, const value_type& val){
            (void)position;
            if (this->_tree->insert(val)){
                this->_size++;
            }
            return iterator(this->_tree->findNode(val), this->_tree);
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last,
        typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL){
            for (InputIterator iter = first; iter != last; iter++){
                this->insert(*iter);
            }
        }

        void erase(iterator position){
            if (this->_tree->erase(*position)){
                this->_size--;
            }
        }

        size_type erase(const key_type& k){
            if (this->_tree->erase(ft::make_pair(k, mapped_type()))){
                this->_size--;
                return (1);
            }
            return (0);
        }

        void erase(iterator first, iterator last){
            iterator temp;
            while(first != last){
                temp = first;
                first++;
                this->erase(temp);
            }
        }

        void swap(map& x){
            size_type sizeTemp = this->_size;
            key_compare keyTemp = this->_comp;
            allocator_type allocTemp = this->_alloc;
            tree_pointer treeTemp = this->_tree;
            this->_size = x._size;
            this->_comp = x._comp;
            this->_alloc = x._alloc;
            this->_tree = x._tree;
            x._size = sizeTemp;
            x._comp = keyTemp;
            x._alloc = allocTemp;
            x._tree = treeTemp;
        }

        void clear(void){
            this->_tree->clear();
            this->_size = 0;
        }

        key_compare key_comp(void) const{
            return key_compare(this->_comp);
        }

        value_compare value_comp(void) const{
            return value_compare(this->_comp);
        }

        iterator find(const key_type& k){
            if (this->count(k)){
                return iterator(this->_tree->findNode(ft::make_pair(k, mapped_type())), this->_tree);
            }
            return iterator(this->_tree->getNilNode(), this->_tree);
        }

        const_iterator find(const key_type& k) const{
            if (this->count(k)){
                return const_iterator(this->_tree->findNode(ft::make_pair(k, mapped_type())), this->_tree);
            }
            return const_iterator(this->_tree->getNilNode(), this->_tree);
        }

        size_type count(const key_type& k) const{
            if (this->_tree->findNode(ft::make_pair(k, mapped_type()))){
                return (1);
            }
            return (0);
        }

        iterator lower_bound(const key_type& k){
            if (this->_tree->lowerThanFirst(ft::make_pair(k, mapped_type()))){
                return iterator(this->_tree->findFirstNode(), this->_tree);
            }
            node_pointer node = this->_tree->firstBetweenLast(ft::make_pair(k, mapped_type()));
            return iterator(node, this->_tree);
        }

        const_iterator lower_bound(const key_type& k) const{
            if (this->_tree->lowerThanFirst(ft::make_pair(k, mapped_type()))){
                return const_iterator(this->_tree->findFirstNode(), this->_tree);
            }
            node_pointer node = this->_tree->firstBetweenLast(ft::make_pair(k, mapped_type()));
            return const_iterator(node, this->_tree);
        }

        iterator upper_bound(const key_type& k){
            if (this->_tree->lowerThanFirst(ft::make_pair(k, mapped_type()))){
                return iterator(this->_tree->findFirstNode(), this->_tree);
            }
            if (this->count(k)){
                node_pointer next = this->_tree->findNode(ft::make_pair(k, mapped_type()));
                next = this->_tree->findNextNode(next);
                if (next){
                    return iterator(next, this->_tree);
                }
            }
            node_pointer node = this->_tree->firstBetweenLast(ft::make_pair(k, mapped_type()));
            return iterator(node, this->_tree);
        }

        const_iterator upper_bound(const key_type& k) const{
            if (this->_tree->lowerThanFirst(ft::make_pair(k, mapped_type()))){
                return const_iterator(this->_tree->findFirstNode(), this->_tree);
            }
            if (this->count(k)){
                node_pointer next = this->_tree->findNode(ft::make_pair(k, mapped_type()));
                next = this->_tree->findNextNode(next);
                if (next){
                    return const_iterator(next, this->_tree);
                }
            }
            return const_iterator(this->_tree->getNilNode(), this->_tree);
        }

        pair<const_iterator, const_iterator> equal_range(const key_type& k) const{
            return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
        }

        pair<iterator, iterator> equal_range(const key_type& k){
            return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
        }

        allocator_type get_allocator(void) const{
            return this->_alloc;
        }
    };

    /* Nonmember function */
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs){
        if (lhs.size() != rhs.size()){
            return false;
        }
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs){
        return (!(lhs == rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs){
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs){
        return (!(rhs < lhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs){
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs){
        return (!(lhs < rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs){
        lhs.swap(rhs);
    }
}

#endif
