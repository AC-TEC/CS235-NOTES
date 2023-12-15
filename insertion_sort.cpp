//!INSERTION SORT

/*

YT: https://www.youtube.com/watch?v=PEhwXHEPbmI 


Header: No additional header needed

declare: insertionSort(datatype arr[array] , int size)

Algorithm:
    start at the second position in the array
    compare that to the element to the left position
    if the element in the second position is than the element to the left position them move the left poition to the right and insert the element in the second position to the left
    repreat 



*/

//!tip when you see [] next to a variable that means the value of that variable not the position in the array. 
//!so arr[i] means the value at position i same with j[]
//! if you see i-1 or j = i etc it means the position(index) at i not value at i

#include <iostream>

//algoritm
void insertionSort(int arr[], int size){
    //itertate through the array starting at 2nd position(i = 1);
    for(int i = 1; i < size; i++){  
        //make variables that keep our position in the array when sorting
        int key = arr[i]; //key stores value of arr[i] 
        int j = i-1; // j stores the index i-1         
    
        while(j >= 0 && arr[j] > key){ //while j index is greater than or 0 and the value at arr[j] greater than the value stored in key
            arr[j+1] = arr[j]; //the arr[i+1] will now store the value at arr[j] 
            j = j-1; //j will now store the position j-1  
        }
        arr[j + 1] = key; //arr[j+1] will now store the key which means it will store the value in key 
    }
}

int main(){
    int arr[] = {8,2,1,4,5,6,3,7};
    int size = 8;

    insertionSort(arr,size);

    for (int i = 0; i < size;i++){
        std::cout << "[" << i << "]" << " = " << arr[i] << std::endl;
    }

}