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
    
public:
    Node* head;
    Node* tail;
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
Node* splitHalf(Node* head){
    Node* sl=head;
    Node* fa=head;
    Node* prev=NULL;
    while(fa!=NULL&&fa->next!=NULL){
        prev=sl;
        sl=sl->next;
        fa=fa->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return sl;
}
Node* reverseHalf(Node* rHalf){
    Node* curr=rHalf;
    Node* prev=NULL;
    Node* nxt=NULL;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
void zigZagLL(Node* head){
    Node* half=splitHalf(head);
    Node* rHead=reverseHalf(half);
    //alternate linking
    Node* left=head;
    Node* right=rHead;
    Node* tail=right;
    while(left!=NULL&&right!=NULL){
        Node* leftNext=left->next;
        Node* rightNext=right->next;
        left->next=right;
        right->next=leftNext;
        tail=right;
        left=leftNext;
        right=rightNext;
    }
    if(right!=NULL){
        tail->next=right;
    }
}
int main(){
    List li;
    li.push_front(5);
    li.push_front(4);
    li.push_front(3);
    li.push_front(2);
    li.push_front(1);
    li.printLL();
    zigZagLL(li.getHead());
    li.printLL();
    return 0;
}