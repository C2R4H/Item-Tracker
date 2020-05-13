#include "database.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

database::database(){
  cout<<"DATABASE_H WORKING"<<endl;
}

void database::RefreshHash(){
  cout<<"DATABASE REFRESHASH"<<endl;
  ifstream read;
  read.open("./data/hash_data.txt");
  ofstream write;
  write.open("./data/hashid_data.txt");

  string hash;
  int id = 1;

  while(read>>hash){
    write<<id<<" "<<hash<<endl;
    id++;
  }

  read.close();
  write.close();
}

void database::ChangeCurrency(int currency){
  ifstream read;
  read.open("./data/hash_data.txt");
  ofstream write;
  write.open("./data/hashid_data.txt");

  string hash;
  int id = 1;

  string currency_write = "currency=";
  while(read>>hash){
    string word_temp;
    for(int i = 0;i<hash.size();i++){
      if(isalpha(hash[i]) || hash[i]=='='){
        word_temp.push_back(hash[i]);
        if(word_temp==currency_write){
          char c = '0' + currency;
          hash[i+1]= c;
          break;
        }
      }
      else
        word_temp.clear();
    }

    write<<id<<" "<<hash<<endl;
    id++;
  }




}









