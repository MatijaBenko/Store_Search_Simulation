using namespace std;
#include <iostream>
#include <string>
#include <vector>

#ifndef BRAND_H
#define BRAND_H

#include "Product.h"
class Product;

class Brand {
public:
  // Special Constructor that initalize the brand name
  Brand(string name) { this->name = name; }

  string getBrandName() const { return name; }

  vector<Product *> getProducts() const { return products; }

  // Adds the product pointer to the list of list pointers
  void addProduct(Product *product);

private:
  string name;
  vector<Product *> products;
};

#endif
