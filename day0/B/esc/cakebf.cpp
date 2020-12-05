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
int a[11];
double f[1111][11];
int main()
{
    int n=io::F(),m=io::F();
    for(int i=0;i<n;++i)a[i]=io::F();
    for(int i=1;i<1<<n;++i)
        for(int k=1;k<=m;++k)
        {
            f[i][k]=1e233;
            for(int j=0;j<n;++j)
                if(i&1<<j)
                {
                    double d=f[i^1<<j][k]-f[i^1<<j][k-1];
                    double tmp;
                    if(d<=a[j])tmp=(a[j]+f[i^1<<j][k]+f[i^1<<j][k-1])/2;
                        else tmp=dmax(f[i^1<<j][k],a[j]+f[i^1<<j][k-1]);
                    cmin(f[i][k],tmp);
                }
        }
    printf("%.10lf\n",f[(1<<n)-1][m]);
    return 0;
}