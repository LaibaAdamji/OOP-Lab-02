#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p)
        : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n, vector<MenuItem> m)
        : name(n), menu(m) {}

    void addOrder(const string& itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                cout << itemName << " added to orders." << endl;
                return;
            }
        }
        cout << "This item is currently unavailable." << endl;
    }

    void fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            cout << "The " << item << " is ready." << endl;
        } else {
            cout << "All orders have been fulfilled." << endl;
        }
    }

    vector<string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0.0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menu.empty()) return "";
        auto minItem = min_element(menu.begin(), menu.end(),
            [](const MenuItem& a, const MenuItem& b) {
                return a.price < b.price;
            });
        return minItem->name;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        MenuItem("Coffee", "drink", 3.50),
        MenuItem("Tea", "drink", 2.50),
        MenuItem("Sandwich", "food", 5.00),
        MenuItem("Cake", "food", 4.00)
    };

    CoffeeShop shop("Java Junction", menu);

    shop.addOrder("Coffee");
    shop.addOrder("Sandwich");
    shop.addOrder("Juice");

    cout << "Orders: ";
    for (const auto& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due amount: $" << shop.dueAmount() << endl;

    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder();  

    cout <<"Cheapest item: " << shop.cheapestItem() << endl;

    cout <<"Drinks: ";
    for (const auto& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food: ";
    for (const auto& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    return 0;
}
