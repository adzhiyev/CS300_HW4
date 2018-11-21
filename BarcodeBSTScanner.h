/**
 * CS300 Assignment 4 BinarySearchTree/Array UPC Scanner
 * Purpose: To create a UPC Scanner with both a BST and Array Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 11/21/2018
 */
#ifndef BARCODE_BST_SCANNER_H_
#define BARCODE_BST_SCANNER_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include "BinarySearchTree.h"
#include "Item.h"

using namespace std;

/*
 *UPC Scanner class for BST
 */
class BarcodeBSTScanner{
    private:
        string upcCode;
    public:
        void setUPC(string);
        void searchUPC();
};

/*
 *Sets the UPC Code
 *
 * @param userInput the upc input from user
 */
void BarcodeBSTScanner::setUPC(string userInput) {
    upcCode = userInput;
}

/*
 * Creates the BST of UPC codes from textfile
 * and searches through it to see if it matches
 * the user input
 */
void BarcodeBSTScanner::searchUPC() {
    string input;
    ifstream file;
    BinarySearchTree<Item> upcTree; //BST for Items
     //opens the text file to read the UPC's and Descriptions 
    file.open("upc_corpus.txt"); 
    //loops through creating an item object with UPC code and description
    //and inserting them in the tree.
    while(getline(file, input)){
        istringstream ss(input);
        string token;
        Item item;
        //Splits string in two based in first comma
        for(int i = 0; i < 2; i++) {
            getline(ss, token, ',');
       
            if(i == 0) {
                item.setUpcCode(token);  //sets UPC code
            }
            else
            {
                 item.setDescription(token); //sets item description               
            } 
        }

        upcTree.insert(item); //stores item in BST
    }

    Item itemSearch; //dummy Item object to search through BST
    itemSearch.setUpcCode(upcCode);
    //Default description which is returned incase item is not found
    itemSearch.setDescription("Error: Item not Found"); 

    clock_t t;
    t = clock(); // clock to keep track of execution time
    size_t size = 100000;

    //searches through the tree for the item's upc and prints its description
    cout<<upcTree.search(itemSearch).getDescription()<<endl; 
    t = clock() - t; //execution time
    cout << "BST time: " << t << " ms" << endl;
}

#endif /* BARCODE_BST_SCANNER_H_ */
