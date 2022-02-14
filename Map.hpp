/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:26:38 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/14 11:16:50 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include "RBTree.hpp"
#include <map>

namespace ft {
    template <class Key,
              class T, 
              class Compare = std::less<Key>, 
              class Alloc = std::allocator< ft::pair<const Key, T> >
              >
    class map {
    public :
        /* typedef */
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef ft::pair<const key_type, mapped_type>       value_type;
        typedef Compare                                     key_compare;
        class value_compare {
        protected :
            Compare comp;
        public :
            value_compare(Compare c) : comp(c){}
            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;
            result_type operator()(const value_type& x, const value_type& y) const{
                return comp(x._first, y._first);
            }
        };
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        // typedef iterator;
        // typedef const_iterator;
        // typedef reverse_iterator;
        // typedef const_reverse_iterator;
        // typedef difference_type;
        typedef size_t                                      size_type;

    /* 현재 여기 아래 구현한 거 한개도 없음 그냥 틀 잡아놓은 것 */
    private :
        /* private variables */

    public :
        /* Constructor, Destructor */
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            /* empty container constructor (default) */
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()){
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

        }

        const_iterator begin(void) const{

        }

        iterator end(void){

        }

        const_iterator end(void) const{

        }

        reverse_iterator rbegin(void){

        }

        const_reverse_iterator rbegin(void) const{

        }

        reverse_iterator rend(void){

        }

        const_reverse_iterator rend(void) const{

        }

        bool empty(void) const{

        }

        size_type size(void) const{

        }

        size_type max_size(void) const{

        }

        mapped_type& operator[](const key_type& k){

        }

        pair<iterator, bool> insert(const value_type& val){
            
        }

        iterator insert(iterator position, const value_type& val){

        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last){

        }

        void erase(iterator position){

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

        }

        value_compare value_comp(void) const{

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
