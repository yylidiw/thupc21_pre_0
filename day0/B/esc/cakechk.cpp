#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
    int F()
    {
        int n=0,F=0;
        char ch;
        while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
        ch=='-'?F=1:n=ch-'0';
        while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
        return F?-n:n;
    }
}
int main()
{
    int cnt=0;
    while(1)
    {
        char b[1111];
        system("cake < cake.in > cake.out");
        system("cakebf < cake.in > cake.ans");
        if(system("diff cake.out cake.ans"))break;
        system("cakemkr > cake.in");
    }
    return 0;
}