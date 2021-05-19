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
        BinaryTree<T> &add_left(T i, T j);
        BinaryTree<T> &add_right(T i, T j);

        class iterator
        {
        private:
            Node<T> *pointer_to_current_node;

        public:
            iterator(Node<T> *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            T &operator*() const
            {
                return pointer_to_current_node->data;
            }

            iterator &operator++()
            {
                pointer_to_current_node = pointer_to_current_node->left;
            }

            const iterator operator++(int)
            {
                iterator temp = *this;
                pointer_to_current_node = pointer_to_current_node->left;
                return temp;
            }

            bool operator==(const iterator &it) const
            {
                return pointer_to_current_node == it.pointer_to_current_node;
            }

            bool operator!=(const iterator &it) const
            {
                return pointer_to_current_node != it.pointer_to_current_node;
            }

            friend std::ostream &operator<<(std::ostream &os, const BinaryTree &b);
        };
        // begin_preorder(), end_preorder()
        // begin_inorder(), end_inorder()
        // begin_postorder(), end_postorder()
        // אופרטור פלט
        iterator begin()
        {
            return iterator(root);
        }

        iterator end()
        {
            return iterator(root);
        }

        iterator begin_preorder()
        {
            return iterator(root);
        }

        iterator end_preorder()
        {
            return iterator(root);
        }

        iterator begin_inorder()
        {
            return iterator(root);
        }

        iterator end_inorder()
        {
            return iterator(root);
        }

        iterator begin_postorder()
        {
            return iterator(root);
        }

        iterator end_postorder()
        {
            return iterator(root);
        }
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
        return &this;
        // }
        // Node<T> temp = new Node<T>(i);
        // this->root = temp;
        // return temp;
    }

    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T i, T j)
    {
        return &this;
    }

    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T i, T j)
    {
        return &this;
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
    {
        return os;
    }
}
#endif
