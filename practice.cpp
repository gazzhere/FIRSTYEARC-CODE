#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }

};
void insert(node* &head,int val){
    node*n =new node(val);
    if(head==NULL){
        head=n;
        return;
    }
   node* temp=head;
   if(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=n;
}
void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
node*reversed (node* &head)
{
    node* prev=NULL;
    node* currentptr=head;
    node* nextptr;
    while(currentptr!=NULL){
        nextptr=currentptr->next;
        currentptr->next=prev;
        prev=currentptr;
        currentptr=nextptr;
    }
    return prev;
    
}
int main(){

   node* head=NULL;
   insert(head,1);
   insert(head,2);
   insert(head,3);
   display(head);
   node* newhead=reversed(head);
   display(newhead);

}