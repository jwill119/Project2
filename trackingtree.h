// trackingtree.h
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/28/2018
// Last modified: 12/4/2018

#ifndef TRACKINGTREE_h
#define TRACKINGTREE_h


#include "hash.h"
#include "node.h"

#include <ctime>

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;


class Trackingtree
{
  public:      
      Trackingtree();
      ~Trackingtree();      
      
      //adds a new node to the tree 
      void add_node();
      
      //updates the relevant hashes in the node
      void update_node(int index_in);
            
      //prints the all the node's elements
      void print_node(int index);        
     
      // prints the entire tree
      void print_tree(void);
      
      // changes the rew_enent in the specified node
      void change_raw_EVENT();
 
      //resets the index to 1 
      void beginning(void);
 
      //sets the index to the last node in the tree
      void end(void);
 
      //sets the index to the given number 
      void set_index(unsigned long int new_index);
 
      //returns the value of the index 
      unsigned long int position(void); 
  
      //returns the value of the number_of_node
      unsigned long int get_number_of_nodes();

      // returns whether tree is empty
      bool is_empty();

  private:
      // Vector of Nodes (primary data member)
      vector<Node> tree;

      // Total number of nodes in the tree 
      unsigned long int number_of_nodes;
      
      // Current position in the tree 
      unsigned long int index_; 
};

#endif
