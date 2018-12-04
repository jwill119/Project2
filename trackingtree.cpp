// trackingtree.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018

#include <ctime>
#include <cstlib>
#include "trackingtree.h"
#include "hash.h"
#include "node.h"

trackingtree::trackingtree()
{
  index = 1;            //sets index to 1 
  number_of_levels =1;  //sets the numbers of level in the tree to 1  
  number_of_nodes =0;   //sets the number of node in the tree to 0
  add_node();           //call the function add_node to add the root node ofthe tree
}

trackingtree::~trackingtree()
{
   // Empty destructor 
}


void trackingtree::add_node()
{
  if(tree.empty()) {
    node new_node;//set new_node as a node 

    // Root node's PID is randomly generated from time data
    clock_t theClock = clock();
    time_t theTime = time();

    string timeStr = time.str();
    string clockStr = clock.str(); 

    string random_PID = hash(timeStr,clockStr);

    //sets the PID of the root node with a random string !!C.A. didn't add random string gen yet!!
    new_node.updatePID(random_PID)
    
      
    // asks for new event to be inputed then stores new event in the node 
    string  raw_event;            
    cout << "Enter raw event : ";
    cin >> raw_event;
    new_node.setEVENT(raw_event); 
    
    tree.push_back(new_node);
    number_of_nodes =1;
  }else 
  {
    node new_node = new node;//set new_node as a node 
    
    //adds the PID to the new node 
    string PID = tree.at((index/2)).getID;
    new_node.updatePID(PID)
      
    // asks for new event to be inputed then stores new event in the node 
    string  raw_event;            
    cout << "Enter raw event : ";
    cin >> raw_event;
    new_node.setEVENT(raw_event); 
        
    tree.push_back(new_node);  
    
    number_of_nodes += 1;
  }   
  update_tree();  
}

void trackingtree::update_node(int index);
{
   //hashs the ID of the new node, and stores new ID 
    string ID = hash(new_node.getPID(), new_node.getEVENT());
    new_node.setID(ID);
}

//void trackingtree::update_tree()
//{

//}

void trackingtree::print_node(int index)
{

}

void trackingtree::print_tree()
{

}

void trackingtree::change_raw_EVENT(unsigned long int index)
{   
  unsigned long int index_CRE;
  cout<<"Which event do you want to change? Enter an integer index."<<endl;
  cout<<"Number of node is :"<<number_of_nodes<<endl;
  cin>>index_CRE;
  
  print_node(index_CRE);  //calls print_node 
  
  cout<<"Enter changes to the node's event";
  string event;
  cin>>event;
  tree.at(index_CRE).setEVENT(event);
  
  update_node(index_CRE);
  update_tree();  
}

void trackingtree::begining()
{
  index = 1;
}

void trackingtree::end()
{
  index = number_of_nodes;
}

void trackingtree::set_index(unsigned long int new_index)
{
  index = new_index;
}

unsigned long int trackingtree::position()
{
  return index;
}
