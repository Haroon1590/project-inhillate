#pragma once
#include "User.h"

// Forward declarations
class Product;
class Order;
template<typename T> class Cart;

class Buyer : public User {
private:
    string buyerId;
    string* orderHistory;      // Dynamic array of order IDs
    int orderCount;            // Current number of orders
    int maxOrders;             // Maximum capacity
    Cart<Product>* cart;       // Shopping cart

public:
    // Constructors
    Buyer();
    Buyer(string buyerId, string userID, string name, string email, string password);

    // Destructor
    ~Buyer();

    // Copy constructor and assignment operator
    Buyer(const Buyer& other);
    Buyer& operator=(const Buyer& other);

    // Override virtual functions
    void displayDetails() const override;
    string getUserType() const override;

    // Buyer-specific getters/setters
    string getBuyerId() const;
    void setBuyerId(string buyerId);

    // Shopping functionalities
    void browseProducts(Product** products, int productCount);
    void searchProducts(Product** products, int productCount, string keyword);
    void filterProductsByCategory(Product** products, int productCount, string category);
    void filterProductsByPriceRange(Product** products, int productCount, double minPrice, double maxPrice);
    void sortProductsByPrice(Product** products, int productCount, bool ascending = true);
    void sortProductsByName(Product** products, int productCount);

    // Cart operations
    void addToCart(Product* product);
    void removeFromCart(string productId);
    void viewCart();
    void clearCart();
    Cart<Product>* getCart();

    // Order operations
    void checkout(Order** orders, int& orderCount, int maxOrders);
    void viewOrderHistory(Order** orders, int orderCount);
    void trackOrder(Order** orders, int orderCount, string orderId);

    // Order history management
    void addOrderToHistory(string orderId);
    string* getOrderHistory() const;
    int getOrderCount() const;

private:
    void resizeOrderArray();
    void copyFrom(const Buyer& other);
    void cleanup();
};