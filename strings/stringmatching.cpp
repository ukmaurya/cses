#include<bits/stdc++.h>
using namespace std;
vector<int> calLPS(string pat){
        int n = pat.size();
        vector<int> lps(n,0);
        int prefix = 0;
        int suffix = 1;
        while(suffix<n){
            if(pat[prefix]==pat[suffix]){
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            }
            else{
                if(prefix==0){
                    lps[suffix]=0;
                    suffix++;
                }
                else{
                    prefix = lps[prefix-1];
                }
            }
        }
        return lps;
    }
int main(){
    string txt , pat;
    cin>>txt>>pat;
     vector<int> lps = calLPS(pat);
            
            // using KMP
            int n = txt.size();
            int m = pat.size();
            vector<int> ans;
            int t=0; // pointer of text
            int p=0;
            while(t<n){
               
                if(txt[t]==pat[p]){
                    t++;
                    p++;
                  if(p==m){
                    ans.push_back(t-p+1); // one based indexing 
                    
                    p=lps[p-1];
                  }
                }
                else{
                    if(p==0){
                        t++;
                    }
                    else{
                        p= lps[p-1];
                    }
                }
                
            }
            
            cout<<ans.size();
            return 0;
}