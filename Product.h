using namespace std;
#include <iostream>
#include <map>
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

#include "Brand.h"

class Brand;

class Product {
public:
  // Special constructor that takes and initialize the values
  Product(string name, string upc, Brand *brand);

  string getUPC() const { return upc; }
  string getName() const { return name; }
  Brand *getBrand() const { return brand; }

private:
  string upc;
  string name;
  Brand *brand = nullptr;
};

#endif
