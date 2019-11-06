#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define func 40

////////////////////////함수 선언부

void printtypes(void);
void printmenu(char ip[]);
void transfer(int* a,int* n,int* b,char* ip); //입력받은 수식에서 필요한 값들만 추출, 변환하는 함수
void graph(int a,int n,int b); //추출한 값들로 그래프를 그려주는 함수
double my_pow(int x,int n); ////math.h의 제곱함수를 내가 쓰고자하는 방식에 맞게 만든 제곱함수

////////////////////////전역변수 선언부

char* search; //문자열에서^를 찾아 저장할 변수
char A[5] = {};
char N[5] = {};
char B[5] = {};

////////////////////////함수 정의부

int main(void)
{
    int a=0,n=0,b=0,cho;
    char ip[] = {};
start:
    printtypes();
    printf("항목을 골라주세요\n1. 그래프 보기\n2. 종료\n");
    scanf("%d",&cho);
    switch(cho)
    {
        case 1:
            break;
        case 2:
            goto finish;
        default:
            printf("다시 골라주세요\n");
            goto start;
    }
    printmenu(ip);
    transfer(&a,&n,&b,ip);
    search = strchr(ip,'^');//문자 찾는 함수
    graph(a,n,b);
finish:
    return 0;
}

/*
 수식을 입력받을 때
 받을 수 있는 형태들을
 출력 해주는 함수
 printtypes
 */

void printtypes(void)
{
    printf("사용할 수 있는 수식의 종류는\n");
    printf("1. ㅁ*x^ㅁ+ㅁ\n");
    printf("2. ㅁ*x^ㅁ-ㅁ\n");
    printf("3. ㅁ*x^-ㅁ+ㅁ\n");
    printf("4. ㅁ*x^-ㅁ-ㅁ\n");
    printf("5. -ㅁ*x^ㅁ+ㅁ\n");
    printf("6. -ㅁ*x^ㅁ-ㅁ\n");
    printf("7. -ㅁ*x^-ㅁ+ㅁ\n");
    printf("8. -ㅁ*x^-ㅁ-ㅁ\n");
    printf("소수,분수 불가\n");
}

/*
 메뉴를 출력 해주는 함수로
 리턴값이 없다.
 printmenu
 */

void printmenu(char ip[])
{
    char* fir = "수식을 입력해주세요";
    char* sec = "a*x^n+b형식을 사용해주세요";
    char* thir = "a,n,b는 원하는 숫자 사용 가능합니다.";
    unsigned long min = strlen(thir)-strlen(fir);
    unsigned long min_ = strlen(thir)-strlen(sec);
    int size=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<min/2;j++)
        {
            size++;
            printf("=");
        }
        if(i==1)
        {
            puts("");
            break;
        }
        printf("%s",fir);
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<min_/2;j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    printf("=");
                }
                else
                {
                    printf(" ");
                }
            }
            if(i==1)
            {
                if(j==min_/2-1)
                {
                    printf("=");
                }
                else
                {
                    if(j==1)
                    {
                        j++;
                    }
                    printf(" ");
                }
            }
        }
        if(i==1)
        {
            puts("");
            break;
        }
        printf("%s",sec);
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("=");
        }
        if(i==1)
        {
            printf("=\n");
            break;
        }
        printf("%s",thir);
    }
    scanf("%s",ip);
}

/*
 main 함수에서 입력받은 문자열을 보고
 필요한 값들만 따로 빼와서 저장하는 함수
 transfer
 */

void transfer(int* a,int* n,int* b,char* ip)
{
    strncpy(A,ip+0,2);
    *a=atoi(A); //문자열A를 정수로 바꿔 a에 저장
    if(*a<0) //a가 음수일 때
    {
            strncpy(N,ip+5,2);
            *n=atoi(N); //문자열N을 정수로 바꿔 n에 저장
            if(*n<0) //n이 음수일 때
            {
                if(ip[7]=='+') //상수가 양수일때
                {
                    strncpy(B,ip+8,2);
                    *b=atoi(B); //문자열B를 정수로 바꿔 b에 저장
                }
                else if(ip[7]=='-') //상수가 음수일 때
                {
                    strncpy(B,ip+7,3);
                    *b=atoi(B);
                }
            }
            else if(*n>0) //n이 양수일 때
            {
                if(ip[6]=='+')
                {
                    strncpy(B,ip+7,2);
                    *b=atoi(B);
                }
                else if(ip[6]=='-')
                {
                    strncpy(B,ip+6,3);
                    *b=atoi(B);
                }
            }
    }
    else if(*a>0) //a가 양수일 때
    {
        strncpy(N,ip+4,2);
        *n=atoi(N);
        if(*n<0) //n이 음수일 때
        {
            if(ip[6]=='+')
            {
                strncpy(B,ip+7,2);
                *b=atoi(B);
            }
            else if(ip[6]=='-')
            {
                strncpy(B,ip+6,3);
                *b=atoi(B);
            }
        }
        else if(*n>0) //n이 양수일 때
        {
            if(ip[5]=='+')
            {
                strncpy(B,ip+6,2);
                *b=atoi(B);
            }
            else if(ip[5]=='-')
            {
                strncpy(B,ip+5,3);
                *b=atoi(B);
            }
        }
    }
}

/*따로 빼온 숫자들을 가지고
 좌표평면에 그래프를 그려주는 함수
 graph
 */

void graph(int a,int n,int b)
{
    for(int y=func;y>=-func;y--)
    {
        for(int x=-func;x<=func;x++)
        {
            int X = my_pow(x,n);//그래프의 크기가 한정적이어서 음수승의 수식도 실수가 아닌 정수로 리턴값을 저장해서 추상적으로 처리함,양수승의 수식은 기본적으로 정수가 리턴됨
            if(y==((a*X)+b))
            {
                printf("*");
            }
            else if(y==0)
            {
                printf("-");
            }
            else if(x==0)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        puts("");
    }
}

/*
 math.h의 제곱함수를
 내 사용 목적에 맞게
 변형하여 만든 함수로
 수식의 x의 차수를
 계산해줄 때 사용함
 my_pow
 */

double my_pow(int x,int n)
{
    int X;
    double fin=1.0;
    double dou;
    X=x;
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
            fin = fin*X;
        }
    }
    else if(n<0)
    {
        int tra;
        tra=-n;
        for(int i=0;i<tra;i++)
        {
            fin = fin*X;
        }
        dou=fin;
        fin=1.0/dou;
    }
        return fin;
}

/*
 결과값은 좌표평면이 그려진 후
 그래프가 그 위로 그려지는 방식으로
 그래프가 그려짐
 +-상수는 y축인 |를하나씩 올라가고 내려가고를 의미 함
 */
