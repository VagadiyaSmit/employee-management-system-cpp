#include <iostream>
#include <vector>
using namespace std;                            //total T.C = O(n)  S.C = O(n) 

vector <int> buildPrefix (vector<int>& arr){    //  T.C = O(n)   S.C = O(n)
    int n = arr.size();
    vector <int> prefix(n);

    prefix[0] = arr [0];
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}
int rangeSum(vector <int>& prefix,int l,int r){  // T.C = O(1)  S.C  = O(1)
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
int main(){
    vector <int> arr = {3,1,4,1,5};
    vector <int> prefix = buildPrefix(arr);

    //queries : [0,2],[1,3],[2,4]
    cout << rangeSum(prefix,0,2) << endl;
    cout << rangeSum(prefix,1,3) << endl;
    cout << rangeSum(prefix,2,4) << endl;


    return 0;
}