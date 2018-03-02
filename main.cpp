#include <bits/stdc++.h>
using namespace std;

class user
{
protected:
  string startloc,endloc;
  int routeid,dist,haltnumbers;
  string halts[5];
  int busid;
  int starthr,startmin,endhr,endmin;
  int seats;
  float price;
public:
    virtual void getChoice()=0;
};

class ticketinfo
{
protected:
    string name;
    char gender;
    int age;
    int numberofseats;
    int date;
    float totalprice;
    int requiredbusid;
    long int pnr;
    int busstarthr,busstartmin,busendhr,busendmin;

};

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}


class bookingadmin:public user,public ticketinfo
{
protected:
  string password;
public:
  int ch;
  friend void getAllRoutes();
  bookingadmin()
  {
    password="password";
  }
  void getChoice()
  {
    Z:
      cout<<"press 1 to see all routes available"<<endl;
      cout<<"press 2 to see all buses available"<<endl;
      cout<<"press 3 to see all tickets booked"<<endl;
      cout<<"press 0 to logout"<<endl;
      cin>>ch;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid choice. \n Please provide a valid choice\n";
          goto Z;
      }
  }
  int checkPassword(string p)
  {
      if(password == p)
      {
          return 1;
      }
      else
      {
          return 0;
      }
  }
  void getAllBuses()
  {
      string x;
      int d;
      int c=0;
      ifstream ifile("bus.csv");

      while(getline(ifile,x,','))
      {
          stringstream s1(x);
          s1>>busid;
          getline(ifile,x,',');
          stringstream s2(x);
          s2>>starthr;
          getline(ifile,x,',');
          stringstream s3(x);
          s3>>startmin;
          getline(ifile,x,',');
          stringstream s4(x);
          s4>>endhr;
          getline(ifile,x,',');
          stringstream s5(x);
          s5>>endmin;
          getline(ifile,x,',');
          stringstream s6(x);
          s6>>price;
          getline(ifile,x,',');
          stringstream s7(x);
          s7>>seats;
          getline(ifile,x,'\n');
          stringstream s8(x);
          s8>>d;

          if(c != busid)
              cout<<"Bus ID- "<<busid<<" Journey start time- "<<starthr<<":"<<startmin<<" Journey end time- "<<endhr<<":"<<endmin<<" , Price- "<<price<<"Rupees"<<endl;

          c=busid;
      }
      cout<<endl;
      ifile.close();
  }
  void getAllTickets()
  {
      string x;
      int flag=0;

      ifstream ifile("ticket.csv");

      while(getline(ifile,x,','))
      {
          stringstream s1(x);
          s1>>pnr;
          getline(ifile,name,',');
          getline(ifile,x,',');
          stringstream s2(x);
          s2>>gender;
          getline(ifile,x,',');
          stringstream s3(x);
          s3>>age;
          getline(ifile,x,',');
          stringstream s4(x);
          s4>>requiredbusid;
          getline(ifile,x,',');
          stringstream s5(x);
          s5>>numberofseats;
          getline(ifile,x,',');
          stringstream s6(x);
          s6>>totalprice;
          getline(ifile,x,',');
          stringstream s11(x);
          s11>>date;
          getline(ifile,x,',');
          stringstream s7(x);
          s7>>busstarthr;
          getline(ifile,x,',');
          stringstream s8(x);
          s8>>busstartmin;
          getline(ifile,x,',');
          stringstream s9(x);
          s9>>busendhr;
          getline(ifile,x,'\n');
          stringstream s10(x);
          s10>>busendmin;

              flag++;
              cout<<endl<<flag<<" ."<<endl;
              cout<<endl<<"PNR Number - "<<pnr<<endl;
              cout<<"Name- "<<name<<" , Gender- "<<gender<<" , Age- "<<age<<endl;
              cout<<"Bus ID- "<<requiredbusid<<" , Number of seats- "<<numberofseats<<" , Date- "<<date<<" Nov 2017 "<<endl;
              cout<<"Journey Start Time- "<<busstarthr<<":"<<busstartmin<<" , Journey End Time- "<<busendhr<<":"<<busendmin<<endl;
              cout<<"Total Price paid- "<<totalprice<<endl<<endl;

      }
  }
};

