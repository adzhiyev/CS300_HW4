#ifndef BARCODE_BST_SCANNER_H_
#define BARCODE_BST_SCANNER_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include "BinarySearchTree.h"
#include "Item.h"

using namespace std;

class BarcodeBSTScanner{
    private:
        string upcCode;
    public:
        void setUPC(string);
        void searchUPC();
};

void BarcodeBSTScanner::setUPC(string userInput) {
    upcCode = userInput;
}
void BarcodeBSTScanner::searchUPC() {
    string input;
    ifstream file;
    BinarySearchTree<Item> upcTree;
    file.open("upc_corpus.txt");

    while(getline(file, input)){
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
        }

        upcTree.insert(item);
    }

    Item itemSearch;
    itemSearch.setUpcCode(upcCode);
    itemSearch.setDescription("Error: Item not Found");

    clock_t t;
    t = clock();
    size_t size = 100000;

    cout<<upcTree.search(itemSearch).getDescription()<<endl;
    t = clock() - t;
    cout << "BST time: " << t << " ms" << endl;
}

#endif /* BARCODE_BST_SCANNER_H_ */
