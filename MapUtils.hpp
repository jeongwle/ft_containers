/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapUtils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:33:57 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/10 10:39:56 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP

namespace ft {
    template <class T1, class T2>
    class pair {
    public :
        /* typedef */
        typedef T1  first_type;
        typedef T2  second_type;

    public :
        /* public variables */
        first_type  _first;
        second_type _second;

    public :
        /* constructor, destructor */
        pair(void) : _first(first_type()), _second(second_type()){

        }

        pair(const first_type& a, const second_type& b) : _first(a), _second(b){

        }

        template <class U, class V>
        pair(const pair<U, V>& pr) : _first(pr._first), _second(pr._second){

        }

        ~pair(void){

        }
    
    public :
        /* Member function */
        pair& operator=(const pair& pr){
            this->_first = pr._first;
            this->_second = pr._second;
            return *(this);
        }
    };

    /* relational operators */
    template <class T1, class T2>
    bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
        return (lhs._first == rhs._first && lhs._second == rhs._second);
    }
    template <class T1, class T2>
    bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
        return (!(lhs < rhs));
    }

    /* make_pair*/
    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y){
        return ft::pair<T1, T2>(x, y);
    }
}


#endif
