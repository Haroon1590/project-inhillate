#pragma once
#include "User.h"

// Forward declarations
class Product;
class Order;

class Seller : public User {
private:
    string sellerId;
    string* productIds;        // Dynamic array of product IDs
    int productCount;          // Current number of products
    int maxProducts;           // Maximum capacity

public:
    // Constructors
    Seller();
    Seller(string sellerId, string userID, string name, string email, string password);

    // Destructor
    ~Seller();

    // Copy constructor and assignment operator
    Seller(const Seller& other);
    Seller& operator=(const Seller& other);

    // Override virtual functions
    void displayDetails() const override;
    string getUserType() const override;

    // Seller-specific getters/setters
    string getSellerId() const;
    void setSellerId(string sellerId);

    // Product management
    void addProduct(Product* product, Product** allProducts, int& totalProducts, int maxTotalProducts);
    void updateProduct(string productId, Product** products, int productCount);
    void deleteProduct(string productId, Product** products, int& productCount);
    void viewMyProducts(Product** allProducts, int totalProducts);
    void viewMyOrders(Order** orders, int orderCount);

    // Product ID management
    void addProductId(string productId);
    void removeProductId(string productId);
    string* getProductIds() const;
    int getProductCount() const;
    bool ownsProduct(string productId) const;

private:
    void resizeProductArray();
    void copyFrom(const Seller& other);
    void cleanup();
};