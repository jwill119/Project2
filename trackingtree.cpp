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
  index = 0;            //sets index to 1 
  number_of_nodes = 0;   //sets the number of node in the tree to 0
  //!!This, make the driver harder then it need to be  
  //add_node();           //call the function add_node to add the root node ofthe tree
  
}

trackingtree::~trackingtree()
{
   // Empty destructor 
}


void trackingtree::add_node() {
  if(tree.empty()) {
    Node new_node;

    // Root node's PID is randomly generated from time data
    clock_t theClock = clock();
    time_t theTime = time();

    string timeStr = time.str();
    string clockStr = clock.str(); 

    string random_PID = hash(timeStr,clockStr);

    //sets the PID of the root node with a random string
    new_node.updatePID(random_PID)
    
      
    // asks for new event to be inputted, then stores new event in the node 
    string  raw_event;            
    cout << "Enter raw event (maximum 1024 characters): ";
    cin >> raw_event;
    new_node.setEVENT(raw_event); 
    
    tree.push_back(new_node);
    index = 1;
    number_of_nodes = 1;
  } else {
    Node new_node;//set new_node as a node 
    
    //adds the PID to the new node 
    string PID = tree.at((index/2)).getID;
    new_node.updatePID(PID)
      
    // asks for new event to be inputed then stores new event in the node 
    string  raw_event;            
    cout << "Enter raw event : ";
    cin >> raw_event;
    new_node.setEVENT(raw_event); 
        
    tree.push_back(new_node);  
    index++;
    number_of_nodes++;
  }   
 update_node(index);
}

void trackingtree::update_node(int index_in);
{
   //hashes the ID of the new node, and stores new ID 
    string newID = hash(tree.at(index_in).getPID(),tree.at(index_in).getEVENT());
    tree.at(index_in).updateID(newID);

    if (number_of_node > 1) {
        if(index_in%2 == 0) {
            string update = hash(tree.at(index_in).getPID(), tree.at(index_in).getEVENT(),
                           tree.at(index_in).getID(), tree.at(index_in)getLHASH(), 
                           tree.at(index_in)getRHASH());      
            tree.at((index_in/2)).updateLHASH(update)
        } else if(index_in%2 == 1) {
            string update = hash(tree.at(index_in).getPID(), tree.at(index_in).getEVENT(),
                           tree.at(index_in).getID(), tree.at(index_in)getLHASH(), 
                           tree.at(index_in)getRHASH());      
            tree.at((index_in/2)).updateRHASH(update);
        } 
  update_node((index_in/2))
}

void trackingtree::print_node(int index) {
    cout << "This is node " << index << ", with ID " << tree.at(index).getID() "." << endl;
    cout << "The raw event is as follows: " << endl;
    cout << tree.at(index).getEVENT() << endl;
    if (index > 1) {
        cout << "The parent is node " << index/2 << ", with ID " << tree.at(index/2).getID() "." << endl;
    }
    cout << endl;

}

void trackingtree::print_tree() {
    for (int i = 0; i < number_of_nodes; i++) {
        print_node(i);
    }
}

void trackingtree::change_raw_EVENT(unsigned long int index) {   
  unsigned long int index_CRE;
  cout<< "Which event do you want to change?" <<endl;
  cout << "There are currently " << number_of_nodes << " entries in the tracking tree." << endl;
  cout << "Enter an integer index : ";
  cin>>index_CRE;
  cout << endl;

  cout << "The current node: " << endl;
  print_node(index_CRE);
  cout << endl;
  
  cout << "Enter changes to the node's event: " << endl;
  string event;
  cin >> event;
  tree.at(index_CRE).setEVENT(event);
  
  update_node(index_CRE);

  cout << "Tracking tree updated." << endl << endl;
}

void trackingtree::beginning() {
  index = 1;
}

void trackingtree::end() {
  index = number_of_nodes;
}

void trackingtree::set_index(unsigned long int new_index) {
  index = new_index;
}

unsigned long int trackingtree::position() {
  return index;
}
unsigned long int trackingtree::get_number_of_nodes()
{ 
  return number_of_nodes;
}
