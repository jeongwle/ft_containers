/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:15:13 by jeongwle          #+#    #+#             */
/*   Updated: 2022/01/25 15:15:14 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {
    class input_iterator_tag {};
    class output_iterator_tag {};
    class forward_iterator_tag : public input_iterator_tag {};
    class bidirectional_iterator_tag : public forward_iterator_tag {};
    class random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Iterator>
    class iterator_traits {
    public :
        /* typedef */
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    private :
        /* nothing */
    };
    /* 
        template specialization 
        specializations for pointer types T*, which makes it possible to use all iterator-based algorithms with raw pointers.
    */
    template <class T>
    class iterator_traits<T*> {
    public :
        /* typedef */
        typedef std::ptrdiff_t              difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    private :
        /* nothing */
    };
    template <class T>
    class iterator_traits<const T*> {
    public :
        /* typedef */
        typedef std::ptrdiff_t              difference_type;
        typedef T                           value_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    private :
        /* nothing */
    };

    /* reverse_iterator */
    template <class Iterator>
    class reverse_iterator{
    public :
        /* typedef */
        typedef Iterator                                                    iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename ft::iterator_traits<Iterator>::reference           reference;

    private :
        /* private variables */
        iterator_type _input;

    public :
        /* Constructor */
        reverse_iterator(void){

        }

        explicit reverse_iterator(iterator_type it){

        }

        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter>& rev_it){

        }

    public :
        /* Member Function */
        iterator_type base(void) const{
            return this->_input;
        }
    };

}

#endif
