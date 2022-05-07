// PRATA - Roti Prata
// https://www.spoj.com/problems/PRATA/
// USING BINARY SEARCH

#include<iostream>

using namespace std; 

bool isPossible(int p, int cook[], int n, int mid){
    int cnt=0;
    for(int i=0; i<n; i++){
        int c=0, time=mid, perpratas=cook[i];
        while(time>0){
            time=time-perpratas;
            if(time>=0){
                c+=1;
                perpratas+=cook[i];
            }
        }
        cnt+=c;
        if(cnt>=p)
            return true;
    }
    return false;
}

int minTime(int p, int cook[], int n){
    int s=0, e=INT_MAX, mid, ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(isPossible(p, cook, n, mid)){
            ans=mid;
            e=mid-1;
        }else
            s=mid+1;
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int p, n;
        cin>>p >>n;
        int cook[n];
        for(int i=0; i<n; i++)
            cin>>cook[i];
        cout<< minTime(p, cook, n)<< endl;
    }
}
