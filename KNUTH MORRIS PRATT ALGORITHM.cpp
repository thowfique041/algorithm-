#include<bits/stdc++.h>
using namespace std;
void lps(vector<int>&v,string s)
{
    int pre=0,suf=1;

//lsp
while (suf<s.size())
{
    if (s[suf]==s[pre]){
        v[suf]=pre+1;
        pre++;
        suf++;
    }
    else{
        if(pre==0){
            suf++;
        }
        else{
            pre=v[pre-1];
        }
    }
}
}
int main() {
string s,ss;
cin >> s>>ss;;
    vector<int>v(ss.size(),0);
    lps(v,ss);
    int i=0,j=0;
     //kmp
     while (i<s.size() && j<ss.size())
     {
        if (s[i]==ss[j])
        {
            i++;
            j++;
        }
        else{
            if(i==0)
            {
                j++;
            }
            else{
                i=v[i-1];
            }
        }
     }
     if(j==ss.size()) cout<<"Yes! find it"<<endl;
     else cout<<"Not found"<<endl;



}
