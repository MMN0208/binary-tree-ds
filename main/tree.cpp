#include "tree.h"
#include <iostream>
using namespace std;

template <class T, class K>
void iTree<T, K>::insertNode(T data, K key) {
    this->root = this->insert(this->root, data, key);
}

template <class T, class K>
Node<T, K> *iTree<T, K>::clear(Node<T, K> *root) {
    if(root) {
        this->clear(root->pLeft);
        this->clear(root->pRight);
        free(root);
    }
    return NULL;
}

template <class T, class K>
int iTree<T, K>::height(Node<T, K> *root) {
    if(!root) return 0;
    int left = 1 + this->height(root->pLeft);
    int right = 1 + this->height(root->pRight);
    if(left > right) return left;
    return right;
}

template <class T, class K>
int iTree<T, K>::largestSum(Node<T, K> *root, int &k) {
    if(!root) return 0;
    if(!k) return 0;
    int ans = this->largestSum(root->pRight, k);
    if(!k) return ans;
    ans += root->data;
    k--;
    if(!k) return ans;
    return ans + this->largestSum(root->pLeft, k);
}

template <class T, class K>
int iTree<T, K>::callLargestSum(int k) {
    return this->largestSum(this->root, k);
}

template <class T, class K>
int iTree<T, K>::smallestSum(Node<T, K> *root, int &k) {
    if(!root) return 0;
    if(!k) return 0;
    int ans = this->smallestSum(root->pLeft, k);
    if(!k) return ans;
    ans += root->data;
    k--;
    if(!k) return ans;
    return ans + this->smallestSum(root->pRight, k);
}

template <class T, class K>
int iTree<T, K>::callSmallestSum(int k) {
    return this->smallestSum(this->root, k);
}

template <class T, class K>
void iTree<T, K>::LNR(Node<T, K> *root) {
    if(root) {
        this->LNR(root->pLeft);
        cout << root->data << " ";
        this->LNR(root->pRight);
    }
    return;
}

template <class T, class K>
void iTree<T, K>::printLNR() {
    this->LNR(this->root);
}

template <class T, class K>
BST<T, K>::BST() {
    this->root = NULL;
    this->count = 0;
}

template <class T, class K>
BST<T, K>::~BST() {
    this->root = this->clear(this->root);
    this->count = 0;
}

template <class T, class K>
Node<T, K> *BST<T, K>::insert(Node<T, K> *root, T data, K key) {
    if(!root) {
        return new Node<T, K>(data, key);
    }
    if(key <= root->key) {
        root->pLeft = this->insert(root->pLeft, data, key);
    }
    else {
        root->pRight = this->insert(root->pRight, data, key);
    }
    return root;
}

template <class T, class K>
AVL<T, K>::AVL() {
    this->root = NULL;
    this->count = 0;
}

template <class T, class K>
AVL<T, K>::~AVL() {
    this->root = this->clear(this->root);
    this->count = 0;
}

template <class T, class K>
Node<T, K> *iTree<T, K>::rotateLeft(Node<T, K> *root) {
    Node<T, K> *newRoot = root->pRight;
    Node<T, K> *temp = newRoot->pLeft;
    newRoot->pLeft = root;
    root->pRight = temp;
    this->setBalance(root);
    this->setBalance(newRoot);
    return newRoot;
}

template <class T, class K>
Node<T, K> *iTree<T, K>::rotateRight(Node<T, K> *root) {
    Node<T, K> *newRoot = root->pLeft;
    Node<T, K> *temp = newRoot->pRight;
    newRoot->pRight = root;
    root->pLeft = temp;
    this->setBalance(root);
    this->setBalance(newRoot);
    return newRoot;
}

template <class T, class K>
void iTree<T, K>::setBalance(Node<T, K> *root) {
    int left = this->height(root->pLeft);
    int right = this->height(root->pRight);
    if(left - right > 1) {
        root->balance = -1;
    }
    else if(right - left > 1) {
        root->balance = 1;
    }
    else root->balance = 0;
    return;
}

template <class T, class K>
Node<T, K> *AVL<T, K>::insert(Node<T, K> *root, T data, K key) {
    if(!root) {
        return new Node<T, K>(data, key);
    }
    if(key <= root->key) {
        root->pLeft = this->insert(root->pLeft, data, key);
    }
    else {
        root->pRight = this->insert(root->pRight, data, key);
    }
    this->setBalance(root);
    if(root->balance == -1 && key <= root->pLeft->key) {
        return this->rotateRight(root);
    }
    else if(root->balance == -1 && key > root->pLeft->key) {
        root->pLeft = this->rotateLeft(root->pLeft);
        return this->rotateRight(root);
    }
    else if(root->balance == 1 && key > root->pRight->key) {
        return this->rotateLeft(root);
    }
    else if(root->balance == 1 && key <= root->pRight->key) {
        root->pRight = this->rotateRight(root->pRight);
        return this->rotateLeft(root);
    }
    return root;
}

template class iTree<int, int>;
template class iTree<float, int>;
template class iTree<double, int>;
template class iTree<int, float>;
template class iTree<float, float>;
template class iTree<double, float>;
template class iTree<int, double>;
template class iTree<float, double>;
template class iTree<double, double>;
template class BST<int, int>;
template class BST<float, int>;
template class BST<double, int>;
template class BST<int, float>;
template class BST<float, float>;
template class BST<double, float>;
template class BST<int, double>;
template class BST<float, double>;
template class BST<double, double>;
template class AVL<int, int>;
template class AVL<float, int>;
template class AVL<double, int>;
template class AVL<int, float>;
template class AVL<float, float>;
template class AVL<double, float>;
template class AVL<int, double>;
template class AVL<float, double>;
template class AVL<double, double>;