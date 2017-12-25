#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void show_game_box();
char a[3][3];
void main()
{	
clrscr();
char player1[15],player2[15];
int i,j,r,c,r1,c1,y;
for(y=0;y<3;y++)
{
for(j=0;j<3;j++)
{
a[y][j]=' ';
}}
int player;
cout<<"                 TIC TAC TOE GAME             "<<endl;
cout<<"\n";
cout<<"RULES"<<endl;
cout<<"\n";
cout<<"Two players are required to play this game."<<endl;
cout<<"Two player are required to mark on the 3x3 grid."<<endl;
cout<<"Player 1 will mark here as O and player 2 will mark as X."<<endl;
cout<<"Once marked position cannot be marked again."<<endl;
cout<<"The player who succeeds in placing three respective marks in a horizontal, vertical or diagonal row wins the game."<<endl;
cout<<"If no one wins after placing all the places then the match is drawn."<<endl;
cout<<"Here r refers to Row and c refers to column"<<endl;
cout<<"\n";
cout<<"r1c1|"<<"r1c2|r1c3"<<endl;
cout<<"----|----|----\n";
cout<<"r2c1|"<<"r2c2|r2c3"<<endl;
cout<<"----|----|----\n";
cout<<"r3c1|"<<"r3c2|r3c3"<<endl;
cout<<"----|----|----\n";
cout<<"\n";
cout<<"enter the name of the player1 \n";
gets(player1);
cout<<"enter the name of the player2 \n";
gets(player2);
for(i=1;i<10;i++)
{
if(i%2==1)
{
player=1;
}
else
{
player=2;
}
if(player==1)
{
cout<<player1<<"  enter the row you want to mark followed by column you want to mark \n";
cin>>r;
cin>>c;
while(r<1 || r>3||c<1||c>3||a[r-1][c-1]=='O'||a[r-1][c-1]=='X')
{
cout<<"invalid choice\n";
cout<<player1<<"  enter the row you want to mark followed by column you want to mark again \n";
cin>>r;
cin>>c;
}
a[r-1][c-1]='O';
}
if(player==2)
{
cout<<player2<<"  enter the row you want to mark followed by column you want to mark \n";
cin>>r;
cin>>c;
while(r<1 || r>3||c<1||c>3||a[r-1][c-1]=='O'||a[r-1][c-1]=='X')
{
cout<<"invalid choice\n";
cout<<player2<<"  enter the row you want to mark followed by column you want to mark again \n";
cin>>r;
cin>>c;
}
a[r-1][c-1]='X';
}
show_game_box();
if(i>4)
{
if(a[0][0]=='O'&&a[0][1]=='O'&&a[0][2]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[2][0]=='O'&&a[2][1]=='O'&&a[2][2]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[0][0]=='O'&&a[1][0]=='O'&&a[2][0]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[0][1]=='O'&&a[1][1]=='O'&&a[2][1]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[0][2]=='O'&&a[1][2]=='O'&&a[2][2]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player1<<"  wins";
break;
}
else if(a[0][0]=='X'&&a[0][1]=='X'&&a[0][2]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[1][0]=='X'&&a[1][1]=='X'&&a[1][2]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[2][0]=='X'&&a[2][1]=='X'&&a[2][2]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[0][1]=='X'&&a[1][1]=='X'&&a[2][1]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[0][2]=='X'&&a[1][2]=='X'&&a[2][2]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else if(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
{
cout<<"CONGRATULATIONS!!!!!\t";
cout<<player2<<"  wins";
break;
}
else
{
cout<<"";
}
}
else if(i==9)
{
cout<<"match is drawn";
}
else
{
cout<<"";
}
}
getch();
}
void show_game_box()
{
cout<<a[0][0]<<"|"<<a[0][1]<<"|"<<a[0][2]<<endl;
cout<<"-|-|-\n";
cout<<a[1][0]<<"|"<<a[1][1]<<"|"<<a[1][2]<<endl;
cout<<"-|-|-\n";
cout<<a[2][0]<<"|"<<a[2][1]<<"|"<<a[2][2]<<endl;
cout<<"-|-|-\n";
}
