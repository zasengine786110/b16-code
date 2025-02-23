#include "queue_enhanced.hpp"
#include "utils.hpp"

#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    // Create a queue with space for a few elements
    auto queue = Dequeue<float>(5);

    // Keep pushing and popping elements from the dequeue for a while
    for (int repetition = 0; repetition < 3; ++repetition) {
        cout << "Enqueued front";
        for (int i = 0; i < 3; ++i) {
            queue.enqueue_front(i);
            cout << ' ' << i;
        }
        cout << "\nDequeued front";
        for (int i = 0; i < 3; ++i) {
            cout << ' ' << queue.front();
            queue.dequeue();
        }
        cout << "\nEnqueued back";
        for (int i = 0; i < 3; ++i) {
            queue.enqueue(i);
            cout << ' ' << i;
        }
        cout << "\nDequeued back";
        for (int i = 0; i < 3; ++i) {
            cout << ' ' << queue.back();
            queue.dequeue_back();
        }
        cout << '\n';
    }

    return 0;
}
