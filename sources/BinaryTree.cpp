#include "BinaryTree.hpp"
using namespace std;
namespace ariel
{
template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}


template<typename T>
Node<T>* BinaryTree<T>::add_root(T i)
{
    // if(this->root == nullptr){
    //     this->root.data = i;
        return this->root;
    // }
    // Node<T> temp = new Node<T>(i);
    // this->root = temp;
    // return temp;
}

template<typename T>
Node<T>* BinaryTree<T>::add_left(T i)
{
    return this->root;

}

template<typename T>
Node<T>* BinaryTree<T>::add_right(T i)
{
    return this->root;
}
}

