# 6-3 实验10_5_指针数组初步
已知一个总长度不超过10000的字符串，字符串中只包含大写字母“A—Z”、小写字母“a—z”和空格‘ ’。空格用于分割单词，空格的个数不超过1000个。你的任务是将字符串中用空格分隔的单词打印出来。 你要按照如下要求完成任务： 1.利用指针数组指向每个单词的开始位置。 2.把字符串中单词结束后的空格改为“\0”,然后使用指针数组将每个单词打印出来。 此题要求用函数完成。

函数接口定义：
函数原型如下：
int getString( char * source , char *strPtr[] ) ;
其中 source 和 strPtr 都是用户传入的参数。 source 为待处理字符串； strPtr 是保存各个单词开始位置的指针数组。函数返回值为单词的个数。

裁判测试程序样例：
函数被调用进行测试的例子如下：
#include<stdio.h>

int getString( char * source , char *strPtr[] ) ;

int main()
{
    char    str[100005];
    char    *strPtr[1005]={0};
    int        i, num ;

    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);

    return 0;    
}

输入样例：
You are great

输出样例：
You
are
great

C (gcc 6.5.0)

    #include<string.h>
    int getString( char * source , char *strPtr[] )

    {
        int i,j=1,num=0,size;
        
        size=strlen(source);
        strPtr[0]=source;
        for(i=0;i<size;i++)
            if(*(source+i)==' ')
            {
                *(source+i)='\0';
                if(*(source+i+1)!=' ')
                {
                    strPtr[j]=source+i+1;
                    num++;
                    j++;
                }
            }
        if(*strPtr[0]=='\0')
        {
            for(i=1;i<=num;i++)
                strPtr[i-1]=strPtr[i];
            num--;
        }
            return num+1;
    }
