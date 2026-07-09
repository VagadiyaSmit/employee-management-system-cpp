//classical binary search algorithm
#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){  //T.C = O(log n)  S.C = O(1)
    int st = 0;
    int end = n-1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(arr[mid] == target){
            cout << "Element found at index " << mid << endl;
            return mid;
        }
        else if(arr[mid] < target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
    }
    cout << "Element not found" << endl;
    return -1;
}
int main(){
    int arr[] = {1,3,5,7,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 123;
    cout << binarySearch(arr,n,target) << endl;
    return 0;
}