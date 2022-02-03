/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:49:19 by jeongwle          #+#    #+#             */
/*   Updated: 2022/01/27 10:49:21 by jeongwle         ###   ########.fr       */
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

    template <>
    class is_integral<unsigned int> {
    public :
        static const bool value = true;
    };

    /* isConst */
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
}

#endif
