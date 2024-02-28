#include<bits/stdc++.h>
using namespace std;

int s[32];
int a[8] = {3,8,7,6,-2,-8,4,9};

void build(int n, int l, int r){
    if(l == r)
        s[n] = a[l];
    else{
        int mid = (l +  r)/2;
        build(2*n + 1,l,mid);
        build(2*n + 2,mid + 1,r);
        s[n] = s[2*n + 1] + s[2*n + 2];
    }
}

int sum(int n,int low, int high, int l,int r){
    if(low>=l && high<=r )
        return s[n];
    else if(low > r || high < l)
        return 0;
    else{
        int mid = (low + high)/2;
        return sum(2*n + 1,low,mid,l,r) + sum(2*n + 2,mid + 1,high,l,r);
    }
}

void update(int n,int l,int r,int id,int num){
    if(l == id && r == id)
        s[n] = num;
    else{
        int mid = (l + r)/2;
        if(l <= id && mid>= id )
            update(2 * n + 1,l,mid,id,num);
        else
            update(2 * n + 2,mid + 1,r,id,num);
        s[n] = s[2*n + 1] + s[2*n + 2];
    }
}

int main(){
    build(0,0,7);
    for(int i=0;i<15;i++)
        cout<<s[i]<<" ";
    cout<<endl<<sum(0,0,7,1,5)<<endl;
    update(0,0,7,1,100);
    for(int i=0;i<15;i++)
        cout<<s[i]<<" ";
}