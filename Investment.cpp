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
    // Polymorphism
    ETF e(10, "1993");
    e.getdes();
    e.getcode();
    e.setprice(20);
    e.getprofitbyDerived(); // access is successful bc get through derived class
    cout << in.checkprofit(e) << endl; // 0: false
    // create Trade Strategies
    Strategies s(10, "1993");
    s.buy(e, in);
    s.gettotalprofit();
}

