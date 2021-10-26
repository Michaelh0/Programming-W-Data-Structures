#include <algorithm>
#include "binary_tree.h"

using namespace std;

template <typename U>
BinaryTree<U>::BinaryTree()
{
   root = nullptr;
} 

template <typename U>
BinaryTree<U>::BinaryTree(U root_data) 
{
   root = new Node<U>;
   root->data = root_data;
   root->left = nullptr;
   root->right = nullptr;
}

template <typename U>
BinaryTree<U>::BinaryTree(U root_data, BinaryTree<U> left, BinaryTree<U> right)
{
   root = new Node<U>;
   root->data = root_data;
   root->left = left.root;
   root->right = right.root;
}

template <typename U>   
int BinaryTree<U>::height(const Node<U>* n) const
{
   if (n == nullptr) { return 0; }
   else { return 1 + max(height(n->left), height(n->right)); }
}

template <typename U>
int BinaryTree<U>::height() const { return height(root); }

template <typename U>
bool BinaryTree<U>::empty() const { return root == nullptr; }

template <typename U>
U BinaryTree<U>::data() const { return root->data; }
   
template <typename U>
BinaryTree<U> BinaryTree<U>::left() const
{ 
   BinaryTree<U> result;
   result.root = root->left; 
   return result;
}

template <typename U>
BinaryTree<U> BinaryTree<U>::right() const
{ 
   BinaryTree<U> result;
   result.root = root->right; 
   return result;
}
