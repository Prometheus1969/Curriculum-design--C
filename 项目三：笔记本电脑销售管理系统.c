#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

//---------------v00001--------------------------------------------------------------------------------------------------------------------

struct Computer                        
{
    char Name[100];                    
	char Brand[100];                  
	char Type[100];                     
	int Sell_quantity;                  
	float Purchase_price;              
	int Remain_quantity;              
	float Sell_price;                 
	float total_money;	               
	struct Computer *next;           
}; 

//---------------v00002--------------------------------------------------------------------------------------------------------------------

#define LEN sizeof(struct Computer)
void CREAT(void);                    
void MENU(void);
void FIND(struct Computer *head);
void SAVE(struct Computer *head);
void ADD(struct Computer *head);
void CHANGE(struct Computer *head);
void DELETe(struct Computer *head);
void HIGH(struct Computer *head);
void SEARCH(struct Computer *head);
void SELL(struct Computer *head); 

//---------------v00003--------------------------------------------------------------------------------------------------------------------

int main()
{
	int number,count;
	FILE *fp;
	system("mode con cols=120 lines=100");         // 行  列 
	system("color F0");
	printf("\n---------------------------------------------欢迎进入笔记本电脑销售管理系统---------------------------------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC); 
	printf("                                                                                        版本型号： V2.1.5\n"); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("·准备好后请按回车键开始（请不要乱按其他键，否则会造成程序错误）\n");
	printf("·Please enter the Enter key to start！"); 
	getchar();
	if((fp = fopen("SellRecord.txt","rb"))==NULL)
	{ 
		printf("        +-------------------------------------------------------------------------------------------------------+\n\n");
	    printf("        |    提示：您是第一次使用该系统，请先录入笔记销售信息！                                                 |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF9);
	    printf("        |                                        ·服务编号：                                                   |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	    printf("        |                                        1.新建笔记本电脑信息                                           |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF6);
	    printf("        |                                        2.退出系统                                                     |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
		printf("        +-------------------------------------------------------------------------------------------------------+\n\n");
        printf("        Input: ");
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	    scanf("%d",&number);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
		if(number==1)  CREAT();
		else if(number==2)  exit(0);
    	else
	    {
	    	printf("                    未查到此编号，回车键退出系统！");
	    	getchar();
	    	exit(0); 
    	}
	}
	else
	{
        fclose(fp);
		MENU();
    }
    return 0;
}

//---------------v00004--------------------------------------------------------------------------------------------------------------------

void MENU(void)
{
	int number;
	FILE *fp;
	int t;
	struct Computer *p1,*p2,*head;
	
	p1=(struct Computer *)malloc(LEN);
	head=p1;
	if((fp=fopen("SellRecord.txt","rb"))==NULL)
	{
		printf("                    未找到该信息！回车键退出程序\n");
		getchar();
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(p1,LEN,1,fp)!=1)	break;                         
		p1->next=(struct Computer *)malloc(LEN);
		if(p1->next==NULL)
		{
			printf("                    error:回车键退出程序\n");
			getchar();
			exit(0);
		}
		p2=p1;
		p1=p1->next;
	}
	p2->next=NULL;
	fclose(fp);

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("\n---------------------------------------------欢迎进入笔记本电脑销售管理系统---------------------------------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf("                                                                                        版本型号： V2.1.5\n"); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("        +-------------------------------------------------------------------------------------------------------+\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf("        |                                        ·服务编号：                                                   | \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	printf("        |                                        1.添加笔记本电脑信息                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF9);
	printf("        |                                        2.删除笔记本电脑信息                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF6);
	printf("        |                                        3.修改笔记本电脑信息                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf("        |                                        4.查询笔记本库存现状                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF4);
	printf("        |                                        5.查询目前销量最高的笔记本                                     |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
    printf("        |                                        6.查询某品牌笔记本库存                                         |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFD);
	printf("        |                                        7.笔记本销售                                                   |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF5);
	printf("        |                                        8.退出系统                                                     |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF8);
	printf("        |                                        9.格式化系统                                                   |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("        +-------------------------------------------------------------------------------------------------------+\n");
    printf("        Input: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
    scanf("%d",&number);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	if(number==1)  ADD(head);
	else if(number==2)  DELETe(head);
	else if(number==3)  CHANGE(head);
	else if(number==4)  FIND(head);
	else if(number==5)  HIGH(head);
	else if(number==6)  SEARCH(head);
	else if(number==7)  SELL(head); 
	else if(number==8)  exit(0);
	else if(number==9)
	{
		getchar();
        remove("SellRecord.txt");
		printf("                    请按回车键退出系统，并重新启动程序\n");
		getchar(); 
		exit(0);	
	}
	else
	{
		printf("                    未查到此编号，回车键退出系统！\n");
		getchar();
		getchar();
		exit(0); 
	}
}

//---------------v00005--------------------------------------------------------------------------------------------------------------------

void CREAT(void)
{
	struct Computer *p1,*p2,*head=NULL,*p=NULL;
	
	FILE *fp;
	p1 = p2 = (struct Computer*)malloc(LEN);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	fp = fopen("SellRecord.txt","wb+");
    printf("                    ·请按如下格式输入来添加笔记本销售信息：\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    产品名称 产品品牌 产品型号 销售数量 进价 库存数量 售价\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("                    ·当输入产品名称为0时则为停止录入！\n\n");
	printf("                    Input: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	scanf("%s",p1->Name);
	while(p1->Name[0]!='0')
	{
		scanf("%s %s %d",p1->Brand,p1->Type,&p1->Sell_quantity);
		scanf("%f %d %f",&p1->Purchase_price,&p1->Remain_quantity,&p1->Sell_price);
		p1->total_money = p1->Sell_quantity*p1->Sell_price;
		if(head==NULL)
		    head = p1;
		else
		    p2->next = p1;
		p2 = p1;
		p1 = (struct Computer*)malloc(LEN);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
        printf("                    Input: ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
		scanf("%s",p1->Name);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
    fclose(fp);
	p2->next = NULL;
	free(p1);
    SAVE(head); 
} 

//---------------v00006--------------------------------------------------------------------------------------------------------------------

void SAVE(struct Computer *head)
{
	struct Computer *p;
	int s=0,k;
	FILE *fp;
	
	p = head;
	if((fp=fopen("SellRecord.txt","wb"))==NULL)
	{
		printf("                    未找到该信息！回车键退出程序\n");
		getchar();
		exit(0);
	}
	else
	{
	    while(p!=NULL)
	    {
		    fwrite(p,LEN,1,fp);
		    p = p->next;
	    }
	    fclose(fp);
	    printf("                    保存成功！请按回车键继续！\n");
	    getchar();
	    getchar();
	    if((fp=fopen("SellRecord.txt","rb"))==NULL)
	    {
		    printf("                    未找到该信息！回车键退出程序\n");
		    getchar();
		    exit(0);
	    }
	    MENU();
    }
}

//---------------v00007--------------------------------------------------------------------------------------------------------------------

void FIND(struct Computer *head)
{
	struct Computer *p;
	
	system("CLS");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                               请按回车键查看！");
    getchar();
    getchar();
	p = head;
	if(head==NULL)
	{
		printf("                    未找到该信息！回车键退出程序\n");
		getchar();
		exit(0);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	    printf("       +---------------------------------------------------------------------------------------------------------+\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
		printf("       |  产品名称         产品品牌        产品型号        销售数量   进价     库存数量    售价       金额       |\n");
	    while(p!=NULL)
	    {
	    	p->total_money = p->Sell_quantity*p->Sell_price;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
		    printf("       +---------------------------------------------------------------------------------------------------------+\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
			printf("       |  %-16s %-16s %-16s %-6d %-12.2f %-6d %-12.2f %-12.2f|\n",p->Name,p->Brand,p->Type,p->Sell_quantity,p->Purchase_price,p->Remain_quantity,p->Sell_price,p->total_money);
            p = p->next;
	    }
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
		printf("       +---------------------------------------------------------------------------------------------------------+\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	}
	printf("                                               请按回车键继续");
	getchar();
	MENU();
}

//---------------v00008--------------------------------------------------------------------------------------------------------------------

void ADD(struct Computer *head)
{
	struct Computer *p1,*p2;
	FILE *fp;
	
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                    ·请按如下格式输入来新增一条笔记本销售信息：\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    产品名称 产品品牌 产品型号 销售数量 进价 库存数量 售价\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	p1 = head;
	if(head==NULL)
	{
		printf("                    未找到该信息！回车键退出程序\n");
		getchar();
		exit(0);
	}
	else
	{
		while(p1->next!=NULL)  p1 = p1->next;
        p2 = (struct Computer*)malloc(LEN);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
        printf("                    Input: ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	    scanf("%s",p2->Name);
	    printf("\n");
        scanf("%s %s %d",p2->Brand,p2->Type,&p2->Sell_quantity);
		scanf("%f %d %f",&p2->Purchase_price,&p2->Remain_quantity,&p2->Sell_price);
		p1->total_money = p1->Sell_quantity*p1->Sell_price;
		p1->next = p2;
		p2->next = NULL;
	}
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	fp = fopen("SellRecord.txt","wb+");
    fclose(fp);
	SAVE(head);
}

//---------------v00009--------------------------------------------------------------------------------------------------------------------

void DELETe(struct Computer *head)
{
    struct Computer *p;
    char ch1[100],ch2[100],ch3[100],flag=0;
    FILE *fp;
    
    p = head;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                    ·请按如下格式输入来删除一条笔记本销售信息：\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    产品名称 产品品牌 产品型号\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
    printf("                    Input: ");
	getchar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
    scanf("%s %s %s",ch1,ch2,ch3);
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
    if(strcmp(ch1,p->Name)==0&&strcmp(ch2,p->Brand)==0&&strcmp(ch3,p->Type)==0)
    {
        head = p->next;
        flag = 1;
    }
    else
    {
        while(p->next!=NULL)
        { 
    	    if(strcmp(ch1,(p->next)->Name)==0&&strcmp(ch2,(p->next)->Brand)==0&&strcmp(ch3,(p->next)->Type)==0)
    	    {
		        p->next = (p->next)->next;
                flag = 1;
            }
        	if(flag==1)  break;
        	p = p->next;
		}
	}
    if(flag==0)  printf("                    未找到该信息！\n");
	fp = fopen("SellRecord.txt","wb+");
    fclose(fp);
	SAVE(head);
}

//---------------v00010--------------------------------------------------------------------------------------------------------------------

void CHANGE(struct Computer *head)
{
    struct Computer *p;
    char ch1[100],ch2[100],ch3[100];
    int a,b,flag=0;
	float c,d;
	FILE *fp;
    
    p = head;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                    请按如下格式输入来修改一条笔记本销售信息：\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    产品名称 产品品牌 产品型号 销售数量(修改后) 进价(修改后) 库存数量(修改后) 售价(修改后)\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("                    Input: "); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
    scanf("%s %s %s %d %f %d %f",ch1,ch2,ch3,&a,&c,&b,&d);
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
    while(p!=NULL)
    {
    	if(strcmp(ch1,p->Name)==0&&strcmp(ch2,p->Brand)==0&&strcmp(ch3,p->Type)==0)
    	{
    		flag = 1;
    		p->Sell_quantity = a;
    		p->Purchase_price = c;
    		p->Remain_quantity = b;
    		p->Sell_price = d;
		    p->total_money = p->Sell_quantity*p->Sell_price;
		}
		if(flag==1)  break;
		p = p->next;
	}
	if(flag==0)  printf("                     未找到该信息！\n");
	fp = fopen("SellRecord.txt","wb+");
    fclose(fp);
	SAVE(head);
}

//---------------v00011--------------------------------------------------------------------------------------------------------------------

void HIGH(struct Computer *head)
{
	struct Computer *p,temp;
	int max;
	
	system("cls");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	getchar();
	p = head;
	max = 0;
	while(p!=NULL)
	{
		if(p->Sell_quantity>max)
		{
		    temp = *p;
		    max = p->Sell_quantity;
		}
		p = p->next;
	}
	p = head;
	printf("              销售最多为");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf(" %d ",max);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("台，品牌型号类型为: \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	while(p!=NULL)
	{
		if(p->Sell_quantity==max)
		    printf("                                    %-16s %-16s %-16s\n\n",p->Name,p->Brand,p->Type);
		p = p->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("\n");
	printf("                                               请按回车键继续");
	getchar();
    MENU();
}

//---------------v00012--------------------------------------------------------------------------------------------------------------------

void SEARCH(struct Computer *head)
{
    struct Computer *p;
    char ch1[100];
    FILE *fp;
    
    system("cls");
    p = head;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                    ·请输入要查询的笔记本品牌：\n\n");
	printf("                    Input: ");
	getchar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
    scanf("%s",ch1);
    printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	printf("       +---------------------------------------------------------------------------------------------------------+\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("       |  产品名称         产品品牌        产品型号        销售数量   进价     库存数量    售价       金额       |\n");
    while(p!=NULL)
    { 
    	if(strcmp(ch1,p->Brand)==0)
    	{
	    	p->total_money = p->Sell_quantity*p->Sell_price;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
		    printf("       +---------------------------------------------------------------------------------------------------------+\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
			printf("       |  %-16s %-16s %-16s %-6d %-12.2f %-6d %-12.2f %-12.2f|\n",p->Name,p->Brand,p->Type,p->Sell_quantity,p->Purchase_price,p->Remain_quantity,p->Sell_price,p->total_money);
        }
        	p = p->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	printf("       +---------------------------------------------------------------------------------------------------------+\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("                                               请按回车键继续");
	getchar();
	getchar();
	MENU();
}

//---------------v00013--------------------------------------------------------------------------------------------------------------------

void SELL(struct Computer *head)
{
    struct Computer *p;
    char ch1[100],ch2[100],ch3[100];
    int a,flag=0;
	FILE *fp;
    
    p = head;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                    请按如下格式销售笔记本：\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    产品名称 产品品牌 产品型号 卖出台数\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("                    Input: "); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
    scanf("%s %s %s %d",ch1,ch2,ch3,&a);
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
    while(p!=NULL)
    {
    	if(strcmp(ch1,p->Name)==0&&strcmp(ch2,p->Brand)==0&&strcmp(ch3,p->Type)==0)
    	{
    		flag = 1;
            if(p->Remain_quantity<a)
                printf("                    余额不足，销售失败！\n\n");
            else
                p->Remain_quantity = p->Remain_quantity-a;
    	    p->total_money = p->Sell_quantity*p->Sell_price;
		}
		if(flag==1)  break;
		p = p->next;
	}
	if(flag==0)  printf("                     未找到该信息！\n");
	fp = fopen("SellRecord.txt","wb+");
    fclose(fp);
	SAVE(head);
}
