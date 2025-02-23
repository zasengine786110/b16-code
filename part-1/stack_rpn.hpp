#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

template<typename T>
void plus(Stack<T> &s){
    T intermediate = s.top();
    s.pop();
    T intermediate2 = s.top();
    s.push(intermediate+intermediate2);
}
template<typename T>
void minus(Stack<T> &s){
    T intermediate = s.top();
    s.pop();
    T intermediate2 = s.top();
    s.push(intermediate-intermediate2);  
}
template<typename T>
void multiplies(Stack<T> &s){
    T intermediate = s.top();
    s.pop();
    T intermediate2 = s.top();
    s.push(intermediate*intermediate2);   
}
template<typename T>
void divides(Stack<T> &s){
    T intermediate = s.top();
    s.pop();
    T intermediate2 = s.top();
    s.push(intermediate/intermediate2);   
}
template<typename T>
void negate(Stack<T> &s){
    T intermediate = s.top();
    s.pop();
    s.push(-intermediate);    
}
//basic and advanced outputs: 2 2 3 + * = 10
#endif // __stack_rpn__