#include <iostream>
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"
#include "string"

using namespace std;

int main()
{
  cout<<"UPC Code: ";
  string userInput;
  cin>>userInput;

  BarcodeBSTScanner bstScan;
  bstScan.setUPC(userInput);
  bstScan.searchUPC();

  BarcodeArrayScanner arrScan;
  arrScan.setUPC(userInput);
  arrScan.searchUPC();

 } 
