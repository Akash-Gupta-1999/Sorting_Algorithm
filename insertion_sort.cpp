#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& a){
    int n = a.size();
    bool swapped = false;
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            swap(a[i],a[i+1]);
            swapped = true;
        }
        if(swapped == true){
            for(int j = i;j>0;j--){
                if(a[j-1] > a[j]){
                    swap(a[j-1],a[j]);
                }
                else
                    break;
            }
        }
        swapped = false;
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
    insertion_sort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}