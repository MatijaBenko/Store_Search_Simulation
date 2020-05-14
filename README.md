## Problem Overview

UPC codes are commonly used to uniquely identify a specific product.
Inventory.txt, based on [this](https://www.grocery.com/open-grocery-database-project/) list of brands and products.

In the end you will want to be able to answer these questions:

* Brand: 
  * What is your name?
  * What are your products?
* Product:
  * What is your name?
  * What is your Brand?
  * What is your UPC?
* Store: 
  * What are your Brands?
  * Given a brand name, what is the Brand?
  * What are your Products?
  * Given a UPC, what is the Product?
  * Given a product name, what are the Products?

## Solution Specifications

* Implement the public member functions for these three classes: Store, Brand, and Product.
* It should have at least seven files, two each for the classes named above (the provided .h files and your own .cpp files), plus main.cpp with tests.
* Using dynamically allocated Brand and Product objects, it should have only one instance of each Brand (with a pointer shared by all references) and only one instance of each Product (with a pointer shared by all references).
* Implement a function to answer each of the questions in the problem overview.
* DONT FORGET TO HAVE POINTERS
* Write test driver main that demonstrates each of the questions in the problem overview.


