#ifndef __list__
#define __list__

#include <cassert>
#include <memory>
#include <vector>
using namespace std;

template <typename T> struct Node {
    T value;
    unique_ptr<Node<T>> next;

    Node() : value{}, next{nullptr} {}
    Node(const T &value, unique_ptr<Node<T>> next)
        : value{value}, next{move(next)}
    {
    }
};

template <typename T>
Node<T> *list_insert_after(Node<T> *node, const T &value)
{
    node->next =
        make_unique<Node<T>>(value, move(node->next));
    return node->next.get();
}

template <typename T, typename F>
Node<T> *list_find_predecessor(Node<T> *node, F predicate)
{
    for (; node && node->next; node = node->next.get()) {
        if (predicate(node->next->value)) return node;
    }
    return nullptr;
}

template <typename T>
vector<T> list_to_vector(const Node<T> &node)
{
    vector<T> v;
    for (Node<T> *current = node.next.get(); current;
         current = current->next.get()) {
        v.push_back(current->value);
    }
    return v;
}

#endif // __list__
