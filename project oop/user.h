#pragma once
#include<iostream>
#include<string>
using namespace std;

class User {
private:
    string userID;
    string name;
    string email;
    string password;

public:
    // Constructors
    User();
    User(string userID, string name, string email, string password);

    // Virtual destructor for proper cleanup
    virtual ~User();

    // Getters
    string getUserId() const;
    string getName() const;
    string getEmail() const;
    string getPassword() const;

    // Setters
    void setUserId(string id);
    void setName(string name);
    void setEmail(string email);
    void setPassword(string password);

    // Pure virtual functions
    virtual void displayDetails() const = 0;
    virtual string getUserType() const = 0;
};