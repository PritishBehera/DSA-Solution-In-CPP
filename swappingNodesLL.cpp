#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    friend class List;

    Node(int value){
        data=value;
        next=NULL;
    }
    ~Node(){
        delete next;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
    void push_front(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next = head;
            head=newNode;
        }
    }
    void push_back(int value){
        Node* newNode= new Node(value);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void pop_front(){
        Node* temp=head;
        if(head==NULL){
            cout<<"empty LL";
            return;
        }
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node* temp=head;
        if(tail==NULL){
            cout<<"empty ll";
            return;
        }
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        tail=temp;
        tail->next=NULL;
        temp=temp->next;
        delete temp;
    }
    void printLL(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void reverseLL(){
        Node* prev=NULL;
        Node* curr=head;
        Node* nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
    }
    Node* getHead(){
        return head;
    }
};
void swap2Nodes(List& li,int x,int y){
    Node* prev1;
    Node* prev2;
    Node* curr1;
    Node* curr2;
    Node* temp=li.getHead();
    for(int i=1;temp!=NULL&&i<=y;i++){
        if(i==x-1){
            prev1=temp;
        }
        else if(i==x){
            curr1=temp;
        }
        else if(i==y-1){
            prev2=temp;
        }
        else if(i==y){
            curr2=temp;
        }
        temp=temp->next;
    }
    Node* nxt=curr1->next;
    Node* nxt2=curr2->next;
    prev1->next=curr2;
    curr2->next=nxt;
    prev2->next=curr1;
    curr1->next=nxt2;
}
int main(){
    List li;
    for(int i=1;i<7;i++){
        li.push_back(i);
    }
    li.printLL();
    int x=2,y=4;
    swap2Nodes(li,x,y);
    li.printLL();
    return 0;
}