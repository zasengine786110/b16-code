#ifndef __binary_tree__
#define __binary_tree__

#include <memory>
#include <utility>
using namespace std;

// A class representing a binary tree
template <typename V> struct BinaryTree {
    V _value;
    unique_ptr<BinaryTree<V>> _left;
    unique_ptr<BinaryTree<V>> _right;

    // These are global functions because of `friend`
    friend V &value(BinaryTree *t) { return t->_value; }
    friend const V &value(const BinaryTree *t) { return t->_value; }
    friend BinaryTree *left(BinaryTree *t) { return t->_left.get(); }
    friend BinaryTree *right(BinaryTree *t){ return t->_right.get();}
};

// A helper function to build a binary tree
template <typename V>
unique_ptr<BinaryTree<V>>
// this make_binary_tree uses an implicitly defined constructor of the three member variables of the BinaryTree structure
make_binary_tree(const V &value, unique_ptr<BinaryTree<V>> left,
                 unique_ptr<BinaryTree<V>> right)
{
    return unique_ptr<BinaryTree<V>>{
        new BinaryTree<V>{value, move(left), move(right)}};
}

#endif // __binary_tree__