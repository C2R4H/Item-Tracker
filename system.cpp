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


int ITEM_ID = 9;



int main(){
  database database;
  database.RefreshHash();
  database.ChangeCurrency(1);
  market market;
  itemdata itemdata;
  itemdata.itemdatastart();
  itemtrack itemtrack;
  item item;
  itemtrack.ShowItemHistory(ITEM_ID);
  item.GetItemsData(ITEM_ID);
  item.GetItemsDataLive(ITEM_ID);
  cout<<"Name = "<<item.ReturnName()<<endl;
  cout<<"Quality = "<<item.ReturnQuality()<<endl;
  cout<<"Lowest Price = "<<item.ReturnLowestPrice()<<endl;
  cout<<"Median Price = "<<item.ReturnMedianPrice()<<endl;
  cout<<"StatTrak = "<<item.ReturnStatTrak()<<endl;
  cout<<"Quantity = "<<item.ReturnQuantity()<<endl;
}
