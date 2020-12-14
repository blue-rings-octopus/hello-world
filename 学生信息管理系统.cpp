#include<stdio.h>
#include<string.h>

typedef struct{
    char name[11];
    char num[11];
    int score[3];
    float aver;
}STUDENT;

void Add(STUDENT stu[]);
void Delete(STUDENT stu[]);
void Update(STUDENT stu[]);
void Output(STUDENT stu[]);

int main()
{
    STUDENT stu[130]={};
    int n,i,option;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&option);
        switch(option)
        {
            case 1:Add(stu);break;
            case 2:Delete(stu);break;
            case 3:Update(stu);break;
            case 4:Output(stu);break;
        }
    }
    return 0;
}
void Add(STUDENT stu[])
{
    int i,judge=1;
    char id[11];
    
    scanf("%s",id);
    for(i=0;stu[i].num[0];i++)
        if(strcmp(stu[i].num,id)==0)
        {
            printf("Students already exist\n");
            judge=0;
        }
        
    if(judge)
    {
        strcpy(stu[i].num,id);
        scanf("%s%d%d%d",stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        printf("Add success\n");
    }
}
void Delete(STUDENT stu[])
{
    int i,j,judge=0;
    char id[11];
    
    scanf("%s",id);
    for(i=0;stu[i].num[0]&&strcmp(stu[i].num,id);i++);
    if(strcmp(stu[i].num,id)==0)
        judge=1;

    if(judge)
    {
        for(j=i;stu[j].num[0];j++)
            stu[j]=stu[j+1];
        printf("Delete success\n");
    }
    else
        printf("Students do not exist\n");
}
void Update(STUDENT stu[])
{
    int i,judge=0;
    char id[11];
    
    scanf("%s",id);
    for(i=0;stu[i].num[0]&&strcmp(stu[i].num,id);i++);
    if(strcmp(stu[i].num,id)==0)
        judge=1;
    
    if(judge)
    {
        scanf("%d%d%d",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        printf("Update success\n");
    }
    else
        printf("Students do not exist\n");
}
void Output(STUDENT stu[])
{
    int i,judge=0;
    char id[11];
    
    scanf("%s",id);
    for(i=0;stu[i].num[0]&&strcmp(stu[i].num,id);i++);
    if(strcmp(stu[i].num,id)==0)
        judge=1;
    
    if(judge)
    {
        stu[i].aver=(float)(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
        printf("Student ID:%s\nName:%s\nAverage Score:%.1f\n",stu[i].num,stu[i].name,stu[i].aver);
    }
    else
        printf("Students do not exist\n");
}

