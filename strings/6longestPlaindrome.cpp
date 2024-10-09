#include<bits/stdc++.h>
using namespace std;
string preprocess(const string& s) {
       string t;
       for(auto c: s) {
        t += string("#") + c;
    }
    t += "#";
    //cout<<t<<endl;
    return t;
}
// we have used the Manchers algorithm 
string longestPalindrome(const string& str) {
    string s = preprocess(str);
    int n = s.length();
    vector<int> p(n, 1); // initiall len = 1 
    int l = 0, r = 0; // left and right boundary of the current rightmost palindrome
    for (int i = 1; i < n ; ++i) {
        int mirr = l+(r- i); 
        p[i] = max(1,min(r - i, p[mirr]));  // when i is outside the right the boundry ir i>r then r-i will be negative 
       while ( i-p[i]>=0 && i+p[i]< n &&  s[i+p[i]] == s[i-p[i]]) {
            p[i]++;

        }
        if (i + p[i] > r) {  // new larger palindrome we got 
            l = i-p[i];
            r = i + p[i];
        }
    }
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
     string result;
    for (int i = centerIndex-maxLen+1; i <centerIndex+maxLen; ++i) {
            if (s[i] != '#') {
                result += s[i];
            }
    }
   return result;

   

}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}




// below is the imopimenstion of the leetcode anf gfg palindrome which is giving then tle 
// we have used the Manchers algorithm 



 /*string longestPalindrome(string s) {

      // optimal approach by changing the window size 
      int n = s.size();
      int start_index = 0;
      int max_len =0;
      // testing the odd length palindrome 
      for(int i=0;i<n;i++){
          int start = i-1;
          int end = i+1;
          while(start>=0 && end<n ){
              if(s[start ]==s[end]){
                  start--;
                  end++;
              }
              else
                break;

          }
          int window_len = end-start-1;
          if(max_len < window_len)
            start_index = start+1;
          max_len = max(max_len , window_len);
          

      }
      // testing even length palindrome 

      for(int i=0;i<n-1;i++){
          int start = i;
          int end = i+1;
          while(start>=0 && end<n){
              if(s[start]==s[end]){
                  start--;
                  end++;
              }
              else 
               break;
          }
           int window_len = end-start-1;
          if(max_len < window_len)
            start_index = start+1;
          max_len = max(max_len , window_len);
          
       
      }
        string ans = "";
        ans = s.substr(start_index , max_len);
        return ans;
    } */
 /*  string longestPalindrome(string s) {

       int n = s.size();
       vector<vector<bool>> dp(n, vector<bool>(n,false));
       string ans ="";
       int maxi = 0;

       for(int gap =0;gap<n; gap++ ){
           for(int i=0,j=gap ; j<n;i++,j++){

               if(gap==0){ // ie i==j 
                   dp[i][j] = true;
               }
               else if(gap==1){ // ie j==i+1
                      if(s[i]==s[j])
                        dp[i][j]=true;
               }
               else if(s[i]==s[j]) {
                   if(dp[i+1][j-1]== true){
                       dp[i][j]= true;
                   }

               }
               if(dp[i][j]== true){
                   int cur_len = j-i+1;
                   if(cur_len > maxi){
                       maxi = cur_len;
                       ans = s.substr(i,cur_len);
                   }
               }

           }
       }
       return ans ;
    }
int main(){
    string s;
    cin>>s;
    string temp = longestPalindrome(s);
    cout<<temp;
    return 0;
} */