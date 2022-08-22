#include<iostream>
#include<cstring>
#include<process.h>
using namespace std;
class dnode
{
    public:
        char number[50];
        char gmail[40];
        char name[30];
        char city[30];
        dnode *prev,*next;
        dnode(char n[],char r[],char g[],char c[])
{
               strcpy(name,n);
            	strcpy(number,r);
               strcpy(gmail,g);
               strcpy(city,c);
                next=NULL;
                prev=NULL;
}
	friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr;
    
    dnode *ptr1, *ptr2, *dup;
    public:
    dnode *prevn;
        
    void insert();
    void deletecontact(char n[20]);
    void deletesamename();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);
    void emergencydial(char c1[30]);

        
        void accept();
        void display();
        void update(char ch[10]);
        dlist()
                {
                        head=NULL;
                        temp=NULL;
                        ptr=NULL;
                        ptr1=NULL;
                        ptr2=NULL;
                        dup=NULL;
                }
};

void dlist::accept()
{
        char number[50];
        char gmail[40];
        char name[30];
        char city[30];
    char ans;
      do
        {
    cout<<"ENTER NAME      :";
    cin>>name;
   
    cout<<"ENTER NUMBER    :";
    cin>>number;
    while(strlen(number)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>number;
    }
    cout<<"ENTER E-MAIL    :";
    cin>>gmail;
    cout<<"ENTER CITY    :";
    cin>>city;
    temp=new dnode(name,number,gmail,city);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
    }
	    cout<<"\n\nDO YOU WANT TO CONTINUE?????????";
    	cin>>ans;
    	cout<<endl;
}while(ans=='y');

}
void dlist::display()
{
    ptr=head;
	while(ptr!=NULL)
	{
			cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nE-MAIL ID::\t"<<ptr->gmail;
			cout<<"\nCITY::  \t"<<ptr->city;
			ptr=ptr->next;
	}
}

    void dlist::insert()
    {
        accept();
    }
    
    void dlist::deletecontact(char s[20])
    {
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            ptr=ptr->next;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr==head)
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(c==2)
        {
            cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...";
        }
    }
    void dlist::deletesamename()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (strcmp(ptr1->name,ptr2->next->name)==0)
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    } 
    }
    void dlist::searchbyname(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                cout<<"\nNAME FOUND"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nE-MAIL ID::\t"<<ptr->gmail;
		        
            }
            else
            {
            	cout<"\nNAME NOT FOUND";
			}
            ptr=ptr->next;
        }
    }
    void dlist::searchbynumber(char num[20])
    {
     ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                cout<<"\nNUMBER FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nE-MAIL ID::\t"<<ptr->gmail;
		        
            }
            else
            {
            	cout<"NUMBER NOT FOUND";
			}
            ptr=ptr->next;
        }   
    }
    void dlist::searchbygmail(char gm[20])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(gm,ptr->gmail)==0)
            {
                cout<<"\nE-MAIL ID FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nE-MAIL ID::\t"<<ptr->gmail;
		        
            }
            else
            {
            	cout<"E-MAIL ID NOT FOUND";
			}
            ptr=ptr->next;
        }
    }
    void dlist::emergencydial(char ct[30])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(ct,ptr->city)==0)
            {
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nE-MAIL ID::\t"<<ptr->gmail;
			cout<<"\nCITY::\t"<<ptr->city;
		        
            }
            ptr=ptr->next;
        }
    }
    void dlist::update(char n[20])
    {
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                
                do
                {
                    cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.E-MAIL ID\n4.CITY\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"\nENTER NEW-NAME: ";
                    cin>>ptr->name;
                    break;
                    case 2:
                    cout<<"\nENTER NEW PHONE-NUMBER: ";
                    cin>>ptr->number;
                    while(strlen(ptr->number)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>ptr->number;
    }
                    break;
                    case 3:
                    cout<<"\nENTER NEW E-MAIL ID: ";
                    cin>>ptr->gmail;
                    break;
                    case 4:
                    cout<<"\nENTER NEW CITY : ";
                    cin>>ptr->city;
                    break;
                }
                cout<<"\n\nDO YOU WANT TO CONTINUE UPDATING?";
                cin>>ans;
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }
int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    char city[30];
    char password[30];
    dlist d1;
    char ans;
    int ch,a;
    cout<<"\t\t**************PHONE BOOK********************";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name,20);
    cout<<"\n\nWHAT IS YOUR HOME TOWN?\n";
    cin.getline(city,20);
    cout<<"\n\nCREATE YOUR PHONEBOOK PASSWORD:\n";
    cin.getline(password,20);
    cout<<"\n\n\t\t*******************WELCOME "<<name<<"*********************";
    cout<<"\n\n\nLET'S CREATE YOUR PHONEBOOK "<<name<<"  \n\n";
    do
    {
    cout<<"\n\t\t*******PHONEBOOK OPERATION MENU*******";
    cout<<"\n\n\n\t\t1. INSERT NEW CONTACT\n";
    cout<<"\t\t2. DISPALY CONTACT LISTS\n";
    cout<<"\t\t3. UPDATE DETAILS ON EXISTING CONTACT\n";
    cout<<"\t\t4. DELETE CONTACT\n";
    cout<<"\t\t5. DELETE SAME NAME IN PHONEBOOK\n";
    cout<<"\t\t6. SEARCH\n";
    cout<<"\t\t7. EMERGENCY DIAL LIST\n";
    cout<<"\t\t8. EXIT\n";
    cout<<"ENTER YOUR CHOICE: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
    d1.insert();
  	break;
    
    case 2:
    d1.display();
    break;
    case 3:
    	char p0[30];
    	cout<<"\nENTER YOUR PASSWORD TO ACCESS THE OPERATION :\n";
    	cin>>p0;
    	if(strcmp(p0,password)==0)
    	{
			cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
        	cin>>n;
        	d1.update(n);
    		 
		}
		else
		{
			cout<<"INCORRECT PASSWORD\n";
		}
    break;
    case 4:
    	char p[30];
    	cout<<"\nENTER YOUR PASSWORD TO ACCESS THE OPERATION :\n";
    	cin>>p;
    	if(strcmp(p,password)==0)
    	{
    		 cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
             cin>>name;
    		 d1.deletecontact(name);
		}
		else
		{
			cout<<"INCORRECT PASSWORD\n";
		}
    break;
    case 5:
    	char p1[30];
    	cout<<"\nENTER YOUR PASSWORD TO ACCESS THE OPERATION :\n";
    	cin>>p1;
    	if(strcmp(p1,password)==0)
    	{
    		 d1.deletesamename();
    		d1.display();
		}
		else
		{
			cout<<"INCORRECT PASSWORD\n";
		}
    break;
    case 6:
    do
    {
    cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY E-MAIL ID\n";
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"ENTER THE NAME TO BE SEARCHED\n";
        cin>>name;
        d1.searchbyname(name);
        break;
        case 2:
        cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
        cin>>number;
        d1.searchbynumber(number);
        break;
        case 3:
        cout<<"ENTER THE E-MAIL ID TO BE SEARCHED\n";
        cin>>gmail;
        d1.searchbygmail(gmail);
        break;
        default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
    }
    cout<<"\n\nDO YOU WANT TO CONTINUE SEARCHING?????????";
    cin>>ans;
}while(ans=='y');

    break;
    case 7:
    	d1.emergencydial(city);
    	break;
    	
    case 8:
    	cout<<"\n\t\t****THANK YOU***";
    	exit(0);
    break;
    default:cout<<"\nNO PROPER INPUT GIVEN..\n";
    }
    cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
    cin>>ans;
}while(ans=='y');
}
