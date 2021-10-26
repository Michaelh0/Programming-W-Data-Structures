/*
   This program demonstrates a decision tree for an animal 
   guessing game.
*/

#include <iostream>
#include <string>
#include "binary_tree.h"

//required to use templates 
#include "binary_tree.cpp"

using namespace std;

int main()
{
/*
   BinaryTree<string> question_tree(
      BinaryTree<string>("Is it a mammal?",
         BinaryTree<string>("Does it have stripes?",
            BinaryTree<string>("Is it a carnivore?",
               BinaryTree<string>("It is a tiger."),
               BinaryTree<string>("It is a zebra.")),
            BinaryTree<string>("It is a pig.")),
      BinaryTree<string>("Does it fly?",
         BinaryTree<string>("It is an eagle."),
         BinaryTree<string>("Does it swim?",
            BinaryTree<string>("It is a penguin."),
            BinaryTree<string>("It is an ostrich.")))));
*/
	BinaryTree<char> question_tree(
      BinaryTree<char>('*',
        BinaryTree<char>('+',
            BinaryTree<char>('4'),
            BinaryTree<char>('3')),
      BinaryTree<char>('-',
            BinaryTree<char>('4'),
            BinaryTree<char>('3'))));

   bool done = false;
   
   while (!done)
   {
      //BinaryTree<string> left = question_tree.left();
      //BinaryTree<string> right = question_tree.right();
	  BinaryTree<char> left = question_tree.left();
      BinaryTree<char> right = question_tree.right();
      
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
