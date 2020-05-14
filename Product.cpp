#include "Product.h"

// Initializes the values given by the parameter
Product::Product(string name, string upc, Brand *brand) {
  this->name = name;
  this->upc = upc;
  this->brand = brand;
  brand->addProduct(this);
}
