/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:27 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/06 12:27:15 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <stdexcept>
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
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;
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
                size_type capacityTemp = this->_capacity;
                this->_capacity *= 2;
                pointer temp = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++){
                    this->_alloc.construct(temp + i, value_type(*(this->_storage + i)));
                }
                for (size_type i = 0; i < this->_size; i++){
                    this->_alloc.destroy(this->_storage + i);
                }
                this->_alloc.deallocate(this->_storage, capacityTemp);
                this->_storage = temp;
            }
        }

        void reallocate(size_type n){
            if (this->_capacity == 0){
                this->_storage = this->_alloc.allocate(n);
                this->_capacity = n;
                return ;
            }
            pointer temp = this->_alloc.allocate(n);
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.construct(temp + i, value_type(*(this->_storage + i)));
            }
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.destroy(this->_storage + i);
            }
            this->_alloc.deallocate(this->_storage, this->_capacity);
            this->_capacity = n;
            this->_storage = temp;
        }

    public :
        /* Constructor, Destructor */
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _storage(NULL){
            /* empty container constructor(default constructor) */
        }
        
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _capacity(0), _size(0), _storage(NULL) {
            /* fill constructor : Constructs a container witn n elements. Each element is a copy of val */
            this->assign(n, val);
        }

        template<class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
        typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc), _capacity(0), _size(0), _storage(NULL){
            /* range constructor : Constructs a container with as many elements as the range(first, last) */
            this->assign(first, last);
        }

        vector(const vector& copy) : _alloc(copy._alloc), _capacity(0), _size(0), _storage(NULL){
            *(this) = copy;
        }

        ~vector(){
            if (this->_capacity > 0){
                this->clear();
                this->_alloc.deallocate(this->_storage, this->_capacity);
            }
        }

    public :
        /* Member Function */
        vector& operator=(const vector& x){
            this->assign(x.begin(), x.end());
            return *(this);
        }

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

        reverse_iterator rbegin(void){
            return reverse_iterator(this->_storage + this->_size);
        }

        const_reverse_iterator rbegin(void) const{
            return const_reverse_iterator(this->_storage + this->_size);
        }

        reverse_iterator rend(void){
            return reverse_iterator(this->_storage);
        }

        const_reverse_iterator rend(void) const{
            return const_reverse_iterator(this->_storage);
        }

        size_type size(void) const{
            return this->_size;
        }

        size_type max_size(void) const{
            return this->_alloc.max_size();
        }

        void resize(size_type n, value_type val = value_type()){
            if (n <= this->_size){
                for (size_type i = n; i < this->_size; i++){
                    this->_alloc.destroy(this->_storage + i);
                }
                this->_size = n;
            }
            else if (n <= this->_capacity){
                for (; this->_size < n; this->_size++){
                    this->_alloc.construct(this->_storage + this->_size, value_type(val));
                }
            }
            else if (n <= this->_capacity * 2){
                this->reallocate();
                for (; this->_size < n; this->_size++){
                    this->_alloc.construct(this->_storage + this->_size, value_type(val));
                }
            }
            else{
                this->reallocate(n);
                for (; this->_size < n; this->_size++){
                    this->_alloc.construct(this->_storage + this->_size, value_type(val));
                }
            }
        }

        size_type capacity(void) const{
            return this->_capacity;
        }

        bool empty(void) const{
            return (this->_size == 0);
        }

        void reserve(size_type n){
            if (n > this->max_size()){
                throw std::length_error("Length error.");
            }
            if (n > this->_capacity){
                this->reallocate(n);
            }
        }

        reference operator[](size_type n){
            return *(this->_storage + n);
        }

        const_reference operator[](size_type n) const{
            return *(this->_storage + n);
        }

        reference at(size_type n){
            if (n >= this->_size){
                throw std::out_of_range("Out of range.");
            }
            return *(this->_storage + n);
        }

        const_reference at(size_type n) const{
            if (n >= this->_size){
                throw std::out_of_range("Out of range.");
            }
            return *(this->_storage + n);
        }

        reference front(void){
            return *(this->_storage);
        }

        const_reference front(void) const{
            return *(this->_storage);
        }

        reference back(void){
            return *(this->_storage + this->_size - 1);
        }

        const_reference back(void) const{
            return *(this->_storage + this->_size - 1);
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
        typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL){
            // for (const_iterator iter = this->begin(); iter != this->end(); iter++){
            //     if (iter == first || iter == last){
            //         return ;
            //     }
            // }
            this->clear();
            difference_type checkSize = 0;
            for (InputIterator iter = first; iter != last; iter++){
                checkSize++;
            }
            this->reserve(checkSize);
            for (InputIterator iter = first; iter != last; iter++){
                this->push_back(*(iter));
            }
        }

        void assign(size_type n, const value_type& val){
            this->clear();
            this->reserve(n);
            for (size_type i = 0; i < n; i++){
                this->push_back(val);
            }
        }

        void push_back(const value_type& val){
            if (this->_size == this->_capacity){
                this->reallocate();
            }
            this->_alloc.construct(this->_storage + this->_size, value_type(val));
            this->_size++;
        }

        void pop_back(void){
            this->_alloc.destroy(this->_storage + --this->_size);
        }

        /* 재점검 필요 */
        iterator insert(iterator position, const value_type& val){
            // if (this->_size == this->_capacity){
            //     this->_capacity *= 2;
            // }
            size_type posTemp = 0;
            for (const_iterator iter = this->begin(); iter != position; iter++){
                posTemp++;
            }
            this->insert(position, 1, val);
            // pointer temp = this->_alloc.allocate(this->_capacity);
            // for (size_type i = 0; this->_storage + i != position.getPtr(); i++){
            //     this->_alloc.construct(temp + i), *(this->_storage + i);
            // }
            // this->_alloc.construct(temp + posTemp, val);
            // for (size_type i = posTemp + 1; i < ++this->_size; i++){
            //     this->_alloc.construct(temp + i, *(this->_storage + i - 1));
            // }
            // for (size_type i = 0; i < this->_size - 1; i++){
            //     this->_alloc.destroy(this->_storage + i);
            // }
            // this->_alloc.deallocate(this->_storage, this->_size - 1);
            // this->_storage = temp;
            return iterator(this->_storage + posTemp);
        }

        void insert(iterator position, size_type n, const value_type& val){
            size_type capacityTemp = this->_capacity;
            if (this->_capacity < this->_size + n && this->_size + n <= this->_capacity * 2){
                this->_capacity *= 2;
            }
            else if (this->_size + n > this->_capacity * 2){
                this->_capacity = this->_size + n;
            }
            size_type posTemp = 0;
            for (const_iterator iter = this->begin(); iter != position; iter++){
                posTemp++;
            }
            pointer temp = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; this->_storage + i != position.getPtr(); i++){
                this->_alloc.construct(temp + i, value_type(*(this->_storage + i)));
            }
            for (size_type i = posTemp + n; i < this->_size + n; i++){
                this->_alloc.construct(temp + i, value_type(*(this->_storage + i - n)));
            }
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.destroy(this->_storage + i);
            }
            this->_alloc.deallocate(this->_storage, capacityTemp);
            this->_size += n;
            for (size_type i = posTemp; n > 0; n--){
                this->_alloc.construct(temp + i, value_type(val));
                i++;
            }
            this->_storage = temp;
        }

        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
        typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL){
            size_type capacityTemp = this->_capacity;
            difference_type num = 0;
            for (InputIterator iter = first; iter != last; iter++){
                num++;
            }
            if (this->_capacity < this->_size + num && this->_size + num <= this->_capacity * 2){
                this->_capacity *= 2;
            }
            else if (this->_size + num > this->_capacity * 2){
                this->_capacity = this->_size + num;
            }
            size_type posTemp = 0;
            for (const_iterator iter = this->begin(); iter != position; iter++){
                posTemp++;
            }
            pointer temp = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; this->_storage + i != position.getPtr(); i++){
                this->_alloc.construct(temp + i, value_type(*(this->_storage + i)));
            }
            for (size_type i = posTemp + num; i < this->_size + num; i++){
                this->_alloc.construct(temp + i, value_type(*(this->_storage + i - num)));
            }
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.destroy(this->_storage + i);
            }
            this->_alloc.deallocate(this->_storage, capacityTemp);
            this->_size += num;
            for (InputIterator iter = first; iter != last; iter++){
                this->_alloc.construct(temp + posTemp, value_type(*(iter)));
                posTemp++;
            }
            this->_storage = temp;
        }

        iterator erase(iterator position){
            size_type posTemp = 0;
            /* remaining number = repeat */
            // difference_type repeat = this->end().getPtr() - position.getPtr() - 1;
            for (const_iterator iter = this->begin(); iter != position; iter++){
                posTemp++;
            }
            this->_alloc.destroy(position.getPtr());
            for (const_iterator iter = position + 1; iter != this->end(); iter++){
                *(this->_storage + posTemp) = *(iter);
                posTemp++;
            }
            // for (size_type i = posTemp; repeat > 0; i++){
            //     *(this->_storage + i) = *(this->_storage + i + 1);
            //     repeat--;
            // }
            this->_size--;
            return position;
        }

        /* 재점검 필요 */
        iterator erase(iterator first, iterator last){
            size_type posTemp = 0;
            iterator iter = this->begin();
            for (; iter != first; iter++){
                posTemp++;
            }
            for (; iter != last; iter++){
                this->_alloc.destroy(iter.getPtr());
            }
            for(; iter != this->end(); iter++){
                *(this->_storage + posTemp) = *(iter);
                posTemp++;
            }
            // for (difference_type i = this->end() - last; i > 0; i--){
            //     *(this->_storage + posTemp) = *(this->_storage + posTemp + (last - first));
            //     posTemp++;
            // }
            this->_size -= (last - first);
            /*뭔가 비효율적인거같음..*/
            // difference_type numOfDestroy = last - first;
            // for (; numOfDestroy > 0; numOfDestroy--){
            //     this->erase(first);
            // }
            return first;
        }

        void swap(vector& x){
            size_type sizeTemp = this->_size;
            size_type capacityTemp = this->_capacity;
            allocator_type allocatorTypeTemp = this->_alloc;
            pointer pointerTemp = this->_storage;
            this->_size = x._size;
            this->_capacity = x._capacity;
            this->_alloc = x._alloc;
            this->_storage = x._storage;
            x._size = sizeTemp;
            x._capacity = capacityTemp;
            x._alloc = allocatorTypeTemp;
            x._storage = pointerTemp;
        }

        void clear(void){
            for (size_type i = 0; i < this->_size; i++){
                this->_alloc.destroy(this->_storage + i);
            }
            this->_size = 0;
        }

        allocator_type get_allocator(void) const{
            return this->_alloc;
        }
    };

    /* relational operator(vector) */
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
        if (lhs.size() != rhs.size()){
            return false;
        }
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
        return (rhs < lhs);
    }
    
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
        return (!(lhs < rhs));
    }

    /* std::swap(vector) */
    template <class T, class Alloc>
    void swap(vector<T, Alloc>& x, vector<T, Alloc>& y){
        x.swap(y);
    }
}

#endif
