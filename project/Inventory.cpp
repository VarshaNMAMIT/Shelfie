#include "Inventory.h"
#include <fstream>
#include <iostream>

Inventory::Inventory(std::string filename) : filename(filename) {
    loadProducts();
}

void Inventory::loadProducts() {
    std::ifstream file(filename);
    if (!file) return;

    int id, quantity;
    std::string name;
    float price;
    while (file >> id >> name >> price >> quantity) {
        products.push_back(Product(id, name, price, quantity));
    }
    file.close();
}

void Inventory::saveProducts() const {
    std::ofstream file(filename);
    for (const auto& product : products) {
        file << product.getId() << " " << product.getName() << " "
             << product.getPrice() << " " << product.getQuantity() << std::endl;
    }
    file.close();
}

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
    saveProducts();
}

void Inventory::updateProductQuantity(int id, int quantity) {
    for (auto& product : products) {
        if (product.getId() == id) {
            product.setQuantity(quantity);
            saveProducts();
            return;
        }
    }
}

void Inventory::displayAllProducts() const {
    for (const auto& product : products) {
        product.displayProduct();
    }
}

void Inventory::deleteProduct(int id) {
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [id](const Product& p) { return p.getId() == id; }),
                   products.end());
    saveProducts();
}

