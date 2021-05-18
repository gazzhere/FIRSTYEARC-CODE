#include<iostream>
using namespace std;
void swap(string s){
    if(s.length()==0){   //base case
        return;  
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        swap(s.substr(2));
    }else{
        cout<<s[0];
        swap(s.substr(1));
    }
}
int main(){
    swap("pipipipiipiiiiiiiiiiiiipiip");

}