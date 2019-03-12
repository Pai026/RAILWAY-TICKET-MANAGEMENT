
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>

class train
{ int tno;
  char tname[20];
  int tot;
  int res;
  char sou[20];
  char dest[20];
 public:
  void readit();
  void display();
  void modify();
  int tn()
  {return tno;}
  int to()
  {return tot;}
  int re()
  {return res;}
  void mod(int x)
  {   res=x;
  }
  void dissor()
  {puts(sou);
  }
  void disdes()
  {puts(dest);
  }
};
class passenger
{ int passno;
  char pname[20];
  char padd[20];
  long phone;
  char s;
  float amount;
  int tid;
 public:
  void readi();
  void dis();
  void modify1();
  int pano()
  {return passno;}
  int t()
  {return tid;}
  void disamt()
  {cout<<amount;
  }
};
int createtno()
   {  int value;
	  train t1;
		fstream file1;
		file1.open("train.dat",ios::in|ios::binary);
		if(file1)
		 {
		   file1.seekg(0,ios::beg);
		   while(file1.read((char*)&t1,sizeof(t1)));
		   value = t1.tn();
		   ++value;
		 }
		 else
		  value=1;


		file1.close();

	 return value;
  }
int createpano()
   {  int value;
	  passenger p1;
		fstream file1;
		file1.open("passenger.dat",ios::in|ios::binary);
		if(file1)
		 {
		   file1.seekg(0,ios::beg);
		   while(file1.read((char*)&p1,sizeof(p1)));
		   value = p1.pano();
		   ++value;
		 }
		 else
		  value=1;


		file1.close();

	 return value;
  }
void train::readit()
{  res=0;
   tno=createtno();
   cout<<"\n\t\t Enter Train Name :";
   gets(tname);
   cout<<"\n\t\t Enter Total seats :";
   cin>>tot;
  // cout<<"\n\t\t Enter Reserved seats :";
  // cout<<res;
   cout<<"\n\t\t Enter Starting point :";
   gets(sou);
   cout<<"\n\t\t Enter Destination :";
   gets(dest);
}
void train::display()
{
   cout<<"\n"<<tno<<"      |"<<"   "<<tname<<"\t\t"<< tot<<"\t\t"
       <<res<<"   \t"<<sou<<"\t\t"<<dest;
}
void train::modify()
{  char a[20],d[20],e[20];int b,c;
   cout<<"\n\t\t Train name :"<<tname;
   cout<<"\n\t\t Total seats"<<tot;
   cout<<"\n\t\t Seats Reserved"<<res;
   cout<<"\n\t\t Starting point"<<sou;
   cout<<"\n\t\t Destination"<<dest;
   cout<<"\n\t\t Enter New Details";
   cout<<"\n\t\t Enter New Train name (Enter '.' to retain old name) :";
   gets(a);
   cout<<"\n Enter Total no of seats (Enter '-1' to retain old value) :";
   cin>>b;
   //cout<<"\n Enter No of Seats Reserved (Enter '-1'to retain old value) :";
   //cin>>c;
   cout<<"\n Enter new starting point (Enter '.' to retain old place) :";
   gets(d);
   cout<<"\n Enter new destination(Enter '.' to retain old place) :";
   gets(e);
   if(strcmpi(a,".")!=0)
     strcpy(tname,a);
   if(b!=-1)
    tot=b;
   //if(c!=-1)
   // res=c;
   if(strcmpi(d,".")!=0)
     strcpy(sou,d);
   if(strcmpi(e,".")!=0)
     strcpy(dest,e);
}
void passenger::readi()
{ passno=createpano();
  cout<<"\n\t\t Enter Passenger name";
  gets(pname);
  cout<<"\n\t\t Enter Passenger address";
  gets(padd);
  cout<<"\n\t\t Enter Phone";
  cin>>phone;
  cout<<"\n\t\t Enter Sex";
  cin>>s;
  cout<<"\n\t\t Enter Amount";
  cin>>amount;
}
void passenger::dis()
{
   cout<<"\n"<<passno<<"\t"<<pname<<"\t"<<padd<<"\t"<<phone<<"\t"<<s
	<<"\t"<<amount;
}
void passenger::modify1()
{  char a[20],b[20]; int d,e;long c;
   cout<<"\n\t\t Passenger name"<<pname;
   cout<<"\n\t\t Passenger address"<<padd;
   cout<<"\n\t\t Phone"<<phone;
   cout<<"\n\t\t Sex"<<s;
   cout<<"\n\t\t Amount"<<amount;
   cout<<"\n\t\t Enter New Details";
   cout<<"\n\t\t Enter New Passenger name (Enter '.' to retain old name) :";
   gets(a);
   cout<<"\n Enter New Passenger address (Enter '.' to retain old value) :";
   gets(b);
   cout<<"\n Enter New phone no (Enter '-1'to retain old value) :";
   cin>>c;
   cout<<"\n Enter new Sex (Enter '.' to retain old Sex) :";
   cin>>d;
   cout<<"\n Enter new Amount (Enter '-1' to retain old amount) :";
   cin>>e;
   if(strcmpi(a,".")!=0)
     strcpy(pname,a);
   if(strcmpi(b,".")!=0)
     strcpy(padd,b);
   if(c!=-1)
    phone=c;
   if(d!='.')
    s=d;
   if(e!=-1)
    amount=e;
}
void write()
{       train t;
	t.readit();
	fstream ifile;
	ifile.open("train.dat",ios::binary|ios::app);
	   ifile.write((char*)&t,sizeof(t));
	  ifile.close();
}

