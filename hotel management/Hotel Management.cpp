#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<string>
#include<limits>
#include <ctime>

using namespace std;

class data
{
public:
    string name;
    char pass[30];
public:
    void signup();
    void signin();
    void option();
};
class work
{
public:
  void opt();
  int payment(int,int);
  void Ldpt();
  void Dpt(int);
  void Arv();
  void avlroom(int);
  void floors();
  void rooms();
  void Frev(int);
};
class details
{
    public:
    char Name[100];
    char Departure[10];
    string Arrival;
    string Booking;
    char ID[30];
    char Phone_no[15];
    char Address[100];
    char Special_request[100];
    double payment;
    double advance;
    string advance_way;
    string payment_way;
    string payment_status;
    char spacer;
};

int n,rm,ppl,rs,dis,days;
string r,f,payment_mode, date;
double amt,income;
data d;
work w;
details fr;
time_t now = time(0);
char* dt = ctime(&now);

string Date()
{
  string mm,dd,yy,m,m1="Jan",m2="Feb",m3="Mar",m4="Apr",m5="May",m6="Jun",m7="Jul",m8="Aug",m9="Sep",m10="Oct",m11="Nov",m12="Dec";

  for(int i=8;i<10;i++)//DATTE
  { dd+=dt[i];}
  for(int i=4;i<7;i++)//MONTH
  { m+=dt[i];}
  for(int i=20;i<24;i++)//YEAR
  { yy+=dt[i];}

  if(m.compare(m1)==0){mm="01";}
  else if(m.compare(m2)==0){mm="02";}
  else if(m.compare(m3)==0){mm="03";}
  else if(m.compare(m4)==0){mm="04";}
  else if(m.compare(m5)==0){mm="05";}
  else if(m.compare(m6)==0){mm="06";}
  else if(m.compare(m7)==0){mm="07";}
  else if(m.compare(m8)==0){mm="08";}
  else if(m.compare(m9)==0){mm="09";}
  else if(m.compare(m10)==0){mm="10";}
  else if(m.compare(m11)==0){mm="11";}
  else if(m.compare(m12)==0){mm="12";}

  date=(dd+"."+mm+"."+yy);

  cout<<date<<endl;
  return date;
}
void wel()
{
    cout<<"\n\t\t\t WELCOME TO HOTEL ATLANTIS";
    cout<<"\n=================================================================================";
    }
void work::opt()
{
      wel();
      cout<<"\n\n\tOPTIONS";
      cout<<"\n\t---------";
      cout<<"\n\n\t1.FRESH RESERVATION\n\t2.ROOMS\n\t3.ARRIVAL\n\t4.DEPARTURE\n\t\t4.1 TO CONTINUE\n\t\t4.2 LATE DEPARTURE\n\t5.Total INCOME\n\t6.UPDATE AVAILABLE ROOM\n\t7.EXIT";
    }
