/*  This is a simple chess move detection code */

#include<process.h>
#include<DOS.h>
#include<iostream.h>
#include<conio.h>

void bishop(char[][8][8],int,int);
void pawn(char[][8][8],int,int);
void rook(char[][8][8],int,int);
void queen(char[][8][8],int,int);
void king(char[][8][8],int,int);
void knight(char[][8][8],int,int);

void main()
{
	int opt,i=0,j=0,k=0;
	char ch_bo[2][8][8],ch,repeat;
	clrscr();

	cout<<"\n Welcome to chess wizard......\n\n";
	getch();
	do{
	cout<<"\n The chess board initially looks like this: ";
	cout<<"\n Here, B-Black  and  W-White\n";
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if((i+j)%2==0)
			ch_bo[0][i][j]='W';
			else
			ch_bo[0][i][j]='B';
			ch_bo[1][i][j]=' ';
		}
	}

	i=0;
	j=0;

	label:
	cout<<"\n";
	ch='A';
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			cout<<ch<<(j+1)<<" "<<ch_bo[0][i][j];
			cout<<" \t";
		}
		cout<<"\n\n";
		ch++;
	}

	i=0;
	j=0;
	cout<<"\nNow enter the location of your piece :-";
	cin>>ch>>j;
	j--;
	i=ch-65;
	if(i>7 || j>7)
	{
		cout<<"\n You entered invalid input XXXXXXXXXXXXXXXXX ";
		getch();
		clrscr();
		for(int l=0;l<3;l++)
		{
			cout<<"\n\n Restarting the program ";
			for(int m=0;m<8;m++)
			{
				cout<<" . ";
				delay(200);
			}
			clrscr();
		}
		sleep(2);
		goto label;
	}
	cout<<"\n\nEnter one of the number to select the piece :";
	cout<<"\n 1-Pawn(P)";
	cout<<"\n 2-Rook(R)";
	cout<<"\n 3-Knight(k)";
	cout<<"\n 4-Bishop(B)";
	cout<<"\n 5-Queen(Q)";
	cout<<"\n 6-King(K)";
	cout<<"\n";
	cin>>opt;
	switch(opt)
	{
		case 1:
		ch_bo[1][i][j]='P';
		pawn(ch_bo,i,j);
		break;

		case 2:
		ch_bo[1][i][j]='R';
		rook(ch_bo,i,j);
		break;

		case 3:
		ch_bo[1][i][j]='k';
		knight(ch_bo,i,j);
		break;

		case 4:
		ch_bo[1][i][j]='B';
		bishop(ch_bo,i,j);
		break;

		case 5:
		ch_bo[1][i][j]='Q';
		queen(ch_bo,i,j);
		break;

		case 6:
		ch_bo[1][i][j]='K';
		king(ch_bo,i,j);
		break;

		default:
		cout<<"\nYou entered a wrong choice.........!!";
		cout<<"\n Enter again";
		clrscr();
		goto label;
	}
	int temp1=i;
	int temp2=j;

	getch();
	clrscr();

	cout<<"\n So we have calculated the places where you can play your move:";
	cout<<"\n The chess board contains X for possible moves :-\n\n";

	ch='A';
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			cout<<ch<<(j+1)<<" "<<ch_bo[0][i][j];
			if(i==temp1 && j==temp2)
			{
				textcolor(RED+BLINK);
				cout<<" "<<ch_bo[1][i][j];
			}
			else
				cout<<" "<<ch_bo[1][i][j];
			cout<<" | ";
		}
		cout<<"\n\n";
		ch++;
	}

	cout<<"\n\n Do you wish to do it again ?(yes/no):";
	cin>>repeat;
	}while(repeat=='Y' || repeat=='y');

	getch();
	clrscr();
	cout<<"\n\nThanks for using my software  !!!!!!!!!";

	getch();
}

void bishop(char ch_bo[][8][8],int row,int col)  //Rectified.
{
	int i,j,k;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=-7;k<8;k++)
			{
				if(i==(row+k) && j==(col+k))
				ch_bo[1][i][j]='X';

				if(i==(row-k) && j==(col+k))
				ch_bo[1][i][j]='X';
			}
		}
	}
	ch_bo[1][row][col]='B';
}

