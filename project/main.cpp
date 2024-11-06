#include "Product.h"
#include "Inventory.h"
#include <iostream>

void showMenu() {
    std::cout << "\n--- Supermarket Management System ---\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Update Product Quantity\n";
    std::cout << "3. Delete Product\n";
    std::cout << "4. Display All Products\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory("products.txt");

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int id, quantity;
            std::string name;
            float price;
            std::cout << "Enter ID, Name, Price, Quantity: ";
            std::cin >> id >> name >> price >> quantity;
            inventory.addProduct(Product(id, name, price, quantity));
        }
        else if (choice == 2) {
            int id, quantity;
            std::cout << "Enter Product ID and new Quantity: ";
            std::cin >> id >> quantity;
            inventory.updateProductQuantity(id, quantity);
        }
        else if (choice == 3) {
            int id;
            std::cout << "Enter Product ID to delete: ";
            std::cin >> id;
            inventory.deleteProduct(id);
        }
        else if (choice == 4) {
            inventory.displayAllProducts();
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
