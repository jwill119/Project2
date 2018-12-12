# Project 2: The tracking tree
// COSC 2030 project 2
// Chase Austin and Jacob Williams
// Created: 11/26/2018
// Last modified: 11/30/2018

## Project organization

We will have headers and cpp files for each of several options:

- hash.h/hash.cpp
    * These define the hash operations, different whether or not there are children
- node.h/node.cpp
    * These define the data structure making up the nodes of our tracking tree
- trackingtree.h/trackingtree.cpp
    * These define the operations on our tracking tree: construction, editing, etc.
    
- driver.cpp
    * The main file


#### Testing notes
Last updated: 12/8/2018, Jacob Williams

I am working on trackingtree.cpp, trying to get adding-nodes to work.
Currently it appears that new events are not properly stored in the tracking tree. Additionally,
the time does not hash into the random PID correctly.

UPDATE 12:11pm MDT --- The add\_node() function seems to work now.
Don't think update\_node() does, yet; neither does print\_node().

- At the least, updating the node's ID does *not* work.

UPDATE 12:32pm --- getID() and related functions do not work.


UPDATE 12/12: It seems some of the confusion was update/version related, or maybe compiler-related?? Anyway we have worked everything out, albeit mostly offline.
