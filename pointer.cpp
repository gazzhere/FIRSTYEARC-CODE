#include<iostream>
using namespace std;

int main(){
   int a=10;
   int *ptr;
   ptr=&a;
   int**q=&ptr;
   cout<<*q<<endl;
   cout<<**q<<endl;
   
}