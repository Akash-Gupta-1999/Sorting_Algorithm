#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& a,int i,int j){
    if(i>=j)
        return;
    int pivot = a[j];
    int ptr = i;
    for(int k=i;k<j;k++){
        if(a[k] < pivot){
            swap(a[k],a[ptr]);
            ptr++;
        }
    }
    swap(a[j],a[ptr]);
    quick_sort(a,i,ptr-1);
    quick_sort(a,ptr+1,j);
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
    quick_sort(a,0,a.size()-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}