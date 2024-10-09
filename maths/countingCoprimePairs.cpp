#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
const int n = 1e6+10;

int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<vector<int>> primeDivisors(n);
    for(int i=2;i<n;i++){
        if(primeDivisors[i].size()==0){ // i is prime 
            // primeDivisors[i].push_back(i);
           for(int j=i;j<n;j+=i){
               primeDivisors[j].push_back(i);
           }
        }
    }

    int in;
    cin>>in;
    vector<int> arr(in);
    for(int i=0;i<in;i++){
        cin>>arr[i];
    }
    
    // go to each array element and see what are its prime divisors 
    vector<int> eleDiv(n,0);
    vector<int> no_of_prime_div(n,0);
    for(int i=0;i<in;i++){
           int size = primeDivisors[arr[i]].size();
        for(int mask=1;mask<(1<<size);mask++){ // generate all combination(subsets) of prime divisors of gcd
             int combination = 1;
            for(int pos = 0;pos<size ;pos++){
                 if(mask&(1<<pos)){
                    combination = combination*primeDivisors[arr[i]][pos];
                 }
            }
             eleDiv[combination]++; // array element is div by this combination of prime divisors 
             no_of_prime_div[combination] = __builtin_popcount(mask);

        }
     }

     ll ans = 0; // allpair -  pairs with gcd != 1
     ll allPairs =  in*1LL*(in-1)/2;
     ll validPairs = 0; // pairs with gcd != 1
     // using the inlcusion and exclusion principle 
     for(int i=0;i<n;i++){
        if(no_of_prime_div[i]&1){ // odd 
          validPairs += eleDiv[i]*1LL*(eleDiv[i]-1)/2; //pairs = nC2
        }
        else{
           validPairs -= eleDiv[i]*1LL*(eleDiv[i]-1)/2;
        }
     }
     ans = allPairs - validPairs;
     cout<<ans <<endl;
     

 return 0;
}