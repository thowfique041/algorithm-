#include <bits/stdc++.h>
using namespace std;

const int n = 1000;

int c[n][n], k[n][n];

int main() {
    int a;
    cout<<"number of matrix : ";
    cin>>a;
    cout<<"Dimension of all matrix : ";
    int d[n];
    int j=0;
    for (int i = 0; i < 2*a; i++)
    {
        int x;
        cin>>x;
        if(i%2==0 or i==(2*a-1))
        {
            d[j]=x;
            j++;
        }

    }
    

    for (int s = 2; s <= a ; s++) {
        for (int i = 1; i <= a - s + 1; i++) {
            int j=i+s-1;
            int m=INT_MAX;
            int l;
            for (l = i; l < j; l++) {
                int x= (c[i][l]+c[l+1][j]+d[i-1]*d[l]*d[j]);
                if(m>x){
                    k[i][j]=l;
                }
                m= min(x,m);
                
            }
            c[i][j]=m;
            
        }
    }
    cout<<"min multiplication is : "<< c[1][a]<<endl;
    cout<<"minimum cost array is : "<<endl;
    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= a; j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"array of k is : "<<endl;
    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= a ; j++) { 
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
