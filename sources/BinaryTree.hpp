#ifndef BTREE_H
#define BTREE_H

//#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

// begin_preorder(), end_preorder()
// begin_inorder(), end_inorder()
// begin_postorder(), end_postorder()
// אופרטור פלט
namespace ariel
{
    template <typename T>
    struct Node
    {
    public:
        T data;
        Node<T> *left;
        Node<T> *right;

        Node<T>(T data)
        {
            this->data = data;
            left = right = nullptr;
        }
    };

    template <typename T>
    class BinaryTree
    {
    private:
        Node<T> *root;

    public:
        BinaryTree();

        BinaryTree<T> &add_root(T i);
        BinaryTree<T> *add_left(T i, T j);
        BinaryTree<T> *add_right(T i, T j);
    };
    template <typename T>
    BinaryTree<T>::BinaryTree()
    {
        root = nullptr;
    }

    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T i)
    {
        // if(this->root == nullptr){
        //     this->root.data = i;
        return *this;
        // }
        // Node<T> temp = new Node<T>(i);
        // this->root = temp;
        // return temp;
    }

    template <typename T>
    BinaryTree<T> *BinaryTree<T>::add_left(T i, T j)
    {
        return this->root;
    }

    template <typename T>
    BinaryTree<T> *BinaryTree<T>::add_right(T i, T j)
    {
        return this->root;
    }
}
#endif