class admin:public user
{
protected:
    string password;
public:
    int ch;
    friend  void getAllRoutes();
    admin()
    {
        int i;
        for(i=0;i<5;i++)
            halts[i]="NULL";
        password="password";
    }
    void getAllBuses()
    {
        string x;
        int d;
        int c=0;
        ifstream ifile("bus.csv");

        while(getline(ifile,x,','))
        {
            stringstream s1(x);
            s1>>busid;
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>starthr;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>startmin;
            getline(ifile,x,',');
            stringstream s4(x);
            s4>>endhr;
            getline(ifile,x,',');
            stringstream s5(x);
            s5>>endmin;
            getline(ifile,x,',');
            stringstream s6(x);
            s6>>price;
            getline(ifile,x,',');
            stringstream s7(x);
            s7>>seats;
            getline(ifile,x,'\n');
            stringstream s8(x);
            s8>>d;

            if(c != busid)
                cout<<"Bus ID- "<<busid<<" Journey start time- "<<starthr<<":"<<startmin<<" Journey end time- "<<endhr<<":"<<endmin<<" , Price- "<<price<<"Rupees"<<endl;

            c=busid;
        }
        cout<<endl;
        ifile.close();
    }
    int checkPassword(string p)
    {
        if(password == p)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void getChoice()
    {
      Z:
        cout<<"press 1 to enter a new route"<<endl;
        cout<<"press 2 to see all routes available"<<endl;
        cout<<"press 3 to see all buses available"<<endl;
        cout<<"press 0 to logout"<<endl;
        cin>>ch;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid choice. \n Please provide a valid choice\n";
            goto Z;
        }
    }
    void input()
    {
        int i;
        for(i=0;i<5;i++)
            halts[i]="NULL";
        G:cout<<"Enter start and end location"<<endl;
        cin>>startloc>>endloc;
          if(startloc==endloc)
          {
            cout<<"Both locations are same"<<endl<<"Enter again"<<endl;
            goto G;
          }
        Z:cout<<"Enter Route ID "<<endl;
        cin>>routeid;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid route ID. \n Please provide a valid route ID\n";
            goto Z;
        }
        Y:cout<<"Enter distance (in km)"<<endl;
        cin>>dist;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid distance. \n Please provide a valid distance\n";
            goto Y;
        }
        X:cout<<"Enter number of haltings (max 5 halts)"<<endl;
        cin>>haltnumbers;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid halts. \n Please provide a valid halts\n";
            goto X;
        }
        for(i=0;i<haltnumbers;i++)
        {
            cout<<"Enter "<<i+1<<" halt location"<<endl;
            cin>>halts[i];
        }
        Q:cout<<"Enter Bus ID running on that route"<<endl;
        cin>>busid;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid bus ID. \n Please provide a valid bus ID\n";
            goto Q;
        }
        P:cout<<"Enter journey start time (only hours and minutes and in 24 hours format)"<<endl;
        cin>>starthr>>startmin;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid time. \n Please provide a valid time\n";
            goto P;
        }
        R:cout<<"Enter journey end time (only hours and minutes and in 24 hours format)"<<endl;
        cin>>endhr>>endmin;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid time. \n Please provide a valid time\n";
            goto R;
        }
        A:cout<<"Enter price per seat"<<endl;
        cin>>price;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid price. \n Please provide a valid price\n";
            goto A;
        }
        seats=10;
    }
    void enterNewRoute()
    {
        int i;
        input();
        ofstream ofile("routes.csv",ios::app);
        ofile<<startloc<<","<<endloc<<","<<routeid<<","<<dist<<","<<haltnumbers<<","<<halts[0]<<","<<halts[1]<<","<<halts[2]<<","<<halts[3]<<","<<halts[4]<<","<<busid<<"\n";
        ofile.close();

        ofstream ofile1("bus.csv",ios::app);
        for(i=1;i<=30;i++)
        {
            ofile1<<busid<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<","<<price<<","<<seats<<","<<i<<"\n";
        }
    }
};

class bookingofficer:public user,public ticketinfo
{
protected:
  string password;
  string startloc1,endloc1;

public:
  friend  void getAllRoutes();
  int ch;
  int remainingseats;

  bookingofficer()
  {
    password="password";
  }

  int checkPassword(string p)
  {
      if(password == p)
      {
          return 1;
      }
      else
      {
          return 0;
      }
  }

