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
#include <map>

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
        std::map<int, double> nodes;

    public:
        BinaryTree();

        BinaryTree<T> &add_root(T i);
        BinaryTree<T> &add_left(T i, T j);
        BinaryTree<T> &add_right(T i, T j);
        Node<T> &get_root();
        bool contains(Node<T>, T);
        bool containSub(Node<T>, T);

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

            T *operator->() const
            {
                return &(pointer_to_current_node->data);
            }

            iterator &operator++()
            {
                pointer_to_current_node = pointer_to_current_node->left;
                return *this;
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
    Node<T> &BinaryTree<T>::get_root()
    {
        if (this->root)
        {
            return *this->root;
        }
        throw("there is no root for this tree");
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
    BinaryTree<T> &BinaryTree<T>::add_left(T i, T j)
    {
        return *this;
    }

    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T i, T j)
    {
        return *this;
    }

    template <typename T>
    bool contains(Node<T> *root, T n)
    {
        // if (root->data == nullptr)
        // {
        //     return false;
        // }
        // if (root->data == n)
        // {
        //     return true;
        // }
        // else
        // {
        //     if (root->left != nullptr)
        //     {
        //         return (containSub(root->left, n));
        //     }
        //     if (root->right != NULL)
        //     {
        //         return (containSub(root->right, n));
        //     }
        // }
        return false;
    }

    template <typename T>
    bool containSub(Node<T> curNode, T n)
    {
        if (curNode.data == nullptr)
        {
            return false;
        }
        if (curNode.data == n)
        {
            return true;
        }
        else
        {
            if (curNode.left != nullptr)
            {
                return (containSub(curNode.left, n));
            }
            if (curNode.right != nullptr)
            {
                return (containSub(curNode.right, n));
            }
        }
        return false;
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
    {
        return os;
    }
}
#endif
