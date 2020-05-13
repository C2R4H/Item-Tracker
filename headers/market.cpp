#include "market.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cctype>
#include <string>
#include <fstream>
#include <cstring>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
using namespace std;

static size_t WriteCallback(void *contents, size_t size,size_t nmemb,void *userp){
  ((string*)userp)->append((char*)contents, size * nmemb);
  return size* nmemb;
}

market::market(){
  cout<<"WORKING MARKET_H"<<endl;
  vector<int> id_s;
  vector<string> hash_s;
  string hash_read;
  int id_read;
  ifstream read;
  read.open("./data/hashid_data.txt");

  while(read>>id_read>>hash_read){
    id_s.push_back(id_read);
    hash_s.push_back(hash_read);
  }read.close();

  time_t now;
  struct tm nowLocal;
  now=time(NULL);
  nowLocal=*localtime(&now);

  ofstream write;
  write.open("./data/live_data.txt");
  ofstream track_write;
  track_write.open("./data/track_data.txt",ios_base::app);
  for(int i = 0;i<id_s.size();i++){
    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    const char* url = hash_s[i].c_str();
    if(curl){
      curl_easy_setopt(curl,CURLOPT_URL,url);
      curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
      curl_easy_setopt(curl,CURLOPT_WRITEDATA,&readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }
    Json::Reader reader;
    Json::Value obj;
    reader.parse(readBuffer,obj);

    string lowest = obj["lowest_price"].asString();
    string lowest_price;
    for(int i = 0;i<lowest.size();i++)
      if(isdigit(lowest[i]) || lowest[i]=='.' || lowest[i]==',')
        lowest_price.push_back(lowest[i]);
    string median = obj["median_price"].asString();
    string median_price;
    for(int i = 0;i<median.size();i++)
      if(isdigit(median[i]) || median[i]=='.' || median[i]==',')
        median_price.push_back(median[i]);

    write<<"Id:"<<id_s[i]<<endl;
    write<<" 1.Lowest_Price:"<<lowest_price<<endl;
    write<<" 2.Median_Price:"<<median_price<<endl;
    write<<" 3.Quantity:"<<obj["volume"].asString()<<endl;

    track_write<<id_s[i]<<" ";
    track_write<<nowLocal.tm_year+1900<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_mday<<" ";
    track_write<<nowLocal.tm_hour<<"/"<<nowLocal.tm_min<<"/"<<nowLocal.tm_sec<<" ";
    track_write<<lowest_price<<" ";
    track_write<<median_price<<" ";
    track_write<<obj["volume"].asString()<<endl;
  }
  write.close();
}

