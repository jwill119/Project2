// node.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/28/2018
// Last updated: 11/28/2018
//
// Function definitions for node class.

#include "node.h"

// The constructor
Node::Node() {
    ID = "";
    PID = "";
    EVENT = "";
    LHASH = "";
    RHASH = "";
    LHIST.resize(0);
    RHIST.resize(0);

    cout << "Node created." << endl << endl;
}

// Empty destructor
Node::~Node() {
}

// Mutator functions
//  Generation of what the fields are actually supposed to be
//  is done in the tree class file. This just pushes the values
//  into the node.
void Node::setEVENT(string theEvent) 
{
    if (theEvent.length() > 1024) theEvent.resize(1024);
    EVENT = theEvent;
}

void Node::updateID(string theID) {
    if (theID.length() > 8) theID.resize(8);
    ID = theID;
}

void Node::updatePID(string thePID) {
    if (thePID.length() > 8) thePID.resize(8);
    PID = thePID;
}

void Node::updateLHASH(string theLHASH) {
    if (theLHASH.length() > 8) theLHASH.resize(8);
    LHASH = theLHASH;
    updateLHIST(theLHASH);
}

void Node::updateRHASH(string theRHASH) {
    if (theRHASH.length() > 8) theRHASH.resize(8);
    RHASH = theRHASH;
    updateRHIST(theRHASH);
}

void Node::updateLHIST(string theLHIST) {
    LHIST.push_back(theLHIST);
}

void Node::updateRHIST(string theRHIST) {
    RHIST.push_back(theRHIST);
}

// Accessor functions
string Node::getID(void)
{
    return ID;
}

string Node::getPID(void)
{
    return PID;
}

string Node::getEVENT(void)
{
    return EVENT;
}

string Node::getLHASH(void)
{
    return LHASH;
}

string Node::getRHASH(void) 
{
    return RHASH;
}

vector<string> Node::getLHIST(void)
{
    return LHIST;
}

vector<string> Node::getRHIST(void) 
{
    return RHIST;
}
