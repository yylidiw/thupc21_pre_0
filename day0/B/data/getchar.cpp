#include<cstdio>
int main()
{
    char ch;
    int cn=0;
    while(ch=getchar(),1)
    {
        if(ch>='0'&&ch<='9'||ch==' '||ch=='\n')putchar(ch);
        //printf("%d\n",(int)ch);
        if(++cn==1000)return 0;
    }
    return 0;
}