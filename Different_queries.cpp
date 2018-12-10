#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct ty
{
    ll l;
    ll r;
    ll x;
}t1[100001],t2[100001],t3[100001],t4[100001];
bool compare(ty a,ty b)
{
    return a.x<b.x;
}
int main()
{
    ll n;
    ll a[501];
    ll l,r,x;
    ll q;
    ll i,j,ty;
    cin>>n>>q;
    for(i=1;i<=n;i++) 
        cin>>a[i];
    ll s1,s2,s3,s4;
    s1=s2=s3=s4=0;
    while(q--)
    {
        cin>>ty>>l>>r>>x;
        
        if(ty==1)
        {
            if(x>0)
            {
                t2[s2].l=l;
                t2[s2].r=r;
                t2[s2].x=x;
                s2++;
            }
            else
            {
                t1[s1].l=l;
                t1[s1].r=r;
                t1[s1].x=x;
                s1++;
            }
        }
        else
        {
             if(x>0)
            {
                t4[s4].l=l;
                t4[s4].r=r;
                t4[s4].x=x;
                s4++;
            }
            else
            {
                t3[s3].l=l;
                t3[s3].r=r;
                t3[s3].x=x;
                s3++;
            }
        }
    }
    sort(t1,t1+s1,compare);
    sort(t2,t2+s2,compare);
    sort(t3,t3+s3,compare);
    sort(t4,t4+s4,compare);
    for(i=0;i<s1;i++)
    {
        for(j=t1[i].l;j<=t1[i].r;j++)
        {
            a[j] = a[j] + t1[i].x;
        }
    }
    for(i=0;i<s3;i++)
    {
        for(j=t3[i].l;j<=t3[i].r;j++)
        {
            a[j] = t3[i].x;
        }
    }
    
    for(i=0;i<s4;i++)
    {
        for(j=t4[i].l;j<=t4[i].r;j++)
        {
            a[j] = t4[i].x;
        }
    }
    for(i=0;i<s2;i++)
    {
        for(j=t2[i].l;j<=t2[i].r;j++)
        {
            a[j] = a[j] + t2[i].x;
        }
    }
    for(i=1;i<=n;i++) 
      cout<<a[i]<<' ';
}
