//
//  AVLTreeNode.h
//  AVL TREE
// Node class for AVL Tree
//  Created by Francis Knight on 5/17/19.
//  Copyright © 2019 Francis Knight. All rights reserved.
//

#ifndef AVLTreeNode_h
#define AVLTreeNode_h

template <class T>
class AVLNode {
    // Store a value, two child pointers & a parent pointer
    T date;
    AVLNode<T>* left;
    AVLNode<T>* right;
    AVLNode<T>* parent;
    
    
public:
    AVLNode(T data);
};

template <class T>
AVLNode<T>::AVLNode(T val) {
    this->data = val;
    parent = left = right = nullptr;
}
#endif /* AVLTreeNode_h */
