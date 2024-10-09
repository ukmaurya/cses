#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<int> arr(n);
    const int maxNum = 1e6+1;
    vector<int> freq(maxNum,0); // stores the freq of each element
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++; // indexes are representing the element , we could use map but it take time ie logn 
    }
    vector<int> gcd(maxNum,0);
    for(int i=1;i< maxNum;i++){  // check weather a number divides atleast two elements
        for(int j=i; j< maxNum; j=j+i){ 
             if(freq[j]!=0){
                gcd[i] += freq[j];  // i divides freq[j] numbers 
             }
        }
    }
    
    int ans = 1;
    for(int i=1;i<maxNum;i++){
        if(gcd[i]>=2){ // for becoming gcd it has to divide atleast 2 ele
            ans = i;
        }
    }
  cout<<ans<<endl;
   
   

}