#include<iostream>
#include<string>

using namespace std;

// Encapsulation
// Base class
class Item{
friend class Income;
public:
    // constructor
    Item(int x, string s, string des="Item"){
        purchase_price = price = x;
        purchase_date = s;
        description = des;
        cout << "create " << des << endl;
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
    void getdes(){
        cout << "Description: " << description << endl;
    }
protected:
    void getprofit(){
        cout << "Profit: " << price - purchase_price << endl;
    }
private:
    int price;
    int purchase_price;
    string purchase_date;
    string description;
};

// Friend classes
class Income{
public:
    bool checkprofit(Item i){
        if(i.price - i.purchase_price>=0){
            income = i.price - i.purchase_price;
            return true;
        }
        else
            return false;
    }  
    int getincome(){
        return income;
    }
private:
    int income;
};

// Inheritance
// Derived class
class ETF: public Item{
public:
    // constructor 
    ETF(int price, string date, string des="ETF", string code="VTI"): Item(price, date, des){
        // The keyword this names a pointer to the object 
        // for which an implicit object member function ([class.mfct.non.static]) is invoked 
        // or a non-static data member’s initializer ([class.mem]) is evaluated.
        this->code = code;
    }
    void getcode(){
        cout << "Code: " << code << endl;
    }
    void getprofitbyDerived(){
        getprofit();
    }
private:
    string code;
};

// Multiple Inheritance
// can be extend by using template (ex: ETF / Found / Bond)
class Strategies: public ETF, public Income{
public:
    Strategies(int price, string date, string des="ETF", string code="VTI"): ETF(price, date, des){
        totalprofit = 0; // init
    }
    void buy(ETF e, Income in){
        if(in.checkprofit(e)){
            cout << "buy the ";
            e.getcode();
            totalprofit += in.getincome();
        }
        else{
            cout << "Not now" << endl;
        }
    }
    void gettotalprofit(){
        cout << "Profit: " << totalprofit << endl;
    }
private:
    int totalprofit;
};


// Polymorphism


