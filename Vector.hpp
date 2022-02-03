/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:27 by jeongwle          #+#    #+#             */
/*   Updated: 2022/01/24 13:21:28 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include "VectorIterator.hpp"

namespace ft {
    template <class T, class Alloc = std::allocator<T> >
    class vector {
    public :
        /* typedef */
        typedef T                                                           value_type;
        typedef Alloc                                                       allocator_type;
        typedef typename allocator_type::reference                          reference;
        typedef typename allocator_type::const_reference                    const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;
        typedef VectorIterator<value_type, false>                           iterator;
        typedef VectorIterator<value_type, true>                            const_iterator;
        // typedef                                             reverse_iterator;
        // typedef                                             const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;
        typedef size_t                                                      size_type;

    private :
        /* private variables */
        allocator_type  _alloc;
        size_type       _capacity;
        size_type       _size;
        pointer         _storage;

    private :
        /* reallocate */
        void reallocate(void){
            if (this->_capacity == 0){
                this->_storage = this->_alloc.allocate(1);
                this->_capacity++;
            }
            else{
                this->_capacity *= 2;
                pointer temp = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++){
                    this->_alloc.construct(temp + i, *(this->_storage + i));
                }
                for (size_type i = 0; i < this->_size; i++){
                    this->_alloc.destroy(this->_storage + i);
                }
                this->_alloc.deallocate(this->_storage, this->_size);
                this->_storage = temp;
            }
        }

        void reallocate(size_type n){
            if (this->_capacity == 0){
                this->_storage = this->_alloc.allocate(n);
                this->_capacity = n;
                return ;
            }
            if (n > this->_capacity){
              this->_capacity = n;
            }
            pointer temp = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.construct(temp + i, *(this->_storage + i));
            }
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.destroy(this->_storage + i);
            }
            this->_alloc.deallocate(this->_storage, this->_size);
            this->_storage = temp;
        }

    public :
        /* Constructor, Destructor */
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _storage(NULL){
            /* empty container constructor(default constructor) */
        }
        
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _capacity(n), _size(n), _storage(NULL) {
            /* fill constructor : Constructs a container witn n elements. Each element is a copy of val */
        }

        template<class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
            /* range constructor : Constructs a container with as many elements as the range(first, last) */
        }

        vector(const vector& copy){

        }

        ~vector(){

        }

    public :
        /* Member Function */
        iterator begin(void){
            return iterator(this->_storage);
        }

        const_iterator begin(void) const{
            return const_iterator(this->_storage);
        }

        iterator end(void){
            return iterator(this->_storage + this->_size);
        }

        const_iterator end(void) const{
            return const_iterator(this->_storage + this->_size);
        }

        // reverse_iterator rbegin(void){

        // }

        // const_reverse_iterator rbegin(void) const{

        // }

        // reverse_iterator rend(void){

        // }

        // const_reverse_iterator rend(void){

        // }

        size_type size(void) const{
            return this->_size;
        }

        size_type max_size(void) const{
            return this->_alloc.max_size();
        }

        /* 02.04(금)에 다시 생각해보기 지금 머리가 너무 안돌아감 */
        void resize(size_type n, value_type val = value_type()){
            if (n <= this->_size){
                for (size_type i = n; i < this->_size; i++){
                    this->_alloc.destroy(this->_storage + i);
                }
                this->_size = n;
            }
            else if (n <= this->_capacity){
                for (; this->_size < n; this->_size++){
                    this->_alloc.construct(this->_storage + this->_size, val);
                }
            }
            else if (n <= this->_capacity * 2){
                reallocate();
                for (; this->_size < n; this->_size++){
                    this->_alloc.construct(this->_storage + this->_size, val);
                }
            }
            else{
                reallocate(n);
                for (; this->_size < n; this->_size++){
                    this->_alloc.construct(this->_storage + this->_size, val);
                }
            }
        }

        size_type capacity(void) const{
            return this->_capacity;
        }

        bool empty(void){
            return (this->_size == 0);
        }
    };
}

#endif
