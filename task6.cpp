#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Node structure for a linked list
struct Item {
    string name;
    double price;
    int quantity;
    Item* next;

    Item(const string& name, double price, int quantity) 
        : name(name), price(price), quantity(quantity), next(nullptr) {}
};

class Inventory {
private:
    Item* head;

public:
    Inventory() : head(nullptr) {}

    ~Inventory() {
        // Destructor to free memory
        while (head) {
            Item* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addItem(const string& name, double price, int quantity) {
        Item* newItem = new Item(name, price, quantity);
        newItem->next = head;
        head = newItem;
        cout << "Item added: " << name << "\n";
    }

    void updateItem(const string& name, double price, int quantity) {
        Item* current = head;
        while (current) {
            if (current->name == name) {
                current->price = price;
                current->quantity = quantity;
                cout << "Item updated: " << name << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Item not found: " << name << "\n";
    }

    void removeItem(const string& name) {
        Item* current = head;
        Item* previous = nullptr;

        while (current) {
            if (current->name == name) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Item removed: " << name << "\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Item not found: " << name << "\n";
    }

    void generateReport() const {
        if (!head) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << setw(15) << "Name" << setw(10) << "Price" 
                  << setw(10) << "Quantity" << "\n";
        cout << "--------------------------------------\n";

        Item* current = head;
        while (current) {
            cout << setw(15) << current->name << setw(10) << current->price
                      << setw(10) << current->quantity << "\n";
            current = current->next;
        }
    }

    void calculateTotalValue() const {
        double totalValue = 0.0;
        Item* current = head;

        while (current) {
            totalValue += current->price * current->quantity;
            current = current->next;
        }

        cout << "Total inventory value: $" << totalValue << "\n";
    }

    void flagRestocking(int threshold) const {
        Item* current = head;
        bool needsRestocking = false;

        while (current) {
            if (current->quantity < threshold) {
                if (!needsRestocking) {
                    cout << "Items needing restocking:\n";
                    needsRestocking = true;
                }
                cout << " - " << current->name << " (Quantity: " << current->quantity << ")\n";
            }
            current = current->next;
        }

        if (!needsRestocking) {
            cout << "No items need restocking.\n";
        }
    }
};

int main() {
    Inventory inventory;

    inventory.addItem("Apples", 0.5, 100);
    inventory.addItem("Bananas", 0.3, 50);
    inventory.addItem("Oranges", 0.7, 30);

    cout << "\n--- Inventory Report ---\n";
    inventory.generateReport();

    cout << "\n--- Total Inventory Value ---\n";
    inventory.calculateTotalValue();

    cout << "\n--- Restocking Check ---\n";
    inventory.flagRestocking(40);

    inventory.updateItem("Oranges", 0.75, 45);
    inventory.removeItem("Bananas");

    cout << "\n--- Updated Inventory Report ---\n";
    inventory.generateReport();

    return 0;
}
