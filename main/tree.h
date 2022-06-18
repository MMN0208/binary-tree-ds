#ifndef TREE_H
#define TREE_H

template <class T, class K>
class Node;

template <class T, class K>
class iTree {
public:
    void insertNode(T data, K key);
    void removeNode(K key);
    int callLargestKeySum(int k);
    int callSmallestKeySum(int k);
    void printLNR();
protected:
    virtual ~iTree() {}
    virtual Node<T, K> *insert(Node<T, K> *root, T data, K key) = 0;
    virtual Node<T, K> *remove(Node<T, K> *root, K key) = 0;
    Node<T, K> *clear(Node<T, K> *root);
    Node<T, K> *rotateLeft(Node<T, K> *root);
    Node<T, K> *rotateRight(Node<T, K> *root);
    void setBalance(Node<T, K> *root);
    int height(Node<T, K> *root);
    int largestKeySum(Node<T, K> *root, int &k);
    int smallestKeySum(Node <T, K> *root, int &k);
    Node<T, K> *maxKeyNode(Node<T, K> *root);
    void LNR(Node<T, K> *root);
    Node<T, K> *root;
    int count;
};

template <class T, class K>
class BST : public iTree<T, K> {
public:
    BST();
    ~BST();
protected:
    Node<T, K> *insert(Node<T, K> *root, T data, K key);
    Node<T, K> *remove(Node<T, K> *root, K key);
};

template <class T, class K>
class AVL : public iTree<T, K> {
public:
    AVL();
    ~AVL();
protected:
    Node<T, K> *insert(Node<T, K> *root, T data, K key);
    Node<T, K> *remove(Node<T, K> *root, K key);
};

template <class T, class K>
class Node {
    Node *pLeft, *pRight;
    T data;
    K key;
    int balance;
    friend class iTree<T, K>;
    friend class BST<T, K>;
    friend class AVL<T, K>;
public:
    Node(T data, K key) : pLeft(0), pRight(0), data(data), key(key), balance(0) {}
};

#endif