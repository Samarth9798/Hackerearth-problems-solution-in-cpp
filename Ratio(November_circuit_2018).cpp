#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    ll n;
    deque<ll> q;
    char c;
    ll k;
    cin>>t;
    ll ratioa,ratiob,gcd;
    ll na,nb;
    ll total_na,total_nb;
    char start;
    ll i;
    ll ans;
    while(t)
    {
        cin>>n;
        na=0;
        nb=0;
        ans=0;
        total_na=0;
        total_nb=0;
        for(i=0;i<n;i++)
        {   
            cin>>k>>c;
            if(c=='A')
            {
                na+=k;
                total_na+=k;
                if(nb>0)
                {
                    q.push_back(nb);
                    nb=0;
                }
            }
            else
            {
                nb+=k;
                total_nb+=k;
                if(na>0)
                {
                    q.push_back(na);
                    na=0;
                }
            }
            if(i==0 and c=='A') start='A';
            else if(i==0 and c=='B') start='B';
        }
        if(na>0) 
            q.push_back(na);
        else if(nb>0) 
            q.push_back(nb);
        if(total_na==0) 
            ans=total_nb;
        else if(total_nb==0) 
            ans=total_na;
        else
        {
            gcd=__gcd(total_na,total_nb);
            ratioa=total_na/gcd;
            ratiob=total_nb/gcd;
            if(ratioa==total_na or ratiob==total_nb)
            {
                ans=1;
            }
            else
            {
                na=0;
                nb=0;
                ll temp=0;
                ll factor=0;
                while(!q.empty())
                {
                    temp=q.front();
                    if(start=='A')
                    {
                        na+=temp;
                        if(na%ratioa==0 and na!=0)
                        {
                            factor=na/ratioa;
                            if(factor*ratiob==nb)
                            {
                                ans++;
                                nb=0;
                                na=0;
                            }
                        }
                        factor=0;
                        if(nb%ratiob==0 and nb!=0)
                        {
                            factor=nb/ratiob;
                            if(factor*ratioa<=na and (na-temp)<=factor*ratioa)
                            {
                                ans++;
                                na=na-(factor*ratioa);
                                nb=0;
                            }
                        }
                        factor=0;
                        start='B';
                    }
                    
                    else if(start=='B')
                    {
                        nb+=temp;
                        if(nb%ratiob==0 and nb!=0)
                        {
                            factor=nb/ratiob;
                            if(factor*ratioa==na)
                            {
                                ans++;
                                na=0;
                                nb=0;
                            }
                        }
                        factor=0;
                        if(na%ratioa==0 and na!=0)
                        {
                            factor=na/ratioa;
                            if(factor*ratiob<=nb and (nb-temp)<=factor*ratiob)
                            {
                                ans++;
                                nb=nb-(factor*ratiob);
                                na=0;
                            }
                        }
                        factor=0;
                        start='A';
                    }
                    q.pop_front();
                }
                if(ans==0) ans=1;
                else if(na>0 or nb>0) ans=1;
            }
        }
        q.clear();
        cout<<ans<<endl;
        t-=1;
    }
}
