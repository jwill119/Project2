// trackingtree.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018

#include "trackingtree.h"
#include <string>

using std::string;
using std::getline;
Trackingtree::Trackingtree()
{
  index_ = 0;             //sets index to 1 
  number_of_nodes = 0;   //sets the number of node in the tree to 0
  
  //!!This, make the driver harder then it needs to be  
  //add_node();          //call the function add_node to add the root node ofthe tree
  
}

Trackingtree::~Trackingtree()
{
   // Empty destructor 
}


void Trackingtree::add_node() 
{
  if(tree.empty())
  {
    Node new_node;	
    // Root node's PID is randomly generated from time data
    clock_t theClock = clock();
    time_t theTime = time(NULL);

    string timeStr = to_string(theTime);
    string clockStr = to_string(theClock);

    string random_PID = hash_1(timeStr,clockStr);

    //sets the PID of the root node with a random string
	new_node.updatePID(random_PID);
    
      
    // asks for new event to be inputted, then stores new event in the node 
    string  raw_event, line;
    //cout << "Enter raw event (maximum 1024 characters): "<<endl;
	getline(cin, raw_event);
    
    new_node.setEVENT(raw_event); 
	new_node.updateID(hash_1(raw_event, random_PID));
    tree.push_back(new_node);    
    number_of_nodes++;
  } else
  {
    Node new_node;//set new_node as a node 
    
    //adds the PID to the new node 
    string PID = tree.at((index_/2)).getID();
	new_node.updatePID(PID);
      
    // asks for new event to be inputed then stores new event in the node 
    string raw_event;            
    //cout << "Enter raw event : "<<endl;
	getline(cin, raw_event);
    new_node.setEVENT(raw_event);         
    tree.push_back(new_node);  
    index_++;
    number_of_nodes++;
  }   
 update_node(index_);
}

void Trackingtree::update_node(int index_in)
{
	
	//hashes the ID of the new node, and stores new ID 
	string newID = hash_1(tree.at(index_in).getPID(), tree.at(index_in).getEVENT());
	tree.at(index_in).updateID(newID);

	
	if (index_in > 1)
	{
		if (index_in % 2 == 0 && index_in != (number_of_nodes-1))
		{
			string update = hash_2(tree.at(index_in).getPID(), tree.at(index_in).getEVENT(),
				tree.at(index_in).getID(), tree.at(index_in).getLHASH(),
				tree.at(index_in).getRHASH());
			tree.at((index_in / 2)).updateLHASH(update);
		}
		if (index_in % 2 == 1 && index_in != number_of_nodes )
		{
			string update = hash_2(tree.at(index_in).getPID(), tree.at(index_in).getEVENT(),
				tree.at(index_in).getID(), tree.at(index_in).getLHASH(),
				tree.at(index_in).getRHASH());
			tree.at((index_in / 2)).updateRHASH(update);
		}
	}

	if (index_in > 0)
	{
		update_node((index_in / 2));
	}
	
}

void Trackingtree::print_node(int index)
{
	index;	
	cout << "This is node " << index << ", with ID " << tree.at(index).getID() <<"." << endl;
    cout << "The raw event is as follows: " << endl;
    cout << tree.at(index).getEVENT() << endl << endl;
	if (tree.at(index).getLHASH() != "")
	{
		cout << "The LHASH is as follows: " << endl;
		cout << tree.at(index).getLHASH() << endl << endl;
	}
	if (tree.at(index).getRHASH() != "")
	{
		cout << "The RHASH is as follows: " << endl;
		cout << tree.at(index).getRHASH() << endl << endl;
	}
	if (tree.at(index).getLHIST() != "")
	{
		cout << "The LHIST is as follows: " << endl;
		cout << tree.at(index).getLHIST() << endl << endl;
	}
	if (tree.at(index).getRHIST() != "")
	{
		cout << "The RHASH is as follows: " << endl;
		cout << tree.at(index).getRHIST() << endl << endl;
	}
	
    if (index > 1) 
	{
        cout << "The parent is node " << index/2 << ", with ID " << tree.at(index/2).getID()<< "." << endl << endl;
    }
    cout << endl;

}

void Trackingtree::print_tree()
{
    for (unsigned long int i = 0; i < number_of_nodes; i++)
	{
        print_node(i);
    }
}

void Trackingtree::change_raw_EVENT()
{
  unsigned long int index_CRE;
  cout<< "Which event do you want to change?" <<endl;
  cout << "There are currently " << number_of_nodes << " entries in the tracking tree." << endl;
  cout << "Enter an integer index followed by the changes : ";
  cin>>index_CRE;
  cout << endl;

  cout << "The node that before it was changed: " << endl;
  print_node(index_CRE);
  cout << endl;  
  string event;   
  getline(cin, event);
  
  tree.at(index_CRE).setEVENT(event);
  
  update_node(index_CRE); 
  cout << "The node that after it was changed: " << endl;
  print_node(index_CRE);

  cout << "Tracking tree updated." << endl << endl;
}

void Trackingtree::beginning()
{
  index_ = 1;
}

void Trackingtree::end() {
  index_ = number_of_nodes;
}

void Trackingtree::set_index(unsigned long int new_index) 
{
  index_ = new_index;
}

unsigned long int Trackingtree::position()
{
  return index_;
}

unsigned long int Trackingtree::get_number_of_nodes()
{ 
  return number_of_nodes;
}
