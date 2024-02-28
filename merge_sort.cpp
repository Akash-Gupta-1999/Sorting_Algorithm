#include<bits/stdc++.h>
using namespace std;

vector<int> merger(vector<int> left,vector<int> right){
    vector<int> arr;
    int m = left.size();
    int n = right.size();
    int i =0, j = 0;
    while(i<m && j<n){
        if(left[i] < right[j]){
            arr.push_back(left[i]);
            i++;
        }
        else if(left[i] > right[j]){
            arr.push_back(right[j]);
            j++;
        }
        else{
            arr.push_back(left[i]);
            i++;
        }
    }
    while(i<m){
        arr.push_back(left[i]);
        i++;
    }
    while(j<n){
        arr.push_back(right[j]);
        j++;
    }
    return arr;
}

vector<int> merge_sort(vector<int>& a,int i,int j){
    if(i >= j){
        vector<int> ar;
        ar.push_back(a[i]);
        return ar;
    }
    int mid = i + (j-i)/2;
    return merger(merge_sort(a,i,mid),merge_sort(a,mid+1,j));
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
    a = merge_sort(a,0,a.size()-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}