/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:34:44 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/08 10:44:32 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP
#include "Iterator.hpp"
#include "Utils.hpp"

namespace ft {
    template <class T, bool Const>
    class VectorIterator {
    public :
        /* typedef */
        typedef T                                                                   value_type;
        typedef typename ft::isConst<value_type*, const value_type*, Const>::type   pointer;
        typedef typename ft::isConst<value_type&, const value_type&, Const>::type   reference;
        typedef std::ptrdiff_t                                                      difference_type;
        typedef ft::random_access_iterator_tag                                      iterator_category;

    private :
        /* variables */
        pointer _ptr;

    public :
        /* constructor, destructor, getter, setter */
        VectorIterator(void) : _ptr(NULL){
        }

        VectorIterator(pointer ptr) : _ptr(ptr){
        }

        VectorIterator(const VectorIterator<value_type, false>& copy) : _ptr(copy.getPtr()){
        }

        VectorIterator& operator=(const VectorIterator& object){
            this->_ptr = object.getPtr();
            return *(this);
        }

        ~VectorIterator(void){
        }

        pointer getPtr(void) const{
            return this->_ptr;
        }

        void    setPtr(pointer _ptr){
            this->_ptr = _ptr;
        }

    public :
        /* Operator */
        VectorIterator& operator++(void){
            this->_ptr++;
            return (*this);
        }

        VectorIterator operator++(int){
            VectorIterator temp(*this);
            this->_ptr++;
            return temp;
        }

        VectorIterator& operator--(void){
            this->_ptr--;
            return (*this);
        }

        VectorIterator operator--(int){
            VectorIterator temp(*this);
            this->_ptr--;
            return temp;
        }

        bool operator==(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr == vIter.getPtr());
        }

        bool operator==(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr == vIter.getPtr());
        }

        bool operator!=(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr != vIter.getPtr());
        }

        bool operator!=(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr != vIter.getPtr());
        }

        reference operator*(void) const{
            return *(this->_ptr);
        }

        pointer operator->(void) const{
            return this->_ptr;
        }

        VectorIterator operator+(const int& num) const{
            return VectorIterator(this->_ptr + num);
        }

        VectorIterator operator-(const int& num) const{
            return VectorIterator(this->_ptr - num);
        }

        difference_type operator-(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr - vIter.getPtr());
        }

        difference_type operator-(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr - vIter.getPtr());
        }

        bool operator<(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr < vIter.getPtr());
        }

        bool operator<(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr < vIter.getPtr());
        }

        bool operator>(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr > vIter.getPtr());
        }

        bool operator>(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr > vIter.getPtr());
        }

        bool operator<=(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr <= vIter.getPtr());
        }

        bool operator<=(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr <= vIter.getPtr());
        }

        bool operator>=(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr >= vIter.getPtr());
        }

        bool operator>=(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr >= vIter.getPtr());
        }

        VectorIterator& operator+=(const int& num){
            this->_ptr = this->_ptr + num;
            return *(this);
        }

        VectorIterator& operator-=(const int& num){
            this->_ptr = this->_ptr - num;
            return *(this);
        }

        reference operator[](const int& num){
            return *(this->_ptr + num);
        }
    };

    template <class T, bool Const>
    VectorIterator<T, Const> operator+(typename VectorIterator<T, Const>::difference_type n,
    const VectorIterator<T, Const>& it) {
        return VectorIterator<T, Const>(it + n);
    }
}

#endif
