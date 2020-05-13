#ifndef ITEM_H
#define ITEM_H
#include <string>

class item{
  private:
    string name;
    string quality;
    int currency;
    bool stattrak;
    double lowest_price;
    double median_price;
    double quantity;
  public:
    void GetItemsData(int);
    void GetItemsDataLive(int);
    
    string ReturnName(){return name;}
    string ReturnQuality(){return quality;}
    bool ReturnStatTrak(){return stattrak;}
    double ReturnLowestPrice(){return lowest_price;}
    double ReturnMedianPrice(){return median_price;}
    double ReturnQuantity(){return quantity;}
};

#endif
