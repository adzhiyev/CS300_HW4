#ifndef ITEM_H_
#define ITEM_H_

using namespace std;

class Item{
    private:
        string upcCode;
        string description;
    public:
        void setUpcCode(string code){upcCode = code;}
        string getUpcCode(){return upcCode;}
        void setDescription(string desc){description = desc;}
        string getDescription(){return description;}
        
         friend bool operator<(Item const& a, Item const& b){
             return a.upcCode < b.upcCode;
         }
         friend bool operator> (Item const& a, Item const& b){
             return a.upcCode > b.upcCode;
         }
         
      
};

#endif /* ITEM_H_ */

