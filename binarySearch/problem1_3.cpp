//Search in rotated sorted array
#include <iostream>
using namespace std;

int searchInRotatedSortedArray(int arr[],int n,int target){ //T.C = O(log n)  S.C = O(1)
    int st = 0;
    int end = n-1;
    while(st <=end){
        int mid = st + (end - st)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[st] <= arr[mid]){
            if(target >= arr[st] && target < arr[mid]){
                end = mid -1;
            }else{
                st = mid +1;
            }
        }
        else{
            if(target > arr[mid] && target <= arr[end]){
                st = mid +1;
            }else{
                end = mid -1;
            }
        }
    }
    return -1;
}
int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int target = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << searchInRotatedSortedArray(arr,n,target) <<endl; 
    return 0;
}