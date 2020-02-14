#include<iostream>
#include<ctime>
//#include<conio.h>
#include <ncurses.h>
using namespace std;
int main()
{

	int num[5][5],row,col,a,b,c,d,e;
	int ask;
	
	srand(time(NULL));

	do{
		
		system("cls");
			cout<<"\n\n\t\t\t\t    BINGO GAME"<<endl;
	for(row=0;row<5;row++)
		for(col=0;col<5;col++)
			num[row][col]=rand()%100;
		cout<<"\n\n\tB\t\tI\t\tN\t\tG\t\tO"<<endl;
		cout<<"\n\n";
			for(row=0;row<5;row++)
			{
				for(col=0;col<5;col++)
					{
					if(col==0)
						{
							num[row][col]=rand()%15;

								if(row==0)
									a=num[row][col];
								else if(row==1)
									b=num[row][col];
								else if(row==2)
									c=num[row][col];
								else if(row==3)
									d=num[row][col];
								else if(row==4)
									e=num[row][col];
						}
							
					else if(col==1)
					{ 
						num[row][col]=rand()%30;
					     
                                                   do{

 							if(num[row][col]<=15)
							{
								num[row][col]=num[row][col]+30;
							}
							else if(num[row][col]>=31)
							{
								num[row][col]=num[row][col]-1;
							}
						}while((num[row][col]<=15)&&(num[row][col]>=31));

						}
						else if(col==2)
						{ num[row][col]=rand()%15;
						do{
							if(num[row][col]<=30)
							{
								num[row][col]=num[row][col]+45;
							}
							else if(num[row][col]>=46)
							{
								num[row][col]=num[row][col]-1;
							}
						}while((num[row][col]<=30)&&(num[row][col]>=46));

						}
		

						else if(col==3)
						{ num[row][col]=rand()%15;
							do{
							if(num[row][col]<=45)
							{
								num[row][col]=num[row][col]+60;
							}
							else if(num[row][col]>=61)
							{
								num[row][col]=num[row][col]-1;
							}
						}while((num[row][col]<=45)&&(num[row][col]>=61));
						}
						else if(col==4)
						{ num[row][col]=rand()%15;
							do{
							if(num[row][col]<=60)
							{
								num[row][col]=num[row][col]+60;
							}
							else if(num[row][col]>=91)
							{
								num[row][col]=num[row][col]-1;
							}
						}while((num[row][col]<=60)&&(num[row][col]>=76));
						}

					if((row==2)&&(col==2))
							cout<<"\tFREE\t";
						else
							cout<<"\t"<<num[row][col]<<"\t";
					}
					cout<<"\n";
			}

			
			{
				cout<<"\n\n\tIs this the card you want to use? [0 for no only.] : ";
				cin>>ask;
			}
	}
			while(ask!=0);

}