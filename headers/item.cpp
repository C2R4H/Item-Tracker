#include "item.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void item::GetItemsData(int id){
  ifstream read_staticdata;
  read_staticdata.open("./data/static_data.txt");

  int id_temp;
  int currency_temp;
  int stattrak_temp;
  string name_real;
  string name_quality;

  string id_write = "Id:";
  string currency_write = " 1.Currency:";
  string stattrak_write = " 2.StatTrak:";
  string name_write = " 3.Name:";
  string quality_write = " 4.Quality:";

  string line;
  int stop_number = 0;
  bool stop = false;
  while(getline(read_staticdata, line)){
    string staticline = line;

    if(stop==true){
      stop_number++;
      if(stop_number==5){
        break;
      }
    }
    string word_temp;
    for(int i = 0;i<staticline.size();i++){
      word_temp.push_back(staticline[i]);

      if(word_temp==id_write){
        id_temp = staticline[i+1]-'0';
        if(id==id_temp)
          stop = true;
        word_temp.clear();
      }

      else if(word_temp==currency_write){
        currency = staticline[i+1]-'0';
        word_temp.clear();
      }

      else if(word_temp==stattrak_write){
        stattrak_temp = staticline[i+1]-'0';
        if(stattrak_temp==1)
          stattrak = true;
        else
          stattrak = false;
        word_temp.clear();
      }

      else if(word_temp==name_write){
        string name_loop;
        for(int j = i+1;j<staticline.size();j++)
          name_loop.push_back(staticline[j]);
        name = name_loop;
        word_temp.clear();
      }

      else if(word_temp==quality_write){
        string quality_loop;
        for(int j = i+1;j<staticline.size();j++)
          quality_loop.push_back(staticline[j]);
        quality = quality_loop;
        word_temp.clear();
      }

    }
  }


  read_staticdata.close();
}

void item::GetItemsDataLive(int id){
  ifstream read_livedata;
  read_livedata.open("./data/live_data.txt");

  int id_temp;
  double lowest_temp;
  double median_temp;
  double quantity_temp;

  string id_write = "Id:";
  string lowest_write = " 1.Lowest_Price:";
  string median_write = " 2.Median_Price:";
  string quantity_write = " 3.Quantity:";

  string line; 
  int stop_number = 0;
  bool stop = false;
  while(getline(read_livedata, line)){
    string staticline = line;

    if(stop==true){
      stop_number++;
      if(stop_number==5)
        break;
    }

    string word_temp;
    for(int i = 0;i<staticline.size();i++){
      word_temp.push_back(staticline[i]);

      if(word_temp==id_write){
        id_temp = staticline[i+1]-'0';
        if(id==id_temp)
          stop = true;
        word_temp.clear();
      }

      else if(word_temp==lowest_write){
        string price_loop;
        for(int l = i+1;l<staticline.size();l++)
          price_loop.push_back(staticline[l]);
        for(int l = 0;l<price_loop.size();l++)
          if(price_loop[l]==',')
            price_loop[l]='.';
        lowest_price = stod(price_loop.c_str());
      }

      else if(word_temp==median_write){
        string price_loop;
        for(int l = i+1;l<staticline.size();l++)
          price_loop.push_back(staticline[l]);
        for(int l = 0;l<price_loop.size();l++)
          if(price_loop[l]==',')
            price_loop[l]='.';
        median_price = stod(price_loop.c_str());
      }

      else if(word_temp==quantity_write){
        string price_loop;
        for(int l = i+1;l<staticline.size();l++)
          price_loop.push_back(staticline[l]);
        for(int l = 0;l<price_loop.size();l++)
          if(price_loop[l]==',')
            price_loop[l]='.';
        quantity = stod(price_loop.c_str());
      }

    }
  }
}










