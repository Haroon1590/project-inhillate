#pragma once
#include "Product.h"

class BookProduct : public Product {
private:
    string author;
    string publisher;
    string isbn;
    int pages;
    string language;
    string genre;
    int publicationYear;
    string format;          // Hardcover, Paperback, Ebook

public:
    // Constructors
    BookProduct();
    BookProduct(string productId, string name, double price, int quantity,
        string sellerId, string author, string publisher, string isbn,
        int pages, string language, string genre, int publicationYear, string format);

    // Getters
    string getAuthor() const;
    string getPublisher() const;
    string getIsbn() const;
    int getPages() const;
    string getLanguage() const;
    string getGenre() const;
    int getPublicationYear() const;
    string getFormat() const;

    // Setters
    void setAuthor(string author);
    void setPublisher(string publisher);
    void setIsbn(string isbn);
    void setPages(int pages);
    void setLanguage(string language);
    void setGenre(string genre);
    void setPublicationYear(int year);
    void setFormat(string format);

    // Override virtual methods
    void displayDetails() const override;
    void applyDiscount(double discountPercent) override;
    string getProductType() const override;

    // Book-specific methods
    void displayBookInfo() const;
    void displayAuthorInfo() const;
    bool isNewRelease() const;
    void displayRecommendedAge() const;
};