  void getChoice()
  {
    Z:
      cout<<"press 1 book tickets"<<endl;
      cout<<"press 2 to get detailed status of bus and available seats on date from 1st Nov 2017 to 30th Nov 2017"<<endl;
      cout<<"press 3 to enquire for ticket details using PNR Number"<<endl;
      cout<<"press 0 to logout"<<endl;
      cin>>ch;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid choice. \n Please provide a valid choice\n";
          goto Z;
      }
  }

  void getBusDetails()
  {
      int requiredbusid;
      int d,flag=0;
      string x;
      Z:cout<<"Enter bus ID to get details"<<endl;
      cin>>requiredbusid;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid bus ID. \n Please provide a valid bus ID\n";
          goto Z;
      }

      ifstream ifile("bus.csv");

      while(getline(ifile,x,','))
      {
          stringstream s1(x);
          s1>>busid;
          getline(ifile,x,',');
          stringstream s2(x);
          s2>>starthr;
          getline(ifile,x,',');
          stringstream s3(x);
          s3>>startmin;
          getline(ifile,x,',');
          stringstream s4(x);
          s4>>endhr;
          getline(ifile,x,',');
          stringstream s5(x);
          s5>>endmin;
          getline(ifile,x,',');
          stringstream s6(x);
          s6>>price;
          getline(ifile,x,',');
          stringstream s7(x);
          s7>>seats;
          getline(ifile,x,'\n');
          stringstream s8(x);
          s8>>d;

          if(busid == requiredbusid)
          {
              if(flag == 0)
              {
                  cout<<"Bus ID- "<<busid<<" Journey start time- "<<starthr<<":"<<startmin<<" Journey end time- "<<endhr<<":"<<endmin<<" , Price- "<<price<<"Rupees"<<endl;
                  cout<<d<<" Nov 2017 seats available- "<<seats<<endl;
              }
              cout<<d<<" Nov 2017 seats available- "<<seats<<endl;
              flag++;
          }

      }
      if(flag == 0)
      {
          cout<<"Bus "<<requiredbusid<<" not found !"<<endl<<endl;
      }
  }

  void input()
  {
      int dflag=1;
      string temp;
      cout<<"Enter name"<<endl;
      getline(cin,temp);
      getline(cin,name);
      L:cout<<"Enter gender (M/F) "<<endl;
      cin>>gender;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid gender. \n Please provide a valid gender\n";
          goto L;
      }
      P:cout<<"Enter age"<<endl;
      cin>>age;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid age. \n Please provide a valid age\n";
          goto P;
      }
      Q:cout<<"Enter bus ID in which ticket is to booked"<<endl;
      cin>>requiredbusid;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid bus ID. \n Please provide a valid bus ID\n";
          goto Q;
      }
      R:cout<<"Enter number of seats to book"<<endl;
      cin>>numberofseats;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid number of seats. \n Please provide a valid number of seats\n";
          goto R;
      }
      cout<<"Enter date on which ticket is to be booked (Date Range - 1st Nov 2017 to 30th Nov 2017)"<<endl;
      while(dflag)
      {
        cin>>date;
        if(date>=1 && date<=30)
          dflag--;
        else
          cout<<endl<<"Enter a valid date"<<endl<<endl;
      }
  }

  void generatePnr()
  {
      pnr=(((((requiredbusid*100)+date)*100)+numberofseats)*100)+remainingseats;
  }

  void updateBusSeats()
  {
      string x;
      int d,i;
      ofstream ofile("test.csv",ios::ate);
      ifstream ifile("bus.csv");

      while(getline(ifile,x,','))
      {
          stringstream s1(x);
          s1>>busid;
          getline(ifile,x,',');
          stringstream s2(x);
          s2>>starthr;
          getline(ifile,x,',');
          stringstream s3(x);
          s3>>startmin;
          getline(ifile,x,',');
          stringstream s4(x);
          s4>>endhr;
          getline(ifile,x,',');
          stringstream s5(x);
          s5>>endmin;
          getline(ifile,x,',');
          stringstream s6(x);
          s6>>price;
          getline(ifile,x,',');
          stringstream s7(x);
          s7>>seats;
          getline(ifile,x,'\n');
          stringstream s8(x);
          s8>>d;

          if(busid == requiredbusid && d == date)
          {
              seats=remainingseats;
          }

          ofile<<busid<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<","<<price<<","<<seats<<","<<d<<"\n";
      }

      ifile.close();
      ofile.close();

      ofstream ofile1("bus.csv",ios::ate);
      ifstream ifile1("test.csv");

      while(getline(ifile1,x,','))
      {
          stringstream s1(x);
          s1>>busid;
          getline(ifile1,x,',');
          stringstream s2(x);
          s2>>starthr;
          getline(ifile1,x,',');
          stringstream s3(x);
          s3>>startmin;
          getline(ifile1,x,',');
          stringstream s4(x);
          s4>>endhr;
          getline(ifile1,x,',');
          stringstream s5(x);
          s5>>endmin;
          getline(ifile1,x,',');
          stringstream s6(x);
          s6>>price;
          getline(ifile1,x,',');
          stringstream s7(x);
          s7>>seats;
          getline(ifile1,x,'\n');
          stringstream s8(x);
          s8>>d;

          ofile1<<busid<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<","<<price<<","<<seats<<","<<d<<"\n";
      }

      ifile.close();
      ofile.close();

      ofstream ofile2("test.csv",ios::ate);
      ofile2.close();
  }

  void bookTicket()
  {
      string x;
      int d;
      int flag=0,flag1=0;
      input();

      ifstream ifile("bus.csv");

      while(getline(ifile,x,','))
      {
          stringstream s1(x);
          s1>>busid;
          getline(ifile,x,',');
          stringstream s2(x);
          s2>>starthr;
          getline(ifile,x,',');
          stringstream s3(x);
          s3>>startmin;
          getline(ifile,x,',');
          stringstream s4(x);
          s4>>endhr;
          getline(ifile,x,',');
          stringstream s5(x);
          s5>>endmin;
          getline(ifile,x,',');
          stringstream s6(x);
          s6>>price;
          getline(ifile,x,',');
          stringstream s7(x);
          s7>>seats;
          getline(ifile,x,'\n');
          stringstream s8(x);
          s8>>d;

          if(busid == requiredbusid)
          {
              flag++;
              if(d == date && seats>=numberofseats)
              {
                  flag1++;
                  remainingseats=seats-numberofseats;
                  busstarthr=starthr;
                  busstartmin=startmin;
                  busendhr=endhr;
                  busendmin=endmin;

                  ofstream ofile("ticket.csv",ios::app);

                  generatePnr();

                  totalprice=price*numberofseats;

                  ofile<<pnr<<","<<name<<","<<gender<<","<<age<<","<<requiredbusid<<","<<numberofseats<<","<<totalprice<<","<<date<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<"\n";

                  ofile.close();
                  cout<<"Ticket booked successfully"<<endl;
                  cout<<endl<<"PNR Number - "<<pnr<<endl;
                  cout<<"Name- "<<name<<" , Gender- "<<gender<<" , Age- "<<age<<endl;
                  cout<<"Bus ID- "<<busid<<" , Number of seats- "<<numberofseats<<" , Date- "<<date<<" Nov 2017 "<<endl;
                  cout<<"Journey Start Time- "<<busstarthr<<":"<<busstartmin<<" , Journey End Time- "<<busendhr<<":"<<busendmin<<endl;
                  cout<<"Total Price to be paid- "<<totalprice<<endl;

                  updateBusSeats();

                  cout<<endl<<endl;
              }
          }

      }
      if(flag == 0)
      {
          cout<<"Bus "<<requiredbusid<<" not found !"<<endl<<endl;
      }
      if(flag != 0 && flag1 == 0)
      {
          cout<<"Required number of seats in bus "<<requiredbusid<<" are not available"<<endl<<endl;
      }

  }

  void getTicketDetails()
  {
      long int requiredpnr;
      string x;
      int flag=0;

      Z:cout<<"Enter your PNR Number"<<endl;
      cin>>requiredpnr;
      while (cin.fail())
      {
          cin.clear(); // clear input buffer to restore cin to a usable state
          cin.ignore(INT_MAX, '\n'); // ignore last input
          cout<<"\n Invalid PNR. \n Please provide a valid PNR\n";
          goto Z;
      }

      ifstream ifile("ticket.csv");

      while(getline(ifile,x,','))
      {
          stringstream s1(x);
          s1>>pnr;
          getline(ifile,name,',');
          getline(ifile,x,',');
          stringstream s2(x);
          s2>>gender;
          getline(ifile,x,',');
          stringstream s3(x);
          s3>>age;
          getline(ifile,x,',');
          stringstream s4(x);
          s4>>requiredbusid;
          getline(ifile,x,',');
          stringstream s5(x);
          s5>>numberofseats;
          getline(ifile,x,',');
          stringstream s6(x);
          s6>>totalprice;
          getline(ifile,x,',');
          stringstream s11(x);
          s11>>date;
          getline(ifile,x,',');
          stringstream s7(x);
          s7>>busstarthr;
          getline(ifile,x,',');
          stringstream s8(x);
          s8>>busstartmin;
          getline(ifile,x,',');
          stringstream s9(x);
          s9>>busendhr;
          getline(ifile,x,'\n');
          stringstream s10(x);
          s10>>busendmin;

          if(pnr == requiredpnr)
          {
              flag++;
              cout<<"Required ticket info. is-"<<endl;
              cout<<endl<<"PNR Number - "<<pnr<<endl;
              cout<<"Name- "<<name<<" , Gender- "<<gender<<" , Age- "<<age<<endl;
              cout<<"Bus ID- "<<requiredbusid<<" , Number of seats- "<<numberofseats<<" , Date- "<<date<<" Nov 2017 "<<endl;
              cout<<"Journey Start Time- "<<busstarthr<<":"<<busstartmin<<" , Journey End Time- "<<busendhr<<":"<<busendmin<<endl;
              cout<<"Total Price paid- "<<totalprice<<endl<<endl;
          }
      }
      if(flag==0)
      {
          cout<<"Ticket having PNR Number- "<<requiredpnr<<" is not present"<<endl<<endl;
      }
      ifile.close();
  }

};

