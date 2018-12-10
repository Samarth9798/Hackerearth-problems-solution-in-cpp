#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    char c1,c2,c3,c4;
    cin>>t;
    string s;
    while(t--)
    {
        s="";
        cin>>c1>>c2>>c3>>c4;
        s+=c1;
        s+=c2;s+=c3;s+=c4;
        if(s=="0110") cout<<"Yes"<<endl;
        else if(s=="0001") cout<<"Yes"<<endl;
        else if(s=="0111") cout<<"Yes"<<endl;
        else if(s=="1110") cout<<"No"<<endl;
        else if(s=="1000") cout<<"No"<<endl;
        else if(s=="1001") cout<<"Yes"<<endl;
        else if(s=="1111") cout<<"Yes"<<endl;
        else if(s=="0000") cout<<"Yes"<<endl;
        else if(s=="1010") cout<<"No"<<endl;
        else if(s=="0101") cout<<"Yes"<<endl;
        else if(s=="1100") cout<<"No"<<endl;
        else if(s=="0011") cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