int work::payment(int k,int ed)
{
  system("cls");
  wel();
  cout<<"\n\n\tPAYMENT";
  cout<<"\n\t---------";

  if(k==0)          //arrival
  {
    cout<<"\n\n\tNo. Of People : ";
    cin>>ppl;
    cout<<"\n\tNo. Of days   : ";
    cin>>days;

    switch(rm)
    {
      case 1: rs =7000;
              break;
      case 2: rs =6000;
              break;
      case 3: rs =5000;
              break;
      case 4: rs =7000;
              break;
      case 5: rs =1000;
              break;
      case 6: rs =4000;
              break;
      default:rs=4000;
              break;
    }

    amt=0;
    amt=(rs*(ppl*0.5)*days);

    ert:
    char w;
    cout<<"\n\tDiscount if applied(Y-Applied/N-Not applied) : ";
    cin>>w;

    if(w=='y'||w=='Y')
    {
      cout<<"\n\tEnter discount : ";
      cin>>dis;
      amt=amt-((amt*dis)*0.01);
    }
    else if(w=='n'||w=='N')
    {
      //amt
    }
    else
    {
      goto ert;
    }

    income=income + amt;

    cout<<"\n\tAMOUNT TO BE PAID : Rs."<<amt<<endl;

    cout<<"\n\n\tENTER TO CONTINUE";
    getch();
    return(amt);
  }
  else if(k==1)   //  departure(ed= 0 )&late departure(ed= 1)
  {
    int i=0,c=0,y;
    string g[20];
    char line[10];
    char date[10];
    string arr;
    string add("name                              : ");

    cout<<"\n\tNAME : ";
    cin>>arr;
    arr = add + arr;//adding string
    if(ed==1)
    {
      cout<<"\n\tENTER NEW DEPARTURE DATE : ";
      cin>>date;
    }

    ifstream infile;
    infile.open("fresh reservation.txt");
    {
      string x[1000];
      //      cout<<"\n\n\tReading from file : "<<endl;

      while(!infile.eof())
      {
        while(getline(infile,x[i]))
        {
          if(x[i].compare(arr) == 0)
          {
            //cout<<"line: "<<i<<" "<< x[i] <<endl;
            line[c]=i;
            c++;
          }
        i++;
        }

      }
      for(int k=0;k<c;k++)
      {
         i=line[k];
         g[k]=x[i+13];
        // cout<<g[k]<<endl;
    //  cout<<"\t"<<x[i+13]<<endl;
    //  cout<<"\n";
      }
      //  cout<<g[k];

      cout<<"\tEnter for choice : ";
      cin>>y;
      y=y-1;
    }
    infile.close();
    //  getch();

    if(g[y]=="payment status                    : unpaid")
    {
      cout<<"\n\n\tNo. Of People : ";
      cin>>ppl;
      cout<<"\n\n\tNo. Of days   : ";
      cin>>days;

      switch(rm)
      {
        case 1: rs =7000;
                break;
        case 2: rs =6000;
                break;
        case 3: rs =5000;
                break;
        case 4: rs =7000;
                break;
        case 5: rs =1000;
                break;
        case 6: rs =4000;
                break;
        default:rs=4000;
                break;
      }

      amt=0;

      amt=(rs*(ppl*0.50)*days);

      char w;
      cout<<"\n\tDiscount if applied(Y-Applied/N-Not applied) : ";
      cin>>w;
      if(w=='y'||w=='Y')
      {
        cout<<"\n\tEnter discount : ";
        cin>>dis;
        amt=amt-((amt*dis)/100);
      }

      income=income + amt;
      cout<<"\n\n\tAMOUNT TO BE PAID : Rs."<<amt<<endl;
      i=0;
      //    cout<<arr;
      {
        ifstream fs;
	      ofstream ft;

	      string str[1000];
        char line1[10];
        int i=0,c=0,totalline=0,o;
        int status;
        //  string arr("name                              : aditya");



	      fs.open("fresh reservation.txt");
	      if (!fs)
	      {
		cout << "Error in Opening Source File...!!!";
		exit(1);
	}

	      ft.open("file_new.txt",ios::out);
	      if (!ft)
	      {
		cout << "Error in Opening Destination File...!!!";
		fs.close();
		exit(2);
	}

	      if (fs && ft)
	      {
    while(!fs.eof())
    {
        while(getline(fs, str[i]))
        {
        //  ft << str[i] << "\n";
          totalline++;
          if(str[i].compare(arr) == 0)
          {
            line1[c]=i;
            c++;
          }
          i++;
        }
  	}
//cout<<i<<"\t"<<c<<"\t";
      if(ed==1)
      {
        for(int k=0;k<c;k++)
        {
          i=line1[k];
          for(o=0;o<i+1;o++)
          {
            ft<<str[o]<<endl;
          }
          ft<<"Date of Departure                 : "<<date<<endl;
          for(o=i+2;o<i+12;o++)
          {
            ft<<str[o]<<endl;
          }
          ft<<"payment                           : "<<amt<<endl;
  				ft<<"payment status                    : paid"<<endl;
  				for(o=i+14;o<totalline;o++)
  				{
  					ft<<str[o]<<endl;
  				//  cout<<"\t"<<str[o]<<endl;
  				}
        }
      }
      else
      {
        for(int k=0;k<c;k++)
        {
          i=line1[k];
          for(o=0;o<i+12;o++)
          {
            ft<<str[o]<<endl;
          //  cout<<"\t"<<str[o]<<endl;
          }
          ft<<"payment                           : "<<amt<<endl;
  				ft<<"payment status                    : paid"<<endl;
  				for(o=i+14;o<totalline;o++)
  				{
  					ft<<str[o]<<endl;
  				//  cout<<"\t"<<str[o]<<endl;
  				}
        }
      }

//		cout << "\n\nSource File Date Successfully Copied to Destination File...!!!";
	}
	      else
	      {
		cout << "File Cannot Open...!!!";
	}

        //	cout << "\n\n Open Destination File and Check!!!\n";

	      fs.close();
	      ft.close();

	       //delete original
        {
	status = remove("fresh reservation.txt");
 if(status==0)
	{
	    //	 cout<<"\nFile Deleted Successfully!"<<endl;
	}
 else
		 cout<<"\nErorr Occurred!";
 cout<<endl;
}

        //renaming temp file to original
        {
  if (rename("file_new.txt","fresh reservation.txt") != 0)
	   perror("Error renaming file");
  else
	{
      //cout << "File renamed successfully"<<endl;
	}
}

      }
      cout<<"\tDATA UPDATED";
      cout<<"\n\n\t ENTER TO CONTINUE";
      getch();
    }
  }
  else if(k==2) //pament income
  {
    system("cls");
    wel();
    int i=0,c=0;
    int num,pay=0;
    char line[10];
    string arr;
    string add("Date of Departure                 : ");
    //  string temp("payment                           : ");
    //  cout<<temp.size();

    cout<<"\n\n\tTOTAL PAYMENT OF THE DAY";
     cout<<"\n\t------------------------";

    cout<<"\n\tEnter  date : ";
    cin>>arr;

    arr = add + arr;//adding string

    ifstream payi;
    payi.open("fresh reservation.txt");
    if (!payi)
    {
      cout << "Error in Opening Source File...!!!";
      exit(1);
    }
    string x[1000];

    cout<<"\n\n\tReading from file : "<<endl;

    while(!payi.eof())
    {
        while(getline(payi,x[i]))
        {
          if(x[i].compare(arr) == 0)
          {
            //cout<<"line: "<<i<<" "<< x[i] <<endl;
            line[c]=i;
            c++;
          }
        i++;
        }
      }
    for(int k=0;k<c;k++)
    {
      i=line[k];
      //  cout<<"\tCUSTOMER : "<<k+1;

      cout<<"\t"<<x[i+11]<<endl;
      string new_line = "";
      for (int j = 36; j < x[i+11].size(); j++)
      {
         new_line += x[i+11][j];
      }
      //  cout << "\t\t" << new_line << endl;

      // using stoi() to store the value of str1 to x
      num = stoi(new_line);
      //  cout << num;
      pay += num;
      //  cout<<"\n";
    }
      //close the opened file.
    payi.close();

    cout<<"\n\n\tTOTAL INCOME : "<<pay;
    cout<<"\n\n\n\tENTER TO CONTINUE";
    getch();
  }
  return (0);
}
void work::Dpt(int k)
{
    system("cls");
    wel();

    int i=0,c=0;
    char line[10];
    string arr;
    string add("Date of Departure                 : ");
    if(k==1)
    {
      cout << "\n\n\tDEPARTURE";
      cout<<"\n\t-----------";
    }
    else
    {
      cout<<"\n\n\tLATE DEPARTURE";
      cout<<"\n\t----------------";
    }

    cout<<"\n\tEnter Departure date : ";
    cin>>arr;

    arr = add + arr;//adding string
    //cout<<"\t"<<arr;

    ifstream infile;
    infile.open("fresh reservation.txt");
    string x[1000];
    {
      cout<<"\n\n\tReading from file : "<<endl;
      while(!infile.eof())
      {
          while(getline(infile,x[i]))
          {
            if(x[i].compare(arr) == 0)
            {
              line[c]=i;
              c++;
            }
            i++;
          }
        }
      for(int k=0;k<c;k++)
      {
        i=line[k];
        cout<<"\tCUSTOMER : "<<k+1<<endl;
        cout<<"\t"<<x[i-1]<<endl;//name
        cout<<"\t"<<x[i+2]<<endl;//id
        cout<<"\t"<<x[i+3]<<endl;//phone no.
        cout<<"\t"<<x[i+8]<<endl;//advance way
        cout<<"\t"<<x[i+9]<<endl;//advance
        cout<<"\t"<<x[i+10]<<endl;//payment way
        cout<<"\t"<<x[i+11]<<endl;//payment
        cout<<"\t"<<x[i+12]<<endl;//payment status
        cout<<"\n";
      }
    }
    //close the opened file.
    infile.close();

    cout<<"\n\n\t ENTER TO CONTINUE ";
    getch();
}
void work::Arv()
{
  system("cls");
  wel();
  int i=0,c=0;
  char line[10];
  string arr;
  string add("Date of Arrival                   : ");

  cout<<"\n\n\tARRIVAL";
  cout<<"\n\t---------";

  cout<<"\n\tEnter arrival date : ";
  cin>>arr;

  arr = add + arr;//adding string

  ifstream infile;
  infile.open("fresh reservation.txt");
  string x[1000];

  cout<<"\n\n\tReading from file : "<<endl;

  while(!infile.eof())
  {
      while(getline(infile,x[i]))
      {
        if(x[i].compare(arr) == 0)
        {
          //cout<<"line: "<<i<<" "<< x[i] <<endl;
          line[c]=i;
          c++;
        }
      i++;
      }
    }
  for(int k=0;k<c;k++)
  {
    i=line[k];
    cout<<"\tCUSTOMER : "<<k+1<<endl;

    cout<<"\t"<<x[i+1]<<endl;
    cout<<"\t"<<x[i+4]<<endl;
    cout<<"\t"<<x[i+5]<<endl;
    cout<<"\t"<<x[i+7]<<endl;
    cout<<"\t"<<x[i+8]<<endl;
    cout<<"\t"<<x[i+9]<<endl;
    cout<<"\n";
}
  //close the opened file.
  infile.close();

  cout<<"\n\n\t ENTER TO CONTINUE";
  getch();

}
void work::avlroom(int k)
{
    if(k==0)
    {
      ifstream ar;
      ar.open("available room.txt");
      string data[100];
      int i=0;
      cout<<"\n\n\t AVAILABLE ROOMS";
      cout<<"\n\t-----------------";
      cout<<"\n\n\tReading from file"<<endl;
      	while ( getline(ar, data[i]) )
        {
            cout<<"\t"<<data[i]<<endl;
            i++;
        }
      //close the opened file.
      ar.close();
      cout<<"\n\n\tENTER TO CONTINUE";
      getch();
    }
    else
    {
      system("cls");
      wel();
      cout<<"\n\n\t UPDATE AVAILABLE ROOMS";
      cout<<"\n\t------------------------";

      char room[100];
      char floor[100];

      ofstream arm;
      arm.open("available room.txt");
      {
      cout<<"\n\n\tWriting to the file"<<endl;
      cin.ignore();
      cout<<"\n\tEnter floor NO. :";
      cin.getline(floor,100);
      cout<<"\n\tEnter room NO. :";
      cin.getline(room,100);

      arm<<floor<<" FLOOR : "<<room<<" ROOM"<<endl;
      }
      arm.close();
      cout<<"\n\n\tENTER TO CONTINUE";
      getch();
    }
  }
