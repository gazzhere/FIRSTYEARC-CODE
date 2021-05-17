#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next =NULL;
    }
};
void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void insertattail(node* &head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<"NULL"<<endl;

}
bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deleteathead(node* &head){
    node* todelete= head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteathead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;

    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    
}
node* reversed(node*& head){
    node* prevptr=NULL;
    node* currentptr=head;
    node* nextptr;
    while(currentptr!=NULL){
        nextptr=currentptr->next;
        currentptr->next=prevptr;
        prevptr=currentptr;
        currentptr=nextptr;
    }
    return prevptr;
}
node*reverserecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead= reverserecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node* reverdedk(node* &head,int k){
    node* prevptr=NULL;
    node* currentptr=head;
    node* nextptr;
    int count=0;
    while(currentptr!=NULL && count<k){
        nextptr=currentptr->next;
        currentptr->next=prevptr;
        prevptr=currentptr;
        currentptr=nextptr;
        count++;

    }
    if(nextptr!=NULL){
    head->next=reverdedk(nextptr,k);
    }
    return prevptr;

}
void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!= NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool detectcycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast= fast->next->next;
        if(fast==slow){
            return true;
        }

    }
    return false;
}
void removecycle(node* &head){
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    


}


int main(){
    node* head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
  makecycle(head,4);
  // display(head);
   cout<<detectcycle(head)<<endl;
   removecycle(head);
   cout<<detectcycle(head)<<endl;
   display(head);
    

    return 0;



}