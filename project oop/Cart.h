#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Cart {
private:
    T** items;              // Dynamic array of pointers to items
    int* quantities;        // Corresponding quantities for each item
    int itemCount;          // Current number of different items
    int maxItems;           // Maximum capacity
    double totalAmount;     // Total cart value

public:
    // Constructors
    Cart();
    Cart(int maxCapacity);

    // Destructor
    ~Cart();

    // Copy constructor and assignment operator
    Cart(const Cart<T>& other);
    Cart<T>& operator=(const Cart<T>& other);

    // Operator overloading
    Cart<T>& operator+=(T* item);              // Add item to cart
    Cart<T>& operator-=(const string& itemId); // Remove item from cart
    friend ostream& operator<<(ostream& os, const Cart<T>& cart) {
        os << "=== SHOPPING CART ===" << endl;
        os << "Items in cart: " << cart.itemCount << endl;
        for (int i = 0; i < cart.itemCount; i++) {
            os << "Item " << (i + 1) << ": ";
            cart.items[i]->displayDetails();
            os << "Quantity: " << cart.quantities[i] << endl;
            os << "Subtotal: $" << (cart.items[i]->getPrice() * cart.quantities[i]) << endl;
            os << "-------------------" << endl;
        }
        os << "Total Amount: $" << cart.totalAmount << endl;
        os << "===================" << endl;
        return os;
    }

    // Cart operations
    void addItem(T* item, int quantity = 1);
    void removeItem(const string& itemId);
    void updateQuantity(const string& itemId, int newQuantity);
    void clearCart();
    bool isEmpty() const;
    int getItemCount() const;
    double getTotalAmount() const;

    // Item access
    T* getItem(int index) const;
    int getQuantity(int index) const;
    bool containsItem(const string& itemId) const;
    int findItemIndex(const string& itemId) const;

    // Display methods
    void displayCart() const;
    void displayCartSummary() const;

    // Validation
    bool isValidIndex(int index) const;
    bool hasStock(const string& itemId, int requestedQuantity) const;

private:
    void calculateTotal();
};