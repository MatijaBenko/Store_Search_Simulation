#include "Store.h"
// Reads the text file and creates the inventory
Store::Store() {
  ifstream inFS;
  inFS.open("Inventory.txt");

  if (!inFS.is_open()) {
    cout << "Could not Open File Inventory.txt" << endl;
    assert(false);
  }
  string header;
  getline(inFS, header, '\n');

  // Loops through all the lines through the code
  while (!inFS.eof()) {
    string upc;
    string brandName;
    string productName;

    // First tab will be the UPC Number
    getline(inFS, upc, '\t');
    
    // Condition just incase if theirs a blank line
    if (upc.size() > 0) {

      // 2nd Tab will get you the brand Name
      getline(inFS, brandName, '\t');

      // The rest of the line will get you the product name
      getline(inFS, productName, '\n');

      // Brand pointer is created 
      Brand *brand = this->getBrandByName(brandName);

      // If the brand Pointer is null creates a new pointer
      // And adds it to the map containter "brands"
      if (brand == nullptr) {
        brand = new Brand(brandName);
        brands.emplace(brandName, brand);
      }

      // Creates a new product pointer to the specific brand
      Product *product = new Product(productName, upc, brand);

      // Adds a new Key to the map container "productsByUpc"
      productsByUpc.emplace(upc, product);

      // A Vector Pointer of type Pointer
      vector<Product *> *productVector;

      // Checks if the Product Key value already exist in the map
      if (productsByName.count(productName) == 1) {
        productVector = productsByName.at(productName);
      } else {
        productVector = new vector<Product *>;
        productsByName.emplace(productName, productVector);
      }
      productVector->push_back(product);
    }
  }
  flush(cout);
  inFS.close();
}

// Function that returns the list of all brands created from .txt file
vector<Brand *> Store::getBrands() const {
  vector<Brand *> result;

  // Loops through the map to grab the brand but not the identical one
  map<string, Brand *>::const_iterator iter;
  for (iter = brands.begin(); iter != brands.end(); iter++) {
    result.push_back((*iter).second);
  }
  return result;
}
// Returns a list of product pointers that are created from .txt file
vector<Product *> Store::getProducts() const {
  vector<Product *> result;

  // Loops through the map to grab the product pointers from a map
  map<string, Product *>::const_iterator iter;
  for (iter = productsByUpc.begin(); iter != productsByUpc.end(); iter++) {
    result.push_back((*iter).second);
  }
  return result;
}
// Checks if a same brand pointer has been created if so
// Doesn't create a new pointer
Brand *Store::getBrandByName(string name) const {

  if (brands.count(name) == 1) {
    return brands.at(name);
  } else {
    return nullptr;
  }
}

// Returns a product pointer given a specific UPC code
Product *Store::getProductsByUPC(string upc) const {

  if (productsByUpc.count(upc) == 1) {
    return productsByUpc.at(upc);
  } else {
    return nullptr;
  }
}
// Returns a Product pointer given the name of the product
vector<Product *> Store::getProductsByName(string name) const {

  if (productsByName.count(name)) {
    return *(productsByName.at(name));
  } else {
    vector<Product *> result;
    return result;
  }
}
