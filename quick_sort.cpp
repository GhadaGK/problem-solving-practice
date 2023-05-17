#include <bits/stdc++.h>
using namespace std;

void display_array(int array[] , int array_size){
    for(int i = 0 ; i < array_size ; i ++ ){
        if(i < array_size -1)
            cout << array[i] << " " ;
        else if(i == array_size -1)
            cout << array[i] ;
    }
}

int partition(int array [] , int low , int high){
    int pivot = array[high];
    int i = low - 1;
    for(int j = low ; j <= high - 1 ; j++){
        if(array[j] < pivot){
            i++;
            swap(array[i] , array[j]);
        }
    }
    swap(array[i+1] , array[high]);
    return i+1;
}


void quick_sort(int array[] , int low , int high){
    if(low < high){
        int pivot = partition(array , low , high );
        quick_sort(array , low , pivot -1 );
        quick_sort(array , pivot + 1 , high);
    }
}

int main(){
    int array[] = {10 , 80, 30, 90 , 40 , 50 , 70 };
    int array_size = sizeof(array) / sizeof(array[0]);
    quick_sort(array , 0 , array_size -1);
    display_array( array, array_size );
    return 0 ;
}