void work::floors()
{
  system("cls");
  wel();
  cout<<"\n\n\tFLOOR";
  cout<<"\n\t-------";
  cout<<"\n\n\t1.1st floor"<<"\n\t2.2st floor"<<"\n\t3.3st floor"<<"\n\t4.4st floor"<<"\n\t5.5st floor"<<"\n\t6.6st floor";

  cout<<"\n\n\t ENTER : ";
  cin>>n;
  switch(n)
  {
    case 1: f ="1st floor";
            break;
    case 2: f ="2nd floor";
            break;
    case 3: f ="3rd floor";
            break;
    case 4: f ="4th floor";
            break;
    case 5: f ="5th floor";
            break;
    case 6: f ="6th floor";
            break;
    case 7: cout<<"Program Terminated";
            exit(7);
    default:cout<<"Invalid Code";
            floors();
            break;
  }
}
void work::rooms()
{
  system("cls");
  wel();
  avlroom(0);
  system("cls");
  wel();
  cout<<"\n\n\tROOMS";
  cout<<"\n\t-------";
  cout<<"\n\n\t1. Delux     :7000"<<"\n\t2. Primary + :6000"<<"\n\t3. Primary   :5000"<<"\n\t4. Suits     :7000"<<"\n\t5. Luxury    :10000"<<"\n\t6. Standard  :4000"<<"\n\t7. Exit";
  cout<<"\n\n\tENTER : ";
  cin>>n;
  switch(n)
  {
    case 1: r ="Delux";rm=1;
            break;
    case 2: r ="Primary +";rm=2;
            break;
    case 3: r ="Primary";rm=3;
            break;
    case 4: r ="Suits";rm=4;
            break;
    case 5: r ="Luxury";rm=5;
            break;
    case 6: r ="Standard";rm=6;
            break;
    case 7: cout<<"Program Terminated";
            exit(7);
    default:cout<<"Invalid Code";
            rooms();
            break;
  }
  floors();
}
void work::Frev(int k)
{

  system("cls");
  wel();
  cout<<"\n\n\t FRESH RESERVATION";
  cout<<"\n\t-------------------";

  ofstream outfrv;
  outfrv.open("fresh reservation.txt",ios::out | ios::app);

{
  cout<<"\n\n\tENTER RESERVATION DETAILS\n"<<endl;;
  cin.ignore();

  cout<<"\n\tName of Guest                     : ";
  scanf ("%[^\n]%*c", fr.Name);

  cout<<"\tDate of Arrival                   : ";
  Date();
  fr.Arrival = date;
  //cin.getline(fr.Arrival,100);

  cout<<"\tDate of Departure                 : ";
  cin.getline(fr.Departure,100);

  cout<<"\tDate of Booking                   : ";
  Date();
  fr.Booking = date;
  //cin.getline(fr.Booking,100);

  cout<<"\tid (passport/addhar/DR)           : ";
  cin.getline(fr.ID,100);

  cout<<"\tPhone No                          : ";
  cin.getline(fr.Phone_no,100);

  cout<<"\tAddress                           : ";
  scanf ("%[^\n]%*c",fr.Address);

  cout<<"\tSpecial request                   : ";
  scanf ("%[^\n]%*c",fr.Special_request);

}
  if(k!=0)
  {  cout<<"\tRooms and Floors                  : ";
      cout<<"enter to continue";
      getch();
      rooms();
  }

  char w;
  cout<<"\n\n\tENTER TO CONTINUE FOR PAYMENT\n\t(y-yes/(if n-no then advance) : ";
  ABC:
  cin>>w;

  if(w=='y'||w=='Y')
  {
    fr.advance = 0;//IF YES
    fr.advance_way ="no mode used";
    {
      int p;
      p=payment(0,0);
      fr.payment =p;
      system("cls");
      wel();
      cout<<"\n\n\tPAYMENT";
      cout<<"\n\t---------";
      cin.ignore();

      cout<<"\n\tpayment(card/office/online/cash)  : ";
       //scanf ("%[^\n]%*c",fr.payment_way);
      cin>>fr.payment_way;

      cout<<"\n\tpayment status (paid/unpaid)      : paid";
      fr.payment_status = "paid";
      //cin.getline(fr.payment_status,100);
      cout<<"\n\n\t ENTER TO CONTINUE";
      getch();
    }
  }
  else if(w=='n'||w=='N')  //IF NO
  { xyz:
    fr.advance = 0;  //ADVANCE =0
    {
      system("cls");
      wel();
      cout<<"\n\n\tPAYMENT";
      cout<<"\n\t---------";
      cin.ignore();
      cout<<"\n\n\tWant to pay advance(y-yes/n-no) : ";
      cin>>w;
      if(w=='y'||w=='Y')  //IF ADVANCE TO BE PAID
      {
        cout<<"\n\tpayment(card/office/online/cash)  : ";
        cin>>fr.advance_way;

        cout<<"\n\tADVANCE                         : ";
        cin>>fr.advance;
        //fr.payment = 0;
      }
      else if(w=='n'||w=='N')   //IF ADVANCE NOT TO BE PAID
      {
        fr.advance_way="no mode used";
        cout<<"\n\tADVANCE                         : 0.00";
      //  fr.payment_status = "unpaid";
        fr.advance = 0;
      //  fr.payment = 0;
      }
      else
      {
        cout<<"Invalid code ";
        cout<<"\n\n ENTER TO CONTINUE";
        goto xyz;
      }
      fr.payment_way="no mode used";
      fr.payment = 0;
      cout<<"\n\tpayment status (paid/unpaid)      : unpaid";
      //cin.getline(fr.payment_status,100);
      fr.payment_status= "unpaid";
      cout<<"\n\n\t ENTER TO CONTINUE";
      getch();
    }
  }
  else
  {
    cout<<"Invalid code ";
    cout<<"\n\n ENTER TO CONTINUE";
    getch();
    goto ABC;
  }
  //outfile
{
  outfrv<<"Date of Arrival                   : "<<fr.Arrival<<endl;//i
  outfrv<<"name                              : "<<fr.Name<<endl;//i+1
  outfrv<<"Date of Departure                 : "<<fr.Departure<<endl;//i+2
  outfrv<<"Date of Booking                   : "<<fr.Booking<<endl;//i+3
  outfrv<<"ID                                : "<<fr.ID<<endl;//i+4
  outfrv<<"Phone No                          : "<<fr.Phone_no<<endl;//i+5
  outfrv<<"Address                           : "<<fr.Address<<endl;//i+6
  outfrv<<"Special request                   : "<<fr.Special_request<<endl;//i+7
  outfrv<<"Room no.                          : "<<r<<endl;//i+8
  outfrv<<"Floor no.                         : "<<f<<endl;//i+9
  outfrv<<"advance_way(debit/credit/online/cash) : "<<fr.advance_way<<endl;//i+10
  outfrv<<"advance                           : "<<fr.advance<<endl;//i+11
  outfrv<<"payment_way(debit/credit/online/cash) : "<<fr.payment_way<<endl;//i+12
  outfrv<<"payment                           : "<<fr.payment<<endl;//i+13
  outfrv<<"payment status                    : "<<fr.payment_status<<endl;//i+14
  fr.spacer ='\0';
  outfrv<<fr.spacer<<endl;
}


  outfrv.close();
}
void data::option()
{
    system("cls");
    int i=0,c,c1,ed;
    w.opt();
    cout<<"\n\n\tENTER CHOICE (1-7) : ";
    cin>>c;
    switch(c)
    {
      case 1: w.Frev(1);//-room()-floor()-avrm()-payment();
              break;
      case 2: w.rooms();//room()-floor()-avrm()-Frev()-payment();
              w.Frev(0);
              break;
      case 3: w.Arv();
              break;
      case 4: c4:
              cout<<"\n\tEnter Choice(1-2) : ";
              cin>>c1;
              switch(c1)
              {
                case 1: w.Dpt(1);
                        cout<<"\n\n\tENTER Y for payment\n\tENTER N FOR options";
                        if((getch()=='y')||(getch()=='Y'))
                        w.payment(1,0);
                        break;
                case 2:w.Dpt(2);
                        ed= w.payment(1,1);
                        break;
                default : cout<<"\n\tInvalid Code"<<endl;
                          cout<<"\n\n\tPRESS ANY KEY TO CONTINUE";
                          getch();
                          system("cls");
                          w.opt();
                          cout<<"\n\n\tENTER CHOICE (1-6) : 4";
                          goto c4;
              }
              break;
      case 5: w.payment(2,0);
              break;
      case 6: w.avlroom(1);
              //login
              break;

      case 7: cout<<"\n\n\tLOGGED OUT AND EXIT\n\n\n";
              exit(7);
      default:  cout<<"\n\tInvalid Code"<<endl;
                cout<<"\n\tPRESS ANY KEY TO CONTINUE.....";
                getch();
                option();
    }
  //  main();
    option();
}
void data::signup()
{
  zyx:
  cout<<"\n\n\t Sign Up";
  cout<<"\n\t---------";
  int i=0,c=0,u;
  int z=0;
  char line[10];
  string user;
  string passw;

  string usr("USERNAME : ");
  string pas("PASSWORD : ");

  cout<<"\n\n\t  ENTER USERNAME: ";
  cin>>d.name;

  user = usr + d.name;//adding string


  ifstream sup;
  sup.open("registration.txt");
  string x[100];

  //  cout<<"\n\n\tReading from file : "<<endl;
  while(!sup.eof())
  {
    while(getline(sup,x[i]))
    {
      if(x[i].compare(user) == 0)
      {
        u=x[i].compare(user);
        cout<<"\n\tusername already exit";
        cout<<"\n\tenter to continue";
        getch();
        system("cls");
        wel();
        goto zyx;
      }
      i++;
    }
  }
  //close the opened file.
  sup.close();

  cout<<"\n\t  ENTER PASSWORD: ";
  while((c=getch())!=13)
  {
    d.pass[z++]=c; //hides password
    cout<<"*";
  }
  d.pass[z]='\0';

  passw = pas + d.pass;

  //  cout<<"\t"<<user;
  //  cout<<"\t"<<passw;

  ofstream supout;
  supout.open("registration.txt",ios::app);
  {
  //  cout<<"\nWriting to the file"<<endl;
    supout<<passw<<endl;
    supout<<user<<endl;
    supout<<endl;
  }
  //close the opened afile
  supout.close();
}
void data:: signin()
{
  //  system("cls");
  //  wel();
    cout<<"\n\n\t Sign In";
    cout<<"\n\t---------";
    int i=0,c=0,u,p;
    int z=0;
    char line[10];
    string user;
    string passw;

    string usr("USERNAME : ");
    string pas("PASSWORD : ");

    cout<<"\n\n\t  ENTER USERNAME: ";
    cin>>d.name;
    cout<<"\n\t  ENTER PASSWORD: ";
    while((c=getch())!=13)
    {
      d.pass[z++]=c; //hides password
      cout<<"*";
    }
    d.pass[z]='\0';

    user = usr + d.name;//adding string
    passw = pas + d.pass;//adding string

  //  cout<<"\t"<<user;
  //  cout<<"\t"<<passw;

    ifstream sin;
    sin.open("registration.txt");
    string x[100];
  //  cout<<"\n\n\tReading from file : "<<endl;
    while(!sin.eof())
    {
      while(getline(sin,x[i]))
      {
        if(x[i].compare(user) == 0)
        {
          u=x[i].compare(user);
          p=x[i-1].compare(passw);
          line[c]=i;
          c++;
        }
        i++;
      }
    }
  //  cout<<u<<endl;
  //  cout<<p<<endl;

  if(u==0 && p==0)
  {
    system("cls");
    wel();
    cout<<"\n\n\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY";
    cout<<"\n\n\n\n PRESS ENTER TO CONTINUE";

    sin.close();
    getch();
    option();
  }
  else if(u==0 && p!=0)
  {
    cout<<"\n\n\tWRONG PASSWORD FOR "<<user;
    cout<<"\n\n\t  (Press 'Y' to re-login)";
    if(getch()=='y'||getch()=='Y')
    {
      system("cls");
      wel();
      signin();
    }
  }
  else if(u!=0)
  {
    cout<<"\n\n\tYou are not a Registered User\n\tPress enter to register yourself";
    getch();
  }

    //close the opened file.
    sin.close();

}
int main()
{
  abcd:
  system("cls");
  wel();
  int i=0;
  char nc;

  cout<<"\n\nPress 'Enter' to continue";
  if(getch()==13)  /*for entering enter or \n*/
    system("cls");
  else
  {
    goto abcd;
  }

  edcba:
  ABCDE:
  system("cls");
  wel();
  cout<<"\n\n\t\t1. SIGNIN\t\t2. SIGNUP";
  cout<<"\n\nENTER YOUR CHOICE(1-2):";
  cin >> nc;

  switch(nc)
    {
      case 49:   system("cls"); wel();
                    d.signin();
                    break;
      case 50:   system("cls"); wel();
                    d.signup();
                    cout<<"\n\n\tTry login your account??\n\n\t\t";
                    cout<<"> PRESS 1 FOR YES\n\n\t\t> PRESS 2 FOR NO\n\nENTER : ";
                    cin>>n;
                    switch(n)
                    {
                        case 1: system("cls"); wel();
                                    d.signin();
                                    break;
                        case 2: system("cls"); wel();
                                    cout<<"\n\nREGISTERING SUCCESFUL";
                                    break;
                    }
                    break;
  //    case 51: system("cls");
    //          main();
      //        break;
      default: cout<<"\n\n\tNO MATCH FOUND";
                    cout<<"\n\n\tPress Enter to re-Enter the choice";
                    if(getch()==13)
                    system("cls");
                    goto ABCDE;
    }
    goto edcba;
}
