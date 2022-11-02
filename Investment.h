#include<iostream>
#include<string>

using namespace std;

// Encapsulation
// Item
class Item{
public:
    Item(int x, string s){
        purchase_price = price = x;
        purchase_date = s;
        cout << "create item" << endl;
    }
    void setprice(int newp){
        price = newp;
    }
    void getprice(){
        cout << "Price: " << price << endl;
    }
    void getpurprice(){
        cout << "Purchase Price: " << purchase_price << endl;
    }
    void getprofit(){
        cout << "Profit: " << price - purchase_price << endl;
    }
private:
    int price;
    int purchase_price;
    string purchase_date;
};

// to be cont...
// Inheritance
// Polymorphism
