#include <iostream>  
#include <vector>  
#include <limits>  
using namespace std;  

class Product {  
private:  
    int productID;  
    string productName;  
    int quantity;  
    double price;  

public:  
    Product(int id, string name, int qty, double pr) : productID(id), productName(name), quantity(qty), price(pr) {}  

    void displayProductInfo() const {  
        cout << "Product ID: " << productID  
             << ", Name: " << productName  
             << ", Quantity: " << quantity  
             << ", Price: Ksh" << price << endl;  
    }  

    void updateQuantity(int amount) {  
        quantity += amount;  
    }  

    int getProductID() const {  
        return productID;  
    }  

    int getQuantity() const {  
        return quantity;  
    }  

    double getPrice() const {  
        return price;  
    }  
};  

class Inventory {  
private:  
    vector<Product> products;  

public:  
    void addProduct(int id, string name, int qty, double pr) {  
        products.emplace_back(id, name, qty, pr);  
        cout << "Product added successfully!" << endl;  
    }  

    void displayAllProducts() const {  
        if (products.empty()) {  
            cout << "No products in inventory." << endl;  
            return;  
        }  
        for (const auto& product : products) {  
            product.displayProductInfo();  
        }  
    }  

    void updateProductQuantity(int id, int amount) {  
        for (auto& product : products) {  
            if (product.getProductID() == id) {  
                product.updateQuantity(amount);  
                cout << "Product quantity updated successfully!" << endl;  
                return;  
            }  
        }  
        cout << "Product with ID " << id << " not found." << endl;  
    }  

    void deleteProduct(int id) {  
        for (auto it = products.begin(); it != products.end(); ++it) {  
            if (it->getProductID() == id) {  
                products.erase(it);  
                cout << "Product deleted successfully!" << endl;  
                return;  
            }  
        }  
        cout << "Product with ID " << id << " not found." << endl;  
    }  

    double calculateTotalInventoryValue() const {  
        double totalValue = 0;  
        for (const auto& product : products) {  
            totalValue += product.getQuantity() * product.getPrice();  
        }  
        return totalValue;  
    }  
};  

int main() {  
    Inventory inventory;  
    int choice;  

    do {  
        cout << "\nInventory Management System" << endl;  
        cout << "1. Add a New Product" << endl;  
        cout << "2. Display All Products" << endl;  
        cout << "3. Update Product Quantity" << endl;  
        cout << "4. Delete a Product" << endl;  
        cout << "5. Calculate Total Inventory Value" << endl;  
        cout << "0. Exit" << endl;  
        cout << "Enter your choice: ";  

        cin >> choice;

        // Clear invalid input if necessary
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue; // Restart the loop
        }

        switch (choice) {  
            case 1: {  
                int id, qty;  
                string name;  
                double price;  
                cout << "Enter Product ID: ";  
                cin >> id;  
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer  
                cout << "Enter Product Name: ";  
                getline(cin, name);  
                cout << "Enter Quantity: ";  
                cin >> qty;  
                cout << "Enter Price: ";  
                cin >> price;  

                inventory.addProduct(id, name, qty, price);  
                break;  
            }  
            case 2:  
                inventory.displayAllProducts();  
                break;  
            case 3: {  
                int id, amount;  
                cout << "Enter Product ID to update: ";  
                cin >> id;  
                cout << "Enter quantity to add (use negative value to subtract): ";  
                cin >> amount;  

                inventory.updateProductQuantity(id, amount);  
                break;  
            }  
            case 4: {  
                int id;  
                cout << "Enter Product ID to delete: ";  
                cin >> id;  
                inventory.deleteProduct(id);  
                break;  
            }  
            case 5:  
                cout << "Total Inventory Value: Ksh" << inventory.calculateTotalInventoryValue() << endl;  
                break;  
            case 0:  
                cout << "Exiting the program." << endl;  
                break;  
            default:  
                cout << "Invalid choice. Please try again." << endl;  
        }  
    } while (choice != 0);  

    return 0;  
} 
