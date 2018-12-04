// trackingtree.h
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/28/2018


 


#ifndef TRACKINGTREE_h_
#define TRACKINGTREE_h_


#include "hash.h"
#include "node.h"

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
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
      Void print_node(int index);        
      //Void print_node(string ID);
      
       //prints the all nodes in the tree 
       
       //??C.A. was thinking of doing this by level.
      Void print_tree();
      
      //changes the rew_enent in the input node?? 
      
      //??C.A. maybe we should ask witch node in the function,rather than input wicth node??
      void change_raw_EVENT();
      
 
      //??C.A. thought it would be a good idea to have a index value 
      // not going to put in yet 
      //resets the index to 1 
      void begining();
 
      //sets the index to the end 
      //(last node that as a raw EVENT)
      void end();
 
      //sets the index to the inputed number 
      void set_index(unsigned long int new_index);
 
      //return the value of the index 
      unsigned long int position(); 
  private:
  
      //stores the number of (live) nodes in the tree 
      //nodes that have a Raw event, ID, and PID.
      unsigned long int number_of_nodes;
      
      //stores the number of levels in the tree 
      
      //??C.A. this may not be needed, I thought it could help, so that we dont need to calcuate it
      //??where we need it 
      int number_of_levels;
      
      //the main part of the Tracking tree where all of 
      //the nodes are stored 
      vector<node> tree;
      
      //current position in the tree 
      unsigned long int index; 
};

#endif
