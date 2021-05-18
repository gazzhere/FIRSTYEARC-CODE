#include<iostream>
using namespace std;
void revrse(string s){
    if(s.length()==0){
        return;
    }
    string ros=s.substr(1);
    revrse(ros);
    cout<<s[0];
}
int main(){
    revrse("ganesh"); 
}