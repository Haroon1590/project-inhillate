#pragma once
#include "Product.h"

class ClothingProduct : public Product {
private:
    string size;
    string color;
    string material;
    string brand;
    string gender;          // Male, Female
    string season;          // Summer, Winter, All-Season

public:
    // Constructors
    ClothingProduct();
    ClothingProduct(string productId, string name, double price, int quantity,
        string sellerId, string size, string color, string material,
        string brand, string gender, string season);

    // Getters
    string getSize() const;
    string getColor() const;
    string getMaterial() const;
    string getBrand() const;
    string getGender() const;
    string getSeason() const;

    // Setters
    void setSize(string size);
    void setColor(string color);
    void setMaterial(string material);
    void setBrand(string brand);
    void setGender(string gender);
    void setSeason(string season);

    // Override virtual methods
    void displayDetails() const override;
    void applyDiscount(double discountPercent) override;
    string getProductType() const override;

    // Clothing-specific methods
    void displaySizeChart() const;
    void displayCareInstructions() const;
    bool isAvailableInSize(string requestedSize) const;
    void displayFashionDetails() const;
};