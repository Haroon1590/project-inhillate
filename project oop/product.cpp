#include"product.h"

//CONSTRUCTOR


Product::Product()
{
}

Product::Product(string productId, string name, string category, double price, int quantity, string sellerId)
{
	 this->productId=productId;
     this->name=name;
	 this->category=category;
	 this->price=price;
	 this->quantity=quantity;
	 this->sellerId=sellerId;
}


//GETTERS


string Product::getProductId() const
{
	return productId;
}

string Product::getName() const
{
	return name;
}

string Product::getCategory() const
{
	return category;
}

double Product::getPrice() const
{
	return price;
}

int Product::getQuantity() const
{
	return quantity;
}

string Product::getSellerId() const
{
	return sellerId;
}

bool Product::getApprovalStatus() const
{
	return isApproved;
}


//SETTERS


void Product::setProductId(string id)
{
	this->productId = id;
}

void Product::setName(string name)
{
	this->name=name;
}

void Product::setCategory(string category)
{
	this->category = category;
}

void Product::setPrice(double price)
{
	this->price=price;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::setSellerId(string sellerId)
{
	this->sellerId=sellerId;
}

void Product::setApprovalStatus(bool status)
{
	 this->isApproved=status;
}


//MEMEBR FUNCTIONS 


bool Product::isInStock() const
{
	if (quantity >= 0)
		return true;
	else
		return false;
}

void Product::updateStock(int newQuantity)
{
	while (newQuantity <= 0 ) {
		cout << "Please enter a valid quantity " << endl; //checking if the quantity provided by user is valid
		cin >> newQuantity;
	}
	quantity = newQuantity;
	cout << "The quantity has been updated" << endl;
}

void Product::reduceStock(int amount)
{
	while (amount <= 0 || amount> quantity) {
		cout << "Please enter a valid quantity " << endl; //checking if the quantity provided by user is valid
		cin >> amount;
	}
	quantity -= amount;
	cout << "The amount has been updated";
}

bool Product::operator<(const Product& other) const
{
	if (this->price < other.price) {
		return true;
	}
	else if (this->price > other.price) {
		return false;
	}
	
}

bool Product::operator>(const Product& other) const
{
	if (this->price < other.price) {
		return false;
	}
	else if (this->price > other.price) {
		return true;
	}
}

bool Product::operator==(const Product& other) const
{
	if (this->productId == other.productId) {
		return true;
	}
	else
		return false;
	
}

bool Product::operator!=(const Product& other) const
{
	if (this->productId != other.productId) {
		return true;
	}
	else
		return false;
}

