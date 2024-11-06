#include "Product.h"

Product::Product(int id, std::string name, float price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
float Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

void Product::setQuantity(int qty) { quantity = qty; }

void Product::displayProduct() const {
    std::cout << "ID: " << id << " | Name: " << name << " | Price: " << price
              << " | Quantity: " << quantity << std::endl;
}
