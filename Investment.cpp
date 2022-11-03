#include<iostream>
#include"investment.h"

using namespace std;

int main(){
    // crete base class
    Item i(5, "1992");
    i.getprice();
    i.getpurprice();
    i.setprice(15);
    i.getprofit(); // access failed bc it is protected 
    i.getdes();
    // create friend class
    Income in;
    cout << in.checkprofit(i) << endl; // 1: true
    // create derived class
    ETF e(10, "1993");
    e.getdes();
    e.getcode();
    e.setprice(20);
    e.getprofitbyDerived(); // access is successful bc get through derived class
    e.getprofit(); // override
    e.getprofit(true); // overload
    cout << in.checkprofit(e) << endl; // 0: false
    // create Trade Strategies
    Strategies s(10, "1993");
    s.buy(e, in);
    s.gettotalprofit();
    // Polymorphism     
    Item* poly = new ETF(10, "1995");
    poly->setprice(100);
    poly->getdate();
    poly->getprofit(); // failed bc it will access base first and then seek if another implement in derived class
    poly->getdes(); // remember to add virtual in base class if override & try to use polymorphism
}

