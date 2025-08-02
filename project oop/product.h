#pragma once
#include<iostream>
#include<string>
using namespace std;

class Product {
protected:
    string productId;
    string name;
    string category;
    double price;
    int quantity;
    string sellerId;
    bool isApproved;

public:
    // Constructors
    Product();
    Product(string productId, string name, string category, double price, int quantity, string sellerId);

    // Virtual destructor
    virtual ~Product() = default;

    // Getters
    string getProductId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getQuantity() const;
    string getSellerId() const;
    bool getApprovalStatus() const;

    // Setters
    void setProductId(string id);
    void setName(string name);
    void setCategory(string category);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setSellerId(string sellerId);
    void setApprovalStatus(bool status);

    // Virtual methods for polymorphism
    virtual void displayDetails() const = 0;
    virtual void applyDiscount(double discountPercent) = 0;
    virtual string getProductType() const = 0;

    // Common operations
    bool isInStock() const;
    void updateStock(int newQuantity);
    void reduceStock(int amount);

    // Operator overloading for comparison (sorting)
    bool operator<(const Product& other) const;    // Sort by price
    bool operator>(const Product& other) const;    // Sort by price
    bool operator==(const Product& other) const;   // Compare by ID
    bool operator!=(const Product& other) const;   // Compare by ID
};