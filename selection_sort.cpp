#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        int min = a[i];
        int pos = i;
        for(int j = i+1;j<n;j++){
            if(min > a[j]){
                min = a[j];
                pos = j;
            }
        }
        swap(a[i],a[pos]);
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
    selection_sort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}