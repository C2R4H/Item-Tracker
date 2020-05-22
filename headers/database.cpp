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

void database::AddItemByUrl(string url){
  string json = "https://steamcommunity.com/market/priceoverview/?appid=730&currency=1&market_hash_name=";
  string last_half;

  string word_temp;
  bool pass = false;
  for(int i = 0;i<url.size();i++){
    if(isdigit(url[i]) && url[i+1]=='/' && url[i]=='0'){
      pass = true;
      i+=2;
    }
    if(pass==true)
      word_temp.push_back(url[i]);
  }
  json.append(word_temp);
  
  ofstream write;
  write.open("./data/hash_data.txt",ios_base::app);
  write<<json<<endl;
  write.close();
}