class enduser:public user,public ticketinfo
{
protected:
    string startloc1,endloc1;

public:
    int ch;
    int remainingseats;
    friend void getAllRoutes();
    void getChoice()
    {
      Z:
        cout<<"press 1 to search for routes and then book tickets"<<endl;
        cout<<"press 2 to get ticket details using PNR Number"<<endl;
        cout<<"press 3 to see all available routes"<<endl;
        cout<<"press 0 to exit"<<endl;
        cin>>ch;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid choice. \n Please provide a valid choice\n";
            goto Z;
        }
    }
    void searchRoute()
    {
        int ch;
        int flag=0;
        string x;
        cout<<"Enter start and end location to be searched"<<endl;
        cin>>startloc1>>endloc1;

        ifstream ifile("routes.csv");

        while(getline(ifile,startloc,','))
        {
            getline(ifile,endloc,',');
            getline(ifile,x,',');
            stringstream s1(x);
            s1>>routeid;
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>dist;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>haltnumbers;
            getline(ifile,halts[0],',');
            getline(ifile,halts[1],',');
            getline(ifile,halts[2],',');
            getline(ifile,halts[3],',');
            getline(ifile,halts[4],',');
            getline(ifile,x,'\n');
            stringstream s4(x);
            s4>>busid;

            if(((startloc1==startloc) && (endloc1==endloc)))
            {
                flag++;
                cout<<endl<<flag<<". From "<<startloc<<" to "<<endloc<<" , Route ID- "<<routeid<<" , distance- "<<dist<<"km  , halts- ";
                for(int i=0;i<5;i++)
                {
                    if(halts[i] != "NULL")
                    {
                       cout<<halts[i]<<" , ";
                    }
                }
                cout<<" bus id of the bus traveling in that route- "<<busid<<endl;
                cout<<endl;

            }
        }
        if(flag != 0)
        {
            do{
              A:
                cout<<endl<<"press 1 to get detailed status of bus and available seats on date from 1st Nov 2017 to 30th Nov 2017"<<endl;
                cout<<"press 2 to book tickets"<<endl;
                cout<<"press 0 to exit"<<endl;
                cin>>ch;
                while (cin.fail())
                {
                    cin.clear(); // clear input buffer to restore cin to a usable state
                    cin.ignore(INT_MAX, '\n'); // ignore last input
                    cout<<"\n Invalid choice. \n Please provide a valid choice\n";
                    goto A;
                }
                if(ch == 1)
                {
                    getBusDetails();
                }
                else if(ch == 2)
                {
                    bookTicket();
                }
                else if(ch == 0)
                {
                    clear();
                    break;
                }
                else
                {
                    cout<<"Wrong choice"<<endl;
                }
                }while(1);
        }
        if(flag == 0)
        {
            cout<<"Sorry No buses found !"<<endl;
        }
        ifile.close();
    }

    void getBusDetails()
    {
        int requiredbusid;
        int d,flag=0;
        string x;
        cout<<"Enter bus ID to get details"<<endl;
        cin>>requiredbusid;

        ifstream ifile("bus.csv");

        while(getline(ifile,x,','))
        {
            stringstream s1(x);
            s1>>busid;
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>starthr;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>startmin;
            getline(ifile,x,',');
            stringstream s4(x);
            s4>>endhr;
            getline(ifile,x,',');
            stringstream s5(x);
            s5>>endmin;
            getline(ifile,x,',');
            stringstream s6(x);
            s6>>price;
            getline(ifile,x,',');
            stringstream s7(x);
            s7>>seats;
            getline(ifile,x,'\n');
            stringstream s8(x);
            s8>>d;

            if(busid == requiredbusid)
            {
                if(flag == 0)
                {
                    cout<<"Bus ID- "<<busid<<" Journey start time- "<<starthr<<":"<<startmin<<" Journey end time- "<<endhr<<":"<<endmin<<" , Price- "<<price<<"Rupees"<<endl;
                    cout<<d<<" Nov 2017 seats available- "<<seats<<endl;
                }
                cout<<d<<" Nov 2017 seats available- "<<seats<<endl;
                flag++;
            }

        }
        if(flag == 0)
        {
            cout<<"Bus "<<requiredbusid<<" not found !"<<endl<<endl;
        }
    }

    void input()
    {
        string temp;
        int dflag=1;
        cout<<"Enter name"<<endl;
        getline(cin,temp);
        getline(cin,name);
        L:cout<<"Enter gender (M/F) "<<endl;
        cin>>gender;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid gender. \n Please provide a valid gender\n";
            goto L;
        }
        P:cout<<"Enter age"<<endl;
        cin>>age;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid age. \n Please provide a valid age\n";
            goto P;
        }
        Q:cout<<"Enter bus ID in which ticket is to booked"<<endl;
        cin>>requiredbusid;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid bus ID. \n Please provide a valid bus ID\n";
            goto Q;
        }
        R:cout<<"Enter number of seats to book"<<endl;
        cin>>numberofseats;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid number of seats. \n Please provide a valid number of seats\n";
            goto R;
        }
        cout<<"Enter date on which ticket is to be booked (Date Range - 1st Nov 2017 to 30th Nov 2017)"<<endl;
        while(dflag)
        {
          cin>>date;
          if(date>=1 && date<=30)
            dflag--;
          else
            cout<<endl<<"Enter a valid date"<<endl<<endl;
        }
    }

    void generatePnr()
    {
        pnr=(((((requiredbusid*100)+date)*100)+numberofseats)*100)+remainingseats;
    }

    void updateBusSeats()
    {
        string x;
        int d,i;
        ofstream ofile("test.csv",ios::ate);
        ifstream ifile("bus.csv");

        while(getline(ifile,x,','))
        {
            stringstream s1(x);
            s1>>busid;
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>starthr;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>startmin;
            getline(ifile,x,',');
            stringstream s4(x);
            s4>>endhr;
            getline(ifile,x,',');
            stringstream s5(x);
            s5>>endmin;
            getline(ifile,x,',');
            stringstream s6(x);
            s6>>price;
            getline(ifile,x,',');
            stringstream s7(x);
            s7>>seats;
            getline(ifile,x,'\n');
            stringstream s8(x);
            s8>>d;

            if(busid == requiredbusid && d == date)
            {
                seats=remainingseats;
            }

            ofile<<busid<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<","<<price<<","<<seats<<","<<d<<"\n";
        }

        ifile.close();
        ofile.close();

        ofstream ofile1("bus.csv",ios::ate);
        ifstream ifile1("test.csv");

        while(getline(ifile1,x,','))
        {
            stringstream s1(x);
            s1>>busid;
            getline(ifile1,x,',');
            stringstream s2(x);
            s2>>starthr;
            getline(ifile1,x,',');
            stringstream s3(x);
            s3>>startmin;
            getline(ifile1,x,',');
            stringstream s4(x);
            s4>>endhr;
            getline(ifile1,x,',');
            stringstream s5(x);
            s5>>endmin;
            getline(ifile1,x,',');
            stringstream s6(x);
            s6>>price;
            getline(ifile1,x,',');
            stringstream s7(x);
            s7>>seats;
            getline(ifile1,x,'\n');
            stringstream s8(x);
            s8>>d;

            ofile1<<busid<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<","<<price<<","<<seats<<","<<d<<"\n";
        }

        ifile.close();
        ofile.close();

        ofstream ofile2("test.csv",ios::ate);
        ofile2.close();
    }

    void bookTicket()
    {
        string x;
        int d;
        int flag=0,flag1=0;
        input();

        ifstream ifile("bus.csv");

        while(getline(ifile,x,','))
        {
            stringstream s1(x);
            s1>>busid;
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>starthr;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>startmin;
            getline(ifile,x,',');
            stringstream s4(x);
            s4>>endhr;
            getline(ifile,x,',');
            stringstream s5(x);
            s5>>endmin;
            getline(ifile,x,',');
            stringstream s6(x);
            s6>>price;
            getline(ifile,x,',');
            stringstream s7(x);
            s7>>seats;
            getline(ifile,x,'\n');
            stringstream s8(x);
            s8>>d;

            if(busid == requiredbusid)
            {
                flag++;
                if(d == date && seats>=numberofseats)
                {
                    flag1++;
                    remainingseats=seats-numberofseats;
                    busstarthr=starthr;
                    busstartmin=startmin;
                    busendhr=endhr;
                    busendmin=endmin;

                    ofstream ofile("ticket.csv",ios::app);

                    generatePnr();

                    totalprice=price*numberofseats;

                    ofile<<pnr<<","<<name<<","<<gender<<","<<age<<","<<requiredbusid<<","<<numberofseats<<","<<totalprice<<","<<date<<","<<starthr<<","<<startmin<<","<<endhr<<","<<endmin<<"\n";

                    ofile.close();
                    cout<<"Ticket booked successfully"<<endl;
                    cout<<endl<<"PNR Number - "<<pnr<<endl;
                    cout<<"Name- "<<name<<" , Gender- "<<gender<<" , Age- "<<age<<endl;
                    cout<<"Bus ID- "<<busid<<" , Number of seats- "<<numberofseats<<" , Date- "<<date<<" Nov 2017 "<<endl;
                    cout<<"Journey Start Time- "<<busstarthr<<":"<<busstartmin<<" , Journey End Time- "<<busendhr<<":"<<busendmin<<endl;
                    cout<<"Total Price to be paid- "<<totalprice<<endl;

                    updateBusSeats();

                    cout<<endl<<endl;
                }
            }

        }
        if(flag == 0)
        {
            cout<<"Bus "<<requiredbusid<<" not found !"<<endl<<endl;
        }
        if(flag != 0 && flag1 == 0)
        {
            cout<<"Required number of seats in bus "<<requiredbusid<<" are not available"<<endl<<endl;
        }

    }

    void getTicketDetails()
    {
        long int requiredpnr;
        string x;
        int flag=0;

        Z:cout<<"Enter your PNR Number"<<endl;
        cin>>requiredpnr;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout<<"\n Invalid PNR. \n Please provide a valid PNR\n";
            goto Z;
        }

        ifstream ifile("ticket.csv");

        while(getline(ifile,x,','))
        {
            stringstream s1(x);
            s1>>pnr;
            getline(ifile,name,',');
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>gender;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>age;
            getline(ifile,x,',');
            stringstream s4(x);
            s4>>requiredbusid;
            getline(ifile,x,',');
            stringstream s5(x);
            s5>>numberofseats;
            getline(ifile,x,',');
            stringstream s6(x);
            s6>>totalprice;
            getline(ifile,x,',');
            stringstream s11(x);
            s11>>date;
            getline(ifile,x,',');
            stringstream s7(x);
            s7>>busstarthr;
            getline(ifile,x,',');
            stringstream s8(x);
            s8>>busstartmin;
            getline(ifile,x,',');
            stringstream s9(x);
            s9>>busendhr;
            getline(ifile,x,'\n');
            stringstream s10(x);
            s10>>busendmin;

            if(pnr == requiredpnr)
            {
                flag++;
                cout<<"Required ticket info. is-"<<endl;
                cout<<endl<<"PNR Number - "<<pnr<<endl;
                cout<<"Name- "<<name<<" , Gender- "<<gender<<" , Age- "<<age<<endl;
                cout<<"Bus ID- "<<requiredbusid<<" , Number of seats- "<<numberofseats<<" , Date- "<<date<<" Nov 2017 "<<endl;
                cout<<"Journey Start Time- "<<busstarthr<<":"<<busstartmin<<" , Journey End Time- "<<busendhr<<":"<<busendmin<<endl;
                cout<<"Total Price paid- "<<totalprice<<endl<<endl;
            }
        }
        if(flag==0)
        {
            cout<<"Ticket having PNR Number- "<<requiredpnr<<" is not present"<<endl<<endl;
        }
        ifile.close();
    }
};

