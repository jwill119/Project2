// node.h
// COSC 2030 project 02
// Chase Austin, Jacob Williams
// Created 11/28/2018
// Last modified: 11/28/2018
//
// Defines the data structure we use for the nodes of our tracking tree.
// Each node contains:
//      ID (8-character string, a hash)
//      PID (8-character string for parent's ID, a hash)
//      EVENT (up-to-1024-character raw event string)
//      LHASH (8-character string hash of left child's contents)
//      RHASH (8-character string hash of right child's contents)
//      LHIST (vector of 8-character strings of the LHASH history)
//      RHIST (vector of 8-character strings of the RHASH history)
//
// In the root node, all values are initialized to NULL,
//      except for the PID, which is random.
//      (For child nodes, the PID is copied from the parent.)
// Raw event is inputted by the user.
// ID is a hash of the raw event and the parent ID. 
//      Returns: an 8-character string.
// RHASH: is a hash of the right child's ID, PID, EVENT, RHASH, and LHASH.
//      Returns: an 8-character string.
//      NULL items (say child LHASH and RHASH) should not affect the hash.
// LHASH: is a hash of the left child's ID, PID, EVENT, RHASH, and LHASH.
//      Returns: an 8-character string.
//      NULL items (say child LHASH and RHASH) do not affect this either.
// LHIST is a vector of all the previous LHASHes. When a change is made to the
//      child, the parent's LHASH is overwritten and the new LHASH is appended
//      to LHIST.
// RHIST is the same as LHIST, but for the right child.
//
// The hashes are implemented in the hash-files.

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
using namespace std;


class Node {
    public:
        Node();
        ~Node();

        void setEVENT(string);
        
        void updateID(string);
        void updatePID(string);
        void updateLHASH(string);
        void updateRHASH(string);
        void updateLHIST(string);
        void updateRHIST(string);

        string getID(void);
        string getPID(void);
        string getEVENT(void);
        string getLHASH(void);
        string getRHASH(void);
        string getLHIST(void);
        string getRHIST(void);

    private:
        string ID;
        string PID;
        string EVENT;
        string LHASH;
        string RHASH;
        string LHIST;
        string RHIST;

};
#endif
