#include <iostream>
#include <fstream>
//headers
#include "./headers/database.h"
#include "./headers/database.cpp"
//#include "interface.h"
//#include "interface.cpp"
#include "./headers/item.h"
#include "./headers/item.cpp"
#include "./headers/market.h"
#include "./headers/market.cpp"
#include "./headers/itemdata.h"
#include "./headers/itemdata.cpp"
#include "./headers/itemtrack.h"
#include "./headers/itemtrack.cpp"
using namespace std;


int ITEM_ID = 1;



int main(){
  database database;
  database.RefreshHash();
  database.ChangeCurrency(5);
  market market;
  itemdata itemdata;
  itemdata.itemdatastart();
  itemtrack itemtrack;
  item item;
  system("clear");
  //WINDOWS
  for(int i = 0;i<5;i++){
    ITEM_ID = i;
    item.GetItemsData(ITEM_ID);
    item.GetItemsDataLive(ITEM_ID);
    cout<<item.ReturnName()<<" --- ";
    cout<<item.ReturnLowestPrice();
    cout<<item.ReturnCurrency()<<endl;
  }
}
