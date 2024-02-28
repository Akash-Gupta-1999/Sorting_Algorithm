#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& a){
    for(int j=0;j<a.size()-1;j++){
        bool swapped = false;
        for(int i=0;i<a.size()-j-1;i++){
            if(a[i] > a[i+1]){
                swap(a[i],a[i+1]);
                swapped = true;
            }  
        }
        if(swapped == false)
            break;
    }
}

int main(){
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    bubble_sort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}