void pawn(char ch_bo[][8][8],int row,int col)      // Rectified.
{
	char ch,pp;
	cout<<"\n Are you playing for white or black (W/B) ? :-";
	cin>>ch;
	if(ch=='W')
	{
		if(row==0)
		{
			cout<<"You have pawn promotion available.";
			cout<<"\nChoose from following (B,K,R,Q):-";
			cin>>pp;
			switch(pp)
			{
				case 'B':
				ch_bo[1][row][col]='B';
				bishop(ch_bo,row,col);
				break;

				case 'K':
				ch_bo[1][row][col]='k';
				knight(ch_bo,row,col);
				break;

				case 'R':
				ch_bo[1][row][col]='R';
				rook(ch_bo,row,col);
				break;

				case 'Q':
				ch_bo[1][row][col]='Q';
				queen(ch_bo,row,col);
				break;
			}
		}
		else if(row==7)
	       {
			cout<<"Invalid position";
			exit(0);
	       }
	       else if(row==6)
	      {
			 ch_bo[1][row-1][col]='X';
			 ch_bo[1][row-2][col]='X';
	      }
	      else
	      {
			ch_bo[1][row-1][col]='X';
	      }
	}

	if(ch=='B')
	{
		if(row==7)
		{
			cout<<"You have pawn promotion available.";
			cout<<"\nChoose from following (B,K,R,Q):-";
			cin>>pp;
			switch(pp)
			{
				case 'B':
				ch_bo[1][row][col]='B';
				bishop(ch_bo,row,col);
				break;

				case 'K':
				ch_bo[1][row][col]='K';
				ch_bo[1][row][col]='n';
				knight(ch_bo,row,col);
				break;

				case 'R':
				ch_bo[1][row][col]='R';
				rook(ch_bo,row,col);
				break;

				case 'Q':
				ch_bo[1][row][col]='Q';
				queen(ch_bo,row,col);
				break;
			}
		}
		else if(row==0)
		{
			cout<<"Invalid position";
			exit(0);
		}
		else if(row==1)
		{
			 ch_bo[1][row+1][col]='X';
			 ch_bo[1][row+2][col]='X';
	      }
	      else
	      {
			ch_bo[1][row+1][col]='X';
	      }
	}
}

void rook(char ch_bo[][8][8],int row,int col)  //rectified.
{
	int k;
	for(k=(0-row);k<(8-row);k++)
		ch_bo[1][row+k][col]='X';
	for(k=(0-col);k<(8-col);k++)
		ch_bo[1][row][col+k]='X';
	ch_bo[1][row][col]='R';
}

void queen(char ch_bo[][8][8],int row,int col)   //rectified.
{
	int i,j,k;
	for(k=-row;k<(8-row);k++)
	{
		ch_bo[1][row+k][col]='X';
	}
	for(k=-col;k<(8-col);k++)
	{
		ch_bo[1][row][col+k]='X';
	}

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			for(int k=-7;k<8;k++)
			{
				if(i==(row+k) && j==(col+k))
				ch_bo[1][i][j]='X';
				if(i==(row-k) && j==(col+k))
				ch_bo[1][i][j]='X';
			}
		}
	}
	ch_bo[1][row][col]='Q';
}

void king(char ch_bo[][8][8],int row,int col) //rectified
{
	int i,j,k;
	for(k=-1;k<2;k++)
	{
		ch_bo[1][row+k][col]='X';
	}
	for(k=-1;k<2;k++)
	{
		ch_bo[1][row][col+k]='X';
	}

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			for(int k=-1;k<2;k++)
			{
				if(i==(row+k) && j==(col+k))
					ch_bo[1][i][j]='X';
				if(i==(row-k) && j==(col+k))
					ch_bo[1][i][j]='X';
			}
		}
	}
	ch_bo[1][row][col]='K';
}

void knight(char ch_bo[][8][8],int row,int col) //rectified.
{
	ch_bo[1][row+2][col+1]='X';
	ch_bo[1][row+2][col-1]='X';
	ch_bo[1][row-2][col+1]='X';
	ch_bo[1][row-2][col-1]='X';
	ch_bo[1][row+1][col+2]='X';
	ch_bo[1][row+1][col-2]='X';
	ch_bo[1][row-1][col+2]='X';
	ch_bo[1][row-1][col-2]='X';
}