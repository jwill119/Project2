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

  cout << "Enter a command: ";
  cin >> command;
  while(command != "exit") {
      if (command == "add") {
      } else if (command == "exit") {
          exit(0);
      } else {
          cout << "Known commands: " << endl;
          cout << "add (Adds a node); " << endl;
          cout << "exit (Exits the program)" << endl;
          cout << endl;
      }
    
  cout << "Enter a command: ";
  cin >> command;
  }



return 0;
}
