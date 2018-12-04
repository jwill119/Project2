// trackingtree.h
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/28/2018
// Last modified: 12/4/2018

#ifndef TRACKINGTREE_h_
#define TRACKINGTREE_h_


#include "hash.h"
#include "node.h"

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
      
      //adds a new nodes to the tree and if needed adds a new level 
      void add_node();
      
      //update_node set the ID of the node at the input index using the hasd function 
      
      //??C.A. may just update all elements in the node,so we  can just call update_node in the 
      //update_tree so that we just make one function that updates but has checks
      //so it knows if the node it is updateing is new or not??
      
      void update_node(int index);
      
      //update_tree set the node's parnet's RHASH or LHASH and pushs the last RHASH or LHASH 
      //on to the either the RHIST or LHIST
      //then flow up 
      
      //void update_tree();
      
      //prints the all the node's elements
      //??C.A. didn't know if we want to print by the ID of the Node too?? 
      
      void print_node(int index);        
     
      //Void print_node(string ID);
      
       //prints the all nodes in the tree 
       
       //??C.A. was thinking of doing this by level.
      void print_tree(void);
      
      //changes the rew_enent in the specified node
      void change_raw_EVENT(unsigned long int index);
 
      //??C.A. thought it would be a good idea to have a index value 
      // not going to put in yet 
      //resets the index to 1 
      void beginning(void);
 
      //sets the index to the end 
      //(last node that has a raw EVENT)
      void end(void);
 
      //sets the index to the given number 
      void set_index(unsigned long int new_index);
 
      //returns the value of the index 
      unsigned long int position(void); 

  private:
      // Vector of Nodes (primary data member)
      vector<Node> tree;

      //Total number of nodes in the tree 
      unsigned long int number_of_nodes;
      
      //Current position in the tree 
      unsigned long int index; 
};

#endif
