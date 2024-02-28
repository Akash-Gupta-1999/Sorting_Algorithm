#include<bits/stdc++.h>
using namespace std;

class trienode {
    public:
        trienode* ch[26];
        bool isend;
};

trienode* addnode(){
    trienode* newnode = new trienode;
    for(int i=0;i<26;i++)
        newnode->ch[i]=NULL;
    newnode->isend=false;
    return newnode;
}

class trie{
public:
    trienode* root;
    trie(){
       root = addnode();
    }
    void addword(string word){
        trienode* ptr = root;
        for(int i=0;i<word.size();i++){
            int num = word[i] - 'A';
            if(ptr->ch[num]==NULL){
                trienode* newnode = addnode();
                ptr->ch[num]=newnode;
            }
            ptr=ptr->ch[num];
        }   
        ptr->isend=true;
    }
    void search(string word){
        trienode* ptr = root;
        bool found = true;
        for(int i=0;i<word.size();i++){
            int num = word[i] - 'A';
            if(ptr->ch[num] == NULL){
                cout<<"Word Not found"<<endl;
                found=false;
                break;
            }
            ptr = ptr->ch[num];
        }
        if(found)
            if(ptr->isend == true)
                cout<<"Word is Present"<<endl;
            else
                cout<<"Word Not found"<<endl;
    }
    void remove(string word){
        trienode* ptr = root;
        for(int i=0;i<word.size();i++){
            int num = word[i] - 'A';
            ptr = ptr->ch[num];
        }
        ptr->isend=false;
    }
};

int main(){
    trie T;
    T.addword("CART");
    T.addword("CAR");
    T.remove("CART");
    T.search("CAR");
    return 0;
}