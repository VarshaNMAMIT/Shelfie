#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    float price;
    int quantity;

public:
    Product() {}
    Product(int id, std::string name, float price, int quantity);

    int getId() const;
    std::string getName() const;
    float getPrice() const;
    int getQuantity() const;

    void setQuantity(int qty);
    void displayProduct() const;
};

#endif
