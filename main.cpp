/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: abdelrhman
 *
 * Created on March 28, 2017, 11:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*
 * 
 */

void binarysearch( int numbers[] , int to_search_for, int start , int last)
{
    
    //cout << "Function called" << " Start is " << start << " End is " << last << " Number is " << to_search_for << endl;
    int mid ;
    mid = (start+last)/2;
    
    //cout << "Mid index is: " << mid << " Number at it is : " << numbers[mid] <<endl ;
    if (numbers[mid] == to_search_for)
    {
        cout <<"Number was found: at index: " << mid+1 <<endl;
    }
    else if (mid == start || mid == last)
    {
        cout << "NOT FOUND" <<endl;
    }
    else if (numbers[mid] < to_search_for)
    {
        binarysearch(numbers,to_search_for,mid,last);
    }
    else if (numbers[mid] > to_search_for )
    {
        binarysearch(numbers,to_search_for,start,mid);
    }
   
    
    
}

void binarysearch2( vector<int> &numbers , int to_search_for, int start , int last)
{
    
    //cout << "Function called" << " Start is " << start << " End is " << last << " Number is " << to_search_for << endl;
    int mid ;
    mid = (start+last)/2;
    
    //cout << "Mid index is: " << mid << " Number at it is : " << numbers[mid] <<endl ;
    if (numbers.at(mid) == to_search_for)
    {
        cout <<"Number was found: at index: " << mid+1 <<endl;
    }
    else if (mid == start || mid == last)
    {
        cout << "NOT FOUND" <<endl;
        numbers.insert(numbers.begin()+mid,to_search_for);
        
        
    }
    else if (numbers.at(mid) < to_search_for)
    {
        binarysearch2(numbers,to_search_for,mid,last);
    }
    else if (numbers.at(mid) > to_search_for )
    {
        binarysearch2(numbers,to_search_for,start,mid);
    }
   
    
    
}

int main(int argc, char** argv) {
    
    int numbers [] = {2,8,23,44,56,88,90,767,999,1002};
    vector<int>  num (numbers, numbers+10) ;
    int to_search_for = 0 , last_idx=10;
    cout << "Please enter a number to search for" <<endl;
    cin >> to_search_for;
    //binarysearch(numbers,to_search_for,0 , 10);
    binarysearch2(num,to_search_for,0 , 10);
    
    for (int i = 0 ; i < num.size() ; i++)
        {
            cout << num.at(i) << " , ";
        }
    //cin.get();
    return 0;
}

