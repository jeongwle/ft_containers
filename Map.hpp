/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:26:38 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/20 17:13:33 by jeongwle         ###   ########.fr       */
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
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef ft::treeIterator<value_type, value_compare, false>      iterator;
        typedef ft::treeIterator<value_type, value_compare, true>       const_iterator;
        typedef ft::reverse_iterator<iterator>                          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef size_t                                                  size_type;

    /* 현재 여기 아래 구현한 거 한개도 없음 그냥 틀 잡아놓은 것 */
    private :
        typedef typename Alloc::template rebind<ft::tree<value_type, value_compare, Alloc> >::other   tree_alloc;
        typedef typename ft::tree<value_type, value_compare, Alloc>*    tree_pointer;
        /* private variables */
        size_type       _size;
        key_compare     _comp;
        allocator_type  _alloc;
        tree_pointer    _tree;

    public :
        /* Constructor, Destructor */
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            /* empty container constructor (default) */
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL){
            /* range constructor */

        }

        map(const map& x){
            /* copy constructor */
        }

        ~map(void){

        }

    public :
        /* Memeber Function */
        map& operator=(const map& x){

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

        }

        void erase(iterator first, iterator last){

        }

        void swap(map& x){

        }

        void clear(void){

        }

        key_compare key_comp(void) const{
            return key_compare(this->_comp);
        }

        value_compare value_comp(void) const{
            return value_compare(this->_comp);
        }

        iterator find(const key_type& k){

        }

        const_iterator find(const key_type& k) const{

        }

        size_type count(const key_type& k) const{

        }

        iterator lower_bound(const key_type& k){

        }

        const_iterator lower_bound(const key_type& k) const{

        }

        iterator upper_bound(const key_type& k){

        }

        const_iterator upper_bound(const key_type& k) const{

        }

        pair<const_iterator, const_iterator> equal_range(const key_type& k) const{

        }

        pair<iterator, iterator> equal_range(const key_type& k){

        }

        allocator_type get_allocator(void) const{
            
        }

    };

}


#endif
