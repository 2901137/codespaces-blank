#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student
{
	char chName[20];
	char chGender;
	int iAge;
	int iClass;
	double dEng;
	double dChinese;
	double dMath;
};//定义结构体指针类型 

void Add(struct Student s[N]);//输入学生数据 
int Append(struct Student s[N]);//增加学生信息 
void Menu();//菜单 
void Search(struct Student s[N],int num);//查询学生信息 
void Modify(struct Student s[N], int i);//修改学生信息 
void Delete(struct Student s[N]);//删除学生信息 
void Sort(struct Student s[N]);//统计未及格学生 
void Print(struct Student s[N]);//打印学生信息 
void Rank(struct Student s[N]);//单科学生成绩排名 

int main(int argc, char* argv[]) 
{
	struct Student s[N];//定义结构体变量 
	int button;
	int i;
	int num = 0;
	while (1)
	{
		system("cls");
		Menu();//调用菜单函数 

		scanf("%d", &button);
		switch (button)//选择结构 
		{
		case 1:
        Add(s); 
		break;
		
		case 2:
			{
				Search(s,num);
			}
		break;
		
		case 3:
			{
				Modify(s, i);
			}
		break;
		
		case 4:
			{
				Delete(s);
			}
		break;
		
		case 5:
			{
				Sort(s);
			}
		break;
		
		case 6:
			{
				Print(s);
				system("pause");
			}
		break;
		
		case 7:
			{
				Append(s);
			}
		break;
		
		case 8:
			{
				Rank(s);
			}
		break; 
		}
	}
	return 0;
}

void Menu()//定义菜单函数 
{
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*                1-录入学生成绩信息                 *\n");
	printf("*                2-查询学生成绩信息                 *\n");
	printf("*                3-修改学生成绩信息                 *\n");
	printf("*                4-删除学生成绩信息                 *\n");
	printf("*                5-统计学生成绩信息                 *\n");
	printf("*                6-显示学生成绩信息                 *\n");
	printf("*                7-增加学生成绩信息                 *\n");
	printf("*                8-单科学生成绩排名                 *\n");
	printf("*                9-单科学生成绩录入                 *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");

	printf("请选择功能选项：");
}

void Add(struct Student s[N])
{
	int num;
	int quit1;

	num = 0;
	quit1 = 0;
	for(num = 0; num <= N; num++)
	{
		while(quit1 == 0)
		{
			printf("请依次填写第%d个学生的：姓名、性别、班级、英语成绩、语文成绩、数学成绩\n",num+1);
			printf("退出添加请输入'quit'"); 
			printf("姓名:\n"); 
			scanf("%s",&s[num].chName);
			if(strcmp(s[num].chName,"quit") == 0)
			{
				quit1 = 1;
				printf("quit = %d",quit1);
				strcpy(s[num].chName,"0");
				continue;
			}
			printf("性别:\n"); 
			scanf("%s",&s[num].chGender);
			printf("班级:\n"); 
			scanf("%d",&s[num].iClass);
			printf("英语成绩:\n"); 
			scanf("%lf",&s[num].dEng); 
			printf("语文成绩:\n"); 
			scanf("%lf",&s[num].dChinese);
			printf("数学成绩：\n");
			scanf("%lf",&s[num].dMath);
		}			
	}
	
}



void Print(struct Student s[N])
{
	int i;
	int n = 1;
	for (i = 0; i <= n; i++)
	{
	if(strcmp(s[i].chName , "0") != 0)
		printf("姓名：%s\t\t英语成绩：%lf\t\t语文成绩：%lf\t\t数学成绩：%lf\t\t", s[i].chName, s[i].dEng, s[i].dChinese, s[i].dMath);
}
}

int Append(struct Student s[])
{
	int n;
	fflush(stdin);
//	gets(s[n].chName);
	scanf("%s",&s[n].chName) ;
	fflush(stdin);
	//gets(s[n].chGender);
	scanf("%c",&s[n].chGender);
	scanf("%d", &s[n].iAge);
	scanf("%d", &s[n].iClass);
	scanf("%lf", &s[n].dEng);
	scanf("%lf", &s[n].dChinese);
	scanf("%lf", &s[n].dMath);
	n++;
	return n;
}


