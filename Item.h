/**
 * CS300 Assignment 4 BinarySearchTree/Array UPC Scanner
 * Purpose: To create a UPC Scanner with both a BST and Array Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 11/21/2018
 */

#ifndef ITEM_H_
#define ITEM_H_

using namespace std;
/**
 * Creates an item object with a UPC code and description
 * 
 */
class Item{
    private:
        string upcCode;
        string description; //description of item
    public:
        void setUpcCode(string code){upcCode = code;}
        string getUpcCode(){return upcCode;}
        void setDescription(string desc){description = desc;}
        string getDescription(){return description;}
        
        //to compare within a BST based on UPC code.
        friend bool operator<(Item const& a, Item const& b){
            return a.upcCode < b.upcCode;
         }

         //to compare within a BST based on UPC code.
        friend bool operator> (Item const& a, Item const& b){
            return a.upcCode > b.upcCode;
         }             
};

#endif /* ITEM_H_ */

