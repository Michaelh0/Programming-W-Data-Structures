class BinaryTree
{
public:
   /**
      Constructs an empty tree.
   */
   BinaryTree();

   /**
      Constructs a tree with one node and no children.
      @param root_data the data for the root
   */
   BinaryTree(string root_data);

   /**
      Constructs a binary tree.
      @param root_data the data for the root
      @param left the left subtree
      @param right the right subtree
   */
   BinaryTree(string root_data, BinaryTree left, BinaryTree right);

   /**
      Returns the height of this tree.
      @return the height
   */
   int height() const;

   /**
      Checks whether this tree is empty.
      @return true if this tree is empty
   */
   bool empty() const;

   /**
      Gets the data at the root of this tree.
      @return the root data
   */
   string data() const;

   /**
      Gets the left subtree of this tree.
      @return the left child of the root
   */
   BinaryTree left() const;

   /**
      Gets the right subtree of this tree.
      @return the right child of the root
   */
   BinaryTree right() const;

private:
   /**
      Returns the height of the subtree whose root is the given node.
      @param n a node or nullptr
      @return the height of the subtree, or 0 if n is nullptr
   */
   int height(const Node* n) const;

   Node* root;
};

#endif
#include <algorithm>
#include "binary_tree.h"

using namespace std;

BinaryTree::BinaryTree()
{
   root = nullptr;
}

BinaryTree::BinaryTree(string root_data)
{
   root = new Node;
   root->data = root_data;
   root->left = nullptr;
   root->right = nullptr;
}

BinaryTree::BinaryTree(string root_data, BinaryTree left, BinaryTree right)
{
   root = new Node;
   root->data = root_data;
   root->left = left.root;
   root->right = right.root;
}

int BinaryTree::height(const Node* n) const
{
   if (n == nullptr) { return 0; }
   else { return 1 + max(height(n->left), height(n->right)); }
}

int BinaryTree::height() const { return height(root); }

bool BinaryTree::empty() const { return root == nullptr; }

string BinaryTree::data() const { return root->data; }

BinaryTree BinaryTree::left() const
{
   BinaryTree result;
   result.root = root->left;
   return result;
}

BinaryTree BinaryTree::right() const
{
   BinaryTree result;
   result.root = root->right;
   return result;
}
/*
   This program demonstrates a decision tree for an animal
   guessing game.
*/

#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;

int main()
{
   BinaryTree question_tree(
      BinaryTree("Is it a mammal?",
         BinaryTree("Does it have stripes?",
            BinaryTree("Is it a carnivore?",
               BinaryTree("It is a tiger."),
               BinaryTree("It is a zebra.")),
            BinaryTree("It is a pig.")),
      BinaryTree("Does it fly?",
         BinaryTree("It is an eagle."),
         BinaryTree("Does it swim?",
            BinaryTree("It is a penguin."),
            BinaryTree("It is an ostrich.")))));

   bool done = false;

   while (!done)
   {
      BinaryTree left = question_tree.left();
      BinaryTree right = question_tree.right();
      if (left.empty() && right.empty())
      {
         cout << question_tree.data() << endl;
         done = true;
      }
      else
      {
         string response;
         do
         {
            cout << question_tree.data() << " (y/n): ";
            cin >> response;
         }
         while (response != "y" && response != "n");

         if (response == "y")
         {
            question_tree = left;
         }
         else
         {
            question_tree = right;
         }
      }
   }
}
