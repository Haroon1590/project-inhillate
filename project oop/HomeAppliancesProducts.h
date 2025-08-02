#pragma once
#include "Product.h"

class HomeAppliancesProduct : public Product {
private:
    string brand;
    string model;
    string dimensions;      // LxWxH format
    double weight;          // in kg
    string energyRating;    // A++, A+, A, B, C, D
    int warrantyPeriod;     // in months
    string powerRequirement;
    string applianceType;   // Kitchen, Cleaning, Heating, etc.

public:
    // Constructors
    HomeAppliancesProduct();
    HomeAppliancesProduct(string productId, string name, double price, int quantity,
        string sellerId, string brand, string model, string dimensions,
        double weight, string energyRating, int warrantyPeriod,
        string powerRequirement, string applianceType);

    // Getters
    string getBrand() const;
    string getModel() const;
    string getDimensions() const;
    double getWeight() const;
    string getEnergyRating() const;
    int getWarrantyPeriod() const;
    string getPowerRequirement() const;
    string getApplianceType() const;

    // Setters
    void setBrand(string brand);
    void setModel(string model);
    void setDimensions(string dimensions);
    void setWeight(double weight);
    void setEnergyRating(string rating);
    void setWarrantyPeriod(int months);
    void setPowerRequirement(string power);
    void setApplianceType(string type);

    // Override virtual methods
    void displayDetails() const override;
    void applyDiscount(double discountPercent) override;
    string getProductType() const override;

    // Home appliances-specific methods
    void displayEnergyInfo() const;
    void displayInstallationRequirements() const;
    void displayMaintenanceInfo() const;
    bool isPortable() const;
    void displaySafetyFeatures() const;
};