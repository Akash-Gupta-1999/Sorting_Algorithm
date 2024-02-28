#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int num;
    node* next;
};

class link{
public:
    node* start;
    node* end;
    int size;
    link(){
        start=NULL;
        end=NULL;
        size=0;
    }
    void append(int num){
        node* newnode = new node;
        newnode->next=NULL;
        newnode->num = num;
        if(end == NULL){
            start = newnode;
            end = newnode;
        }
        else{
            end->next = newnode;
            end = newnode;
        }  
        size++;
    }
    void prepend(int num){
        node* newnode = new node;
        newnode->next=NULL;
        newnode->num = num;
        if(end == NULL){
            start = newnode;
            end = newnode;
        }
        else{
            newnode->next = start;
            start = newnode;
        }
        size++;
    }
    void print(){
        node* tr = start;
        while(tr!=NULL){
            cout<<tr->num<<" -> ";
            tr = tr->next;
        }
    }
    void insert(int num,int pos){
        if(pos - 1 > size){
            cout<<num<<" cannot be inerted at position "<<pos<<endl;
            return;
        }
        if(pos == 1){
            prepend(num);
            return;
        }
        if(pos == size + 1){
            append(num);
            return;
        }
        node* fr = start;
        node* bk = start;
        while(pos != 1){
            bk=fr;
            fr = fr->next;
            pos--;
        }
        node* newnode = new node;
        newnode->next=fr;
        newnode->num = num;
        bk->next=newnode;
    }
    void reverse(){
        if(start == NULL)
            return;
        end = start;
        node* front = start->next;
        node* back = NULL;
        while(front!=NULL){
            start->next = back;
            back=start;
            start=front;
            front=front->next;
        }
        start->next=back;
    }
};

int main(){
    link l;
    l.prepend(4);
    l.prepend(6);
    l.append(15);
    l.append(24);
    l.prepend(77);
    l.insert(144,1);
    l.insert(167,7);
    l.insert(177777,16);
    l.insert(92,4);
    l.insert(99,7);
    l.print();
    l.reverse();
    cout<<endl;
    l.print();
    return 0;
}