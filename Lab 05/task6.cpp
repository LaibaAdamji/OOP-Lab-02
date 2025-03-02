#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item {
    string name;
    double price;
    string type; //"food" or "drink"
};

class CoffeeShop {
private:
    const string Name; 
    vector<Item> Menu; 
    vector<string> Orders;

public:

    CoffeeShop(string shopName, vector<Item> shopMenu)
        : Name(shopName), Menu(shopMenu) {}

    string addOrder(string itemName) {
        for (const auto& item : Menu) {
            if (item.name == itemName) {
                Orders.push_back(itemName);
                return itemName + " added to orders!";
            }
        }
        return "This item is currently unavailable lol noooo :(";
    }

    string fulfillOrder() {
        if (!Orders.empty()) {
            string item = Orders.front(); 
            Orders.erase(Orders.begin()); 
            return "The " + item + " is ready!";
        } else {
            return "All orders have been fulfilled!";
        }
    }

    vector<string> listOrders() const {
        return Orders;
    }

    double dueAmount() const {
        double total = 0.0;
        for (const auto& order : Orders) {
            for (const auto& item : Menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (Menu.empty()) return "No items in the menu!";
        Item cheapest = Menu[0];
        for (const auto& item : Menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : Menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> foods;
        for (const auto& item : Menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }

    void displayMenu() const {
        cout << "Welcome to " << Name << "!" << endl;
        cout << "Menu:" << endl;
        for (const auto& item : Menu) {
            cout << "- " << item.name << " (" << item.type << "): $" << item.price << endl;
        }
    }
};

int main() {

    vector<Item> menu = {
        {"Latte", 3.50, "drink"},
        {"Cappuccino", 4.00, "drink"},
        {"Sandwich", 5.50, "food"},
        {"Croissant", 2.50, "food"},
        {"Tea", 2.00, "drink"}
    };


    CoffeeShop shop("Java Junction", menu);


    shop.displayMenu();

    cout << "\nAdding orders..." << endl;
    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Smoothie") << endl; // Unavailable item

    cout << "\nList of orders:" << endl;
    for (const auto& order : shop.listOrders()) {
        cout << "- " << order << endl;
    }

    cout << "\nFulfilling orders..." << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl; 

    cout << "\nTotal amount due: $" << shop.dueAmount() << endl;

    cout << "\nCheapest item on the menu: " << shop.cheapestItem() << endl;

    cout << "\nDrinks only:" << endl;
    for (const auto& drink : shop.drinksOnly()) {
        cout << "- " << drink << endl;
    }

    cout << "\nFood only:" << endl;
    for (const auto& food : shop.foodOnly()) {
        cout << "- " << food << endl;
    }

    return 0;
}
