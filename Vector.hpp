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
    template<class T, class Alloc = std::allocator<T> >
    class vector {
    public :
        /* type def */
        typedef T                           value_type;
        typedef Alloc                       allocator_type;
        typedef value_type&                 reference;
        typedef const value_type&           const_reference;
        typedef value_type*                 pointer;
        typedef const value_type*           const_pointer;
        typedef size_t                      size_type;
        typedef VectorIterator<value_type>  iterator;

    private :
        /* private variables */
        allocator_type  _alloc;
        size_type       _capacity;
        size_type       _size;
        pointer         _storage;

    public :
        /* Constructor, Destructor */
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _storage(NULL){
            /* empty container constructor(default constructor) */
        }
        
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
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
    };
}

#endif
