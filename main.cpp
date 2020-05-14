#include <cassert>
#include <iostream>
#include <string>
using namespace std;

#include "Brand.h"
#include "Product.h"
#include "Store.h"
int main() {
  Store store;
  Brand *brand = new Brand("Riceland");
  assert(brand->getBrandName() == "Riceland");
  assert((brand->getProducts()).size() == 0);

  Product *product = new Product("Brown Rice", "1234", brand);
  assert(product->getName() == "Brown Rice");
  assert(product->getUPC() == "1234");
  assert(product->getBrand() == brand);

  assert((store.getBrands()).size() > 0);
  assert((store.getProducts()).size() > 0);
  assert(store.getBrandByName("Riceland") != nullptr);
  vector<Product *> airFresheners = store.getProductsByName("Air Freshener");
  assert(airFresheners.size() == 4);

  Brand *riceland = store.getBrandByName("Riceland");
  assert((riceland->getProducts()).size() == 5);

  // Test #1 (Brand) What is Your Name?
  cout << endl;
  Brand *test1 = new Brand("Lego's");
  // Should Print out itself
  cout << test1->getBrandName() << endl;
  cout << endl << "====================" << endl << endl;

  // Test #2 (Brand) Given a Brand what are its products?
  Brand *test2 = store.getBrandByName("Riceland");
  vector<Product *> listOfProductsByBrand = test2->getProducts();
  for (auto each : listOfProductsByBrand) {
    cout << each->getName() << endl;
  }
  cout << endl << "====================" << endl << endl;

  // Test #3 (Product) What is your Name?
  Brand *testBrand = new Brand("Walla Walla Juice");
  Product *test3 = new Product("Apple Juice", "000000000000", testBrand);
  cout << test3->getName() << endl;
  cout << endl << "====================" << endl << endl;

  // Test #4 (Product) What is your Brand?
  vector<Product *> test4 = store.getProductsByName(
      "Beauty Without Cruelty Waterproof Mascara Black - 0.27 Fl Oz");
  for (auto product : test4) {
    // Should Print out "Beauty Without Cruelty"
    cout << product->getBrand()->getBrandName() << endl;
  }
  cout << endl << "====================" << endl << endl;

  // Test #5 (Product) What is Your UPC?
  vector<Product *> test5 = store.getProductsByName("Odense Almond Paste");
  for (auto product : test5) {
    // Should Print out "070650000064"
    cout << product->getUPC() << endl;
  }
  cout << endl << "====================" << endl << endl;

  // Test #6 (Store) What are your brands?
  vector<Brand *> test6 = store.getBrands();
  for (auto eachBrand : test6) {
    cout << eachBrand->getBrandName() << endl;
  }
  cout << endl << "====================" << endl << endl;
  // Test #7 (Store) Given Brand Name, what is the brand?
  Brand *test = store.getBrandByName("Hartz");
  // Should print out itself
  cout << test->getBrandName() << endl;
  cout << endl << "====================" << endl << endl;
  // Test #8 (Store) What are your Products?
  vector<Product *> test8 = store.getProducts();
  for (auto each : test8) {
    cout << each->getName() << endl;
  }
  cout << endl << "====================" << endl << endl;
  // Test #9 (Store) Given UPC, what is the Products?
  Product *test9 = store.getProductsByUPC("062338804200");
  cout << test9->getName() << endl;
  cout << endl << "====================" << endl << endl;
  // Test #10 (Store) Given a Product name, What are the products?
  vector<Product *> test10 =
      store.getProductsByName("Sante Homme After Shave - 100 Ml");
  for (auto product : test10) {
    // Should Print out itself
    cout << product->getName() << endl;
  }
  cout << endl << "====================" << endl << endl;
  return 0;
}
