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
    class BinaryTree
    {
        struct Node
        {
            T data;
            Node *left;
            Node *right;
            Node(const T &c) : data(c), right(nullptr), left(nullptr) {}
            ~Node()
            {
                delete right;
                delete left;
            }

        public:
            Node(const Node &unq) : data(unq.data)
            {
                if (unq.right)
                {
                    right = new Node(*unq.right);
                }
                else
                {
                    right = nullptr;
                }
                if (unq.left)
                {
                    left = new Node(*unq.left);
                }
                else
                {
                    left = nullptr;
                }
            }

            Node &operator=(Node other)
            {
                if (this != &other)
                {

                    delete left;
                    delete right;
                    data = other.data;

                    if (other.right)
                    {
                        right = new Node(*other.right);
                    }
                    else
                    {
                        right = nullptr;
                    }
                    if (other.left)
                    {
                        left = new Node(*other.left);
                    }
                    else
                    {
                        left = nullptr;
                    }
                }
                return *this;
            }
            Node(Node &&other)
            {
                data = other.data;
                left = other.left;
                right = other.right;
                other.data = nullptr;
                other.left = nullptr;
                other.right = nullptr;
            }
            Node &operator=(Node &&other)
            {
                if (left)
                    delete left;
                if (right)
                    delete right;
                if (data)
                    delete data;
                data = other.data;
                left = other.left;
                right = other.right;
                other.data = nullptr;
                other.left = nullptr;
                other.right = nullptr;
            }
        };
        Node *root;
        Node *retriveNode(Node *curNode, T i)
        {
            if (curNode == nullptr)
            {
                return nullptr;
            }
            if (curNode->data == i)
            {
                return curNode;
            }

            Node *nextNode = retriveNode(curNode->right, i);
            if (nextNode == nullptr)
            {
                return retriveNode(curNode->left, i);
            }

            return nextNode;
        }

        static void createPreorderVec(Node **node, std::vector<Node *> &vec)
        {
            if (node != nullptr)
            {
                vec.push_back(*node);
                createPreorderVec(&(*node)->left, vec);
                createPreorderVec(&(*node)->right, vec);
            }
            return;
        }

        static void createInorderVec(Node **node, std::vector<Node *> &vec)
        {
            if (node != nullptr)
            {
                createPreorderVec(&(*node)->left, vec);
                vec.push_back(*node);
                createPreorderVec(&(*node)->right, vec);
            }
            return;
        }

        static void createpostorderVec(Node **node, std::vector<Node *> &vec)
        {
            if (node != nullptr)
            {
                createPreorderVec(&(*node)->left, vec);
                createPreorderVec(&(*node)->right, vec);
                vec.push_back(*node);
            }
            return;
        }

    public:
        BinaryTree() : root(nullptr) {}

        BinaryTree &add_root(T i)
        {
            if (this->root == nullptr)
            {
                this->root = new Node{i};
                return *this;
            }
            this->root->data = i;
            return *this;
        }
        BinaryTree &add_left(T i, T j)
        {
            Node *temp = retriveNode(root, i);
            if (temp)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(j);
                }
                else
                    temp->left->data = j;
                return *this;
            }
            throw("tree does not contain node");
        }
        BinaryTree &add_right(T i, T j)
        {
            Node *temp = retriveNode(root, i);
            if (temp)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(j);
                }
                else
                    temp->right->data = j;
                return *this;
            }
            throw("tree does not contain node");
        }
        ~BinaryTree() { delete root; }

        BinaryTree(const BinaryTree &unq) : root(unq.root)
        {
            if (unq.root)
            {
                root = new Node(*unq.right);
            }
            else
            {
                root = nullptr;
            }
        }
        Node &operator=(Node other)
        {
            if (this != &other)
            {

                delete root;
                root = other.root;
            }
            return *this;
        }
        BinaryTree(BinaryTree &&other)
        {
            root = other.root;
            other.root = nullptr;
        }
        BinaryTree &operator=(BinaryTree &&other)
        {
            if (root)
                delete root;
            root = other.root;
            other.root = nullptr;
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
        {
            return os;
        }

        class iterator
        {
        private:
            Node *pointer_to_current_node;
            std::vector<Node *> vec;
            int sort;
            unsigned long index;

        public:
            iterator(Node *ptr = nullptr, int sort = 0)
                : pointer_to_current_node(ptr), sort(sort), index(0)
            {
                vec.clear();
                if (ptr)
                {
                    if (sort == 1)
                    {
                        createPreorderVec(&pointer_to_current_node, vec);
                    }
                    if (sort == 2)
                    {
                        createInorderVec(&pointer_to_current_node, vec);
                    }
                    if (sort == 3)
                    {
                        createpostorderVec(&pointer_to_current_node, vec);
                    }
                }
                vec.push_back(nullptr);
                pointer_to_current_node = vec.at(0);
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
                index++;
                pointer_to_current_node = vec.at(index);
                return *this;
            }

            const iterator operator++(int)
            {
                iterator temp = vec.at(index);
                pointer_to_current_node = vec.at(++index);
                return temp;
            }

            bool operator==(const iterator &it) const
            {
                return pointer_to_current_node == it.pointer_to_current_node;
            }

            bool operator!=(const iterator &it) const
            {
                return !(pointer_to_current_node == it.pointer_to_current_node);
            }
        };

        iterator begin()
        {
            return begin_inorder();
        }

        iterator end()
        {
            return iterator(nullptr);
        }

        iterator begin_preorder()
        {
            return iterator{root, 1};
        }

        iterator end_preorder()
        {
            return iterator(nullptr);
        }

        iterator begin_inorder()
        {
            return iterator{root, 2};
        }

        iterator end_inorder()
        {
            return iterator(nullptr);
        }

        iterator begin_postorder()
        {
            return iterator{root, 3};
        }

        iterator end_postorder()
        {
            return iterator(nullptr);
        }
    };
}
#endif

