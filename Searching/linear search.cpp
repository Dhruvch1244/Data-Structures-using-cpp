// Created by cdrv
// complexity o(n) avg
#include <iostream>
#include <vector>
using namespace std;
bool linearsearch(vector<int>arr,int target){
    for(int i : arr){ // iterating in vector
        if(i == target){
            return true;
            break;
        }
    }
    return false;
}
int main(){
    vector<int>arr = {6,5,4,3,2,1};
    cout<<linearsearch(arr,0)<<endl;
    cout<<linearsearch(arr,3)<<endl;
    cout<<linearsearch(arr,1)<<endl;
    return 0;
}
