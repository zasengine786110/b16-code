#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>
using namespace std;

template <typename T> //when using templates the functions/methods MUST BE defined in the hpp files so the compiler is able to see entire function definition when instantiating. [Not the same as regular functions and classes]
void array_delete(vector<T> &A, size_t index)
{
    if(A.size() > index){
        A.erase(A.begin()+index); // this will remove the value and resize automatically
    }
}
//output = Initially A = [0, 1, 2, 3, 4]
//After deleting the element at position 0: A = [1, 2, 3, 4]
//After deleting the element at position 0: A = [2, 3, 4]
//After deleting the element at position 0: A = [3, 4]
//After deleting the element at position 0: A = [4]
//After deleting the element at position 0: A = []
#endif // __array_delete__