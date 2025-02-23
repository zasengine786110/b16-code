#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"
using namespace std;

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        return this->_storage.back();
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        return this->_storage.back();
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        this->_storage.insert(this->_storage.begin(), value);
        ++this->_size;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        this->_storage.pop_back();
        --this->_size;
    }

    // Remove all elements from the queue
    void clear() { 
        this->_storage.clear();
        this->_size = 0;
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        return this->_size - 1;
    }
};
/*outputs Enqueued front 0 1 2
Dequeued front 0 0 1
Enqueued back 0 1 2
Dequeued back 1 2 0
Enqueued front 0 1 2
Dequeued front 2 0 0
Enqueued back 0 1 2
Dequeued back 0 0 0
Enqueued front 0 1 2
Dequeued front 0 1 2
Enqueued back 0 1 2
Dequeued back 1 2 0
*/

#endif // __queue_enhanced__