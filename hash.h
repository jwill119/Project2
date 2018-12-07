// hash.h
// COSC 2030 project 2
// Chase Austin and Jacob Williams
// Created: 11/28/2018
// Last modified: 12/4/2018
//
// The header file for the hash function.
// Hash function takes two or five strings and hashes them into eight
// hexadecimal characters.
//
// The hash was modified from:
//      https://stackoverflow.com/questions/8567238/hash-function-in-c-for-string-to-int?rq=1


#ifndef HASH_H
#define HASH_H

#include <string>       
#include <iostream>     
#include <sstream>
#include <climits>
//using std::INT_MAX;
using std::string;
using std::stringstream;
using std::hex;
using std::to_string;

// Two functions that take inputs of type string.
//  One takes two strings (to hash PARENT_ID and RAW_EVENT); 
//  the other takes five (PID, EVENT, ID, LHASH, and RHASH).
// First, the strings are concatenated;
// second, they are converted to a number;
// the number is converted into hexadecimal,
// which is then returned to string form (and truncated to 8 characters).
string hash_1(string parent_ID , string raw_E);
string hash_2(string parent_ID, string raw_E, string ID, string L_hash, string R_hash);
 
#endif 
