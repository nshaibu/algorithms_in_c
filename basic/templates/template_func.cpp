#include<iostream>
using namespace std;

template<typename T>
T genericMin(T a, T b) { return (a < b)? a : b;}

template<typename T>
T genericMax(T a, T b) { return (a > b)? a : b; }

int main(void) {
    cout << "Min of [12, 32]: " << genericMin(12, 32) << endl;
    cout << "Min of [10.233, 7.23]: " << genericMin(10.233, 7.23) << endl;
    cout << "Min of [a, b]: " << genericMin('a', 'b') << endl;
    
    cout << endl << endl;

    cout << "Max of [12, 32]: " << genericMax(12, 32) << endl;
    cout << "Max of [10.233, 7.23]: " << genericMax(10.233, 7.23) << endl;
    cout << "Max of [a, b]: " << genericMax('a', 'b') << endl;
    
    return 0;
}
