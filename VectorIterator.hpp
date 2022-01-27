/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:34:44 by jeongwle          #+#    #+#             */
/*   Updated: 2022/01/26 11:34:45 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP
#include "Iterator.hpp"

namespace ft {
    template <class T>
    class VectorIterator {
    public :
        /* typedef */
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef ft::random_access_iterator_tag  iterator_category;

    private :
        /* variables */
        pointer _ptr;

    public :
        /* constructor, destructor, getter, setter */
        VectorIterator() : _ptr(NULL) {
        }

        VectorIterator(pointer ptr) : _ptr(ptr){

        }

        VectorIterator(const VectorIterator& copy){
            *(this) = copy;
        }

        VectorIterator& operator=(const VectorIterator& object){
            this->_ptr = object._ptr;
            return *(this);
        }

        ~VectorIterator(){

        }

        pointer get_Ptr(void){
            return this->_ptr;
        }

        void    set_Ptr(pointer _ptr){
            this->_ptr = _ptr;
        }

    public :
        /* Operator */
        VectorIterator& operator++(){
            this->_ptr++;
            return (*this);
        }

        VectorIterator operator++(int){
            VectorIterator temp(*this);
            this->_ptr++;
            return temp;
        }

        VectorIterator& operator--(){
            this->_ptr--;
            return (*this);
        }

        VectorIterator operator--(int){
            VectorIterator temp(*this);
            this->_ptr--;
            return temp;
        }

        bool operator==(const VectorIterator& vIter) const{
            return (this->_ptr == vIter._ptr);
        }

        bool operator!=(const VectorIterator& vIter) const{
            return (this->_ptr != vIter._ptr);
        }

        reference operator*() const{
            return *(this->_ptr);
        }

        pointer operator->() const{
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

        difference_type operator-(const VectorIterator& vIter){
            return (this->_ptr - vIter._ptr);
        }

        bool operator<(const VectorIterator& vIter) const{
            return (this->_ptr < vIter._ptr);
        }

        bool operator>(const VectorIterator& vIter) const{
            return (this->_ptr > vIter._ptr);
        }

        bool operator<=(const VectorIterator& vIter) const{
            return (this->_ptr <= vIter._ptr);
        }

        bool operator>=(const VectorIterator& vIter) const{
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