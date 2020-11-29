#include <bits/stdc++.h>
#include "snakelib.h"


using namespace std;

int main()
{
    char a1,a2;
    int k=get_speed();
    int len=12122;
    int a=len/3;
    int b=2*a;
    ask_snake(a,b,&a1,&a2);
    int l1,r1,l2,r2;
    if(a1=='s')
    {
        if(a2=='s')
        {
            l1=0;
            r1=a;
            l2=b;
            r2=len;
        }
        if(a2=='f')
        {
            l1=0;
            r1=a;
            l2=a;
            r2=b-1;
        }
    }
    if(a1=='f')
    {
      l1=0;
      r1=a-1;
      l2=0;
      r2=a-1;
    }
    if(a1=='b')
    {
        if(a2=='s')
        {
            l1=a+1;
            r1=b;
            l2=b;
            r2=len;
        }
        if(a2=='f')
        {
            l1=a+1;
            r1=b-1;
            l2=a+1;
            r2=b-1;
        }
        if(a2=='b')
        {
            l1=b+1;
            r1=len;
            l2=b+1;
            r2=len;
        }
    }
    while(r1-l1+1>k+1 || r2-l2+1>k+1)
    {
        r1=min(r1+k,len);
        r2=min(r2+k,len);
        int m1=(l1+r1)/2;
        int m2=(l2+r2+1)/2;
        ask_snake(m1,m2,&a1,&a2);
        if(a1=='s')
        {
           r1=m1;
        }
        if(a1=='f')
        {
           r1=m1-1;
        }
        if(a1=='b')
        {
           l1=m1+1;
        }
        if(a2=='s')
        {
           l2=m2;
        }
        if(a2=='f')
        {
           r2=m2-1;
        }
        if(a2=='b')
        {
           l2=m2+1;
        }
    }
    int m1=(l1+r1)/2;
    int m2=(l2+r2)/2;
    tell_length(m2-m1+1);
    return 0;
}
