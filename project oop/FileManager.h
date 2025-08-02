#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Forward declarations
class User;
class Admin;
class Seller;
class Buyer;
class Product;
class ElectronicsProduct;
class ClothingProduct;
class BookProduct;
class HomeAppliancesProduct;
class Order;

class FileManager {
private:
    static const string USER_FILE;
    static const string PRODUCT_FILE;
    static const string ORDER_FILE;
    static const string ADMIN_FILE;
    static const string SELLER_FILE;
    static const string BUYER_FILE;

    // Helper methods for parsing and formatting data
    string userToString(User* user);
    User* stringToUser(const string& data);
    string productToString(Product* product);
    Product* stringToProduct(const string& data);
    string orderToString(Order* order);
    Order* stringToOrder(const string& data);

    // File I/O helpers
    bool writeToFile(const string& filename, const string& data, bool append = false);
    string readFromFile(const string& filename);
    bool clearFile(const string& filename);

    // Data validation helpers
    bool isValidUserData(const string& data);
    bool isValidProductData(const string& data);
    bool isValidOrderData(const string& data);

public:
    // Constructor
    FileManager();

    // Destructor
    ~FileManager();

    // User Management File Operations
    bool saveUsers(User** users, int userCount);
    int loadUsers(User** users, int maxUsers);
    bool saveAdmins(Admin** admins, int adminCount);
    int loadAdmins(Admin** admins, int maxAdmins);
    bool saveSellers(Seller** sellers, int sellerCount);
    int loadSellers(Seller** sellers, int maxSellers);
    bool saveBuyers(Buyer** buyers, int buyerCount);
    int loadBuyers(Buyer** buyers, int maxBuyers);

    // Product Management File Operations
    bool saveProducts(Product** products, int productCount);
    int loadProducts(Product** products, int maxProducts);
    bool saveElectronicsProducts(ElectronicsProduct** products, int productCount);
    int loadElectronicsProducts(ElectronicsProduct** products, int maxProducts);
    bool saveClothingProducts(ClothingProduct** products, int productCount);
    int loadClothingProducts(ClothingProduct** products, int maxProducts);
    bool saveBookProducts(BookProduct** products, int productCount);
    int loadBookProducts(BookProduct** products, int maxProducts);
    bool saveHomeAppliancesProducts(HomeAppliancesProduct** products, int productCount);
    int loadHomeAppliancesProducts(HomeAppliancesProduct** products, int maxProducts);

    // Order Management File Operations
    bool saveOrders(Order** orders, int orderCount);
    int loadOrders(Order** orders, int maxOrders);
    bool saveOrderHistory(string buyerId, string* orderIds, int orderCount);
    int loadOrderHistory(string buyerId, string* orderIds, int maxOrders);

    // System Data Operations
    bool loadSystemData(User** users, int& userCount, int maxUsers,
        Product** products, int& productCount, int maxProducts,
        Order** orders, int& orderCount, int maxOrders);
    bool saveSystemData(User** users, int userCount,
        Product** products, int productCount,
        Order** orders, int orderCount);

    // File Validation and Utility
    bool fileExists(const string& filename);
    bool createFile(const string& filename);
    bool deleteFile(const string& filename);
    bool backupData();
    bool restoreData();

    // Data Export/Import
    bool exportToCSV(const string& dataType, const string& filename);
    bool importFromCSV(const string& dataType, const string& filename);

    // Error Handling
    void displayFileError(const string& operation, const string& filename);
    bool validateFileIntegrity(const string& filename);
};