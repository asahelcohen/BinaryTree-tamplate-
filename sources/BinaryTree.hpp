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
template<typename T>
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

template<typename T>
class BinaryTree
{
private:
    Node<T> *root;

public:
    BinaryTree ();

    Node<T> *add_root(T i);
    Node<T> *add_left(T i);
    Node<T> *add_right(T i);

};
}
#endif
