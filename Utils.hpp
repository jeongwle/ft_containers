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
    template <bool Cond, class T = void>
    class enable_if {

    };

    template <class T>
    class enable_if<true, T> {
        typedef T type;
    };

    template <class T>
    class is_integral {
        static const bool value = false;
    };

    template <>
    class is_integral<bool> {
        static const bool value = true;
    };

    template <>
    class is_integral<char> {
        static const bool value = true;
    };
    
    template <>
    class is_integral<signed char> {
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned char> {
        static const bool value = true;
    };

    template <>
    class is_integral<wchar_t> {
        static const bool value = true;
    };

    template <>
    class is_integral<char16_t> {
        static const bool value = true;
    };

    template <>
    class is_integral<char32_t> {
        static const bool value = true;
    };

    template <>
    class is_integral<short> {
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned short> {
        static const bool value = true;
    };

    template <>
    class is_integral<int> {
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned int> {
        static const bool value = true;
    };

    template <>
    class is_integral<long> {
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned long> {
        static const bool value = true;
    };

    template <>
    class is_integral<long long> {
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned long long> {
        static const bool value = true;
    };

    template <>
    class is_integral<unsigned int> {
        static const bool value = true;
    };
}

#endif
