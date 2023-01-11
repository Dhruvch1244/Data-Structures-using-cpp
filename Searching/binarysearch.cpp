//
// Created by cdrv on 1/11/23.
//
#include <iostream>
#include <vector>
using namespace std;
bool binarysearch(vector<int>arr,int target,int high,int low){
    if(high>=low) {
        int med = (low + high) / 2;
        if (target == arr[med]) {
            return true;
        }
        if (arr[med] > target) {
            high = med - 1;
            return binarysearch(arr, target, high, low);
        }
        if (arr[med] < target) {
            low = med + 1;
            return binarysearch(arr, target, high, low);
        }
    }
    return false;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6};
    int low = 0,high = arr.size()-1;
    int med = (low+high)/2;
    cout<<binarysearch(arr,3,high,low)<<endl;
    cout<<binarysearch(arr,10,high,low)<<endl;
    cout<<binarysearch(arr,1,high,low)<<endl;
    return 0;
}
