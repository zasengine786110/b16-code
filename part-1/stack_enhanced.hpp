#ifndef __stack_enhanced___
#define __stack_enhanced___

#include "stack.hpp"

template <typename T> 
class StackEnhanced : public Stack<T>{
  public:
    // Inherit the Stack<T> constructors as they are - avoid having to redefine all class constructors.
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;

    void clear()
    {// have to use this-> as operating on the object of the class in which the method is being declared
        while(this->empty() == false){
            this->pop();
        }
    }
};

template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, const T &value)
{
    stack.push(value);
    return stack;
}

//output = Stack content: 6 5 4
#endif // __stack_enhanced___