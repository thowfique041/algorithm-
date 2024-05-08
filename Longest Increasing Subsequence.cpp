#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct vec {
    int a;
    int l;
    int p;
};

int main() {
    int n;
    cin >> n;
    vector<vec> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i].a;
        v[i].l=1;
        v[i].p=-1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
    {      
        if(v[j].a<v[i].a and v[j].l>=v[i].l)
        {
            v[i].l=v[j].l+1;
            v[i].p=j;

        }
    }
    }
    int j;
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(v[i].l>m)
        {
            m=v[i].l;
            j=i;
        }
    }
    vector<int>b;
    
    while(j!=-1)
    {
      b.push_back( v[j].a);
      
       j=v[j].p;
       
    }
    reverse(b.begin(),b.end());
  for(auto i : b)
  {
    cout<<i<<" ";
  }
    

    

    return 0;
}