void getAllRoutes()
{
    string startloc,endloc;
    int routeid,dist,haltnumbers;
    string halts[5];
    int busid;

    string x;
    int flag=0;

    ifstream ifile("routes.csv");

        while(getline(ifile,startloc,','))
        {
            getline(ifile,endloc,',');
            getline(ifile,x,',');
            stringstream s1(x);
            s1>>routeid;
            getline(ifile,x,',');
            stringstream s2(x);
            s2>>dist;
            getline(ifile,x,',');
            stringstream s3(x);
            s3>>haltnumbers;
            getline(ifile,halts[0],',');
            getline(ifile,halts[1],',');
            getline(ifile,halts[2],',');
            getline(ifile,halts[3],',');
            getline(ifile,halts[4],',');
            getline(ifile,x,'\n');
            stringstream s4(x);
            s4>>busid;
            flag++;

                cout<<endl<<flag<<". From "<<startloc<<" to "<<endloc<<" , Route ID- "<<routeid<<" , distance- "<<dist<<"km  , halts- ";
                for(int i=0;i<5;i++)
                {
                    if(halts[i] != "NULL")
                    {
                       cout<<halts[i]<<" , ";
                    }
                }
                cout<<" bus id of the bus traveling in that route- "<<busid<<endl;
                cout<<endl;

        }
    ifile.close();
}

