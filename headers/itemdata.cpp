#include "itemdata.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string itemdata::UrlDecrypter(string hash){
  bool iscase = true;
  string url = hash;

  string url20 = "%20";
  string url28 = "%28";
  string url29 = "%29";
  string url7C = "%7C";
  string urlE284 = "%E2";

  string word_temp;
  int i_temp = 0;
  for(int i = 0;i<url.size();i++){
    if(url[i]=='=')
      i_temp = i;
    else if(url[i]=='%'){
      for(int j = i;j<i+3;j++)
        word_temp.push_back(url[j]);

      if(word_temp==url20 || word_temp==url29){
        for(int j = i;j<=i+2;j++){
          if(j!=i+2)
            url[j]='\0';
          else
            url[j]=' ';
        }i+=2;
      }

      else if(word_temp==url28){
        iscase = false;
        for(int j = i;j<=i+2;j++){
          if(j!=i+2)
            url[j]='\0';
          else 
            url[j]='>';
        }i+=2;
      }

      else if(word_temp==url7C){
        for(int j = i;j<=i+2;j++){
          if(j!=i+2)
            url[j]='\0';
          else
            url[j]='|';
        }i+=2;
      }

      else if(word_temp==urlE284){
        for(int j = i;j<=i+8;j++){
          if(j!=i+8)
            url[j]='\0';
          else 
            url[j]=' ';
        }i+=8;
      }

      word_temp.clear();
    }
  }

  string url_t;
  for(int i = 0;i<url.size();i++)
    if(url[i]!='\0')
      url_t.push_back(url[i]);
  if(iscase==true){
    url_t.clear();
    for(int i = 0;i<url.size();i++){
      if(i==i_temp){
        url_t.push_back('<');
        i++;
      }
      if(url[i]!='\0')
        url_t.push_back(url[i]);
    }
  }
  return url_t;
}

void itemdata::itemdatastart(){
  ifstream read;
  read.open("./data/hashid_data.txt");
  ofstream write;
  write.open("./data/static_data.txt");
  vector<int> id_s;
  vector<string> hash_s;
  int id_read;
  string hash_read;
  while(read>>id_read>>hash_read){
    id_s.push_back(id_read);
    hash_s.push_back(hash_read);
  }

  string currency_t = "currency=";
  string mhn_t = "market_hash_name";
  string stattrak_t = "StatTrak";
  
  itemdata market;
  for(int i = 0;i<id_s.size();i++){
    string url = market.UrlDecrypter(hash_s[i]);

    bool GetCurrency = false;
    bool GetMarketHash = false;
    bool GetStatTrak = false;
    bool GetName = false;
    bool GetQuality = false;

    int currency;
    string name;
    string quality = "NONE";
    bool stattrak = false;
    bool getcase = false;

    string word_temp;
    for(int j = 0;j<url.size();j++){
      if(GetCurrency==false&&url[j]=='c'&&url[j+1]=='u'){
        for(int l = j;l<j+currency_t.size();l++)
          word_temp.push_back(url[l]);
        if(word_temp==currency_t){
          currency = url[j+currency_t.size()]-'0';
          j+=currency_t.size();
          GetCurrency = true;
          word_temp.clear();
        }
      }

      if(GetMarketHash == false && GetCurrency == true){
        for(int l = j;l<j+mhn_t.size();l++)
          word_temp.push_back(url[l]);
        if(word_temp == mhn_t){
          j+=mhn_t.size()+1;
          GetMarketHash = true;
          word_temp.clear();
          if(url[j-1]=='<')
            getcase = true;
          else if(url[j]!='S' && url[j+1]!='t'){
            GetStatTrak = true;
            j++;
          }
        }
      }

      if(GetStatTrak == false && GetMarketHash == true && getcase == false){
        for(int l = j-1;l<j+stattrak_t.size()-1;l++)
          word_temp.push_back(url[l]);
        if(word_temp==stattrak_t){
          stattrak = true;
          GetStatTrak = true;
          j=j+stattrak_t.size();
          word_temp.clear();
        }
      }

      else if(GetName == false && GetMarketHash == true){
        if(getcase==true){
          for(int l = j;l<url.size();l++)
            word_temp.push_back(url[l]);
          name = word_temp;
          GetName = true;
          word_temp.clear();
        }
        else if(getcase==false){
          int l = j-1;
          while(url[l]!='>'){
            word_temp.push_back(url[l]);
            l++;
          }
          if(word_temp[0]==' ')
            word_temp.erase(0,1);
          name = word_temp;
          GetName = true;
          word_temp.clear();
        }
      }

      if(GetQuality == false && GetName == true && getcase == false){
        if(url[j]=='>'){
          for(int l = j+1;l<url.size();l++)
            word_temp.push_back(url[l]);
          if(word_temp[0]==' ')
            word_temp.erase(0,1);
          quality = word_temp;
          GetQuality = true;
        }
      }
      word_temp.clear();
    }
    /*
    cout<<"Id:"<<id_s[i]<<endl;
    cout<<" 1.Currency:"<<currency<<endl;
    cout<<" 2.StatTrak:"<<stattrak<<endl;
    cout<<" 3.Name:"<<name<<endl;
    cout<<" 4.Quality:"<<quality<<endl;
    */

    write<<"Id:"<<id_s[i]<<endl;
    write<<" 1.Currency:"<<currency<<endl;
    write<<" 2.StatTrak:"<<stattrak<<endl;
    write<<" 3.Name:"<<name<<endl;
    write<<" 4.Quality:"<<quality<<endl;
  }
}
