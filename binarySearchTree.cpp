//
//  binarySearchTree.cpp
//  Binary Search Tree
//
//  Created by Ricardo Rodriguez on 1/10/16.
//  Copyright © 2016 Ricardo Rodriguez. All rights reserved.
//

#include "binarySearchTree.hpp"

binarySearchTree::binarySearchTree(){
    root = NULL;
}

binarySearchTree::~binarySearchTree(){
    deleteTree(root);
}

void binarySearchTree::deleteTree(node *&leaf){
    if (leaf != NULL) {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

bool binarySearchTree::search(int value){
    return search(value, root);
}

bool binarySearchTree::search(int value, const node *leaf){
    if (leaf == NULL) {
        return false;
    }else if (leaf->key_value == value){
        return true;
    }else if (value < leaf->key_value){
        return search(value, leaf->left);
    }else{
        return search(value, leaf->right);
    }
}

void binarySearchTree::insert(int value){
    insert(value, root);
}

void binarySearchTree::insert(int value, node *&leaf){
    if (leaf == NULL) {
        leaf = new node;
        leaf->key_value = value;
        leaf->left = leaf->right = NULL;
    }else if (value < leaf->key_value){
        insert(value, leaf->left);
    }else{
        insert(value, leaf->right);
    }
}

void binarySearchTree::remove(int value){
    remove(value, root);
}

void binarySearchTree::remove(int value, node *&leaf){
    if (leaf == NULL) {
        std::cerr << "Nothing was deleted" << std::endl;
    }else if(value == leaf->key_value){
        remove(leaf);
    }else if (value < leaf->key_value){
        remove(value, leaf->left);
    }else{
        remove(value, leaf->right);
    }
}

void binarySearchTree::remove(node *&leaf){
    node *temp;
    if (leaf->left == NULL && leaf->right == NULL) {
        delete leaf;
        leaf = NULL;
    }else if (leaf->left != NULL && leaf->right == NULL){
        temp = leaf;
        leaf = leaf->left;
        delete temp;
        temp = NULL;
    }else if(leaf->left == NULL && leaf->right != NULL){
        temp = leaf;
        leaf = leaf->right;
        delete temp;
        temp = NULL;
    }else{
        int successor = inOrderSuccessor(leaf->right);
        leaf->key_value = successor;
        remove(successor, leaf->right);
    }
}

int binarySearchTree::inOrderSuccessor(node *&leaf){
    if (leaf->left == NULL) {
        return leaf->key_value;
    }else{
        return inOrderSuccessor(leaf->left);
    }
}

void binarySearchTree::printTree(){
    printTree(root);
}

void binarySearchTree::printTree(const node *leaf){
    if (leaf != NULL) {
        if (leaf->left != NULL) {
            printTree(leaf->left);
        }
        std::cout << " " << leaf->key_value << " " << std::endl;
        if (leaf->right != NULL) {
            printTree(leaf->right);
        }
    }
}




