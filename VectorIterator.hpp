/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:34:44 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/04 15:36:23 by jeongwle         ###   ########.fr       */
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
        typedef T                                                           value_type;
        typedef ft::isConst<value_type*, const value_type*, Const>::type    pointer;
        typedef ft::isConst<value_type&, const value_type&, Const>::type    reference;
        typedef std::ptrdiff_t                                              difference_type;
        typedef ft::random_access_iterator_tag                              iterator_category;

    private :
        /* variables */
        pointer _ptr;

    public :
        /* constructor, destructor, getter, setter */
        VectorIterator(void) : _ptr(NULL){
        }

        VectorIterator(pointer ptr) : _ptr(ptr){

        }

        VectorIterator(const VectorIterator<value_type, false>& copy){
            *(this) = copy;
        }

        VectorIterator& operator=(const VectorIterator<value_type, false>& object){
            this->_ptr = object._ptr;
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
            return (this->_ptr == vIter._ptr);
        }

        bool operator==(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr == vIter._ptr);
        }

        bool operator!=(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr != vIter._ptr);
        }

        bool operator!=(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr != vIter._ptr);
        }

        reference operator*(void) const{
            return *(this->_ptr);
        }

        pointer operator->(void) const{
            return this->_ptr;
        }

        VectorIterator& operator+(const int& num){
            this->_ptr = this->_ptr + num;
            return *(this);
        }

        VectorIterator& operator-(const int& num){
            this->_ptr = this->_ptr - num;
            return *(this);
        }

        difference_type operator-(const VectorIterator<value_type, false>& vIter){
            return (this->_ptr - vIter._ptr);
        }

        difference_type operator-(const VectorIterator<value_type, true>& vIter){
            return (this->_ptr - vIter._ptr);
        }

        bool operator<(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr < vIter._ptr);
        }

        bool operator<(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr < vIter._ptr);
        }

        bool operator>(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr > vIter._ptr);
        }

        bool operator>(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr > vIter._ptr);
        }

        bool operator<=(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr <= vIter._ptr);
        }

        bool operator<=(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr <= vIter._ptr);
        }

        bool operator>=(const VectorIterator<value_type, false>& vIter) const{
            return (this->_ptr >= vIter._ptr);
        }

        bool operator>=(const VectorIterator<value_type, true>& vIter) const{
            return (this->_ptr >= vIter._ptr);
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
}

#endif
