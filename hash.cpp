// hash.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018
// Last modified: 12/4/2018

// Hash function definitions.

#include "hash.h"


string hash_1(string parent_ID , string raw_E) 
{ 
  string output;
  unsigned long int hash_number = 0;
  
  // Concatenate the inputs
  string to_hash_1;
  to_hash_1 += parent_ID;
  to_hash_1 += raw_E;
  // Generate the hash number
  for (int index =0; index < to_hash_1.length(); index++)
  {
	  hash_number = 13 * hash_number + to_hash_1[index];
  }  

 

  // The maximum number of 8-character hex strings
  hash_number %= (UINT_MAX-1);

  // Convert hexadecimal representation of the hash number to a string 
  stringstream thing;
  thing << hex << hash_number;
  output = thing.str();
  return output;
}

string hash_2(string parent_ID, string raw_E,string ID,string L_hash, string R_hash) 
{
  unsigned long int hash_number = 0;
  string output,to_hash;
  string to_hash_2;   
  to_hash_2 += parent_ID;
  to_hash_2 += raw_E;
  to_hash_2 += ID;
  to_hash_2 += L_hash;
  to_hash_2 += R_hash;
  // Generate the hash number
  for (int index =0; index < to_hash_2.length(); index++)
  {
	  hash_number = 13 * hash_number + to_hash_2[index];
  } 

  // The maximum number of 8-hex-character strings possible 
  hash_number %= (UINT_MAX-1);

  // Convert hexadecimal representation of the hash number to a string
  stringstream thing;
  thing << hex << hash_number;
  output = thing.str();
  return output; 
}
