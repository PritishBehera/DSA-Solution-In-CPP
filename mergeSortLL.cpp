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
Node* merge(Node* left, Node* right){
    Node* resHead;
    Node* resTail;
    if(left==NULL) return right;
    if(right==NULL) return left;
    if(left->data>right->data){
        resHead=resTail=right;
        right=right->next;
    }else{
        resHead=resTail=left;
        left=left->next;
    }
    while(left!=NULL&&right!=NULL){
        if(left->data>right->data){
            resTail->next=right;
            right=right->next;
        }else{
            resTail->next=left;
            left=left->next;
        }
        resTail=resTail->next;
    }
    while(left!=NULL){
        resTail->next=left;
        left=left->next;
        resTail=resTail->next;
    }
    while(right!=NULL){
        resTail->next=right;
        right=right->next;
        resTail=resTail->next;

    }
    return resHead;
}
Node* mergeSort(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* rHead=splitHalf(head);
    Node* left=mergeSort(head);
    Node* right=mergeSort(rHead);
    return merge(left,right);
}

int main(){
    List li;
    li.push_front(1);
    li.push_front(8);
    li.push_front(2);
    li.push_front(1);
    li.printLL();
    li.head=mergeSort(li.getHead());
    li.printLL();
    return 0;
}