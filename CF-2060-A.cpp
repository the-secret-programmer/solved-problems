#include <iostream>
 
using namespace std;
 
int f[410];
 
 
int main()
{
 
 
    int t;
    cin>>t;
 
    for (int i = 1; i<=t; i++){
 
 
    int a,b;
    cin>>a;
    for (int i = 2; i<=4; i++){
        cin>>b;
 
        if(i==2){
            f[a+b+200]++;
        }
        else{
            f[b-a+200]++;
        }
        a=b;
 
 
    }
 
    int ans = 0;
    for (int i = 0; i<=405; i++){
        ans = max(ans,f[i]);
        f[i]=0;
    }
    cout<<ans<<'\n';
    }
 
    return 0;
}
