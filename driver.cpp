// driver.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018

#include "hash.h"
#include "node.h"
#include "trackingtree.h"


int main() {
  cout << "Welcome to the tracking tree!" << endl;
  cout << "This custom data structure stores an entry (up to 1024 characters)"
      << endl << "and tracks all changes to the structure." << endl;
  cout << "For all your sensitive information needs!" << endl << endl;
  string command;
  Trackingtree our_tree;
  cout << "Enter a command: ";
  cin >> command;
  while(command != "exit") 
  {
      if (command == "add") 
      {
        our_tree.add_node();        
      }else if(command == "print")
      {
		  our_tree.print_tree();

      }else if (command == "change_event")
      {
        our_tree.change_raw_EVENT(); 

      }else if(command == "print_node")
      {
        
		 unsigned long int node_at;
        cin >> node_at;
        if(node_at <= our_tree.get_number_of_nodes() && node_at >= 0)
        {
           our_tree.print_node(node_at);
        }else
        { 
           cout<<"invalid Input for the index"<<endl;
           cout<<"index between 0 and " <<our_tree.get_number_of_nodes()<< endl;
        }       
      }else if (command == "exit")       
      {
          exit(0);
      } else 
      {
          cout << endl;
          cout << "Known commands: " << endl;
          cout << "add <event> (Adds a node's event); " << endl;
          cout << "exit (Exits the program)" << endl;
          cout << "print (prints out the tree)"<<endl;
          cout << "change_event (changes a node's event); " << endl;
          cout << "print_node <index> (prints out the node at index) index between 1 and " <<our_tree.get_number_of_nodes()<< endl;
          cout << endl;
      }
    
  cout << "Enter a command: ";
  cin >> command;
  }
return 0;
}
