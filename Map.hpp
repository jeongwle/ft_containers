/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:26:38 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/10 11:19:37 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include "MapUtils.hpp"

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
        // typedef                                         value_compare;
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
    };

}


#endif
