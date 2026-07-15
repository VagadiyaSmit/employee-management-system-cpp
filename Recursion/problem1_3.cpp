// power function 
#include <iostream>
using namespace std;

int power(int x,int n){   // base case   // T.C = O(log n) S.C = O(log n)
    if(n == 0){
        return 1;
    }
    int halfPower = power(x,n/2); //divide problem in half
    if(n%2 == 0){
        return halfPower * halfPower;
    } else{
        return x * halfPower * halfPower;
    }
}
int main(){

    cout << power(2,10) << endl;
    return 0;
}