#include"stdio.h"
#include"string.h"
#include"stdlib.h"

struct Account
{
	char name[100];
	char IDcard[100];

	char username[100];
	char password[100];
	float money;

	struct Account * next;
};

typedef struct Account Account;

Account * head=NULL;
Account * tail=NULL;

Account *curAccount=NULL;

void menu()
{
	int select;
	while(select!=0)
	{
		printf("\t\t\t\t\t*****��ӭʹ��!***** \n");
	   	printf("\t\t\t\t\t     1.��ѯ��� \n");
    	printf("\t\t\t\t\t     2.ȡ��\n");
	    printf("\t\t\t\t\t     3.���\n");
    	printf("\t\t\t\t\t     0.�˳�ʹ��\n");
     	printf("\t\t\t\t\t     ����������ѡ�\n");
		scanf("%d",&select);
		system("cls");
		if(select!=0 && select!=1 && select!=2 && select!=3)
		{
			printf("�������ѡ����������������\n");
			continue;
		}
		switch(select)
		{
	     	case 1: one();break;
			case 2: drawMoney();break;
			case 3: saveMoney();break;
		}
	}
	if(select==0)
	{
		zero();
	}

}

void one()
{
    printf("\t\t\t\t\t     �������Ϊ��%f\n",deposit);
	system("pause");
	system("cls");
}

void zero()
{
    printf("��ӭ���ٴ�ʹ�ã�\n");
}

int finAccount(Account a)
{
	Account * curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)&&(strcmp(curP->password,a.password)==0))
		{
			curAccpunt = curP;
			return 1;
		
		}
		curP=curP->next;
	}
	return 0;

}

void updatepassword()
{
	char oldpassword[100]={'\0'};
	printf("����������룺\n");

	scanf("%s",oldpassword);
	if(strcmp(oldpassword,curAccount->password)==0)
	{
		printf("�����������룺\n");
		scanf("%s",curAccount->password);
	}
	else
	{
		printf("������󣬲����޸ģ�\n");
	}

}

void showMenu()
{
	system("cls");
	printf("�޸������밴1��\n");

    updatepassword();

}

void sighIn()
{
	Account a;
	printf("�������˺ţ�\n");
	scanf("%s",a.username);

    printf("���������룺\n");
    scanf("%s",a.password);

	if(finAccount(a))
	{
        printf("��½�ɹ���\n");
		showMenu();
	}
	else
	{  
		printf("��½ʧ�ܣ�\n");
		int count=0;
        while(count<=3);
		{
              scanf("%s",a.password);
			  if(finAccount(a))
			  {
                  printf("��½�ɹ���\n");
				  break;
			  }
			  else
			  {
				  count++;
			  }
		}
        printf("δ��¼�ɹ����˺��ѱ�����\n");
	}
}

int loaDate()
{
	FILE * fp=fopen("D:\\atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
			Account * newNode=(Account *) malloc(sizeof(Account));

			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNeod->username,newNode->password);

			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		fclose(fp);
		return 1;
	}
}

void printLinkedlist()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}
}

void drawMoney()
{
	float money;
	printf("������ȡ���\n");
	scanf("%f",&money);
	curAccount->money-=money;
}

void saveMoney()
{
	float money;
	printf("�������Ǯ�Ľ��:\n");
    scanf("%f",&money);
	curAccount->money+=money;
}

int main()
{
	int status=loaDate();
	if(status==1)
	{
		printf("���سɹ���\n");
	}
	else
	{
        printf("����ʧ�ܣ�\n");
	}

    float deposit=0.0;
	menu();//������˵�

	printLinkedlist();//���

	sighIn();//��¼

    loaDate();//����

	drawMoney();//ȡǮ

	saveMoney();//��Ǯ

	return 0;

}