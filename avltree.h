#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class AVLTree
{
    private:
        class AVLNode
        {
            public:
                T element;
                AVLNode* left, * right;
                int height;
                AVLNode()
                {
                    left = nullptr;
                    right = nullptr;
                }
                AVLNode(T& data, AVLNode* lt, AVLNode*rt, int h = 0):
                    element(data), left(lt), right(rt), height(h){}
                ~AVLNode(){
                    delete[] left;
                    delete[] right;
                }
        };
        AVLNode* root;
        void insert(T&, AVLNode*&);
        void rotateWithLeftChild(AVLNode*&);
        void rotateWithRightChild(AVLNode*&);
        void doubleWithRightChild(AVLNode*&);
        void doubleWithLeftChild(AVLNode*&);
        void printInOrder(AVLNode*&);
        void printPostOrder(AVLNode*&);
        void printPreOrder(AVLNode*&);
        void printIndex(AVLNode*, ofstream&);

    public:
        AVLTree();
        AVLTree(T);
        AVLTree(const AVLTree<T>&);
        AVLTree<T>& operator= (const AVLTree<T>&);
        void insert(T&);
        T search(T);
        int height(AVLNode*);
        int getMax(int, int);
        bool isEmpty();
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
        void printIndex(ofstream&);
        void bringBack(ifstream&);
};

template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(T newData)
{
    AVLNode* temp = new AVLNode();
    temp->data = newData;
    root = temp;
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& second)
{
    root = second.root;
}

template <typename T>
T AVLTree<T>::search(T arg)
{
    AVLNode* current = root;
    while(current != nullptr && current->element != arg){
        if(current->element > arg)
            current = current->left;
        else
            current = current->right;
    }
    if(current == nullptr)
        throw out_of_range("Element is not in the tree");
    else
        return current->element;
}

template <typename T>
void AVLTree<T>::printInOrder(){
    printInOrder(root);
}

template <typename T>
void AVLTree<T>::printInOrder(AVLNode *& current)
{
    if(current == nullptr){
        return;
    }
    printInOrder(current->left);
    cout << current->element.getWord() << " " << endl;
    printInOrder(current->right);
}

template <typename T>
void AVLTree<T>::printPreOrder(){
    printPreOrder(root);
}

template <typename T>
void AVLTree<T>::printPreOrder(AVLNode *& current)
{
    if(current == nullptr){
        return;
    }
    cout << current->element;
    printPreOrder(current->left);
    printPreOrder(current->right);
}

template <typename T>
void AVLTree<T>::printPostOrder(){
    printPostOrder(root);
}

template <typename T>
void AVLTree<T>::printPostOrder(AVLNode *& current)
{
    if(current == nullptr){
        return;
    }
    printPostOrder(current->left);
    printPostOrder(current->right);
    cout << current->element;
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& second)
{
    root = second.root;
    return *this;
}

template <typename T>
int AVLTree<T>::height(AVLNode* n)
{
    if(n == nullptr)
    {
        return -1;
    }
    else
        return n->height;
}

template <typename T>
int AVLTree<T>::getMax(int first, int second)
{
    return first > second ? first : second ;
}

template <typename T>
void AVLTree<T>::insert(T& data)
{
    insert(data, root);
}

template <typename T>
void AVLTree<T>::insert(T& x, AVLNode* & t)
{
    if(t == nullptr)
    {
        t = new AVLNode(x, nullptr, nullptr);
    }
    else
        if(x < t->element)
        {
            insert(x, t->left);
            if(height(t->left)-height(t->right) == 2)
            {
                if(x < t->left->element)
                {
                    rotateWithLeftChild(t);
                }
                else
                {
                    doubleWithLeftChild(t);
                }
            }
        }
    else if(t->element < x)
        {
            insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
                if(t->right->element < x)
                {
                    rotateWithRightChild(t);
                }
                else
                {
                    doubleWithRightChild(t);
                }
        }
        else {
            t->element.pushback(x.getPtr());
        }
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <typename T>
void AVLTree<T>::rotateWithLeftChild(AVLNode*& k2)
{
    AVLNode * k1 = k2->left;
    k2 -> left = k1->right;
    k1 -> right = k2;
    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->height = max(height(k1->left),height(k2)) + 1;
    k2 = k1;
}

template <typename T>
void AVLTree<T>::rotateWithRightChild(AVLNode *& k1)
{
    AVLNode * k2 = k1->right;
    k1->right= k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(height(k2->right),height(k1)) + 1;
    k1 = k2;
}

template <typename T>
void AVLTree<T>::doubleWithRightChild(AVLNode*& k3)
{
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

template <typename T>
void AVLTree<T>::doubleWithLeftChild(AVLNode*& k4)
{
     rotateWithRightChild(k4->left);
     rotateWithLeftChild(k4);
}

template <typename T>
bool AVLTree<T>::isEmpty()
{
    if(root == nullptr)
        return true;
    return false;
}

template <typename T>
void AVLTree<T>::printIndex(AVLNode* current, ofstream& outFile){
    if(current == nullptr){
        return;
    }
    printIndex(current->left, outFile);
    outFile << current->element << endl;
    printIndex(current->right, outFile);
}

template <typename T>
void AVLTree<T>::printIndex(ofstream& outFile){
    printIndex(root, outFile);
}

template <typename T>
void AVLTree<T>::bringBack(ifstream& str)
{

}

#endif // AVLTREE_H
