#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define MAXN 500
using namespace std;
const double eps=1e-8;
int N,M,T;
double R;
int dcmp(double x)
{return (fabs(x)<eps)?0:((x>0)?1:-1);}
struct Point
{
    double x,y,z;
    Point(){}
    Point(double _x,double _y,double _z){x=_x;y=_y;z=_z;}
    void input()
    {
        char s[5];
        scanf("%lf%lf%s",&x,&y,s);
        if (s[0]=='+')z=sqrt(R*R-x*x-y*y);
        if (s[0]=='-')z=-sqrt(R*R-x*x-y*y);
    }
}tt[MAXN+10][2],us[MAXN+10][2],ki;
Point Ctt[MAXN+10],Cus[MAXN+10];
int ans_tt,ans_us;
double dis(Point P,Point Q)
{
    double theta,d=sqr(P.x-Q.x)+sqr(P.y-Q.y)+sqr(P.z-Q.z);
    theta=acos((2*sqr(R)-d)/2/sqr(R));
    return theta*R;
}
Point center(Point U,Point V,Point W)
{
    double x1=U.x,y1=U.y,z1=U.z;
    double x2=V.x,y2=V.y,z2=V.z;
    double x3=W.x,y3=W.y,z3=W.z;
    double A1=y1*z2-y1*z3-z1*y2+z1*y3+y2*z3-y3*z2;
    double B1=-x1*z2+x1*z3+z1*x2-z1*x3-x2*z3+x3*z2;
    double C1=x1*y2-x1*y3-y1*x2+y1*x3+x2*y3-x3*y2;
    double D1=-x1*y2*z3+x1*y3*z2+x2*y1*z3-x3*y1*z2-x2*y3*z1+x3*y2*z1;
    double A2=2*(x2-x1),B2=2*(y2-y1),C2=2*(z2-z1);
    double D2=x1*x1+y1*y1+z1*z1-x2*x2-y2*y2-z2*z2;
    double A3=2*(x3-x1),B3=2*(y3-y1),C3=2*(z3-z1);
    double D3=x1*x1+y1*y1+z1*z1-x3*x3-y3*y3-z3*z3;
    double M[4][4];
    M[1][1]=B2*C3-B3*C2;M[1][2]=-B1*C3+B3*C1;M[1][3]=B1*C2-B2*C1;
    M[2][1]=-A2*C3+A3*C2;M[2][2]=A1*C3-A3*C1;M[2][3]=-A1*C2+A2*C1;
    M[3][1]=A2*B3-A3*B2;M[3][2]=-A1*B3+A3*B1;M[3][3]=A1*B2-A2*B1;
    double det=A1*B2*C3+A2*B3*C1+A3*B1*C2-A3*B2*C1-A2*B1*C3-A1*B3*C2;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            M[i][j]/=det;
    Point C=Point(-M[1][1]*D1-M[1][2]*D2-M[1][3]*D3,-M[2][1]*D1-M[2][2]*D2-M[2][3]*D3,-M[3][1]*D1-M[3][2]*D2-M[3][3]*D3);
    double L=sqrt(sqr(C.x)+sqr(C.y)+sqr(C.z));
    C.x=C.x/L*R;C.y=C.y/L*R;C.z=C.z/L*R;
    return C;
}
int main()
{
    scanf("%d%d%d%lf",&N,&M,&T,&R);
    for (int i=1;i<=N;i++)
    {
        tt[i][0].input(),tt[i][1].input();
        Ctt[i]=center(tt[i][0],tt[i][1],Point(0,0,R));
    }
    for (int i=1;i<=M;i++)
    {
        us[i][0].input(),us[i][1].input();
        Cus[i]=center(us[i][0],us[i][1],Point(0,0,R));
    }
    while (T--)
    {
        ki.input();
        ans_tt=ans_us=0;
        for (int i=1;i<=N;i++)
        {
            //Point C=center(tt[i][0],tt[i][1],Point(0,0,R));
            //printf("%.4lf %.4lf\n",dis(Point(0,0,R),C),dis(ki,C));
            if (dcmp(dis(ki,Ctt[i])-dis(Point(0,0,R),Ctt[i]))<0)ans_tt=1;
        }
        for (int i=1;i<=M;i++)
        {
            //Point C=center(us[i][0],us[i][1],Point(0,0,R));
            //printf("%.4lf %.4lf\n",dis(Point(0,0,R),C),dis(ki,C));
            if (dcmp(dis(ki,Cus[i])-dis(Point(0,0,R),Cus[i]))<0)ans_us=1;
        }
        if (ans_tt)puts("Safe");
        else if (!ans_us)puts("Passer");
        else puts("Goodbye");
    }
    return 0;
}
