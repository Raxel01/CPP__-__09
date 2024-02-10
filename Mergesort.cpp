#include <iostream> 
using namespace std; 
  
// Merges two subarrays of array[]. 
// First subarray is arr[begin..mid] 
// Second subarray is arr[mid+1..end] 
void merge(int array[], int const left,  
           int const mid, int const right) 
{ 
    size_t const subArrayOne = mid - left + 1; 
    size_t const subArrayTwo = right - mid; 

    int *leftArray = new int[subArrayOne], 
         *rightArray = new int[subArrayTwo];

    std::cout << "==============Leftarray================="<< std::endl;
    for (size_t i = 0; i < subArrayOne; i++){
        leftArray[i] = array[left + i];
        std::cout << leftArray[i]<< std::endl;
    }
    std::cout << "===============End======================"<< std::endl;

    std::cout << "==============rightarray================="<< std::endl;
    for (size_t j = 0; j < subArrayTwo; j++) {
        rightArray[j] = array[mid + 1 + j];
        std::cout << rightArray[j]<< std::endl;
    }

    std::cout << "===============End======================"<< std::endl;
    // Initial index of first sub-array 
    // Initial index of second sub-array 
    // size_t indexOfSubArrayOne = 0,  
    //        indexOfSubArrayTwo = 0;  
    
    // // Initial index of merged array 
    // size_t indexOfMergedArray = left;
  
    // // Merge the temp arrays back into  
    // // array[left..right] 
    // while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)  
    // { 
    //     if (leftArray[indexOfSubArrayOne] <=  
    //         rightArray[indexOfSubArrayTwo]) { 
    //         array[indexOfMergedArray] =  
    //         leftArray[indexOfSubArrayOne]; 
    //         indexOfSubArrayOne++; 
    //     } 
    //     else 
    //     { 
    //         array[indexOfMergedArray] =  rightArray[indexOfSubArrayTwo]; 
    //         indexOfSubArrayTwo++; 
    //     } 
    //     indexOfMergedArray++; 
    // } 
      
    // // Copy the remaining elements of 
    // // left[], if there are any 
    // while (indexOfSubArrayOne < subArrayOne)  
    // { 
    //     array[indexOfMergedArray] =  leftArray[indexOfSubArrayOne]; 
    //     indexOfSubArrayOne++; 
    //     indexOfMergedArray++; 
    // } 
  
    // // Copy the remaining elements of 
    // // right[], if there are any 
    // while (indexOfSubArrayTwo < subArrayTwo)  
    // { 
    //     array[indexOfMergedArray] =  
    //     rightArray[indexOfSubArrayTwo]; 
    //     indexOfSubArrayTwo++; 
    //     indexOfMergedArray++; 
    // } 
} 
  
// begin is for left index and end is 
// right index of the sub-array 
// of arr to be sorted */ 
void mergeSort(int array[], int const begin, int const end) 
{ 
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;


    mergeSort(array, begin, mid);//0 - 7
    mergeSort(array, mid + 1, end);//8 => 14
    merge(array, begin, mid, end);
} 
  
// UTILITY FUNCTIONS 
// Function to print an array 
void printArray(int A[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << A[i] << " "; 
    cout<<endl; 
} 
  #include <vector>

// Driver code 
int main() 
{ 
    int arr[] = { 7, 6, 5, 4, 3, 2, 1 , 8, 9 , 11 , 12, 13, 80, 19, 20};
                                 // |
                             // ---------
    // {7, 6, 5, 4, 3, 2, 1 , 8} |     {9,11 , 12, 13, 80, 19, 20}
            // -------                              |
              //  |                              =======
    // {{7, 6, 5, 4} => {3, 2, 1 , 8}       {9, 11, 12, 13} <=> {80, 19, 20}
    
    std::vector<int> ok;
    ok.push_back(1);
    ok.push_back(12);
    ok.push_back(18);
    ok.at(ok.size()-1);
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    std::cout << arr_size - 1<< std::endl;
    exit(0);
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "Sorted array is "<<endl; 
    printArray(arr, arr_size); 
    return 0; 
} 
