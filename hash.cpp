// hash.cpp
// COSC 2030 project 2
// Chase Austin, Jacob Williams
// Created: 11/29/2018

#include "hash.h"

string hash(string parent_ID , string raw_E)
{ 
  unsigned long int hash_number;// i thought it may overflow in the for loop CA
  string output,to_hash;
  to_hash = parent_ID + raw_E;
  
  for (int index =0; index <to_hash.length(); index++)
  {
    hash_number = 13*hash_number + to_hash[index]
  }  
  hash_number %= (UINT_MAX-1); // 
  stringstream thing <<hex <<hash_number;
  output = thing.str();
  return output ;
}
string hash(string parent_ID, string raw_E,string ID,string L_hash, string R_hash)
{
  int hash_number;
  string output,to_hash;
  to_hash = parent_ID + raw_E + ID + L_hash +R_hash;
  
  for (int index =0; index <to_hash.length(); index++)
  {
    hash_number = 13*hash_number + to_hash[index]
  } 

 // The maximum number of 8-hex-character strings possible 
  hash_number %= (UINT_MAX-1);
  stringstream streamHex << hex <<hash_number;
  output = streamHex.str();
  
  
  return output;
}
