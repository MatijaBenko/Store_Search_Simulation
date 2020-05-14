using namespace std;
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#ifndef STORE_H
#define STORE_H

#include "Brand.h"
#include "Product.h"
class Store {
public:
  // Default Constructor
  Store();
  // Returns a list of Brand pointers that has been initialize
  // From the .txt file
  vector<Brand *> getBrands() const;
  // Searches the map of Brands as key and returns a brand pointer
  // That is from the User request
  Brand *getBrandByName(string name) const;
  // Returns a Vector of Product pointers that has been initialize
  // From the specific brand
  vector<Product *> getProducts() const;
  // Returns a Product pointer with matching UPC
  Product *getProductsByUPC(string upc) const;
  // Returns a vector of product pointers by name
  vector<Product *> getProductsByName(string name) const;

private:
  // A Map containter, key
  map<string, Brand *> brands;
  map<string, Product *> productsByUpc;
  map<string, vector<Product *> *> productsByName;
};

#endif
