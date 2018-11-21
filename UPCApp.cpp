/**
 * CS300 Assignment 4 BinarySearchTree/Array UPC Scanner
 * Purpose: To create a UPC Scanner with both a BST and Array Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 11/21/2018
 */
#include <iostream>
#include <string>
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"


using namespace std;

int main()
{
  cout<<"UPC Code: ";
  string userInput; 
  cin>>userInput;  //stores input for UPC code

  //BST scanner for UPC
  BarcodeBSTScanner bstScan;
  bstScan.setUPC(userInput); //set UPC based on userInput
  bstScan.searchUPC(); //Scans for the UPC in a BST

  //Array scanner for UPC
  BarcodeArrayScanner arrScan;
  arrScan.setUPC(userInput); //set UPC based on userInput
  arrScan.searchUPC(); //Scans for the UPC in an Array

 } 
