//
//  binarySearchTree.hpp
//  Binary Search Tree
//
//  Created by Ricardo Rodriguez on 1/10/16.
//  Copyright © 2016 Ricardo Rodriguez. All rights reserved.
//

#ifndef binarySearchTree_hpp
#define binarySearchTree_hpp

#include <stdio.h>
#include <iostream>

class binarySearchTree{
private:
    struct node{
        int key_value;
        node *left;
        node *right;
    };
    node *root;
    
    void deleteTree(node *&leaf);
    bool search(int value, const node *leaf);
    void insert(int value, node *&leaf);
    void remove(int value, node *&leaf);
    void remove(node *&leaf);
    int inOrderSuccessor(node *&leaf);
    void printTree(const node *leaf);
public:
    binarySearchTree();
    ~binarySearchTree();
    
    bool search(int value);
    void insert(int value);
    void remove(int value);
    void printTree();
};

#endif /* binarySearchTree_hpp */
