#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class clothes
{
	char brand[20],model[20] ,size[10],colour[20],mat[20],cat[10],type[20];
	int price;
	int avail;
	public:

	void read()
	{
		cout<<"\n enter the category: ";
		cin>>cat;
		cout<<"\n enter the type: ";
		cin>>type;
		cout<<"\n enter brand name:";
		cin>>brand;
		cout<<"\n enter model : ";
		cin>>model;
		cout<<"\n enter price:";
		cin>>price;
		cout<<"\n enter size :";
		cin>>size;
		cout<<"\n enter colour :";
		cin>>colour;
		cout<<"\n enter cloth material :";
		cin>>mat;
		cout<<"\n enter availibility :";
		cin>>avail;
	}
	void display()
	{
		cout<<"\n"<<brand<<"\t"<<model<<"\tRs"<<price<<"\t"<<size<<"\t"<<colour<<"\t"<<mat<<"\t"<<avail<<" available";

	}
	char* getbr()
	{
		return brand;
	}
	char* getsize()
	{
		return size;
	}
	char* getcol()
	{
		return colour;
	}
	char* getmat()
	{
		return mat;
	}
	int getpr()
	{
		return price;

	}
	char* getmod()
	{
		return model;
	}
	void decavail()
	{
		avail--;
	}

	char* getcat()
	{
		return cat;
	}
	char* gettype()
	{
		return type;
	}
	int getavail()
	{
		return avail;
	}
	void maindisp()
	{
	       cout<<"\n"<<type<<"\t"<<brand<<"\t"<<model<<"\tRs"<<price<<"\t"<<size<<"\t"<<colour<<"\t"<<mat<<"\t"<<avail<<" available";
	}
};
class details
{
  char name[30], add[50], phn[20],modbuy[20],typebuy[20],catbuy[20],brbuy[20];
  int rate;

  public:

