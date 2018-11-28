

#ifndef HASH_H
#define HASH_H


#include <string>
#include <climits> 
using std::INT_MAX;
using std::string;
usind std::stringstream ;
usind std::hex;

//hash take two or five input of tpye string 
//appends the strings togeght then hashs that new string 
//by taking the string and turning it in to a number set 
//then uses a function to hash the number set 
//last it sjanges the hashs number in to a string 
//hash was modeify https://stackoverflow.com/questions/8567238/hash-function-in-c-for-string-to-int?rq=1
string hash(string parent_ID , string raw_E)
{ 
  unsigned int hash_number;
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
  hash_number %= (UINT_MAX-1); // 
  stringstream thing <<hex <<hash_number;
  output = thing.str();
  
  
  return output ;
}


#endif 
