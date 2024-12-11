#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:

Product(const string& name, double price) : name(name), price(price) {}

string getName() const {
    return name;
}

void setName(const string& name) {
    this->name = name;
}

double getPrice() const {
    return price;
}

void setPrice(double price) {
    this->price = price;
}

virtual double getFinalPrice() const = 0;
virtual ~Product() {}
};


class Discountable {
public:
    virtual double applyDiscount(double price) const = 0;
    virtual ~Discountable() {}
};


class Book : public Product, public Discountable {
public:

Book(const string& name, double price) : Product(name, price) {}

double applyDiscount(double price) const override {
    return price * 0.9;
}

double getFinalPrice() const override {
    return applyDiscount(price);
}
};


class Pen : public Product, public Discountable {
public:

Pen(const string& name, double price) : Product(name, price) {}

double applyDiscount(double price) const override {
    return price > 5 ? price - 5 : price;
}

double getFinalPrice() const override {
    return applyDiscount(price);
}
};


int main() {

Product* book1 = new Book("C++ Programming", 200);
Product* book2 = new Book("Clean Code", 150);
Product* pen1 = new Pen("Pilot Pen", 20);
Product* pen2 = new Pen("Simple Pen", 4);
Product* products[] = { book1, book2, pen1, pen2 };

for (Product* product : products) {
    cout << product->getName() << endl;
    cout << "Базова ціна = " << product->getPrice() << endl;
    cout << "Кінцева ціна = " << product->getFinalPrice() << endl;
    cout << "--------------------" << endl;
}

for (Product* product : products) {
    delete product;
}

}