	void read(int amt,char buytype[20],char buycat[20],char buymod[20],char buybr[20])
	{
		cout<<"\n enter name: ";
		cin>>name;
		cout<<"\n enter address: ";
		cin>>add;
		cout<<"\n enter phone no.: ";
		cin>>phn;
		strcpy(modbuy,buymod);
		rate=amt;
		strcpy(typebuy,buytype);
		strcpy(catbuy,buycat);
		strcpy(brbuy,buybr);
	}
	void display()
	{
		cout<<"\n\n name: ";
		cout<<name;
		cout<<"\n address: ";
		cout<<add;
		cout<<"\n phone no.: ";
		cout<<phn;
		cout<<"\n type bought: ";
		cout<<typebuy;
		cout<<"\n model bought: ";
		cout<<modbuy;
		cout<<"\n amount paid : ";
		cout<<rate;
	}
	int getrate()
	{
		return rate;
	}
	char * getmod()
	{
		return modbuy;
	}
	char* getcat()
	{
		return catbuy;
	}
	char* gettype()
	{
		return typebuy;
	}
	char* getbr()
	{
		return brbuy;
	}
	void disname()
	{
		cout<<"\n"<<name;
	}
	char* getname()
	{
		return name;
	}
};
void disptype()
{
	cout<<"\n------------ TYPES AVAILABLE AT YALA -----------------------------------------";
	cout<<"\n\n pants\t t_shirt\t shirt\t jacket\t shorts\t skirt\t top\t dress\t palazzos\t kurti\t dungrees\t saree\t frock";
	cout<<"\n------------------------------------------------------------------------------";
}
void dispbrand()
{
	cout<<"\n------------- BRANDS AVAILABLE AT YALA----------------------------------------";
	cout<<"\n\n wrangler\t indigo_nation\t lee_cooper\t buffalo\t bare\t flying_machine\t scullers\t rig\t ethnicity\t raymond\t srishti\t colors\t gini&jony\t ant\t seals\t diesel\t chloe\t d&g\t only\t vero_moda\t vanheusen\t levis\t fcuk\t biba\t lee\t and\t desi\t holli";
	cout<<"\n------------------------------------------------------------------------------";
}
int main()
{
	clothes c;
	details d;
	ifstream fin;
	ofstream fout;
	int ch,i,entry,count;
	char cont,purch,pass[20],any;
	char catsold[20],typesold[20],brsold[20];
	unsigned long total=0;
	

		system("cls");
		cout<<"\n*********************************************************************";
		cout<<"\n\t\t\t YALA FASHION HUB";
		cout<<"\n*********************************************************************";
		cout<<"\n\t\t\t A Project by\n\t\t Ujwala G and Siya Philip \n\t\t\t Class XII C\n\t\t Kendriya Vidyalaya AFS Yelahanka";
		cout<<"\n*********************************************************************";
		cout<<"\n\n Enter any key to continue....";
		cin>>any;
		system("cls");
		cout<<"\n********************** YALA FASHION HUB *****************************";
		cout<<"\n\n YOU ARE.....\n\t1. ADMINISTRATOR\n\t2. CUSTOMER\nOTHERWISE 10. EXIT\n ENTER CHOICE: ";
		cin>>entry;
		system("cls");
		switch(entry)
		{
			case 1: //admin
				cout<<"\n enter password:";
				cin>>pass;
				if(strcmp(pass,"siya_ujwala")!=0)
					return(0);

				do{
				system("cls");
				cout<<"\n************************************************************";
				cout<<"\n 1. add new detail \n 2. display the details \n 3. buyers list \n 4. total income \n 5. items sold\n 6. modify record  \n 10. exit ";
				cout<<"\n************************************************************\n";
				cout<<"enter the choice : ";
				cin>>ch;

				switch(ch)
				{
					case 1:
						fout.open("clothes.txt",ios::app|ios::binary);
						c.read();
						fout.write((char*)&c,sizeof(c));
						fout.close();
						break;
					case 2:
						int choice; char cats[20],types[20];
						cout<<"\n\t1. display by category\n\t2. display by category and type\n enter choice: ";
						cin>>choice;
						switch(choice)
						{
							case 1:
								cout<<"\n enter the category: ";
								cin>>cats;
								fin.open("clothes.txt",ios::in|ios::binary);
								while(fin.read((char*)&c,sizeof(c)))
								{       if(strcmp(c.getcat(),cats)==0 )
										c.maindisp();
								}
								fin.close();
								break;
							case 2:

								cout<<"\n enter the category: ";
								cin>>cats;
								cout<<"\n enter the type: ";
								cin>>types;
								fin.open("clothes.txt",ios::in|ios::binary);
								while(fin.read((char*)&c,sizeof(c)))
								{       if((strcmp(c.gettype(),types)==0)&&(strcmp(c.getcat(),cats)==0 ))
										c.display();
								}
								fin.close();
								break;
						}
						break;
					case 3:
						fin.open("details.txt",ios::in|ios::binary);
						while(fin.read((char*)&d,sizeof(d)))
						{
							d.display();
						}
						fin.close();
						break;

					case 4: 
						total = 0;
						fin.open("details.txt",ios::in|ios::binary);
						while(fin.read((char*)&d,sizeof(d)))
						{
							  total+=d.getrate();

						}
						cout<<"\n TOTAL INCOME : Rs. "<<total;
						fin.close();
						break;
					case 5:
						count=0;
						cout<<"\n enter category: ";
						cin>>catsold;
						cout<<"\n enter type: ";
						cin>>typesold;
						
						cout<<"\n sold brands : ";
						fin.open("details.txt",ios::in|ios::binary);
						while(fin.read((char*)&d,sizeof(d)))
						{
							  if((strcmp(d.gettype(),typesold)==0)&&(strcmp(d.getcat(),catsold)==0 ))
							  {	count++;
								cout<<"\t " <<d.getbr();
							  }
						}
						cout<<"\n TOTAL SOLD: "<<count;
						cout<<"\n ....................................................................";
						fin.close();
						char chco;
						cout<<"\n do you want to check brand-wise(y/n) ? ";
						cin>>chco;
						if(chco=='y')
						do
						{         count=0;
							  cout<<"\n enter brand : ";
							  cin>>brsold;
							  fin.open("details.txt",ios::in|ios::binary);
							  while(fin.read((char*)&d,sizeof(d)))
							  {
								if((strcmp(d.getbr(),brsold)==0))
								{	count++;

								}


							  }
							  cout<<"\n TOTAL SOLD: "<<count;

							  cout<<"\n do you want to search more brands (y/n)? ";
							  cin>>chco;
						}while(chco=='y');
						break;
					case 6:
						char mod2[20];
						clothes c2;
						
						cout<<"\nmodel no present in the file...\n";
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char *)&c,sizeof(c)))
						{
							cout<<"\t"<<c.getmod();
						}			
						fin.close();
						
						cout<<"\nenter model no to be modified: ";
						cin>>mod2;
						cout<<"\nenter new details: ";
						c2.read();
				
						fin.open("clothes.txt",ios::in|ios::binary);
						fout.open("tem.txt",ios::app|ios::binary);
					
						while(fin.read((char *)&c,sizeof(c)))
						{
							if(strcmp(mod2,c.getmod())==0)
								fout.write((char*)&c2,sizeof(c2));
							else
								fout.write((char*)&c,sizeof(c));
						}				
						fout.close();
						fin.close();
						remove("clothes.txt");
						rename("tem.txt","clothes.txt");
						break;
					


					default:
						return(0);
			       }
			       cout<<"\n do you want to continue(y/n)?" ;
			       cin>>cont;
			       }while(cont=='y');


			       break;
			case 2:  //customer
				for(;;){
				char chcat[20],chtype[20];
				system("cls");

				cout<<"\n WHICH SECTION DO YOU WANT TO PURCHASE FROM?\n\t* ladies\n\t* gents\n\t* kids\n otherwise \n\t exit\n ENTER CHOICE: ";
				cin>>chcat;
				if(strcmp(chcat,"exit")==0)
				{
					return(0);
				}
				disptype();
				cout<<"\n ENTER THE TYPE: ";
				cin>>chtype;

				do{
				system("cls");
				cout<<"\n "<<chcat<<"\t"<<chtype;
				cout<<"\n************************************************************";
				cout<<"\n 1. display all\n 2. choose by brand \n 3. choose by price\n 4. choose by size\n 5. choose by colour\n 6. choose by cloth material\n 7. exit ";
				cout<<"\n************************************************************\n";
				cout<<"\n enter choice :";
				cin>>ch;

				switch(ch)
				{

					case 1: count=0;
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char*)&c,sizeof(c)))
						{       if((strcmp(c.gettype(),chtype)==0)&&(strcmp(c.getcat(),chcat)==0 ))
							{	c.display();
								count++;
							}
						}
						cout<<"\n"<<count<<" option(s) found";
						fin.close();
						break;
					case 2: char chbr[20];
						count=0;
						dispbrand();
						cout<<"\n enter choice brand: ";
						cin>>chbr;
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char*)&c,sizeof(c)))
						{       if((strcmp(c.gettype(),chtype)==0)&&(strcmp(c.getcat(),chcat)==0 ))
							if(strcmp(chbr,c.getbr())==0)
							{	c.display();
								count++;

							}
						}
						cout<<"\n"<<count<<" option(s) found";
						fin.close();
						break;
					case 3:
						int chpr;
						count=0;
						cout<<"\n range options\n\t1.below 500\n\t2.between 500 & 1000\n\t3.between 1000 & 2000\n\t4.above 2000:";
						cout<<"\n enter choice:";
						cin>>chpr;
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char*)&c,sizeof(c)))
						{       if((strcmp(c.gettype(),chtype)==0)&&(strcmp(c.getcat(),chcat)==0 ))
							switch(chpr)
							{
								case 1:
									if(c.getpr()<=500)
									{	c.display();
										count++;
									}

									break;
								case 2:
									if(c.getpr()>500&&c.getpr()<=1000)
									{	c.display();
										count++;
									}
									break;
								case 3:
									if(c.getpr()>1000&&c.getpr()<=2000)
									{	c.display();
										count++;
									}
									break;
								case 4:
									if(c.getpr()>2000)
									{	c.display();
										count++;
									}
									break;
								default:
									cout<<"\nplease enter properly..";
									break;
							}

						}
						cout<<"\n"<<count<<" option(s) found";
						fin.close();
						break;
					case 4:
						char chsize[10];
						count=0;
						cout<<"\n size options \n\t S: small \n\t M: medium \n\t L: large \n\t XL: extra large ";
						cout<<"\n enter choice: ";
						cin>>chsize;
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char*)&c,sizeof(c)))
						{       if((strcmp(c.gettype(),chtype)==0)&&(strcmp(c.getcat(),chcat)==0 ))
							if(strcmp(chsize,c.getsize())==0)
							{	c.display();
								count++;

							}
						}
						cout<<"\n"<<count<<" option(s) found";
						fin.close();
						break;
					case 5: char chcol[20];
						count=0;
						cout<<"\n enter choice colour: ";
						cin>>chcol;
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char*)&c,sizeof(c)))
						{       if((strcmp(c.gettype(),chtype)==0)&&(strcmp(c.getcat(),chcat)==0 ))
							if(strcmp(chcol,c.getcol())==0)
							{	c.display();
								count++;

							}
						}
						cout<<"\n"<<count<<" option(s) found";
						fin.close();
						break;
					case 6: char chmat[20];
						count=0;
						cout<<"\n enter choice cloth material: ";
						cin>>chmat;
						fin.open("clothes.txt",ios::in|ios::binary);
						while(fin.read((char*)&c,sizeof(c)))
						{       if((strcmp(c.gettype(),chtype)==0)&&(strcmp(c.getcat(),chcat)==0 ))
							if(strcmp(chmat,c.getmat())==0)
							{	c.display();
								count++;

							}
						}
						cout<<"\n"<<count<<" option(s) found";
						fin.close();
						break;
					default:

						return(0);
				}

				cout<<"\n DO YOU WANT TO BUY(Y/N)?";
				cin>>purch;
				if(purch=='Y'&& count!=0)
				{       int amt;
					char buytype[20],buycat[20],buybr[20];
					char modch[20];
					cout<<"\n To check if available, enter the model: ";
					cin>>modch;
					//retrieving data					
					fin.open("clothes.txt",ios::in|ios::binary);
					while(fin.read((char*)&c,sizeof(c)))
					{
							if(strcmp(modch,c.getmod())==0)
							{
								amt=c.getpr();
								strcpy(buytype,c.gettype());
								strcpy(buycat,c.getcat());
								strcpy(buybr,c.getbr());
							}
					}
					
					fin.close();
					//reducing availability
					fin.open("clothes.txt",ios::in|ios::binary);
					fout.open("avail.txt",ios::app|ios::binary);				
					while(fin.read((char *)&c,sizeof(c)))
					{
						if(strcmp(modch,c.getmod())==0)
						{
							c.decavail();
							fout.write((char*)&c,sizeof(c));
						}	
							
						else	
							fout.write((char*)&c,sizeof(c));
					}				
					fout.close();
					fin.close();
					remove("clothes.txt");
					rename("avail.txt","clothes.txt");
					
					//deleting if avail=0
					fin.open("clothes.txt",ios::in|ios::binary);
					fout.open("avail.txt",ios::app|ios::binary);				
					while(fin.read((char *)&c,sizeof(c)))
					{
						if(c.getavail()!=0)
								fout.write((char*)&c,sizeof(c));
					}				
					fout.close();
					fin.close();
					remove("clothes.txt");
					rename("avail.txt","clothes.txt");					
					
					//storing details
					cout<<"\n enter your details ( please don't use spaces after each  word, use UNDERSCORE):";
					fout.open("details.txt",ios::app|ios::binary);
					d.read(amt,buytype,buycat,modch,buybr);
					fout.write((char*)&d,sizeof(d));
					fout.close();

					system("cls");
					cout<<"\n\nTHANK YOU FOR PURCHASING....PURCHASE SUCCESSFUL.....";
					cout<<"\n\nenter any alphabet to continue.....";
					cin>>any;

					break;
				}
				else
				{
					cout<<"\n do you want to continue in this category(y/n)?" ;
					cin>>cont;
				}
				}while(cont=='y');
				}//for infinite loop

			default:
				return(0);
		}

}
