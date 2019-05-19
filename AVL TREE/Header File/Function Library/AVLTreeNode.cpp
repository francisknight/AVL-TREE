//
//  AVLTree.cpp
//  AVL TREE
//
//  Created by Francis Knight on 5/17/19.
//

#include "AVLTree.hpp"
#include <iostream>
#include "AVLTreeNode.h"
using namespace std;

template <class T>
void AVLTree<T>::add(T value) {
    if (root == nullptr) {
        root = new AVLNode<T>(value);
        currentSize++;
        return;
    }
    
    // if root is not null / alreay has a value
    recurviseAdd(root, value);
}

template <class T>
void AVLTree<T>::recurviseAdd(AVLNode<T> parent, AVLNode<T> newValue) {
    
    // Adding to the right side of the tree
    if(newValue > parent->data) { // add to the right size of the tree
        if (parent->right == nullptr) {
            parent->right = newValue;
            newValue->parent = parent;
            currentSize++;
        }
        else {
            recurviseAdd(parent->rigt, newValue);
        }
    }
    
    // Adding to the left side of the tree
    if(newValue < parent->data) { // add to the left side of the tree
        if (parent->left == nullptr) {
            parent->left = newValue;
            newValue->parent = parent;
            currentSize++;
        }
        else {
            recurviseAdd(parent->left, newValue);
        }
    }
    
    // after adding we call check balance
    checkBalance(newValue);
}

template <class T>
void AVLTree<T>::checkBalance(AVLNode<T> value){
    if((height(value->left) - height(value->right) > 1 ||
       height(value->left) - height(value->right) < -1)) {
        rebalance(value);
    }
    
    if(value->parent == nullptr)
        return;
    checkBalance(value->parent);
}

template <class T>
void AVLTree<T>::rebalance(AVLNode<T> value) {
    
    // left hand side of tree
    if(height(value->left) - height(value->right) > 1){
        if(height(value->left) > height(value->right)) { // do a right totation
            value = rightRotate(value);
        }
        else {
            value = leftRotate(value);
        }
    }
    
    // right hand side of tree
    else {
        if(height(value->right) > height(value->left)) { // do a right totation
            value = leftRotate(value);
        }
        else {
            value = rightRotate(value);
        }
    }
    
    if (value->parent == nullptr) {
        root = value;
    }
}

template <class T>
void AVLTree<T>::leftRotate(AVLNode<T> value) {
    AVLNode<T> temp = value->right;
    value->right = temp->left;
    if (value->right != nullptr) {
        value->right->parent = value;
        //value->right.isleftchild = false;
    }
    
    if (value->parent == nullptr) { // root node
        root = temp;
        temp->parent = nullptr;
    }
    else {
        temp->parent = value->parent;
        //if(value->isleftchild) {
           // temp->isleftchild = true;
           // temp->parent->left = temp;
        //}
    }
    //else {
        //temp.isleftchild = false;
        //temp->parent->right = temp;
    //}
    
    temp->left = value;
    //value->isleftchild = true;
    value->parent = temp;
}

template <class T>
void AVLTree<T>::rightRotate(AVLNode<T> value) {
    value = nullptr;
}



// -------------------- Height functions implementation ----------------------------
template <class T>
int AVLTree<T>::height(){
    if (root == nullptr) {
        return 0;
    }
    
    return height(root) -1;  // call height overload function
}

template <class T>
int AVLTree<T>::height(AVLNode<T> value) {
    if(value == nullptr)
        return 0;
    
    int leftHeight = height(value->left) + 1;
    int rightHeight = height(value->right) + 1;
    
    if(leftHeight > rightHeight)
        return leftHeight;
    
    return rightHeight;
}
// ------------------ End Height functions implementation -----------------------------
