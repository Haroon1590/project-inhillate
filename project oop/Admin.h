#pragma once
#include "User.h"

// Forward declarations
class Product;
class Order;

class Admin : public User {
private:
    string adminId;

public:
    // Constructors
    Admin();
    Admin(string adminId, string userID, string name, string email, string password);

    // Override virtual functions
    void displayDetails() const override;
    string getUserType() const override;

    // Admin-specific getters/setters
    string getAdminId() const;
    void setAdminId(string adminId);

    // Admin functionalities
    void displayAllUsersDetails(User** users, int userCount);
    void manageUsers(User** users, int& userCount, int maxUsers);
    void viewReports();
    void approveProducts(Product** products, int productCount);
    void generateSalesReport(Order** orders, int orderCount);
    void viewDashboard(User** users, int userCount, Order** orders, int orderCount);
    void addUser(User** users, int& userCount, int maxUsers);
    void deleteUser(User** users, int& userCount, string userId);
    void editUser(User** users, int userCount, string userId);
};