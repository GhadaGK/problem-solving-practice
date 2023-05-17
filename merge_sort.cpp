#include <bits/stdc++.h>
using namespace std;

void display_array(int array[] , int array_size){
    for(int i = 0 ; i < array_size ; i++){
        if (i < array_size - 1) cout << array[i] << " " ;
        else if (i == array_size ) cout << array[i] ;
    }
}

void merge(int array[] , int begain , int mid , int end){
    int const ARRAY1 = mid - begain + 1 , ARRAY2 = end - mid ;
    int * sub_array_one = new int [ARRAY1], * sub_array_two = new int [ARRAY2] ;
    for(int i = 0 ; i < ARRAY1 ; i++ )  sub_array_one[i] = array[ i + begain] ; 
    for(int j = 0 ; j < ARRAY2 ; j++ )  sub_array_two[j] = array[ mid + 1 + j] ; 
    int index_sub_array_one = 0 , index_sub_array_two = 0 , index_merged_array = begain ;
    while(index_sub_array_one < ARRAY1 && index_sub_array_two < ARRAY2){
        if(sub_array_one[index_sub_array_one] < sub_array_two[index_sub_array_two]){
            array[index_merged_array] = sub_array_one[index_sub_array_one];
            index_sub_array_one++;
        }
        else{
            array[index_merged_array] = sub_array_two[index_sub_array_two];
            index_sub_array_two++;
        }
        index_merged_array++;
    }
    while(index_sub_array_one < ARRAY1 ){
        array[index_merged_array] = sub_array_one[index_sub_array_one];
        index_sub_array_one++;
        index_merged_array++;
    }
    while(index_sub_array_two < ARRAY2 ){
        array[index_merged_array] = sub_array_two[index_sub_array_two];
        index_sub_array_two++;
        index_merged_array++;
    }
}

void merge_sort(int array[] , int begain , int end ){
    if(begain >= end ) return;
    int mid = begain + (end - begain) / 2 ;
    merge_sort(array , begain , mid);
    merge_sort(array , mid + 1 , end );
    merge(array , begain , mid , end );
}

int main(){
    int array[] =  {38, 27, 43, 3, 9, 82, 10} ;
    int array_size = sizeof(array) / sizeof(array[0]) ;
    merge_sort(array , 0 , array_size - 1 );
    display_array(array , array_size);
    return 0 ;
}
