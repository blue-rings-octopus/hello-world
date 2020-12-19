# 7-5 实验11_3_结构排序 (100分)
有n名学生，每个学生的属性包括姓名与总成绩。已知学生的姓名与总成绩，你的任务是将学生的信息按照以下方式排序：首先比较总成绩，总成绩高的在前面，总成绩低的在后面，当总成绩相同时，你要比较学生的姓名，姓名字典序小的同学在前面，姓名字典序大的同学在后面(ASCII码顺序)。n的范围是1—100；学生的姓名中只能包含大小写字母，不会超过20个字符；总成绩为整数。

要求：在本题中，你要设计一个结构来存储学生的信息。在此结构中，需要有一个字符数组来存储姓名，一个整型变量存储总成绩。 输入与输出要求：输出：。。

输入格式:
首先输入一个正整数n，代表学生的数量，1<=n<=100；每名学生的信息按照姓名、总成绩的顺序输入（空格分开），每名学生信息占一行。具体格式见样例。

输出格式:
n名学生的信息，姓名占一行，总成绩占一行，输出顺序要按照题目的要求，每名同学的信息后都再输出一个空行。 注意：每名同学的信息后都再输出一个空行。

输入样例:

    4
    AlbertEinstein 1328
    GeorgeWalkerBush 860
    LiuMengmeng 1475
    BillGates 1328

输出样例:

    Name:LiuMengmeng
    total:1475

    Name:AlbertEinstein
    total:1328

    Name:BillGates
    total:1328

    Name:GeorgeWalkerBush
    total:860

C (gcc 6.5.0)

    #include<stdio.h>
    #include<string.h>
    typedef struct{
        char name[20];
        int total;
    }STUDENT;
    int main()
    {
        int n,i,j;
        STUDENT stu[100],temp;
        STUDENT *ptr[100];

        scanf("%d",&n);
        for(j=0;j<n;j++)
            ptr[j]=&stu[j];
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",stu[i].name);
            scanf("%d",&stu[i].total);
            getchar();
        }

        for(i=n-1;i>=0;i--)
            for(j=0;j<n-1;j++)
            {
                if(stu[j].total<stu[j+1].total)
                {
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;
                }
                if(stu[j].total==stu[j+1].total)
                    if(strcmp(stu[j].name,stu[j+1].name)>0)
                    {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                    }
            }
        for(j=0;j<n;j++)
            printf("Name:%s\ntotal:%d\n\n",ptr[j]->name,ptr[j]->total);

    }
