#include <iostream>
using namespace std;

void firstLastOccurnce(int arr[],int n,int target){ //T.C = O(n)  S.C = O(1)
    int first = -1;
    int last= -1;
    for(int i = 0;i < n;i++){
        if(arr[i] == target){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }
    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl;
}
int main(){
    int arr[] = {1,2,2,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 2;
    firstLastOccurnce(arr,n,target);
    return 0;
}