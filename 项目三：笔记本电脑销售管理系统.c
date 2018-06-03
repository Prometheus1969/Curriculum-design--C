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
	system("mode con cols=120 lines=100");         // ��  �� 
	system("color F0");
	printf("\n---------------------------------------------��ӭ����ʼǱ��������۹���ϵͳ---------------------------------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC); 
	printf("                                                                                        �汾�ͺţ� V2.1.5\n"); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("��׼���ú��밴�س�����ʼ���벻Ҫ�Ұ����������������ɳ������\n");
	printf("��Please enter the Enter key to start��"); 
	getchar();
	if((fp = fopen("SellRecord.txt","rb"))==NULL)
	{ 
		printf("        +-------------------------------------------------------------------------------------------------------+\n\n");
	    printf("        |    ��ʾ�����ǵ�һ��ʹ�ø�ϵͳ������¼��ʼ�������Ϣ��                                                 |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF9);
	    printf("        |                                        �������ţ�                                                   |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	    printf("        |                                        1.�½��ʼǱ�������Ϣ                                           |\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF6);
	    printf("        |                                        2.�˳�ϵͳ                                                     |\n\n");
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
	    	printf("                    δ�鵽�˱�ţ��س����˳�ϵͳ��");
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
		printf("                    δ�ҵ�����Ϣ���س����˳�����\n");
		getchar();
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(p1,LEN,1,fp)!=1)	break;                         
		p1->next=(struct Computer *)malloc(LEN);
		if(p1->next==NULL)
		{
			printf("                    error:�س����˳�����\n");
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
	printf("\n---------------------------------------------��ӭ����ʼǱ��������۹���ϵͳ---------------------------------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf("                                                                                        �汾�ͺţ� V2.1.5\n"); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("        +-------------------------------------------------------------------------------------------------------+\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf("        |                                        �������ţ�                                                   | \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	printf("        |                                        1.��ӱʼǱ�������Ϣ                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF9);
	printf("        |                                        2.ɾ���ʼǱ�������Ϣ                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF6);
	printf("        |                                        3.�޸ıʼǱ�������Ϣ                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf("        |                                        4.��ѯ�ʼǱ������״                                           |\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF4);
	printf("        |                                        5.��ѯĿǰ������ߵıʼǱ�                                     |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
    printf("        |                                        6.��ѯĳƷ�ƱʼǱ����                                         |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFD);
	printf("        |                                        7.�ʼǱ�����                                                   |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF5);
	printf("        |                                        8.�˳�ϵͳ                                                     |\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF8);
	printf("        |                                        9.��ʽ��ϵͳ                                                   |\n\n");
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
		printf("                    �밴�س����˳�ϵͳ����������������\n");
		getchar(); 
		exit(0);	
	}
	else
	{
		printf("                    δ�鵽�˱�ţ��س����˳�ϵͳ��\n");
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
    printf("                    ���밴���¸�ʽ��������ӱʼǱ�������Ϣ��\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    ��Ʒ���� ��ƷƷ�� ��Ʒ�ͺ� �������� ���� ������� �ۼ�\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("                    ���������Ʒ����Ϊ0ʱ��Ϊֹͣ¼�룡\n\n");
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
		printf("                    δ�ҵ�����Ϣ���س����˳�����\n");
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
	    printf("                    ����ɹ����밴�س���������\n");
	    getchar();
	    getchar();
	    if((fp=fopen("SellRecord.txt","rb"))==NULL)
	    {
		    printf("                    δ�ҵ�����Ϣ���س����˳�����\n");
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
    printf("                                               �밴�س����鿴��");
    getchar();
    getchar();
	p = head;
	if(head==NULL)
	{
		printf("                    δ�ҵ�����Ϣ���س����˳�����\n");
		getchar();
		exit(0);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	    printf("       +---------------------------------------------------------------------------------------------------------+\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
		printf("       |  ��Ʒ����         ��ƷƷ��        ��Ʒ�ͺ�        ��������   ����     �������    �ۼ�       ���       |\n");
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
	printf("                                               �밴�س�������");
	getchar();
	MENU();
}

//---------------v00008--------------------------------------------------------------------------------------------------------------------

void ADD(struct Computer *head)
{
	struct Computer *p1,*p2;
	FILE *fp;
	
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                    ���밴���¸�ʽ����������һ���ʼǱ�������Ϣ��\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    ��Ʒ���� ��ƷƷ�� ��Ʒ�ͺ� �������� ���� ������� �ۼ�\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	p1 = head;
	if(head==NULL)
	{
		printf("                    δ�ҵ�����Ϣ���س����˳�����\n");
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
    printf("                    ���밴���¸�ʽ������ɾ��һ���ʼǱ�������Ϣ��\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    ��Ʒ���� ��ƷƷ�� ��Ʒ�ͺ�\n\n");
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
    if(flag==0)  printf("                    δ�ҵ�����Ϣ��\n");
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
    printf("                    �밴���¸�ʽ�������޸�һ���ʼǱ�������Ϣ��\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    ��Ʒ���� ��ƷƷ�� ��Ʒ�ͺ� ��������(�޸ĺ�) ����(�޸ĺ�) �������(�޸ĺ�) �ۼ�(�޸ĺ�)\n\n");
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
	if(flag==0)  printf("                     δ�ҵ�����Ϣ��\n");
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
	printf("              �������Ϊ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
	printf(" %d ",max);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("̨��Ʒ���ͺ�����Ϊ: \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	while(p!=NULL)
	{
		if(p->Sell_quantity==max)
		    printf("                                    %-16s %-16s %-16s\n\n",p->Name,p->Brand,p->Type);
		p = p->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("\n");
	printf("                                               �밴�س�������");
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
    printf("                    ��������Ҫ��ѯ�ıʼǱ�Ʒ�ƣ�\n\n");
	printf("                    Input: ");
	getchar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);
    scanf("%s",ch1);
    printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF2);
	printf("       +---------------------------------------------------------------------------------------------------------+\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);
	printf("       |  ��Ʒ����         ��ƷƷ��        ��Ʒ�ͺ�        ��������   ����     �������    �ۼ�       ���       |\n");
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
	printf("                                               �밴�س�������");
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
    printf("                    �밴���¸�ʽ���۱ʼǱ���\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF1);
	printf("                    ��Ʒ���� ��ƷƷ�� ��Ʒ�ͺ� ����̨��\n\n");
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
                printf("                    ���㣬����ʧ�ܣ�\n\n");
            else
                p->Remain_quantity = p->Remain_quantity-a;
    	    p->total_money = p->Sell_quantity*p->Sell_price;
		}
		if(flag==1)  break;
		p = p->next;
	}
	if(flag==0)  printf("                     δ�ҵ�����Ϣ��\n");
	fp = fopen("SellRecord.txt","wb+");
    fclose(fp);
	SAVE(head);
}
