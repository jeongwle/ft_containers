/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <jeongwle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:45:50 by jeongwle          #+#    #+#             */
/*   Updated: 2022/02/09 11:47:51 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "Vector.hpp"

namespace ft {
    template <class T, class Container = ft::vector<T> >
    class stack {
    public :
        /* typedef */
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

    protected :
        /* protected variables */
        container_type c;

    private :
        /* friend */
        template<class _T, class _Container>
        friend bool operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
        template<class _T, class _Container>
        friend bool operator>(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
        template<class _T, class _Container>
        friend bool operator<(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

    public :
        /* Constructor, Destructor */
        explicit stack(const container_type& ctnr = container_type()) : c(ctnr){
        }

        stack(const stack& copy) : c(copy.c){
        }
        
        virtual ~stack(void){
        }

    public :
        /* Member Function */
        stack& operator=(const stack& object){
            this->c = object.c;
            return *(this);
        }

        bool empty(void) const{
            return (this->size() == 0);
        }

        size_type size(void) const{
            return this->c.size();
        }

        value_type& top(void){
            return this->c.back();
        }

        const value_type& top(void) const{
            return this->c.back();
        }

        void push(const value_type& val){
            this->c.push_back(val);
        }

        void pop(void){
            this->c.pop_back();
        }
    };
    /* realational operators(stack) */
    template <class T, class Container>
    bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
        return (!(lhs == rhs));
    }

    template <class T, class Container>
    bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
        return (!(lhs > rhs));
    }

    template <class T, class Container>
    bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
        return (lhs.c > rhs.c);
    }

    template <class T, class Container>
    bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
        return (!(lhs < rhs));
    }
}

#endif
