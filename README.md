0.3 CS:GO Item Price Tracker

ID = 1++

WHAT YOU NEED TO DO:
 1.A something to change the currency +
 2.A user friendly interface and a console one
   1.Learn python
 3.To add a url and then the url to be transformed into a hash
 4.Support for cases/keys/agents +
 5.To make a big hash base to chose from
 6.To show the currency icon somewhere

Items:
  1.Weapon:
    1.Name
    2.Quality
    3.StatTrak
  2.Cases|Keys|Agents:
    1.Name

Items:
  1.Succes(True,False)
  2.Lowest price
  3.Median price
  4.Quantity(Volume)

Database:
  1.Hash data:
    1.Hash -> AddHash()
  2.HashId data:
    1.Id   -> RefreshHash()
    2.Hash -> RefreshHash()
  3.Static data:
    1.Id
    2.Currency -> GetCurrency()
    2.Name     -> GetName()
    3.Quality  -> GetQuantity()
    4.StatTrak -> GetStatTrak()
  4.Live data:
    1.Id
    2.Lowest price -> GetLowestPrice()
    3.Median price -> GetMedianPrice()
    4.Quantity     -> GetQuantity()
  5.Track data:
    1.Id
    2.YY/MM/DD 
    3.HH/MM/SS
    4.Lowest price
    5.Median price
    6.Quantity

Class:
  1.Item:
    1.Class Functions:
      1.ReturnName()
        string name;
      2.ReturnQuality()
        string quality;
      3.ReturnStatTrak()
        bool stattrak;
      4.ReturnLowestPrice()
        double lowest_price;
      5.ReturnMedianPrice()
        double median_price;
      6.ReturnQuantity()
        double quantity;

    2.GetItemsData(ID) -> Will show all the information about an item
      1.Will open Static Data file:
        1.Name
        2.Quality
        3.StatTrack
      2.Will open Live Data file:
        4.Lowest price
        5.Median price
        6.Quantity

  2.DataBase:
    1.RefreshHash() -> Will get the hash from "hash data" and will give him an 'ID'
      1.Will use the hash from hash data text file
      2.Will give him an id
      3.Will put all the information in a new text file called "HashId data"
    2.ChangeCurrency() -> Will edit hash from "hash data" and will change the currency number 
      1.Will use the hash from the text file
      2.Will change just the currency number
      3.Will write in the "hashid data" file

  3.Market: -> Will get all the hashes from HashId data
    1.GetLowestPrice() -> Will write all the data in the file "live data"
    2.GetMedianPrice() -> Will write all the data in the file "live data"
    3.GetQuantity()    -> Will write all the data in the file "live data"

  4.Item data:
    1.GetCurrency() -> Will write all the data in the file "static data"
    2.GetName()     -> Will write all the data in the file "static data" 
    3.GetQuality()  -> Will write all the data in the file "static data"
    4.GetStatTrak() -> Will write all the data in the file "static data"

  5.Graphic Interface:
    1.GetHash() -> User Input
      1.Will store hash in the hash text file
  6.Price Traker
    1.ShowPriceChanges(ID)
      ITEM_ ID YEAR/MONTH/DAY HOUR/MINUTES LOWEST_PRICE MEDIAN_PRICE QUANTITY