void reserve()
{
	int tos,r,pos,flag=0,flag1=0;
	train T;
	passenger P;
	fstream ifile2;
	ofstream ofile;
	ofile.open("passenger.dat",ios::binary|ios::app);
	ifile2.open("train.dat",ios::binary|ios::in|ios::out);
	cout<<"n\t\t Enter the train no :";
	cin>>tos;
	//P.readi();
	while(!ifile2.eof())
	{ pos=ifile2.tellg();
	  ifile2.read((char*)&T,sizeof(T));
	  if(T.tn()==tos)
	   { flag=1;
	     if(T.re()<T.to())
	      {	r=T.re()+1;
		T.mod(r);
		ifile2.seekg(pos);
		ifile2.write((char*)&T,sizeof(T));
	      }
	      else
		 flag1=1;
	     break;
	   }
	 }
	 if(flag==0)
	 {
	   cout<<"No such train exists";
	   getch();
	 }
	 else
	  { if(flag1==1)
	     {  cout<<"No more seats available";
		getch();
	     }
	    else
	      { P.readi();
		ofile.write((char*)&P,sizeof(P));
		cout<<"\n Ticket Reserved";
		getch();
		ofile.close();
	      }
	   }
	    ifile2.close();
}
void delete2()
{       int flag=0;int tro;
	train t1;
	ifstream ifile1;
	ifile1.open("train.dat",ios::binary);
	ofstream ofile1;
	ofile1.open("temp.dat",ios::binary);
	cout<<"\n\t\t Enter the train to be deleted :";
	cin>>tro;
	while(ifile1.read((char*)&t1,sizeof(t1)))
	{
		if(t1.tn()==tro)
		{
		  flag=1;
		  //t1.re()-1;
		}
		else
		 ofile1.write((char*)&t1,sizeof(t1));
	}
	if(flag==0)
	 { cout<<"Train does not exist";
	   getch();
	 }
	remove("train.dat");
	rename("temp.dat","train.dat");
	ifile1.close();
	ofile1.close();
}
void cancel()
{	ifstream ifile;
	ofstream ofile;
	train t1,t2;
	int flag1=0,tro,r;
	long int pos;
	ifstream ifile1;
	ifile1.open("train.dat",ios::binary);
	fstream file1;

	cout<<"\n\t\t Enter the train :";
	cin>>tro;

	while(!ifile1.eof())
	{ ifile1.read((char*)&t1,sizeof(t1));
	  if(t1.tn()==tro)
	   { flag1=1;
	     break;
	   }
	}
	 ifile1.close();

	if(flag1==0)
	 {
	  cout<<"Train does not exist";
	  getch();
	 }
	else
	{
	   passenger p1;
	  ifile.open("passenger.dat",ios::binary);
	  ofile.open("temp.dat",ios::binary);
	  int pn,flag=0;
	  cout<<"\n\t\t Enter the passenger number to be cancelled:";
	  cin>>pn;
	  while(ifile.read((char*)&p1,sizeof(p1)))
	  { if(p1.pano()==pn)
	      flag=1;
	    else
	      ofile.write((char*)&p1,sizeof(p1));
	  }
	  ofile.close();
	  ifile.close();
	  remove("passenger.dat");
	  rename("temp.dat","passenger.dat");
	  if(flag==0)
	    cout<<"\n passenger does not exist ";
	  else
	  { file1.open("train.dat",ios::in|ios::out|ios::binary);
	    while(!file1.eof())
	    { pos= file1.tellg();
	      file1.read((char*)&t2,sizeof(t2));
	      if(t2.tn()==tro)
	       { flag1=1;
		 r=t2.re()-1;
		 t2.mod(r);
		 file1.seekg(pos);
		 file1.write((char*)&t2,sizeof(t2));
		 cout<<"\n Ticket Cancelled";
		 getch();
		 break;
	       }
	    }
	    file1.close();
	  }
	}
}
void modify2()
{ int tos;
  char found='f';
  long pos;
  train t2;
  fstream ifile;
  ifile.open("train.dat",ios::in|ios::out|ios::binary);
  cout<<"\n\t\t Enter the train to modified :";
  cin>>tos;
  while(!ifile.eof())
  { pos=ifile.tellg();
    ifile.read((char*)&t2,sizeof(t2));
    if(t2.tn()==tos)
    { t2.modify();
      ifile.seekg(pos);
      ifile.write((char*)&t2,sizeof(t2));
      found='t';
      break;
    }
  }
  if(found=='f')
    cout<<"Record not found";
   ifile.close();
}
void reptrain()
{ int tos;
  train t3;
  ifstream ifile;
  ifile.open("train.dat",ios::binary);
  cout<<"Enter the train no to be displayed";
  cin>>tos;
  while(ifile.read((char*)&t3,sizeof(t3)))
  {
    if(tos==t3.tn())
    t3.display();
  }
  ifile.close();
}
void reppassenger()
{ int pn;
  passenger P;
  ifstream ifile;
  ifile.open("passenger.dat",ios::binary);
  cout<<"\n\t\t Enter the passenger to be displayed :";
  cin>>pn;
  while(ifile.read((char*)&P,sizeof(P)))
  {
    P.dis();
  }
  ifile.close();
}
void disptall()
{ train T;
  ifstream ifile;
  ifile.open("train.dat",ios::binary);
  cout<<"\t"<<"Train Details";
   cout<<"\n     TRAIN                    SEATS             ORIGIN      DESTINATION";
   cout<<"\n NO    |   NAME         TOTAL   |   RESERVED                           ";
  while(ifile.read((char*)&T,sizeof(T)))
  {
    T.display();
  }
  ifile.close();
}
void disppall()
{ passenger P;
  ifstream ifile;
  ifile.open("passenger.dat",ios::binary);
  cout<<"\t"<<"Passenger Details";
  cout<<"\n       PASSENGER ";
  cout<<"\n    NUMBER     NAME      ADDRESS       PHONE      SEX     AMOUNT ";
  while(ifile.read((char*)&P,sizeof(P)))
  {
    P.dis();
  }
  ifile.close();
}
void ticket()
{ float tic;
  train T;
  passenger P;
  ifstream ifile;
  ifile.open("train.dat",ios::binary);
  ifstream ifile2;
  ifile2.open("passenger.dat",ios::binary);
  cout<<" ENTER THE PSSENGER NUMBER OF THE TICKET :";
  cin>>tic;
  clrscr();
  while((ifile.read((char*)&T,sizeof(T)))&&(ifile2.read((char*)&P,sizeof(P))))
  { if(tic==P.pano())
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n-------------------------------------------------------------------  ";
    cout<<"\n|                 .......T.I.C.K.E.T.......                       | ";
    cout<<"\n|                I.R.T.C   |   HAPPY JOURNEY                      | ";
    cout<<"\n|         TRAIN NO : "<<T.tn()<<"                                 | ";
    cout<<"\n|         ORIGIN                             DESTINATION          | ";
    cout<<"\n|      ";T.dissor();cout<<"                 ";T.disdes();cout<<"  | ";
    cout<<"\n|      ";P.disamt();cout<<"                                       | ";
    cout<<"\n|            PASSENGER HELP LINE : 138                            | ";
    cout<<"\n|      NOTE : * ticket is not transferable                        | ";
    cout<<"\n|             * railway help line : 1322                          | ";
    cout<<"\n|-----------------------------------------------------------------| ";
  }
  getch();
   ifile.close();
   ifile2.close();
}
void main()
{	int ch,ch1,ch2,ch3,ch4,ch5,i;
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n                      ----------------------------------";
	cout<<"\n                           RAILWAY RESERVATION SYSTEM";
	cout<<"\n                      ----------------------------------";
	getch();
	for(i=0;i<8;i++)
	{
		clrscr();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                 loading.....| ";
		delay(200);
		clrscr();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                 loading.....0/ ";
		delay(200);
	 }
	do
	{
	 clrscr();
	 cout<<"\n\n\n\n\n\t---------------------------------------------------";
	  cout<<"\n\t---------------------------------------------------";
	 cout<<"\n\n\t\t\t MAIN MENU ";
	 cout<<"\n\t\t\t 1 : TRAIN "
	     <<"\n\t\t\t 2 : PASSENGER "
	     <<"\n\t\t\t 3 : REPORT "
	     <<"\n\t\t\t 4 : EXIT ";
	 cout<<"\n\n\n\n\n\t---------------------------------------------------";
	  cout<<"\n\t---------------------------------------------------";
	 cout<<"\n\n\t\t\t Enter your choice :";
	 cin>>ch;
	 switch(ch)
	 {case 1:do
		{ clrscr();
		   cout<<"\n\n\n\n\n\t---------------------------------------------------";
		   cout<<"\n\t---------------------------------------------------";
		   cout<<"\n\n\t\t\t TRAIN MENU "
		       <<"\n\t\t\t 1 : ADD "
		       <<"\n\t\t\t 2 : DELETE "
		       <<"\n\t\t\t 3 : MODIFY "
		       <<"\n\t\t\t 4 : RETURN ";
		   cout<<"\n\n\n\n\n\t---------------------------------------------------";
		   cout<<"\n\t---------------------------------------------------";
		   cout<<"\n\t\t\t Enter your choice :";
		   cin>>ch1;
		   switch(ch1)
		 { case 1:write();
			  break;
		   case 2:delete2();
			  break;
		   case 3:modify2();
			  break;
		   case 4:break;
		 }
		}while(ch1!=4);
		 break;
	  case 2:do
		{ clrscr();
		   cout<<"\n\n\n\n\n\t---------------------------------------------------";
		   cout<<"\n\t---------------------------------------------------";
		   cout<<"\n\n\t\t\t PASSENGER MENU "
		       <<"\n\t\t\t 1 : RESERVATION "
		       <<"\n\t\t\t 2 : CANCELLATION "
		       <<"\n\t\t\t 3 : RETURN ";
		   cout<<"\n\n\n\n\n\t---------------------------------------------------";
		   cout<<"\n\t---------------------------------------------------";
		   cout<<"\n\t\t\t Enter your choice :";
		   cin>>ch2;
		   switch(ch2)
		 { case 1:reserve();
			  break;
		   case 2:cancel();
			  break;
		   case 3:break;
		 }
		}while(ch2!=3);
		 break;
	  case 3:do

		 { clrscr();
		   cout<<"\n\n\n\n\n\t---------------------------------------------------";
		   cout<<"\n\t---------------------------------------------------";
		   cout<<"\n\n\t\t\t Report Menu";
		   cout<<"\n\t\t\t 1 : TRAIN "
		       <<"\n\t\t\t 2 : PASSENGER "
		       <<"\n\t\t\t 3 : TICKET "
		       <<"\n\t\t\t 4 : RETURN ";
		   cout<<"\n\n\n\n\n\t---------------------------------------------------";
		   cout<<"\n\t---------------------------------------------------";
		   cout<<"\n\t\t\t Enter Your choice :";
		   cin>>ch3;
		   switch(ch3)
		   { case 1:clrscr();
			    do
			    {
			      cout<<"\n\n\n\n\n\t---------------------------------------------------";
			      cout<<"\n\t---------------------------------------------------";
			      cout<<"\n\t\t 1 . INDIVIDUAL ";
			      cout<<"\n\t\t 2 . All ";
			      cout<<"\n\t\t 3 . RETURN ";
			      cout<<"\n\n\n\n\n\t---------------------------------------------------";
			      cout<<"\n\t---------------------------------------------------";
			      cout<<"\nEnter your Choice :";
			      cin>>ch4;
			      switch(ch4)
			     { case 1:reptrain();
				      break;
			       case 2:disptall();
				      break;
			       case 3:break;
			     }
			    }while(ch4!=3);
			     break;
		     case 2:clrscr();
			    do
			    {
			      cout<<"\n\n\n\n\n\t---------------------------------------------------";
			      cout<<"\n\t---------------------------------------------------";
			      cout<<"\n\t\t 1 . INDIVIDUAL ";
			      cout<<"\n\t\t 2 . All";
			      cout<<"\n\t\t 3 . RETURN ";
			      cout<<"\n\n\n\n\n\t---------------------------------------------------";
			      cout<<"\n\t---------------------------------------------------";
			      cout<<"\nEnter your Choice :";
			      cin>>ch5;
			      switch(ch5)
			      { case 1:reppassenger();
				       break;
				case 2:disppall();
				       break;
				case 3:break;
			      }
			    }while(ch5!=3);
			     break;
		     case 3:ticket();
			    break;
		     case 4:break;
		    }
		  }while(ch3!=4);
		   break;

	  case 4:exit(0);
	 }
      }while(ch!=4);
       getch();
}

