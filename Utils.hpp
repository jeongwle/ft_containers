/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:49:19 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/08 10:44:40 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {
    /* enable if */
    template <bool Cond, class T = void>
    class enable_if {

    };

    template <class T>
    class enable_if<true, T> {
    public :
        typedef T type;
    };

    /* is_integral */
    template <class T>
    class is_integral {
    public :
        static const bool value = false;
    };

    template <>
    class is_integral<bool> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<char> {
    public :
        static const bool value = true;
    };
    
    template <>
    class is_integral<signed char> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned char> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<wchar_t> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<char16_t> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<char32_t> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<short> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned short> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<int> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned int> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<long> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned long> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<long long> {
    public :
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned long long> {
    public :
        static const bool value = true;
    };

    /* isConst(custom) */
    template <class T, class ConstT, bool Const = false>
    class isConst {
    public :
        typedef T type;
    };

    template <class T, class ConstT>
    class isConst<T, ConstT, true> {
    public :
        typedef ConstT type;
    };

    /* equal */
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
        while (first1 != last1){
            if (!(*first1 == *first2)){
                return false;
            }
            ++first1;
            ++first2;
        }
        return true;
    }

    /* lexicographical_compare */
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
        while (first1 != last1){
            if (first2 == last2 || *first2 < *first1){
                return false;
            }
            else if (*first1 < *first2){
                return true;
            }
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

#endif
