/**
A selection problem : Bridge Crossing

 If a boat crossing a river can hold 2 robots and a maximum weight of 150 lbs, what are the minimum number of boats needed, given a list of their weights represented as positive integers.

  **/


/**


Solution is upperbounded by O(n) ; sorting in-place using counting sort takes up O(n+k) which is lower than O(n)

Since we do not create a separate/intermediate array we are also space bounded by O(n)
**/

#include <iostream>
#include<string.h>

//To facilitate an O(n) non-comparison based sorting - we cap the weight range at 1001 . From 0 to 1000 lbs
#define RANGE 1001


//According to the problem. If more flexibility is desired this param could also be fed as an argument. For simplicity its a static variable.
#define MAX_WEIGHT 150  

using namespace std;
/**
 * @brief getNboats
 * @param array : the sorted input array.
 * @param lastpointer: The array index of the
 * @return the minimum number of boats required to transport robots
 *
 * O(n) - might go through all elements in worst case.
 */

void countSort(int arr[],int numelems)
{
    // The output character array that will have sorted arr
    int output[numelems];
 
    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
 
    // Store count of each character
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
 
    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}


static int getNboats(int array[],int size){
	
    if(size<=0){  //Boundary case test - bad input
      return 0;
    }

if(size==1 && array[0]<=150)  //Boundary case - if theres only one robot less than 150lbs
{
return 1;

}
else if(size==1 && array[0]>150){

return 0;

}


countSort(array,size);
int first = 0;
int result = 0;
int last = size-1;

//Case where there are odd number of robots the middle element cannot be paired.
if(size %2 !=0 && array[(size/2)]<=150)
{
	result++;
}


while(first<last){
    int sum =array[first] + array[last]; //calculate once and reutilize as sum
   
    if(sum <= MAX_WEIGHT){
   
        result++;
        last--;     //Last element consumed
        first++;    //First element consumed
    }
    else if(sum > MAX_WEIGHT)
    {
        last--;   // last element is too big, so lets move down a notch
    }
}
return result;
}


//Main

int main()
{

/**
      Test Cases

      We are testing with positive integers - according to the problem definition - i dont think negative weights apply here. 
      A separate discussion could be made for floating points which would require modification of the input argument types - for simplicity I've done it with ints. But floats are a good reason to get into polymorphic implementations.
      
      Change some of the test conditions to exercise all logic.
**/

int list1[] = {100,20,50,30};
int size1 = sizeof(list1)/sizeof(int);

//Empty case should return empty
int list2[] = {};
int size2 = sizeof(list2)/sizeof(int);

int list3[] = {1,23,54,1000,2};
int size3 = sizeof(list3)/sizeof(int);

int list4[] = {170}; //Nobody likes this guy.
int size4 = sizeof(list4)/sizeof(int);

int list5[] = {150};  //Forever alone.
int size5 = sizeof(list5)/sizeof(int);


cout<< "Number of boats for list 1 is :"<< getNboats(list1,size1) << endl;
cout<< "Number of boats for list 2 is :"<< getNboats(list2,size2) << endl;
cout<< "Number of boats for list 3 is :"<< getNboats(list3,size3) << endl;
cout<< "Number of boats for list 4 is :"<< getNboats(list4,size4) << endl;
cout<< "Number of boats for list 5 is :"<< getNboats(list5,size5) << endl;


return 0;
}


