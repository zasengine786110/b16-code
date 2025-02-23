#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>
using namespace std;
// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    unique_ptr<BinaryTreeEnhanced<V>> _left;
    unique_ptr<BinaryTreeEnhanced<V>> _right;
    BinaryTreeEnhanced<V> *_parent;
    BinaryTreeEnhanced(V value): _value(value){};
    // friend defines the functions as friends of the class, required to have access to private members. Could also just use member functions.
    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_left_value;
    }
    // * means that the function left will return a pointer to a BinaryTreeEnhanced
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        return t->_parent;
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          unique_ptr<BinaryTreeEnhanced<V>> l,
                          unique_ptr<BinaryTreeEnhanced<V>> r)
// constructor to create Binary Tree, includes functionality for parents
{
    auto tree = make_unique<BinaryTreeEnhanced<V>>(value);
    tree->_left = move(l);
    tree->_right = move(r);
    if(tree->_left){
        tree->_left->_parent = tree.get(); //gets the value of the parent pointer and assigns it to left and right children classes
    }
    if(tree->_right){
        tree->_right->_parent = tree.get();
    }
    return tree;
}
                        

#endif // __binary_tree_enhanced__