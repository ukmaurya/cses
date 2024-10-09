#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> div(1e6+1,0);
    for(int i=1;i<=1e6+1;i++){
        for(int j=i;j<=1e6+1;j+=i){  // time = o(n*logn)
            if(j%i==0){
                div[j]++;
            }
        }
    }
    while(n--){
        int x;
        cin>>x;
        cout<<div[x]<<endl;

    }
    return 0;
}