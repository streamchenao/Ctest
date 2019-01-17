#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#define size 2
#define N 2
struct course
{
	char nums[10];//课程编号
	char name[20];
    char nature[12];//只有选修与必修的区别
	int total_time;//总学时
    int cla;//授课学时
    int exper;//实验学时
	int credit;//学分
	char term[12];//开课学期
}cour[size];
struct student
{
	char numbers[10];//学号
	char sname[20];//姓名
     int total_credits;//总学分
     struct course c[2];
}stu[N];
int course_nums=0;//当前所选的课程数目
void firstmenu();
void StudentMenu();
void MangerMenu();
void MangerMenu1();
void Xueshengformer();
void Laoshiformer();
void save();
void put_infor();
void Paixu();
void search();
void choose(struct student *stu);

void print_information(struct student );
void input_infor();
void del();
static int total=0;//当前课程数目

void put_infor()
{
    FILE *fp;
    int i;
    struct course cour1[total];
    fp=fopen("G:\\测试\\test.dat","rb+");
    if(fp==NULL)
        printf("打开文件出错");
    for(i=0;i<total;i++)
       {
         fread(&cour1[i],sizeof(struct course),1,fp);
//printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,cour[i].nature,cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
       }
    fclose(fp);
}

void save()
{
    FILE *fp;
    int i;
    fp=fopen("G:\\测试\\test.dat","wb+");
    if(fp==NULL)
        printf("打开文件出错");
    for(i=0;i<size;i++)
if(fwrite(&cour[i],sizeof(struct course),1,fp)!=1)
    printf("写文件出错\n");
  fclose(fp);
}
void modify(struct course *p,char a[])//参数是:要修改的课程在最开始录入时的序号
{
	//先查找到所要修改的课程信息
	FILE *fp;
	FILE *fp1;
	struct course c1;
	fp=fopen("G:\\测试\\test.dat","rb");
	fp1=fopen("G:\\测试\\test1.dat","wb+");
	if(fp==NULL||fp1==NULL)
	{
      printf("文件打开失败\n");
	}
	rewind(fp);
	fread(&c1,sizeof(struct course),1,fp);
	while(!feof(fp))
    {
        if(strcmp(c1.nums,a)==0)
        {
            fwrite(p,sizeof(struct course),1,fp1);
        }
        else
        {
            fwrite(&c1,sizeof(struct course),1,fp1);
        }
         fread(&c1,sizeof(struct course),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("G:\\测试\\test.dat");
    rename("G:\\测试\\test1.dat","G:\\测试\\test.dat");
    printf("修改数据成功!\n");
}
void firstmenu()
{int y;

	printf("************欢迎进入选课系统************\n");
		printf("\n");
	printf("\n");
	printf("          ◆◆◆◆◆        ◆◆◆◆◆　\n");
printf("        ◆◆◆◆◆◆◆    ◆◆◆◆◆◆◆　\n");
printf("     　◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　 \n");
printf("    　◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　\n");
printf("   　◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　 \n");
printf("    ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　\n");
printf("   　◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　\n");
printf("    　◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　\n");
printf("     　 ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆　\n");
printf("          ◆◆◆◆◆◆◆◆◆◆◆◆◆◆　 \n");
printf("            ◆◆◆◆◆◆◆◆◆◆◆◆　 \n");
printf("              ◆◆◆◆◆◆◆◆◆◆ \n");
printf("                ◆◆◆◆◆◆◆◆　\n");
printf("                  ◆◆◆◆◆◆\n");
printf("	           ◆◆◆◆\n");
printf("                     ◆◆\n");
printf("		      ◆\n");
	printf("\n");
	printf("\n");
		printf("请您选择您的身份:\n");
printf("               1.学生\n");
printf("               2.管理员\n");
printf("               3.退出\n");
printf("               请输入您的操作:\n");
scanf("%d",&y);
switch(y)
{
case 1: Xueshengformer();break;
case 2: Laoshiformer();break;
case 3:exit (0);break;
default:printf("请输入正确的数字!\n");break;
}
}
void StudentMenu()
{
    int r,k,j;
	printf("************欢迎进入学生服务系统************\n");
for(k=0;k<6;k++)
    {
        for(j=0;j<=k;j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
	printf("            你可以选择如下操作:\n");
	printf("            1.浏览课表\n");
	printf("            2.查询课程信息\n");
	printf("            3.选课\n");
	printf("            4.打印所选课程的信息\n");
	printf("            5.退出\n");
	printf("            请输入您的选择服务!\n");
	scanf("%d",&r);
	switch(r)
	{
	case 1: Paixu();break;
	case 2: search();break;
	case 3:
	    {
	    int i=0;
	    char num[10];
	    printf("请 输 入 你 的 学 号\n");
	    scanf("%s",num);
        while(strcmp(stu[i].numbers,num)!=0&&i<N)
        {
            i++;
        }
        if(strcmp(stu[i].numbers,num)==0)
        {
        if(stu[i].total_credits<60)
	       {
	           printf("你的学分不够，无法进行选课！\n");
	           StudentMenu();
           }
	      else
              choose(&stu[i]);
        }
        if(i==N)
            printf("不存在该学生\n");
	  }
	    break;
	case 4:
	    {
	        int i=0;
	        char num[10];
	    printf("请 输 入 你 的 学 号\n");
	        scanf("%s",num);
	    while(strcmp(stu[i].numbers,num)!=0&&i<N)
            {
               i++;
            }
        if(strcmp(stu[i].numbers,num)==0)
            {
                print_information(stu[i]);
            }
         if(i==N)
               {
                   printf("不存在该学生!\n");
               }
	        break;
	        }
	case 5:firstmenu();break;
	default:printf("请输入正确的数字!");break;
	}

}
void MangerMenu1()
{
	printf("************欢迎进入教师服务系统************\n");
	printf("\n");
	printf("\n");
	printf("                     ▁▂▃▄▅▆▇█▇▆▅▄▃▂▁ \n");
printf("      ▁▂▃▄▅▆▇█████████████████▇▆▅▄▃▂▁\n");
printf("           ██████████████████████████\n");
printf("                 ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
printf("                      ▉□                      □▉\n");
printf("                      ▉  □        ★        □  ▉\n");
printf("                      ▉    □     ☆☆     □    ▉\n");
printf("                      ▉     ▓▓ ☆☆☆ ▓▓     ▉\n");
printf("                      ▉     ▓▓  ☆☆  ▓▓     ▉\n");
printf("                      ▉    □▉    ★    ▉□    ▉\n");
printf("                      ▉  □  ▉          ▉  □  ▉\n");
printf("                      ▉□    ▉          ▉    □▉\n");
printf("                      ▉      ▉          ▉      ▉\n");
printf("                      ▉      ▉          ▉      ▉\n");
printf("                      ▉      ▉          ▉      ▉\n");
printf(" ▂▃▄▅▆▇████████████████████████▇▆▅▄▃▂\n");
	printf("\n");
	printf("\n");
	printf("            您可以进入如下操作\n");
	printf("            1.录入信息\n");
	printf("            2.修改信息\n");
	printf("            3.删除信息\n");
	printf("            4.退出\n");
    printf("            请输入您的选择服务:\n");
}
void MangerMenu()
	{
	    int m;
	    int sel=1;
	while(sel)
	{
	    MangerMenu1();
	    scanf("%d",&m);
	    switch(m)
	   {
	case 1: input_infor();
	           break;
	case 2:
	    {
	        struct course c2;
	        printf("请输入该课程对应的正确信息,依次为(课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期)\n");
	        scanf("%s%s%s%d%d%d%d%s",c2.nums,c2.name,c2.nature,&c2.total_time,&c2.cla,&c2.exper,&c2.credit,c2.term);
	        modify(&c2,c2.nums);
	    }
	    break;
	case 3: del();
	       break;
	case 4: sel=0;
	       break;
	   }
	}
  firstmenu();
  }
void Laoshiformer()
{
	int i=0;
	char password[10]={0};
	char name[20];
	printf("          请输入用户名:\n");
	scanf("%s",name);
	printf("          请输入您的密码:\n");
	while(i<3)
	{
		scanf("%s",password);
		printf("\n");
		if(strcmp(password,"2019666")==0)
		{
			printf("          登陆成功^_^\n");
		  MangerMenu1();
		  MangerMenu();
		    break;
	    }
	   else
	   {
		i++;
		if(i!=3)
			printf("          请您再输入一次:\n");
	   }
	}
	if(i==3)
      {
          printf("          您的密码错误系统将退出登录界面*_*\n");
	     firstmenu();
      }
}
void Xueshengformer()
{
     int i=0;
  char password[10]={0};
	char name[20];
	printf("          请输入用户名!\n");
	scanf("%s",name);
	printf("          请输入您的密码\n");
	while(i<3)
	{
		scanf("%s",password);
		printf("\n");
		if(strcmp(password,"2019999")==0)
		{
			printf("          登陆成功啦^_^\n");
		 StudentMenu();
		break;
	}
	else
	{
		i++;
		if(i!=3)
			printf("          不要灰心，请您再输入一次*_*:\n");
	}
	}
	if(i==3)

		printf("          流泪了，您的密码错误系统将退出登录界面\n");
		firstmenu();
	}
void Paixu()
{
    int i,j;
    struct course class;
    FILE *fp;
    fp=fopen("G:\\测试\\test.dat","rb");
    if(fp==NULL)
        printf("文件打开失败");
    else
    {
        for(i=0;i<total;i++)
    {
        fread(&cour[i],sizeof(struct course),1,fp);
    }

    }
    //if(fread(&cour[i],sizeof(struct course),1,fp)!=0)
    for(i=0;i<total-1;i++)
	{
		for(j=0;j<total-1-i;j++)
		{
			if(strcmp(cour[j].name,cour[j+1].name)>0)
			{
				class=cour[j];
				cour[j]=cour[j+1];
				cour[j+1]=class;
			}
		}
	}
	printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
   for(i=0;i<total;i++)
{
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,cour[i].nature,cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
}
StudentMenu();
}
//依次输出
void input_infor()//录入课程信息
{
    int i;
    printf("请输入你要录入的课程信息(课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期)\n");
    for(i=0;i<size;i++)
    {
    scanf("%s%s%s%d%d%d%d%s",cour[i].nums,cour[i].name,cour[i].nature,&cour[i].total_time,&cour[i].cla,&cour[i].exper,&cour[i].credit,cour[i].term);
    total++;//得出当前录入课程的数目
    }
    save();
    printf("录入课程信息成功\n");
    printf("**********");
    printf("请录入学生的相关信息\n");
    printf("请依次输入学生的学号，姓名，获得的总学分!\n");
    for(i=0;i<N;i++)
    {
     scanf("%s%s%d",stu[i].numbers,stu[i].sname,&stu[i].total_credits);
    }
    printf("**********");
     printf("录入学生信息成功\n");
    printf("按任意键进入到主菜单中");
    getchar();
    system("cls");
}

void menu2()
{
printf("\n\n\t\t**********请选择查询方式*************\n");
printf("\n\t\t\t1---按课程编号查找\n");
printf("\n\t\t\t2---按课程名称查找\n");
printf("\n\t\t\t3---按课程性质查找\n");
printf("\n\t\t\t4---按学分查找\n");
printf("\n\t\t\t5---按开课学期查找\n");
printf("\n\t\t\t0---退出查找\n");
printf("\n\n\t\t**************************************\n");
}

void search()//查询课程
{
int i,sel=1;
char min[10],kind[10],no[10],date[10];
int a,grade;
/*menu2();
printf("\n\n请输入你要进行的选项(0-5):[ ]\b\b");
scanf("%d",&a);*/
while(sel)//输入0退出
{
  menu2();
  printf("\n\n请输入你要进行的选项(0-5):[ ]\b\b");
  scanf("%d",&a);
	switch(a)
{

case 1:
    //put_infor();//文件导出函数
printf("输入要查找的课程的编号:");
scanf("%s",no);
printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
for(i=0;i<size;i++)
{
if(cour[i].nums!=NULL&&strcmp(no,cour[i].nums)==0)
{
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,cour[i].nature,cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
}
}
break;

case 2:
printf("请输入要查找的课程的名称:");
scanf("%s",min);
put_infor();
printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
for(i=0;i<size;i++)
{
if(cour[i].name!=NULL&&strcmp(min,cour[i].name)==0)
{
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,cour[i].nature,cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
}
}
break;

case 3:
printf("请输入要查找的课程的性质:");
scanf("%s",kind);
put_infor();
printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
for(i=0;i<size;i++)
{
if(cour[i].nature!=NULL&&strcmp(kind,cour[i].nature)==0)
{
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,cour[i].nature,
       cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
}
}
break;

case 4:
printf("输入要查找的课程的学分:");
scanf("%d",&grade);
put_infor();
printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
for(i=0;i<size;i++)
{
if(cour[i].credit!=0&&grade==cour[i].credit)
{
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,
       cour[i].nature,cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
}
}
break;

case 5:
printf("输入要查找的课程的开课学期:");
scanf("%s",date);
put_infor();
printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
for(i=0;i<size;i++)
{
if(cour[i].term!=NULL&&strcmp(date,cour[i].term)==0)
{
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",cour[i].nums,cour[i].name,
       cour[i].nature,cour[i].total_time,cour[i].cla,cour[i].exper,cour[i].credit,cour[i].term);
}
}
break;

case 0:sel=0;

}
}
StudentMenu();
}

void menu3()
   {
    printf("\n\n\t\t**********请选择删除方式*************\n");
    printf("\n\t\t\t1---按课程编号删除\n");
    printf("\n\t\t\t2---按课程名称删除\n");
    printf("\n\t\t\t3---按课程性质删除\n");
    printf("\n\t\t\t0---退出删除界面\n");
    printf("\n\n\t\t**************************************\n");
   }
void del()//删除课程信息
{

    int i,sel=1;
    int c;
    int j;
    char b[10];
 while(sel)//输入0则退出循环
 {
     menu3();
   scanf("%d",&c);
   switch(c)
  {
    case 1:printf("请 输 入 课 程 编 号");
        scanf("%s",b);
        for(i=0;i<size;i++)
     {
        if(cour[i].nums!=NULL&&strcmp(b,cour[i].nums)==0)
        {
            for(j=i;j<size;j++)
            cour[j]=cour[j+1];
            total=total-1;
        }
     }
     printf("删除成功");
     break;
    case 2:printf("请 输 入 课 程 名 称");
        scanf("%s",b);
        for(i=0;i<size;i++)
     {
        if(cour[i].name!=NULL&&strcmp(b,cour[i].name)==0)
        {
            for(j=i;j<size;j++)
            cour[j]=cour[j+1];
            total=total-1;
        }
     }
     printf("删除成功");
     break;
    case 3:
        printf("请 输 入 课 程 性 质");
        scanf("%s",b);
        for(i=0;i<size;i++)
     {
        if(cour[i].nature!=NULL&&strcmp(b,cour[i].nature)==0)
        {
            for(j=i;j<size;j++)
            {
                cour[j]=cour[j+1];
            }
            total=total-1;
        }
     }
     printf("删除成功");
     break;
    case 0:sel=0;
         break;
  }
}
MangerMenu();
}
void choose(struct student *stu)  //选课
{
    FILE *fp;
    char n[10];
    //int i=0;
    printf("请输入要选课程的编号：");
    scanf("%s",n);
    fp=fopen("G:\\测试\\test.dat","rb+");
    if(fp==NULL)
            printf("该文件不存在\n");
    else
    {
        struct course c1;
        fread(&c1,sizeof(struct course),1,fp);
        while(!feof(fp))
       {
           if(strcmp(n,c1.nums)==0)
          {
              stu->c[course_nums]=c1;
              course_nums++;
           }

          fread(&c1,sizeof(struct course),1,fp);
       }
       if(course_nums!=0)
      {
          printf("选课成功!\n");
          int i=course_nums;
          printf("你的选修课程信息如下：\n");
          printf("\n课程编号  课程名称  课程类别  总学时  授课学时  上机学时  学分  开课学期\n");
          printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",stu->c[i-1].nums,stu->c[i-1].name,stu->c[i-1].nature,
         stu->c[i-1].total_time,stu->c[i-1].cla,stu->c[i-1].exper,stu->c[i-1].credit,stu->c[i-1].term);
      }
    else
        printf("选课失败,请重新选择\n");
   }
   fclose(fp);
   StudentMenu();
}

void print_information(struct student stu1)
{
    int i;
printf("你的信息如下：\n");
printf("  学号      姓名     总学分   \n");
printf("%s   %6s   %10d",stu1.numbers,stu1.sname,stu1.total_credits);
printf("\n课程编号  课程名称  课程类别  总学时  授课学时  上机学时  学分  开课学期\n");
for(i=0;i<size;i++)
printf("%-4s %10s %10s %8d %8d %8d %8d %8s\n",stu1.c[i].nums,stu1.c[i].name,
       stu1.c[i].nature,stu1.c[i].total_time,stu1.c[i].cla,stu1.c[i].exper,stu1.c[i].credit,stu1.c[i].term);
}



int main()
{
    system("color E2");
	//char numbers[10];学号char sname[20]姓名 int total_credits;总学分

    firstmenu();
    return 0;
}




