/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:15:13 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/08 12:08:31 by jeongwle         ###   ########.fr       */
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
        /* Constructor, Destructor */
        reverse_iterator(void){

        }

        explicit reverse_iterator(iterator_type it) : _input(it){

        }

        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter>& rev_it){
            this->_input = rev_it.base();
        }

        ~reverse_iterator(void){

        }

    public :
        /* Member Function */
        reverse_iterator& operator=(const reverse_iterator& object){
            this->_input = object.base();
            return *(this);
        }

        iterator_type base(void) const{
            return this->_input;
        }

        reference operator*(void) const{
            iterator_type temp = this->_input;
            temp--;
            return *(temp);
        }

        reverse_iterator operator+(difference_type n) const{
            return reverse_iterator(this->_input - n);
        }

        reverse_iterator& operator++(void){
            this->_input--;
            return *(this);
        }

        reverse_iterator operator++(int){
            reverse_iterator temp(this->_input);
            this->_input--;
            return temp;
        }

        reverse_iterator& operator+=(difference_type n){
            this->_input -= n;
            return *(this);
        }

        reverse_iterator operator-(difference_type n) const{
            return reverse_iterator(this->_input + n);
        }

        reverse_iterator& operator--(void){
            this->_input++;
            return *(this);
        }

        reverse_iterator operator--(int){
            reverse_iterator temp(this->_input);
            this->_input++;
            return temp;
        }

        reverse_iterator& operator-=(difference_type n){
            this->_input += n;
            return *(this);
        }

        pointer operator->(void) const{
            return &(operator*());
        }

        reference operator[](difference_type n) const{
            reverse_iterator temp(this->_input - n);
            return *(temp);
        }
    };

    /* Nonmember function overloads */
    /* 재이해 필요 */
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (lhs.base() == rhs.base());
    }
    
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (lhs.base() != rhs.base());
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (lhs.base() > rhs.base());
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (lhs.base() < rhs.base());
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (lhs.base() <= rhs.base());
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return (rhs.base() - lhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it){
        return reverse_iterator<Iterator>(rev_it + n);
    }

    /* c++ 11 reverse_iterator */
    // template <class Iterator1, class Iterator2>
    // bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (lhs.base() == rhs.base());
    // }
    
    // template <class Iterator1, class Iterator2>
    // bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (lhs.base() != rhs.base());
    // }

    // template <class Iterator1, class Iterator2>
    // bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (lhs.base() > rhs.base());
    // }

    // template <class Iterator1, class Iterator2>
    // bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (lhs.base() >= rhs.base());
    // }

    // template <class Iterator1, class Iterator2>
    // bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (lhs.base() < rhs.base());
    // }

    // template <class Iterator1, class Iterator2>
    // bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (lhs.base() <= rhs.base());
    // }

    // template <class Iterator1, class Iterator2>
    // typename reverse_iterator<Iterator1>::difference_type operator-(
    // const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
    //     return (rhs.base() - lhs.base());
    // }
}

#endif