void Modify(struct Student s[N], int i)
{
	char inname[20];
	int n;
	scanf("%d", &n);
	printf("请输入您想修改信息的学生的姓名：\n");
	scanf("%s", &inname);
	if (strcmp(s[i].chName, inname) == 0)
	{
		switch (n)
		{
		case 1:
			printf("修改学生姓名请按1：\n");
			printf("请输入新的姓名：\n");
			scanf("%s", &s[i].chName);
			break;

		case 2:
			printf("修改学生性别请按2：\n");
			printf("请输入新的性别：\n");
			scanf("%s", &s[i].chGender);
			break;

		case 3:
			printf("修改学生年龄请按3：\n");
			printf("请输入新的年龄：\n");
			scanf("%d", &s[i].iAge);
			break;

		case 4:
			printf("修改学生班级请按4：\n");
			printf("请输入新的班级：\n");
			scanf("%d", &s[i].iClass);
			break;

		case 5:
			printf("修改学生英语成绩请按5：\n");
			printf("请输入新的英语成绩：\n");
			scanf("%lf", &s[i].dEng);
			break;

		case 6:
			printf("修改学生语文成绩请按6：\n");
			printf("请输入新的语文成绩：\n");
			scanf("%lf", &s[i].dChinese);
			break;

		case 7:
			printf("修改学生数学成绩请按7：\n");
			printf("请输入新的数学成绩：\n");
			scanf("%lf", &s[i].dMath);
			break;

		}
	}
}

void Delete(struct Student s[N])
{
	char name[N];
	int i;
	printf("请输入您想要删除学生的姓名:");
	scanf("%s", &name[1000]);
	for (i = 0; i <= 30; i++)
	{
		if (strcmp(name, s[i].chName) == 0)
		{
			strcpy(s[i].chName, "0");
		}
	}
}

void Rank(struct Student s[N])
{

	int i;
	int j;
	double t;

	s[N].dEng;
	for (i = 0; i <= N - 1; i++)
		for (i = N - 2; i >= 0; i--)
		{
			for (j = 0; j <= i; j++)
				if (s[j].dEng < s[j + 1].dEng)
				{
					t = s[j].dEng;
					s[j].dEng = s[j + 1].dEng;
					s[j + 1].dEng = t;
				}
		}

	s[N].dChinese;
	for (i = 0; i <= N - 1; i++)
		for (i = N - 2; i >= 0; i--)
		{
			for (j = 0; j <= i; j++)
				if (s[j].dChinese < s[j + 1].dChinese)
				{
					t = s[j].dChinese;
					s[j].dChinese = s[j + 1].dChinese;
					s[j + 1].dChinese = t;
				}
		}

	s[N].dMath;
	for (i = 0; i <= N - 1; i++)
		for (i = N - 2; i >= 0; i--)
		{
			for (j = 0; j <= i; j++)
				if (s[j].dMath < s[j + 1].dMath)
				{
					t = s[j].dMath;
					s[j].dMath = s[j + 1].dMath;
					s[j + 1].dMath = t;
				}
		}

	for (i = 0; i <= N - 1; i++)
		printf("英语成绩：%lf", s[N].dEng);
	printf("语文成绩：%lf", s[N].dChinese);
	printf("数学成绩：%lf", s[N].dMath);
	//return 0;
}

void Search(struct Student s[N], int num)
{
	char name[30];//--------------
	int i;
	printf("请输入您想查询成绩的学生姓名：\n");
	scanf("%s", &name);
	for (i = 0; i < N; i++)
	{
		if (strcmp(s[i].chName,name ) == 0)
			printf("英语成绩：%lf\t\t语文成绩：%lf\t\t数学成绩：%lf\t\t", s[i].dEng, s[i].dChinese, s[i].dMath);
	}
}

void Sort(struct Student s[N])
{
	int count = 0;
	int i;
	s[N].dEng;
	s[N].dChinese;
	s[N].dMath;
	for(i=0;i<N;i++)
    {
     if(s[i].dEng <= 59 && s[i].dChinese <= 59 && s[i].dMath <= 59)
	 count++;
	 printf("不及格科目超过两科的同学名单为：\n", s[i].chName);
    }
    
}

void sign_score(struct Student s[N], int num)
{
	
	char Subject[10];
	int i;
	printf("请输入您想要录入单科成绩的科目：\n");
	scanf("%s",&Subject);
	if(strcmp(Subject,"英语") == 0)
	{
		printf("请输入学生姓名：\n");
		scanf("%s",&s[i].chName); 
		printf("请输入英语成绩：\n");
		scanf("%lf", &s[i].dEng);
	}
	if(strcmp(Subject,"语文") == 0);
		{
		printf("请输入学生姓名：\n");
		scanf("%s",&s[i].chName); 
		printf("请输入语文成绩：\n");
		scanf("lf", &s[i].dChinese);
	    }
	if(strcmp(Subject,"数学") == 0);
		{
		printf("请输入学生姓名：\n");
		scanf("%s",&s[i].chName); 
		printf("请输入数学成绩：\n");
		scanf("%lf", &s[i].dMath);
	    }
}