#include "itemtrack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

itemtrack::itemtrack(){
  cout<<"ITEMTRACK_H"<<endl;
}


void itemtrack::ShowItemHistory(int id){
  ifstream read;
  read.open("./data/track_data.txt");

  int id_temp;
  string year_temp;
  string hour_temp;
  string lowest_temp;
  string median_temp;
  string quantity_temp;

  while(read>>id_temp>>year_temp>>hour_temp>>lowest_temp>>median_temp>>quantity_temp){
    if(id_temp==id){
      //If you want to save all of this you will need to change from string to double
      cout<<year_temp<<" "<<hour_temp<<" "<<lowest_temp<<" "<<median_temp<<" "<<quantity_temp<<endl;
    }
  }


  /*string id_write = "Id:";
  string year_write = " 1.";
  string hour_write = " 2.";
  string lowest_write = " 3.";
  string median_write = " 4.";
  string quantity_write = " 5.";

  string staticline;
  while(getline(read, staticline)){

    string word_temp;
    for(int i = 0;i<staticline.size();i++){
      word_temp.push_back(staticline[i]);

      if(word_temp==id_write){
        id_temp = staticline[i+1]-'0';
        word_temp.clear();
      }
      if(word_temp==year_write){
      string time_loop;
      for(int l = i+1;l<staticline.size();l++)
        time_loop.push_back(staticline[l]);
      year = time_loop;
      }

      else if(word_temp==hour_write){
      string time_loop;
      for(int l = i+1;l<staticline.size();l++)
        time_loop.push_back(staticline[l]);
      hour = time_loop;
      }

      else if(word_temp==lowest_write){
      string price_loop;
      for(int l = i+1;l<staticline.size();l++)
        price_loop.push_back(staticline[l]);
      lowest_temp = stod(price_loop.c_str());
      }

      else if(word_temp==median_write){
      string price_loop;
      for(int l = i+1;l<staticline.size();l++)
        price_loop.push_back(staticline[l]);
      median_temp = stod(price_loop.c_str());
      }

      else if(word_temp==quantity_write){
      string price_loop;
      for(int l = i+1;l<staticline.size();l++)
        price_loop.push_back(staticline[l]);
      quantity_temp = stod(price_loop.c_str());
      }
    }
    word_temp.clear();
    cout<<id_temp<<" "<<year<<" "<<hour<<" "<<lowest_temp<<endl;
  }*/
}










