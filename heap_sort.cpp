#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int k,int n){
    int large = k;
    int left = 2*k + 1;
    int right = 2*k + 2;
    if(left<n && a[large] < a[left])
        large = left;
    if(right<n && a[large] < a[right])
        large = right;
    if(large!=k){
        swap(a[large],a[k]);
        heapify(a,large,n);
    }
}

void heap_sort(vector<int>& a,int i,int j){
    int n = a.size();
    for(int k = (n/2) - 1;k>=0;k--)
        heapify(a,k,n);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
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
    heap_sort(a,0,a.size()-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}