int main()
{
    int ch;
    cout<<endl<<"-------------------------WELCOME-------------------------"<<endl<<endl;
    do{
    Z:cout<<"press 1 to enter as admin"<<endl<<"press 2 to enter as booking admin"<<endl<<"press 3 to enter as booking officer"<<endl<<"press 4 to enter as end user"<<endl<<"press 0 to exit"<<endl;;
    cin>>ch;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout<<"\n Invalid choice. \n Please provide a valid choice\n";
        goto Z;
    }
    if(ch==1)
    {
      clear();
        user *p;
        admin a;
        p=&a;
        string pass="";
        cout<<"Enter password"<<endl;
        cin>>pass;
/*
        char temp;
        temp=getchar();
        while(1)
        {
            temp=getch();
            if(temp!='\n')
            {
                pass = pass + temp;
                cout<<"*";
            }
            else
            {
                cout<<endl;
                break;
            }
        }
*/
        if(a.checkPassword(pass))
        {
            do
            {
            p->getChoice();
            if(a.ch == 1)
            {
                a.enterNewRoute();
            }
            else if(a.ch == 2)
            {
                getAllRoutes();
            }
            else if(a.ch == 3)
            {
                a.getAllBuses();
            }
            else if(a.ch == 0)
            {
                cout<<"Logged out successfully"<<endl;
                exit(1);
            }
            else
            {
                cout<<"Wrong choice"<<endl;
            }
            }while(1);
        }
        else
        {
            cout<<"Wrong Password"<<endl;
        }

    }
    else if(ch == 2)
    {
      clear();
      user *p;
      bookingadmin a;
      p=&a;
      string pass="";
      cout<<"Enter password"<<endl;
      cin>>pass;

      /*
              char temp;
              temp=getchar();
              while(1)
              {
                  temp=getch();
                  if(temp!='\n')
                  {
                      pass = pass + temp;
                      cout<<"*";
                  }
                  else
                  {
                      cout<<endl;
                      break;
                  }
              }
      */

      if(a.checkPassword(pass))
      {
          do
          {
          p->getChoice();
          if(a.ch == 1)
          {
            getAllRoutes();
          }
          else if(a.ch == 2)
          {
            a.getAllBuses();
          }
          else if(a.ch == 3)
          {
            a.getAllTickets();
          }
          else if(a.ch == 0)
          {
              cout<<"Logged out successfully"<<endl;
              exit(1);
          }
          else
          {
              cout<<"Wrong choice"<<endl;
          }
          }while(1);
      }
      else
      {
          cout<<"Wrong Password"<<endl;
      }
    }
    else if(ch == 3)
    {
      clear();
      user *p;
      bookingofficer u;
      p=&u;

      string pass="";
      cout<<"Enter password"<<endl;
      cin>>pass;

      /*
              char temp;
              temp=getchar();
              while(1)
              {
                  temp=getch();
                  if(temp!='\n')
                  {
                      pass = pass + temp;
                      cout<<"*";
                  }
                  else
                  {
                      cout<<endl;
                      break;
                  }
              }
      */

      if(u.checkPassword(pass))
      {
          do
          {
          p->getChoice();
          if(u.ch == 1)
          {
            cout<<endl<<"We have following routes on which our buses travel your may book bus tickets according to bus ID"<<endl<<endl;
            getAllRoutes();
            u.bookTicket();
          }
          else if(u.ch == 2)
          {
            cout<<endl<<"We have following routes on which our buses travel your may book bus tickets according to bus ID"<<endl<<endl;
            getAllRoutes();
            u.getBusDetails();
          }
          else if(u.ch == 3)
          {
            u.getTicketDetails();
          }
          else if(u.ch == 0)
          {
              cout<<"Logged out successfully"<<endl;
              exit(1);
          }
          else
          {
              cout<<"Wrong choice"<<endl;
          }
          }while(1);
      }
      else
      {
          cout<<"Wrong Password"<<endl;
      }
    }
    else if(ch == 4)
    {
      clear();
        user *p;
        enduser u;
        p=&u;
        do{
          p->getChoice();
          if(u.ch == 1)
          {
              u.searchRoute();
          }
          else if(u.ch == 2)
          {
              u.getTicketDetails();
          }
          else if(u.ch == 3)
          {
              getAllRoutes();
          }
          else if(u.ch == 0)
          {
              exit(1);
          }
          else
          {
              cout<<"Wrong choice"<<endl;
          }
        }while(1);
    }
    else if(ch == 0)
    {
        exit(1);
    }
    else
    {
        cout<<"Wrong choice"<<endl;
    }
    }while(1);
    return 0;
}
