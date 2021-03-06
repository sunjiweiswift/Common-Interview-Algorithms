#include "binary_serach_tree.h"

#include <iostream>

template <typename Type>
BinarySerachTree<Type>::BinarySerachTree() {}

template <typename Type>
BinarySerachTree<Type>::~BinarySerachTree() {}

template <typename Type>
void BinarySerachTree<Type>::Inorder(BSTNode<Type>* x) {
    if (x != Nil) {
        Inorder(x->left);
        std::cout << x->key << std::endl;
        Inorder(x->right);
    }
}

template <typename Type>
BSTNode<Type>* BinarySerachTree<Type>::Search(Type key, BSTNode<Type>* node) {
    if (node == Nil || key == node->key) {
        return node;
    }
    if (key < node->key) {
        return Search(node->left, key);
    } else {
        return Search(node->right, key);
    }
}

template <typename Type>
BSTNode<Type>* BinarySerachTree<Type>::Search2(Type key, BSTNode<Type>* node) {
    while (node == Nil && key != node->key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

template <typename Type>
BSTNode<Type>* BinarySerachTree<Type>::Minimum(BSTNode<Type>* node) {
    while (node->left != Nil) {
        node = node->left;
    }
    return node;
}

template <typename Type>
BSTNode<Type>* BinarySerachTree<Type>::Maximum(BSTNode<Type>* node) {
    while (node->right != Nil) {
        node = node->right;
    }
    return node;
}

template <typename Type>
void BinarySerachTree<Type>::Insert(BSTNode<Type>* z) {
    BSTNode<Type>* y = Nil;
    BSTNode<Type>* x = root;
    while (x != Nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == Nil) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

int main() {
    return 0;
}