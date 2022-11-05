#include<iostream>

using namespace std;

// basic usage: class template
template <class T1, class T2, class T3=int>
class TwoInt{
public:
    TwoInt(T1 n1, T2 n2){
        num1 = n1;
        num2 = n2;
    }
    T3 sum(){
        return num1 + num2;
    }
private:
    T1 num1;
    T2 num2;
};

// basic usage:  class template partial specialization
template<class T>
class TwoInt<double, double, T>{
public:
    TwoInt(double n1, double n2){
        num1 = n1;
        num2 = n2;
    }
    T sum(){
        return num1 + num2;
    }
private:
    double num1;
    double num2;
};

// basic usage:  class template specialization
template<>
class TwoInt<double, double, float>{
public:
    TwoInt(double n1, double n2){
        num1 = n1;
        num2 = n2;
    }
    float sum(){
        return (num1 + num2)*2;
    }
private:
    double num1;
    double num2;
};

// futher usage: class template inhiretance
template <class T>
class Base{
public:
    void setNum(T n){
        num = n;
    }
    void print(){
        cout << num << " from Base" << endl;
    }
private:
    T num;
};

template <class T>
class Derived: public Base<T>{
public:
    void setNum(T n){
        Base<T>::setNum(n);
    }
    void print(){
        cout << num << " from Derived" << endl;
    }
private:
    T num;
};

int main(){
    // basic usage: class template
    TwoInt<int, int> t1(3.3,4.6); // will be cast to int
    cout << t1.sum() << endl; // 3 + 4 = 7 
    TwoInt<float, float, float> t2(3.3,4.6);
    cout << t2.sum() << endl; // 3.3 + 4.6 = 7.9 
    TwoInt<float, float> t3(3.3,4.6);
    cout << t3.sum() << endl; // 3.3 + 4.6 = 7.9 -> 7 (default: int)
    // basic usage:  class template partial specialization
    TwoInt<double, double, int> t4(3.3,4.6);
    cout << t4.sum() << endl; // 3.3 + 4.6 = 7.9 -> 7
    // basic usage:  class template specialization
    TwoInt<double, double, float> t5(3.3,4.6);
    cout << t5.sum() << endl; // (3.3 + 4.6)*2 = 15.8
    // class template inheritance
    Derived<float> d;
    d.setNum(6.6);
    d.print(); // Expected: 6.6 from Derived / Actual: 0 from Derived => bc we use the setNum() in Base so that the num in Derived is not set
    d.Base::print(); // 6.6 from Base
    return 0;
}
