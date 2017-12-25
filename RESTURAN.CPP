
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>



class product
{
int pno;
char name[50];
float price,qty,tax;
public:
void create_product()
{
cout<<"\nEnter The serial number of dish ";
cin>>pno;
cout<<"\n\nEnter the dish name to be inserted in menu ";
gets(name);
cout<<"\nEnter the price ";
cin>>price;

}
void show_product()
{
cout<<"\n\n Enter the serial number of Dish :"<<pno;
cout<<"\nName of the dish ";
puts(name);
cout<<"\n Price  : "<<price;

}
int retpno()
{return pno;}
float retprice()
{return price;}
char* retname()
{return name;}

};
fstream fp;
product pr;

void write_product()
{
fp.open("Shop.dat",ios::out|ios::app);
pr.create_product();
fp.write((char*)&pr,sizeof(product));
fp.close();
cout<<"\n\nYour dish has been added to menu ";
getch();
}

void display_all()
{
clrscr();
cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
fp.open("Shop.dat",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
pr.show_product();
cout<<"\n\n====================================\n";
getch();
}
fp.close();
getch();
}

void display_sp(int n)
{
int flag=0;
fp.open("Shop.dat",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retpno()==n)
{
clrscr();
pr.show_product();
flag=1;
}
}
fp.close();
if(flag==0)
cout<<"\n\ndish not found";
getch();
}

void modify_product()
{
int no,found=0;
clrscr();
cout<<"\n\n\tTo Modify ";
cout<<"\n\n\tPlease Enter serial number of the dish";
cin>>no;
fp.open("Shop.dat",ios::in|ios::out);
while(fp.read((char*)&pr,sizeof(product)) && found==0)
{
if(pr.retpno()==no)
{
pr.show_product();
cout<<"\nPlease Enter  Details of new  dish"<<endl;
pr.create_product();
int pos=-1*sizeof(pr);
fp.seekp(pos,ios::cur);
fp.write((char*)&pr,sizeof(product));
cout<<"\n\n\t Record Updated";
found=1;
}
}
fp.close();
if(found==0)
cout<<"\n\n Dish Not Found ";
getch();
}

void delete_product()
{
int no;
clrscr();
cout<<"\n\n\n\tDelete Dish";
cout<<"\n\nPlease Enter The dish no. of The dish You Want To Delete";
cin>>no;
fp.open("Shop.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retpno()!=no)
{
fp2.write((char*)&pr,sizeof(product));
}
}
fp2.close();
fp.close();
remove("Shop.dat");
rename("Temp.dat","Shop.dat");
cout<<"\n\n\tDish Deleted ..";
getch();
}

void menu()
{
clrscr();
fp.open("Shop.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create";

cout<<"\n\n\n Program is closing ....";
getch();
exit(0);
}
cout<<"\n\n\t\t MENU\n\n";
cout<<"====================================================\n";
cout<<"D.NO.\t\tNAME\t\tPRICE\n";
cout<<"====================================================\n";
while(fp.read((char*)&pr,sizeof(product)))
{
cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
}
fp.close();
}


void place_order()
{
int order_arr[50],quan[50],c=0;
float amt,damt;
char ch='Y';
menu();
cout<<"\n============================";
cout<<"\n  YOUR ORDER";
cout<<"\n============================\n";
do{
cout<<"\n\nEnter The Dish No. Of The Dish : ";
cin>>order_arr[c];
cout<<"\nQuantity in number : ";
cin>>quan[c];
c++;
cout<<"\nDo You Want To Order Another Dish ? (y/n)";
cin>>ch;
}while(ch=='y' ||ch=='Y');
cout<<"\n\nThank You For  The Order";getch();clrscr();
cout<<"\n \n********************************HOTEL TAJ***************************************\n";

cout<<"\nO No.\tO Name\tQuantity \tPrice \tAmount \n";

for(int x=0;x<=c;x++)
{
fp.open("Shop.dat",ios::in);
fp.read((char*)&pr,sizeof(product));
while(!fp.eof())
{
if(pr.retpno()==order_arr[x])
{
amt=pr.retprice()*quan[x];

cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()
<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t";
}
fp.read((char*)&pr,sizeof(product));
}
fp.close();
}

getch();
}

void intro()
{
clrscr();
gotoxy(31,11);

cout<<"RESTURANT MANAGEMENT PROJECT";
cout<<"\n\nMADE BY : TANVEER AHEMED";
cout<<"\n\nSCHOOL : BVVS INTERNATIONAL SCHOOL";

getch();
}


void admin_menu()
{
int password;
cout<<"\n";
cout<<"Enter Password\n";
cin>>password;
if(password==1)
{
clrscr();
char ch2;
cout<<"\n\n\n\tADMIN MENU";
cout<<"\n\n\t1.CREATE MENU";
cout<<"\n\n\t2.DISPLAY ALL DISHES IN MENU";
cout<<"\n\n\t3.QUERY ";
cout<<"\n\n\t4.MODIFY REGARDING DISH";
cout<<"\n\n\t5.DELETE A DISH FROM MENU";
cout<<"\n\n\t6.VIEW  MENU";
cout<<"\n\n\t7.BACK TO MAIN MENU";
cout<<"\n\n\tPlease Enter Your Choice (1-7) ";

ch2=getche();

switch(ch2)
{
case '1': clrscr();
write_product();
break;
case '2': display_all();break;
case '3':
int num;
clrscr();
cout<<"\n\n\tPlease Enter The DISH No. ";
cin>>num;
display_sp(num);
break;
case '4': modify_product();break;
case '5': delete_product();break;
case '6': menu();
getch();
case '7': break;
default:cout<<"\a";
admin_menu();
}
}
}

void main()
{
char ch;
intro();
do
{
clrscr();
cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\t01. CUSTOMER";
cout<<"\n\n\t02. ADMINISTRATOR";
cout<<"\n\n\t03. EXIT";
cout<<"\n\n\tPlease Select Your Option (1-3) ";
ch=getche();
switch(ch)
{
case '1': clrscr();
place_order();
getch();
break;
case '2': admin_menu();
break;
case '3':exit(0);
default :cout<<"\a";
}
}while(ch!='3');
}


