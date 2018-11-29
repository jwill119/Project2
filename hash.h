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
//last it sjanges the hashs number in to a string 
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


#endif 
