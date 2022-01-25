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

namespace ft {
    template<class T, class Alloc = std::allocator<T> >
    class vector {
    public :
        /* type def */
        typedef T                   value_type;
        typedef Alloc               allocator_type;
        typedef value_type&         reference;
        typedef const value_type&   const_reference;
        typedef value_type*         pointer;
        typedef const value_type*   const_pointer;
        typedef size_t              size_type;

    private :
        /* private variables */
        allocator_type  _alloc;
        size_type       _capacity;
        size_type       _size;
        pointer         _storage;
    };
}

#endif
