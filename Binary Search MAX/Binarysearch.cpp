//  You are given an array of integers. The array is guaranteed to be monotonically increasing up to some maximum, then monotonically decreasing until the end. For example:
//  {1, 3, 7, 9, 10, 4, 3, 2, 0, -1, -2, -3, -4, -1000}

/**
  This soultion is upper bounded by O(log n) since its a modified version of binary search.
  However this solution will not work well for cases where there are value repetitions.

  **/

#include <iostream>
using namespace std;

int getMiddle(int arr[], int left, int right){

    int mid = (left+right)/2;

    if (right>=left){

        if((right==left+1) && arr[left] >= arr[right])
        {
            return arr[left];
        }

        if((right==left+1) && arr[left] <= arr[right])
        {
            return arr[right];
        }

        else if (left==right)
        {
            return arr[left];
        }

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            return arr[mid];
        }

        if(arr[mid]>arr[mid+1] && arr[mid] <arr[mid -1])
        {
            return getMiddle(arr,left,mid-1);
        }

        if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1] )
        {
            return getMiddle(arr,mid+1,right);
        }
    }
    return -99999;


}


int main(){

    int arr[] ={1, 3, 7, 9, 10, 4, 3, 2, 0, -1, -2, -3, -4, -1000};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"The Max element is "<< getMiddle(arr,0,(size-1)) <<endl;
    return 0;


}
