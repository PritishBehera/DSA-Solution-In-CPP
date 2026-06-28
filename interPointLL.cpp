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
    Node* getTail(){
        return tail;
    }
};
Node* makeConnect(Node* head1, Node* tail2){
    Node* ptr=tail2;
    tail2->next=head1->next->next;
    return ptr;
}
Node* findPoint(Node* head1,Node* head2){
    unordered_map<Node*,int> mp;
    while(head1!=NULL){
        mp[head1]++;
        head1=head1->next;
    }
    while(head2!=NULL){
        if(mp.find(head2)==mp.end()){
            head2=head2->next;
        }else{
            return head2;
        }
    }
    return NULL;
}
int main(){
    List li;
    li.push_front(5);
    li.push_front(6);
    li.push_front(7);
    li.push_front(8);
    li.printLL();
    List li2;
    li2.push_front(4);
    li2.push_front(3);
    li2.push_front(2);
    li2.push_front(1);
    li2.printLL();
    Node* ptr=makeConnect(li.getHead(),li2.getTail());
    Node* liPoint=findPoint(li.getHead(),li2.getHead());
    cout<<liPoint->data;
    ptr->next=NULL;
    return 0;
}