#ifndef DATABASE_H
#define DATABASE_H
#include <string>
using namespace std;

class database{
  public:
    database();
    void RefreshHash();
    void ChangeCurrency(int);
    void AddItemByUrl(string);
    int TotalItems();
};

#endif
