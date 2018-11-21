#ifndef BARCODE_ARRAY_SCANNER_H_
#define BARCODE_ARRAY_SCANNER_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include "BinarySearchTree.h"
#include "Item.h"

using namespace std;

class BarcodeArrayScanner{
    private:
        string upcCode;
    public:
        void setUPC(string);
        void searchUPC();
};

void BarcodeArrayScanner::setUPC(string userInput) {
    upcCode = userInput;
}

void BarcodeArrayScanner::searchUPC() {
    string input;
    ifstream file;
    Item* arr = new Item[1100000];
   
 file.open("upc_corpus.txt");
 int j = 0;

while(getline(file, input)) {
  istringstream ss(input);
  string token;
  Item item;
  for(int i = 0; i < 2; i++) {
  getline(ss, token, ','); 
      if(i == 0) {
   item.setUpcCode(token);  
      }
      else
      {
        item.setDescription(token);     
      }
      arr[j] = item;     
}
j++; 
 }

Item itemTest;
itemTest.setUpcCode(upcCode);
itemTest.setDescription("Error: Item not found");
   clock_t t;
t = clock();
size_t size = 100000;

    for(int k = 0; k < 1100000; k++ ) {   
        if(arr[k].getUpcCode() ==itemTest.getUpcCode()) { 
            break;
        }
    }
    t = clock() - t;
    cout << "Array time: " << t << " ms" << endl;
delete[]arr;
}

#endif /* BARCODE_ARRAY_SCANNER_H_ */