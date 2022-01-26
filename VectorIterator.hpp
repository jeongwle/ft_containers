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
        pointer ptr;

    public :
        /* constructor, destructor, getter, setter */
        VectorIterator(){
            ptr = NULL;
        }

        VectorIterator(const VectorIterator& copy){
            *(this) = copy;
        }

        VectorIterator& operator=(const VectorIterator& object){
            this->ptr = object.ptr;
            return *(this);
        }

        ~VectorIterator(){

        }

        pointer getPtr(void){
            return this->ptr;
        }

        void    setPtr(pointer ptr){
            this->ptr = ptr;
        }

    public :
        /* Operator */
        VectorIterator& operator++(){
            this->ptr++;
            return (*this);
        }

        VectorIterator operator++(int){
            VectorIterator temp(*this);
            this->ptr++;
            return temp;
        }

        VectorIterator& operator--(){
            this->ptr--;
            return (*this);
        }

        VectorIterator operator--(int){
            VectorIterator temp(*this);
            this->ptr--;
            return temp;
        }

        bool operator==(const VectorIterator& vIter) const{
            return (this->ptr == vIter.ptr);
        }

        bool operator!=(const VectorIterator& vIter) const{
            return (this->ptr != vIter.ptr);
        }

        reference operator*() const{
            return *(this->ptr);
        }

        pointer operator->() const{
            return this->ptr;
        }

        VectorIterator& operator+(const int& num){
            this->ptr = this->ptr + num;
            return *(this);
        }

        VectorIterator& operator-(const int& num){
            this->ptr = this->ptr - num;
            return *(this);
        }

        difference_type operator-(const VectorIterator& vIter){
            return (this->ptr - vIter.ptr);
        }

        bool operator<(const VectorIterator& vIter) const{
            return (this->ptr < vIter.ptr);
        }

        bool operator>(const VectorIterator& vIter) const{
            return (this->ptr > vIter.ptr);
        }

        bool operator<=(const VectorIterator& vIter) const{
            return (this->ptr <= vIter.ptr);
        }

        bool operator>=(const VectorIterator& vIter) const{
            return (this->ptr >= vIter.ptr);
        }

        VectorIterator& operator+=(const int& num){
            this->ptr = this->ptr + num;
            return *(this);
        }

        VectorIterator& operator-=(const int& num){
            this->ptr = this->ptr - num;
            return *(this);
        }

        reference operator[](const int& num){
            return *(this->ptr + num);
        }
    };
}

#endif