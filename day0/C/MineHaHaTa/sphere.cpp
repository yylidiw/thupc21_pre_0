#include<bits/stdc++.h>
#define MAXN 20000
using namespace std;
const double eps=1e-12;
int N,M,K,l,r,mid,ans_tt,ans_us;
double R;
int dcmp(double x)
{return (fabs(x)<eps)?0:((x>0)?1:-1);}
struct Point3
{
    double x,y,z;
    Point3(){}
    Point3(double _x,double _y,double _z){x=_x;y=_y;z=_z;}
    void input()
    {
        char s[5];
        scanf("%lf%lf%s",&x,&y,s);
        if (s[0]=='+')z=sqrt(R*R-x*x-y*y);
        if (s[0]=='-')z=-sqrt(R*R-x*x-y*y);
    }
    void output(){printf("%.16lf %.16lf %.16lf\n",x,y,z);}
}P;
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x;y=_y;}
    Point(Point3 P){x=R*P.x/(R-P.z);y=R*P.y/(R-P.z);}
    void input(){scanf("%lf%lf",&x,&y);}
    void output(){printf("%.16lf %.16lf\n",x,y);}
}tt[MAXN+10][2],us[MAXN+10][2],ki[MAXN+10],ttI[MAXN+10],usI[MAXN+10];
typedef Point Vector;
bool operator==(Point A,Point B)
{return ((dcmp(A.x-B.x)==0)&&(dcmp(A.y-B.y)==0));}
Vector operator+(Vector A,Vector B)
{return Vector(A.x+B.x,A.y+B.y);}
Vector operator-(Vector A,Vector B)
{return Vector(A.x-B.x,A.y-B.y);}
double operator*(Vector A,Vector B)
{return A.x*B.y-A.y*B.x;}
Vector operator*(Vector A,double k)
{return Vector(A.x*k,A.y*k);}
Vector operator/(Vector A,double k)
{return Vector(A.x/k,A.y/k);}
struct Line
{
    Point A,B;
    Line(){}
    Line(Point _A,Point _B){A=_A;B=_B;}
    double arg(){return atan2((B-A).y,(B-A).x);}
}ttL[MAXN+10],usL[MAXN+10],ttQ[MAXN+10],usQ[MAXN+10];
bool operator==(Line I,Line J)
{return ((I.A==J.A)&&(I.B==J.B));}
bool operator<(Line I,Line J)
{
    if (dcmp(I.arg()-J.arg()))return I.arg()<J.arg();
    return dcmp((J.A-I.A)*(J.B-I.A))>0;
}
Point operator*(Line I,Line J)
{
    double s1=(J.A-I.A)*(J.B-I.A)/2;
    double s2=(J.B-I.B)*(J.A-I.B)/2;
    return I.A+((I.B-I.A)*s1)/(s1+s2);
}
struct Polygon
{
    int N;
    Point P[MAXN+10];
    void output()
    {
        printf("#%d\n",N);
        for (int i=1;i<=N;i++)
            P[i].output();
    }
}ttP,usP;
int main()
{
    scanf("%d%d%d%lf",&N,&M,&K,&R);
    for (int i=1;i<=N;i++)
    {
        P.input();tt[i][0]=Point(P);
        P.input();tt[i][1]=Point(P);
        //tt[i][0].input();tt[i][1].input();
        //tt[i][0].output();tt[i][1].output();
        if (dcmp((tt[i][1]-tt[i][0])*(Vector(0,0)-tt[i][0]))<0)swap(tt[i][0],tt[i][1]);
        ttL[i]=Line(tt[i][0],tt[i][1]);
    }
    ttL[N+1]=Line(Point(-5e7,-5e7),Point(5e7,-5e7));
    ttL[N+2]=Line(Point(5e7,-5e7),Point(5e7,5e7));
    ttL[N+3]=Line(Point(5e7,5e7),Point(-5e7,5e7));
    ttL[N+4]=Line(Point(-5e7,5e7),Point(-5e7,-5e7));
    sort(ttL+1,ttL+N+5);
    l=r=0;
    for (int i=1;i<=N+4;i++)
    {
        if (ttL[i].arg()==ttL[i-1].arg())continue;
        while ((r-l>1)&&(dcmp((ttL[i].B-ttI[r])*(ttL[i].A-ttI[r]))>0))r--;
        while ((r-l>1)&&(dcmp((ttL[i].B-ttI[l+2])*(ttL[i].A-ttI[l+2]))>0))l++;
        ttQ[++r]=ttL[i];
        if (r-l>1)ttI[r]=ttQ[r]*ttQ[r-1];
    }
    while ((r-l>1)&&(dcmp((ttQ[l+1].B-ttI[r])*(ttQ[l+1].A-ttI[r]))>0))r--;
    ttI[r+1]=ttQ[l+1]*ttQ[r];r++;
    for (int i=l+2;i<=r;i++)
        ttP.P[++ttP.N]=ttI[i];
    for (int i=1;i<=M;i++)
    {
        P.input();us[i][0]=Point(P);
        P.input();us[i][1]=Point(P);
        //us[i][0].input();us[i][1].input();
        //us[i][0].output();us[i][1].output();
        if (dcmp((us[i][1]-us[i][0])*(Vector(0,0)-us[i][0]))<0)swap(us[i][0],us[i][1]);
        usL[i]=Line(us[i][0],us[i][1]);
    }
    usL[M+1]=Line(Point(-5e7,-5e7),Point(5e7,-5e7));
    usL[M+2]=Line(Point(5e7,-5e7),Point(5e7,5e7));
    usL[M+3]=Line(Point(5e7,5e7),Point(-5e7,5e7));
    usL[M+4]=Line(Point(-5e7,5e7),Point(-5e7,-5e7));
    sort(usL+1,usL+M+5);
    l=r=0;
    for (int i=1;i<=M+4;i++)
    {
        if (usL[i].arg()==usL[i-1].arg())continue;
        while ((r-l>1)&&(dcmp((usL[i].B-usI[r])*(usL[i].A-usI[r]))>0))r--;
        while ((r-l>1)&&(dcmp((usL[i].B-usI[l+2])*(usL[i].A-usI[l+2]))>0))l++;
        usQ[++r]=usL[i];
        if (r-l>1)usI[r]=usQ[r]*usQ[r-1];
    }
    while ((r-l>1)&&(dcmp((usQ[l+1].B-usI[r])*(usQ[l+1].A-usI[r]))>0))r--;
    usI[r+1]=usQ[l+1]*usQ[r];r++;
    for (int i=l+2;i<=r;i++)
        usP.P[++usP.N]=usI[i];
    //ttP.output();
    //usP.output();
    //printf("#%d %d\n",ttP.N,usP.N);
    for (int i=1;i<=K;i++)
    {
        P.input(),ki[i]=Point(P);
        //ki[i].input();
        //ki[i].output();
        if (dcmp((ki[i]-ttP.P[1])*(ttP.P[2]-ttP.P[1]))>0)ans_tt=0;
        else if (dcmp((ki[i]-ttP.P[1])*(ttP.P[ttP.N]-ttP.P[1]))<0)ans_tt=0;
        else
        {
            l=2;r=ttP.N-1;
            while (l<r)
            {
                mid=(l+r+1)>>1;
                if (dcmp((ki[i]-ttP.P[1])*(ttP.P[mid]-ttP.P[1]))<0)l=mid;
                else r=mid-1;
            }
            if (dcmp((ki[i]-ttP.P[l])*(ttP.P[l+1]-ttP.P[l]))<0)ans_tt=1;
            else ans_tt=0;
        }
        if (dcmp((ki[i]-usP.P[1])*(usP.P[2]-usP.P[1]))>0)ans_us=0;
        else if (dcmp((ki[i]-usP.P[1])*(usP.P[usP.N]-usP.P[1]))<0)ans_us=0;
        else
        {
            l=2;r=usP.N-1;
            while (l<r)
            {
                mid=(l+r+1)>>1;
                if (dcmp((ki[i]-usP.P[1])*(usP.P[mid]-usP.P[1]))<0)l=mid;
                else r=mid-1;
            }
            if (dcmp((ki[i]-usP.P[l])*(usP.P[l+1]-usP.P[l]))<0)ans_us=1;
            else ans_us=0;
        }
        //printf("#%d %d\n",ans_tt,ans_us);
        if (!ans_tt)puts("Safe");
        else if (ans_us)puts("Passer");
        else puts("Goodbye");
    }
    return 0;
}