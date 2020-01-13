#include<iostream>
#include<fstream>   //to open files
#include<string>    //to use string class
#include<sstream>   //to open files
#include<windows.h>  //to call system
using namespace std;
class def //parent class A
{
	public:
		   void define(string); //for definitions
		   void first(); //introduction page 1
		   void per();  //periodic table def
};
class element : public def //derived class B
{
	public:
	int number, x, y, year, type, state,take;
	string symbol, name, el;
	float weight, melting, boiling, density, ion;
	public:
		element();
		element(element &); //constructor
		element get(int);  //to accept values
		void show();  //displays the details of elements induvidually
		void display(); //displays the full periodic table
		friend void menu(); //to display menu, friend function
		friend void ex(); //to exit
};
class elecseries : public element //derived class C
{
	public:
		string name,sym,vol;
	public:
	void es(); //displays es
	void cat(); //displays categories
	void eldes(); //accepts compound to send to the chr function
	void equation(); //asks user to enter half equation
	void chr(string); //displays the properties and fully balanced equation
};
void ex()
{
	exit(0);
}
void gotoxy(short x, short y)
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void menu()
{
  string choice,a;
  int number;
  element xyz,e;
  elecseries ty;
  again:
  system("cls");
  system("COLOR F0");
  gotoxy(15,5);
  cout<<"Enter SHOW to display the periodic table";
  gotoxy(15,7);
  cout<<"Enter OTHER to see other options";
  gotoxy(19, 15);
  cout<<"Choice : ";
  gotoxy(15,25);
  cout<<"Enter exit anywhere in the application to exit";
  gotoxy(28,15);
  cin>>choice;
  if(choice=="show")
	{
	  system("cls");
	  gotoxy(0,0);
	  xyz.display();
	  gotoxy (5,25);
	  cout<<"Enter menu to see the menu : ";
	  cin>>a;
	  if(a == "menu")
	  {
	   system("COLOR 07");
	   system("cls");
	   goto again;
      }
    }
    else if (choice == "other")
    {
	 system("cls");
	 gotoxy(17,3);
	 cout<<"Enter ATOMIC NUMBER of an element to view properties";
	 gotoxy(17,5);
	 cout<<"Enter ELECTROCHEMICAL SERIES ('es') to view the series";
	 gotoxy(17,7);
	 cout<<"Enter 'cat' to view the categories of elements";
	 gotoxy(17,9);
	 cout<<"Enter 'next' to view list of compounds";
	 gotoxy(17,11);
	 cout<<"Enter 'equation' to form compounds with equations";
	 string op1;
	 gotoxy(27,19);
	 cin>>op1;
	   if(op1=="ES" || op1=="es")
        {
			ty.es();
        }
        else if(op1=="exit")
		 ex();
		else if(op1=="cat")
		{
			ty.cat();
		}
		else if(op1=="next")
		{
			ty.eldes();
		}
		else if(op1=="equation")
		{
			ty.equation();
		}
       else //if(isdigit(op1))
        {
	        number  = stoi(op1);
	        if(number>118)
	         {
		       system("cls");
			   gotoxy(25,10);
               system("COLOR 0C");
		       cout<<"ELEMENT NOT DISCOVERED YET!";
             }
             else
	          {
		        xyz=e.get(number);
              }
        }
    }
	else
    {
    	ex();
	}
	  gotoxy (5,25);
	  cout<<"Enter menu to see the menu : ";
	  cin>>a;
	  if(a == "menu")
	  {
	   system("COLOR 07");
	   system("cls");
	   goto again;
      }
	  else
	   ex();
}
void def :: per()
{
	system("cls");
	system("COLOR B0");
	gotoxy(10,8);
	cout<<"A table of elements arranged in order of increasing proton number";
	gotoxy(20,9);
	cout<<"to show the similarities of chemical elements";
	gotoxy(22,10);
	cout<<" with related electronic configurations";
	gotoxy(25,11);
	cout<<"is called Periodic Table";
	Sleep(5000);
}
void def :: first()
{
	char a;
	for(int i=0;i<3;i++)
	{
	    system("cls");
	   	Sleep(800);
	 gotoxy(19,10);
	 system("COLOR 0E");
	 cout<<"  PERIODIC TABLE AND ITS PROPERTIES";
	 gotoxy(19,11);
	 cout<<"-------------------------------------";
	 gotoxy(55,23);
	 cout<<"Mini Project By";
	 gotoxy(55,25);
	 cout<<"LIKHITA SURESH";
	 Sleep(1000);

    }
}
element :: element()
{
	number = 0;
	x = 0;
	y = 0;
	symbol = " ";
	name = " ";
	weight = 0;
	melting = 0;
	boiling = 0;
	density = 0;
	year = 0;
	ion = 0;
	type = 0;
	state = 0;
	el = " ";
}
element :: element(element &a)
{
	number = a.number;
	x = a.x;
	y = a.y;
	symbol = a.symbol;
	name = a.name;
	weight = a.weight;
	melting = a.melting;
	boiling = a.boiling;
	density = a.density;
	year = a.year;
	ion = a.ion;
	type = a.type;
	state = a.state;
	el = a.el;
}
element element :: get(int number)
{
	int take;
	element a;
	string z;
	ifstream b_file("peri6969.txt");
	while (!b_file.eof())
	{

	 b_file>>a.take;
	 b_file>>a.x;
	 b_file>>a.y;
	 b_file>>a.symbol;
	 b_file>>a.name;
	 b_file>>a.weight;
	 b_file>>a.melting;
	 b_file>>a.boiling;
	 b_file>>a.density;
	 b_file>>a.year;
	 b_file>>a.ion;
	 b_file>>a.type;
     getline(b_file,a.el);
	 if (number==a.take)
	 {
	   a.show();
	   break;
     }
    }
    b_file.close();
    return (a);
}
void element :: show()
{
	   string term;
	   char x = 248;
	   system("cls");
	   system("COLOR 0F");
	   for(int j=4;j<=15;j++)
		{
			gotoxy(14,j);
			cout<<"|";
			gotoxy(57,j);
			cout<<"|";
        }
	   gotoxy(15,3);
       cout<<"__________________________________________";
       gotoxy(17,5);
       cout<<"PHYSICAL PROPERTY";    gotoxy(38,5); cout<<"VAULE";
	   gotoxy (17,7);
 	   cout<<"Atomic number     : "; gotoxy(38,7);cout<<take;
 	   gotoxy (17,8);
	   cout<<"Symbol            : "; gotoxy(38,8); cout<<symbol;
	   gotoxy (17,9);
	   cout<<"Name              : ";gotoxy(38,9); cout<<name;
	   gotoxy (17,10);
	   cout<<"Mass number       : ";gotoxy(38,10);cout<<weight<<"g/mol";
	   gotoxy (17,11);
	   cout<<"Melting point     : ";gotoxy(38,11); cout<<melting<<x<<"C";
	   gotoxy (17,12);
	   cout<<"Boiling point     : ";gotoxy(38,12); cout<<boiling<<x<<"C";
	   gotoxy (17,13);
	   cout<<"Density           : ";gotoxy(38,13); cout<<density<<"g/cm^3";
	   gotoxy (17,14);
	   //cout<<"Year of discovery : "<<year<<endl;
	   //gotoxy (17,13);
	   cout<<"Ionization energy :  "<<ion*100<<"kJ/mol"<<endl;
       gotoxy(15,15);
	   cout<<"__________________________________________";
	   gotoxy(14,18);
	   cout<<"Enter the physical property to know the significance";
	   gotoxy(14,19);
	   cout<<"             or ";
	   gotoxy(14,20);
	   cout<<"Enter menu to go to menu : ";
	   gotoxy(27,23);
	   cin>>term;
	   if(term=="menu")
	   menu();
	   else if(term=="exit")
	   ex();
	   define(term);
	   gotoxy(0,18);
}
void element :: display()
{
	 element a;
	 ifstream b_file("peri6969.txt");
	 system("COLOR 0B");
	    while (!b_file.eof())
	     {
           b_file>>a.take;
	       b_file>>a.x;
	       b_file>>a.y;
           b_file>>a.symbol;
	       getline(b_file,a.el);
		   gotoxy (a.x,a.y-2);
		   cout<<a.symbol;
         }
		 gotoxy (12,19);
		 cout<<"LANTHANIDES";
		 gotoxy(12,21);
		 cout<<"ACTINIDES";
		 gotoxy (2,3);
		 cout<<"PERIOD 1 ";
		 gotoxy(2,5);
		 cout<<"PERIOD 2 ";
		 gotoxy(2,7);
		 cout<<"PERIOD 3 ";
		 gotoxy(2,9);
		 cout<<"PERIOD 4 ";
		 gotoxy(2,11);
		 cout<<"PERIOD 5 ";
		 gotoxy(2,13);
		 cout<<"PERIOD 6 ";
		 gotoxy(2,15);
		 cout<<"PERIOD 7 ";
		 b_file.close();
		 gotoxy(10,25);
		 cout<<"Enter menu to go to menu : ";
		 string op;
		 cin>>op;
		 if(op=="menu")
		   menu();
		 else
		   ex();
}
void def :: define (string term)
{
	 system("cls");
	 if(term=="atomic")
	 {
 		system("COLOR C0");
		gotoxy(20,5);
		cout<<"ATOMIC NUMBER is the number of protons";
		gotoxy(20,6);
		cout<<"     in the nuclues of an element";
	 }
	 else if(term=="symbol")
	 {
	 	system("COLOR 10");
	 	gotoxy(20,5);
	 	cout<<"SYMBOL is a code for a chemical ELEMENT";
     }
     else if(term=="name")
     {
     	system("COLOR 20");
     	gotoxy(15,5);
     	cout<<"Chemical elements may be named from various sources";
     	gotoxy(15,6);
     	cout<<"  somtimes based on the person who discovered it,";
     	gotoxy(15,7);
     	cout<<"         or the place it was discovered.";
		gotoxy(1,8);
		cout<<"Some have Latin or Greek roots deriving from something related to the element.";
	 }
	 else if(term=="mass")
	 {
	 	system("COLOR 30");
	 	gotoxy(15,5);
	 	cout<<"MASS NUMBER is the number of protons and neutrons";
	 	gotoxy(15,6);
	 	cout<<"            in a chemical element";
	 }
	 else if(term=="boiling")
	 {
	 	system("COLOR 40");;
	 	gotoxy(11,5);
	 	cout<<"The temperature at which the saturated vapour pressure at which";
	 	gotoxy(11,6);
	 	cout<<" the saturated vapour pressure of a liquid equals the external";
	 	gotoxy(11,7);
	 	cout<<"         atmospheric pressure is called BOILING POINT";
	 }
	 else if(term=="density")
	 {
	 	system("COLOR 50");
	 	gotoxy(11,5);
	 	cout<<"Density is the mass of a substance per unit of volume";
	 }
	 else if(term=="year")
	 {
	 	system("COLOR 60");
	 	gotoxy(11,5);
	 	cout<<"This element was discovered in this year ";
	 }
	 else if(term=="ionization")
	 {
	 	system("COLOR 70");
	 	gotoxy(9,5);
	 	cout<<"The minimum energy required to remove an electron from a specified";
	 	gotoxy(9,6);
	 	cout<<"atom or molecule to such a distance that there is no electrostatic";
	 	gotoxy(9,7);
	 	cout<<"        interaction between ion and electron is called";
	 	gotoxy(9,8);
	 	cout<<"                    IONIZATION ENERGY";
	 }
	 gotoxy(11,25);
	 cin.sync();
	 cout<<"Enter menu to go to menu : ";
	 string xyz;
	 cin>>xyz;
	 if(xyz=="menu")
	 {
 	  menu();
     }
     else
	  ex();
}
void elecseries :: es()
{
	int x=0,y=3;
	elecseries cv;
	system("cls");
	system("COLOR 0D");
	gotoxy(10,0);
	cout<<"------------------------------------------------------------";
	gotoxy(15,1);
	cout<<"ELEMENT";
	gotoxy(30,1);
	cout<<"SYMBOL";
	gotoxy(45,1);
	cout<<"ELECTRODE POTENTIAL (V)";
	gotoxy(10,2);
	cout<<"------------------------------------------------------------";
	ifstream a_file("es.txt");
	while (x<19)
	{
	 a_file>>cv.name;
	 a_file>>cv.sym;
	 getline(a_file,cv.vol);
	 gotoxy(15,y);
	 cout<<cv.name;
	 gotoxy(30,y);
	 cout<<cv.sym;
	 gotoxy(55,y);
	 cout<<cv.vol;
	 y++;
	 x++;
    }
    a_file.close();
    gotoxy(10,24);
    cout<<"Enter menu to see the menu : ";
    string men;
	cin>>men;
	if(men=="menu")
    menu();
    else
	 ex();
}
void elecseries :: cat()
{
	system("cls");
	system("COLOR 06");
	gotoxy(35,5);
	cout<<"ELEMENTS";
	gotoxy(35,6);
	cout<<"    |";
	gotoxy(20,7);
	cout<<"----------------------------------------";
	gotoxy(20,8);
	cout<<"|";
	gotoxy(39,8);
	cout<<"|";
	gotoxy(59,8);
	cout<<"|";
	gotoxy(17,9);
	cout<<"Metals";
	gotoxy (20,10);
	cout<<"|";
	gotoxy (17,11);
	cout<<"Sodium,";
	gotoxy(17,12);
	cout<< "Calcium,";
	gotoxy(17,13);
	cout<< "Magnesium";
	gotoxy(17,14);
	cout<<"Iron,";
	gotoxy(17,15);
	cout<<"Tin,";
	gotoxy(17,15);
	cout<<"Nickel,";
	gotoxy(17,16);
	cout<<" Copper";
	gotoxy(34,9);
	cout<<"Non Metals";
	gotoxy (39,10);
	cout<<"|";
	gotoxy(34,11);
	cout<<"Hydrogen,";
    gotoxy(34,12);
	cout<<"Oxygen,";
	gotoxy(34,13);
	cout<<"Chlorine";
	gotoxy(34,14);
	cout<<"Sulphur,";
	gotoxy(34,15);
	cout<<"Carbon,";
	gotoxy(34,16);
	cout<<"Iodine";
	gotoxy(56,9);
	cout<<"Metalloids";
	gotoxy (59,10);
	cout<<"|";
	gotoxy(56,11);
	cout<<"Boron,";
	gotoxy(56,12);
	cout<<" Silicon,";
	gotoxy(56,13);
	cout<<"Arsenic";
	gotoxy(56,14);
	cout<<"Germanium,";
	gotoxy(56,15);
	cout<<"Tellurium";
	
}
void elecseries :: eldes()
{
	elecseries asd;
	string op;
	int i,j=10;
	system("cls");
	system("COLOR CF");
	gotoxy(25,5);
	cout<<"Compounds";
	gotoxy(30,8);
	cout<<"H2O";
	gotoxy(30,9);
	cout<<"NaCl";
	gotoxy(30,10);
	cout<<"NH3";
	gotoxy(30,11);
	cout<<"HNO3";
	gotoxy(30,12);
	cout<<"HCl";
	gotoxy(30,13);
	cout<<"H2SO4";
	gotoxy(15,20);
	cout<<"Enter compound name accurately : " ;
	cin>>op;
	asd.chr(op);
}
void elecseries :: chr(string op)
{
	int i,j=5;
	system("cls");
	gotoxy(10,5);
	if(op=="H2O")
	 {
	 	ifstream a_file("h20.txt");
	 	while(getline(a_file,op))
		 {
		 	cout<<op;
		 	gotoxy(10,j++);
		 }
		a_file.close();
	 }
	else if(op=="HCl")
	 {
	 	ifstream a_file("hcl.txt");
	 	while(getline(a_file,op))
		 {
		 	cout<<op;
		 	gotoxy(10,j++);
		 }
		 a_file.close();
	 }
	 else if(op=="NH3")
	 {
	 	ifstream a_file("nh3.txt");
	 	while(getline(a_file,op))
		 {
		 	cout<<op;
		 	gotoxy(10,j++);
		 }
		a_file.close();
	 }
	else if(op=="NaCl")
	 {
	 	ifstream a_file("nacl.txt");
	 	while(getline(a_file,op))
		 {
		 	cout<<op;
		 	gotoxy(10,j++);
		 }
		a_file.close();
	 }
	 else if(op=="H2SO4")
	 {
	 	ifstream a_file("H2SO4.txt");
	 	while(getline(a_file,op))
		 {
		 	cout<<op;
		 	gotoxy(10,j++);
		 }
		a_file.close();
	 }
	 else if(op=="HNO3")
	 {
	 	ifstream a_file("hno3.txt");
	 	while(getline(a_file,op))
		 {
		 	cout<<op;
		 	gotoxy(10,j++);
		 }
		a_file.close();
	 }
	 else
	  ex();
}
void elecseries :: equation()
{
	string str;
	elecseries asd;
	system("cls");
	system("COLOR 70");
	gotoxy(5,8);
	cout<<"Enter the equation with the elements in their molecular form";
	gotoxy(30,6);
	cout<<"-";
	cin.sync();
 	getline(cin,str);
	if(str == "N2 + H2")
	 {
	   asd.chr("NH3");
	 }
	else if (str == "H2 + O2")
	 {
	 	asd.chr("H2O");
     }
	else if (str == "H2 + SO42-")
	{
		asd.chr("H2SO4");
	}
	else if (str == "H2 + Cl2")
	{
		asd.chr("HCl");
	}
	else if (str == "H2 + NO3-")
	{
		asd.chr("HNO3");
	}
	else if (str == "Na + Cl2")
	{
		asd.chr("NaCl");
	}
	else
	 ex();
}
int main()
{

	element xyz;
	def qw;
	qw.first();
	qw.per();
	menu();

	return 0;
}
