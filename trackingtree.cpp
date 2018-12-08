// trackingtree.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018
// Last modified: 12/8/2018
//
// CURRENT STATE
//      Crashes when adding node. This appears to occur *after* the add_node()
//      method is called, on update_node(). Working on that now.

#include "trackingtree.h"
#include <string>

using std::string;
using std::getline;
Trackingtree::Trackingtree() {
  index_ = 0;            
  number_of_nodes = 0;   //sets the number of node in the tree to 0
}

Trackingtree::~Trackingtree() {
   // Empty destructor 
}


void Trackingtree::add_node() {
    if (is_empty()) {
      cout << "Tree is empty, adding new..." << endl;
      Node new_node;
      tree.push_back(new_node);
    
      // Root node's PID is randomly generated from time data
      clock_t theClock = clock();
      time_t theTime = time(NULL);

      string timeStr = to_string(theTime);
      string clockStr = to_string(theClock);
      
      string random_PID = hash_1(timeStr,clockStr);
    
      //sets the PID of the root node with a random string
      new_node.updatePID(random_PID);
    
      // asks for new event to be inputted, then stores new event in the node 
      string raw_event;
      cout << "Please enter the event to be stored in the tracking tree (max 1024 characters)"
          << endl;
      cout << "Type here:  ";
      getline(cin,raw_event);
      new_node.setEVENT(raw_event); 

      index_++;
      number_of_nodes++;
      cout << "Base adding finished, update next..." << endl;
  
    } else {
      Node new_node; 
      tree.push_back(new_node);  
    
    
      //adds the PID to the new node 
      string PID = tree.at((index_/2)).getID();
      new_node.updatePID(PID);
    
      // asks for new event to be inputed then stores new event in the node 
      string raw_event;            
      getline(cin, raw_event);
      new_node.setEVENT(raw_event); 
    
      index_++;
      number_of_nodes++;
    }   
    update_node(index_);
}

void Trackingtree::update_node(int theIndex) {
    // This is never called directly by user --- add_node() calls it
	
    int index_in = theIndex - 1;
    //hashes the ID of the new node, and stores new ID 
	string newID = hash_1(tree.at(index_in).getPID(), tree.at(index_in).getEVENT());
	tree.at(index_in).updateID(newID);
    cout << "Updated ID." << endl;

	while (index_in > 1) {
		if (index_in % 2 == 0) {
			string update = hash_2(tree.at(index_in).getPID(), tree.at(index_in).getEVENT(),
				tree.at(index_in).getID(), tree.at(index_in).getLHASH(),
				tree.at(index_in).getRHASH());
			tree.at((index_in / 2)).updateLHASH(update);
		}
		else if (index_in % 2 == 1) {
			string update = hash_2(tree.at(index_in).getPID(), tree.at(index_in).getEVENT(),
				tree.at(index_in).getID(), tree.at(index_in).getLHASH(),
				tree.at(index_in).getRHASH());
			tree.at((index_in / 2)).updateRHASH(update);
		}
		update_node((index_in / 2));
	}
}

void Trackingtree::print_node(int index) {
    if (is_empty()) {
        cout << "The tree is empty. Add a node before printing." << endl << endl;
        return;
    }

	cout << "This is node " << index << ", with ID " << tree.at(index).getID() <<"." << endl;
    cout << "The raw event is as follows: " << endl;
    cout << tree.at(index).getEVENT() << endl;

    if (index > 1) {
        cout << "The parent is node " << index/2 << ", with ID " << tree.at(index/2).getID()<< "." << endl;
    }

    cout << endl;

}

void Trackingtree::print_tree() {
    if (is_empty()) {
        cout << "You can't print an empty tree." << endl << endl;
        return;
    }
    for (unsigned long int i = 0; i < number_of_nodes; i++) {
        print_node(i);
    }
}

void Trackingtree::change_raw_EVENT() {
    if (is_empty()) {
        cout << "Please add an event before changing it." << endl << endl;
        return;
    }

    unsigned long int index_CRE;
    cout<< "Which event do you want to change?" <<endl;
    cout << "There are currently " << number_of_nodes << " entries in the tracking tree." << endl;
    cout << "Enter an integer index : ";
    cin >> index_CRE;
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

void Trackingtree::beginning() {
  index_ = 1;
}

void Trackingtree::end() {
  index_ = number_of_nodes;
}

void Trackingtree::set_index(unsigned long int new_index) {
  index_ = new_index;
}


unsigned long int Trackingtree::position() {
  return index_;
}

unsigned long int Trackingtree::get_number_of_nodes() { 
  return number_of_nodes;
}

bool Trackingtree::is_empty(void) {
    return tree.empty();
}
