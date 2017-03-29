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
#include <cstdlib>
#include <ctime>
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

void binarysearch2( vector<int> &numbers , int to_search_for, int start , int last, int min , int &num_of_comp)
{
    
    //cout << "Function called" << " Start is " << start << " End is " << last << " Number is " << to_search_for << endl;
    int mid ;
    mid = (start+last)/2;
    if (to_search_for < numbers.at(0))
    {
        num_of_comp = num_of_comp+ 1;
        numbers.insert(numbers.begin(),to_search_for);
    }
    else if (to_search_for > numbers.at(numbers.size()-1)) 
    {
        num_of_comp = num_of_comp+ 1;
        numbers.push_back(to_search_for);
    }
    
    //cout << "Mid index is: " << mid << " Number at it is : " << numbers[mid] <<endl ;
    else
    {
        if (numbers.at(mid) == to_search_for)
        {
            num_of_comp = num_of_comp+ 1;
            cout <<"Number was found: at index: " << mid+1 <<endl;
        }
        else if (mid == start || mid == last)
        {
            //cout << "NOT FOUND" <<endl;        
            numbers.insert(numbers.begin()+min,to_search_for);

        }
        else if (numbers.at(mid) < to_search_for)
        {
            num_of_comp = num_of_comp+ 1;
            binarysearch2(numbers,to_search_for,mid,last,min,num_of_comp);
        }
        else if (numbers.at(mid) > to_search_for )
        {
            num_of_comp = num_of_comp+ 1;
            min = mid;
            binarysearch2(numbers,to_search_for,start,mid,min,num_of_comp);
        }
    }
    
    
}

int main(int argc, char** argv) {
    
    int numbers [] = {2,8,23,44,56,88,90,767,999,1002};
    vector<int>  num (numbers, numbers+10) ;
    vector<int>  num2 ;
    for (int i = 0 ; i < 300 ; i +=3)
    {
        srand(time(NULL));
        int temp = rand() % 1000 + i;
        num2.push_back(temp);
    }
    
    int to_search_for = 0 , min_idx=10, num_of_comp =0;
    
    for (int i = 0 ; i < num2.size() ; i++)
        {
            cout <<  i+1 << ")" << num2.at(i) << endl;
        }
    
    cout << "Please enter a number to search for" <<endl;
    cin >> to_search_for;
    cout << "\n";
    binarysearch2(num2,to_search_for,0 , num2.size() , min_idx,num_of_comp);
    
   for (int i = 0 ; i < num2.size() ; i++)
        {
            cout << i+1 << ")" << num2.at(i) << "\n";
        }
    cout << "\nIt took " << num_of_comp << " Comparisons to find the place";
    return 0;
}

