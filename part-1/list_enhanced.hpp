
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>
using namespace std;

template <typename T> void list_delete_after(Node<T> *node)
{
    // check that both the pointers are not nullptrs
    if(node && node->next){
        Node<T> *node_to_delete = node->next.get(); // get address of the node to delete
        node->next = move(node_to_delete->next); // transfer pointer to original node
    }
    
}

#endif // __list_enhanced__