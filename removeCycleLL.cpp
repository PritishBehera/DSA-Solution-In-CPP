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
    void makeCycle(){
        tail->next=head;
    }
};
void removeCycle(Node* ptr){
    Node* fa=ptr;
    Node* sl=ptr;
    while(fa!=NULL&&fa->next!=NULL){
        sl=sl->next;
        fa=fa->next->next;
        if(sl==fa){
            break;
        }
    }
    if(fa==NULL||fa->next==NULL){cout<<"no loop"; return;}
    sl=ptr;
    while(sl!=fa){
        sl=sl->next;
        fa=fa->next;
    }
    while(fa->next!=sl){
        fa=fa->next;
    }
    fa->next=NULL;
    cout<<"cycle removed";
}
int main(){
    List li;
    li.push_front(1);
    li.push_front(8);
    li.push_front(2);
    li.push_front(1);
    li.printLL();
    li.makeCycle();
    removeCycle(li.getHead());
}