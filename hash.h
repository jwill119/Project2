// hash.h
// COSC 2030 project 2
// Chase Austin and Jacob Williams
// Created: 11/28/2018
// Last modified: 11/28/2018
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
#include <climits> 

using std::INT_MAX;
using std::string;
using std::stringstream ;
using std::hex;

//hash take two or five input of tpye string 
//appends the strings togeght then hashs that new string 
//by taking the string and turning it in to a number set 
//then uses a function to hash the number set 
//last it changes the hash's number into a string 
string hash(string parent_ID , string raw_E);

string hash(string parent_ID, string raw_E,string ID,string L_hash, string R_hash);
 
#endif 
