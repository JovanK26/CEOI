#include <bits/stdc++.h>
#include "icc.h"
using namespace std;
int prt[101];
int sz[101];
int ask(vector<int> a,vector<int> b)
{
    int n=a.size();
    int m=b.size();
    int a1[n];
    int b1[m];
    for(int i=0;i<n;i++)
    {
        a1[i]=a[i];
    }
    for(int i=0;i<m;i++)
    {
        b1[i]=b[i];
    }
    return query(n,m,a1,b1);
}
void sett(int n)
{
    for(int i=1;i<=n;i++)
    {
        prt[i]=i;
        sz[i]=1;
    }
}
int findd(int x)
{
    while(x!=prt[x])
    {
        prt[x]=prt[prt[x]];
        x=prt[x];
    }
    return x;
}
void unionn(int x,int y)
{
    x=findd(x);
    y=findd(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    prt[y]=x;
    sz[x]+=sz[y];
}
void run(int n)
{
    sett(n);
    int rez1,rez2;
    for(int i=0;i<n-1;i++)
    {
        vector< vector<int> > g(n+1);
        for(int j=1;j<=n;j++)
        {
            g[findd(j)].push_back(j);
        }
        vector< vector<int> > cur;
        for(int j=1;j<=n;j++)
        {
            if(!g[j].empty())
            {
                cur.push_back(g[j]);
            }
        }
        vector<int> v1,v2;
        for(int bit=8;bit>=0;bit--)
        {
            if((1<<bit)>=cur.size())continue;
            vector<int> t1,t2;
            for(int j=0;j<cur.size();j++)
            {
                if(j&(1<<bit))
                {
                    for(auto x : cur[j])
                    {
                        t1.push_back(x);
                    }
                }
                else
                {
                    for(auto x : cur[j])
                    {
                        t2.push_back(x);
                    }
                }
            }
            if(t1.empty() || t2.empty())continue;
            if(ask(t1,t2))
            {
                v1=t1;
                v2=t2;
                break;
            }
        }
        int l=0;
        int r=v1.size()-1;
        int m;
        while(l<r)
        {
           m=(l+r)/2;
           vector<int> temp;
           for(int i=0;i<=m;i++)
           {
               temp.push_back(v1[i]);
           }
           if(ask(temp,v2))
           {
               r=m;
           }
           else
           {
               l=m+1;
           }
        }
        rez1=v1[l];
        l=0;
        r=v2.size()-1;
        while(l<r)
        {
           m=(l+r)/2;
           vector<int> temp;
           for(int i=0;i<=m;i++)
           {
               temp.push_back(v2[i]);
           }
           if(ask(v1,temp))
           {
               r=m;
           }
           else
           {
               l=m+1;
           }
        }
        rez2=v2[l];
        setRoad(rez1,rez2);
        unionn(rez1,rez2);
    }
}
