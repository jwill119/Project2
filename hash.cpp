// hash.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018
// Last modified: 12/4/2018

// Hash function definitions.

#include "hash.h"

string hash(string parent_ID , string raw_E) { 
  string output;
  unsigned long int hash_number = 0;
  
  // Concatenate the inputs
  string to_hash = parent_ID + raw_E;
  
  // Generate the hash number
  for (int index =0; index <to_hash.length(); index++) {
    hash_number = 13*hash_number + to_hash[index]
  }  

  // The maximum number of 8-character hex strings
  hash_number %= (UINT_MAX-1);

  // Convert hexadecimal representation of the hash number to a string
  stringstream thing <<hex <<hash_number;
  output = thing.str();
  return output;
}

string hash(string parent_ID, string raw_E,string ID,string L_hash, string R_hash) {
  unsigned long int hash_number = 0;
  string output,to_hash;
  string to_hash = parent_ID + raw_E + ID + L_hash +R_hash;
  
  // Generate the hash number
  for (int index =0; index <to_hash.length(); index++) {
    hash_number = 13*hash_number + to_hash[index]
  } 

  // The maximum number of 8-hex-character strings possible 
  hash_number %= (UINT_MAX-1);

  // Convert hexadecimal representation of the hash number to a string
  stringstream streamHex << hex <<hash_number;
  output = streamHex.str();
  
  return output;
}
