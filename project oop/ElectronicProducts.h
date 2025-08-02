#pragma once
#include "Product.h"

class ElectronicsProduct : public Product {
private:
    string brand;
    string model;
    int warrantyPeriod;     // in months
    string powerConsumption;

public:
    // Constructors
    ElectronicsProduct();
    ElectronicsProduct(string productId, string name, double price, int quantity,
        string sellerId, string brand, string model,
        int warrantyPeriod, string powerConsumption);

    // Getters
    string getBrand() const;
    string getModel() const;
    int getWarrantyPeriod() const;
    string getPowerConsumption() const;

    // Setters
    void setBrand(string brand);
    void setModel(string model);
    void setWarrantyPeriod(int months);
    void setPowerConsumption(string power);

    // Override virtual methods
    void displayDetails() const override;
    void applyDiscount(double discountPercent) override;
    string getProductType() const override;

    // Electronics-specific methods
    void displayWarrantyInfo() const;
    void displayTechnicalSpecs() const;
    bool isEnergyEfficient() const;
};