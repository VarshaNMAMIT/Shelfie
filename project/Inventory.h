#ifndef INVENTORY_H
#define INVENTORY_H
#include <algorithm>
#include "Product.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Product> products;
    std::string filename;

    void loadProducts();
    void saveProducts() const;

public:
    Inventory(std::string filename);
    void addProduct(const Product& product);
    void updateProductQuantity(int id, int quantity);
    void displayAllProducts() const;
    void deleteProduct(int id);
};

#endif

