#ifndef __binary_search_tree_enhanced__
#define __binary_search_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    if(!left(tree)){
        return tree;
    }
    else{
        return bst_min(left(tree));
    }
}

template <typename T> T bst_max(const T &tree)
{
    if(!right(tree)){
        return tree;
    }
    else{
        return bst_max(right(tree));
    }
}

#endif // __binary_search_tree_enhanced__