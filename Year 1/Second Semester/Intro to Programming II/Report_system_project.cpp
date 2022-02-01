#include<fstream>
#include<iomanip>
#include <iostream>

using namespace std;

class student
{
 int studentNum;
 char name[50];
 int phy_marks, pr_marks, phi_marks, cal_marks, dat_marks;
 double per;
 char grade;
 void calculate(); //function to calculate grade
public:
 void getdata(); //function to accept data from user
 void showdata() const; //function to show data on screen
 void show_tabular() const;
 int retStudentNum() const;
}; //class ends here


void student::calculate()
{
 per=(phy_marks+pr_marks+phi_marks+cal_marks+dat_marks)/5.0;

 if((per>89) && (per<101))
 grade='A';
  else if((per>79) && (per<90))
 grade='B';
 else if((per>69) && (per<80))
 grade='C';
 else if((per>59) && (per<70))
 grade='D';
 else if((per>49) && (per<60))
 grade='E';
 else if((per>39) && (per<50))
 grade='F';
 else
 grade='G';
}

void student::getdata()  //the get data function inherits the student class
{
 cout<<"\nEnter The Student number ";
 cin>>studentNum;
 cout<<"\n\nEnter The Name of student ";
 cin.ignore();
 cin.getline(name,50);
 cout<<"\nEnter The marks in General Physics out of 100 : ";
 cin>>phy_marks;
 cout<<"\nEnter The marks in Programming out of 100 : ";
 cin>>pr_marks;
 cout<<"\nEnter The marks in Philosophy out of 100 : ";
 cin>>phi_marks;
 cout<<"\nEnter The marks in Calculus out of 100 : ";
 cin>>cal_marks;
 cout<<"\nEnter The marks in Data Structures and Algorithms out of 100 : ";
 cin>>dat_marks;
 calculate();
}

void student::showdata() const //the show data function inherits the student class
{
 cout<<"\nStudent number : "<<studentNum;
 cout<<"\nName of student : "<<name;
 cout<<"\nMarks in General Physics : "<<phy_marks;
 cout<<"\nMarks in Programming : "<<pr_marks;
 cout<<"\nMarks in Philosophy : "<<phi_marks;
 cout<<"\nMarks in Calculus : "<<cal_marks;
 cout<<"\nMarks in Data Structures and Algorithms :"<<dat_marks;
 cout<<"\nPercentage of student is  :"<<per;
 cout<<"\nGrade of student is :"<<grade;
}

void student::show_tabular() const
{
 cout<<studentNum<<setw(6)<<" "<<name<<setw(10)<<phy_marks<<setw(10)<<pr_marks<<setw(10)<<phi_marks<<setw(10)
 <<cal_marks<<setw(10)<<dat_marks<<setw(10)<<per<<setw(10)<<grade<<endl;
}

int  student::retStudentNum() const
{
 return studentNum;
}

void write_student(); //write the record in binary file
void display_all(); //read all records from binary file
void display_sp(int); //accept studentNum and read record from binary file
void modify_student(int); //accept studentNum and update record of binary file
void delete_student(int); //accept studentNum and delete selected records from binary file
void class_result(); //display all records in tabular format from binary file
void result(); //display result menu
void intro(); //display welcome screen
void entry_menu(); //display entry menu on screen

int main()
{
 char ch;
 cout.setf(ios::fixed|ios::showpoint);
 cout<<setprecision(2); // program outputs decimal number to two decimal places
 intro();
 do
 {

 cout<<"\n\n\n\tMAIN MENU";
 cout<<"\n\n\t1. RESULT MENU";
 cout<<"\n\n\t2. ENTRY/EDIT MENU";
 cout<<"\n\n\t3. EXIT";
 cout<<"\n\n\tPlease Select Your Option (1-3) :";
 cin>>ch;
 switch(ch)
 {
 case '1': result();
 break;
 case '2': entry_menu();
 break;
 case '3':
 break;
 default :cout<<"\a";
 }
    }while(ch!='3');
 return 0;
}

void write_student()
{
 student st;
 ofstream outFile;
 outFile.open("student.dat",ios::binary|ios::app);
 st.getdata();
 outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
 outFile.close();
     cout<<"\n\nStudent record Has Been Created ";
 cin.ignore();
 cin.get();
}

void display_all()
{
 student st;
 ifstream inFile;
 inFile.open("student.dat",ios::binary);
 if(!inFile)
 {
 cout<<"File could not be open !! Press any Key...";
 cin.ignore();
 cin.get();
 return;
 }
 cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
 while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
 {
 st.showdata();
 cout<<"\n\n====================================\n";
 }
 inFile.close();
 cin.ignore();
 cin.get();
}

void display_sp(int n)
{
 student st;
 ifstream inFile;
 inFile.open("student.dat",ios::binary);
 if(!inFile)
 {
 cout<<"File could not be open !! Press any Key...";
 cin.ignore();
 cin.get();
 return;
 }
 bool flag=false;
 while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
 {
 if(st.retStudentNum()==n)
 {
     st.showdata();
  flag=true;
 }
 }
 inFile.close();
 if(flag==false)
 cout<<"\n\nrecord not exist";
 cin.ignore();
 cin.get();
}

void modify_student(int n)
{
 bool found=false;
 student st;
 fstream File;
 File.open("student.dat",ios::binary|ios::in|ios::out);
 if(!File)
 {
 cout<<"File could not be open !! Press any Key...";
 cin.ignore();
 cin.get();
 return;
 }
     while(!File.eof() && found==false)
 {

  File.read(reinterpret_cast<char *> (&st), sizeof(student));
 if(st.retStudentNum()==n)
 {
 st.showdata();
 cout<<"\n\nPlease Enter The New Details of student"<<endl;
 st.getdata();
      int pos=(-1)*static_cast<int>(sizeof(st));
      File.seekp(pos,ios::cur);
      File.write(reinterpret_cast<char *> (&st), sizeof(student));
      cout<<"\n\n\t Record Updated";
      found=true;
 }
 }
 File.close();
 if(found==false)
 cout<<"\n\n Record Not Found ";
 cin.ignore();
 cin.get();
}

void delete_student(int n)
{
 student st;
 ifstream inFile;
 inFile.open("student.dat",ios::binary);
 if(!inFile)
 {
 cout<<"File could not be open !! Press any Key...";
 cin.ignore();
 cin.get();
 return;
 }
 ofstream outFile;
 outFile.open("Temp.dat",ios::out);
 inFile.seekg(0,ios::beg);
 while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
 {
 if(st.retStudentNum()!=n)
 {
 outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
 }
 }
 outFile.close();
 inFile.close();
 remove("student.dat");
 rename("Temp.dat","student.dat");
 cout<<"\n\n\tRecord Deleted ..";
 cin.ignore();
 cin.get();
}

void class_result()
{
 student st;
 ifstream inFile;
 inFile.open("student.dat",ios::binary);

 if(!inFile)
 {
 cout<<"File could not be open !! Press any Key...";
 cin.ignore();
 cin.get();
 return;
 }
 cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
 cout<<"======================================================================================================\n";
 cout<<"Student.No       Name               PHY-GP   CSIE-P   GE-PHI   CSIE-C   CSIE-D   %age   Grade"<<endl;
 cout<<"======================================================================================================\n";
 while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
 {
 st.show_tabular();
 }
 cin.ignore();
 cin.get();
 inFile.close();
}

void result()
{
 char ch;
 int sNo;

 cout<<"\n\n\n\tRESULT MENU";
 cout<<"\n\n\n\t1. Class Result";
 cout<<"\n\n\t2. Student Report Card";
 cout<<"\n\n\t3. Back to Main Menu";
 cout<<"\n\n\n\tEnter Choice (1/2/3)? :";
 cin>>ch;

 switch(ch)
 {
 case '1' : class_result(); break;
 case '2' : cout<<"\n\n\tEnter Student Number Of Student : "; cin>>sNo;
 display_sp(sNo); break;
 case '3' : break;
 default: cout<<"\a";
 }
}

void intro()
{
 cout<<"********************************************************************************";
 cout<<"\n\n\n\t\t\t NATIONAL DONG HWA UNIVERSITY";
 cout<<"\n\n\n\t\t   WELCOME TO STUDENT REPORT CARD SYSTEM"<<endl<<endl;
 cout<<"********************************************************************************";
 cout<<"\n\n\n\tPress Enter To Continue\n\n";

 cin.get();
}

void entry_menu()
{
 char ch;
 int num;

 cout<<"\n\n\n\tENTRY MENU";
 cout<<"\n\n\t1.CREATE STUDENT RECORD";
 cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
 cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
 cout<<"\n\n\t4.MODIFY STUDENT RECORD";
 cout<<"\n\n\t5.DELETE STUDENT RECORD";
 cout<<"\n\n\t6.BACK TO MAIN MENU";
 cout<<"\n\n\tPlease Enter Your Choice (1-6) :";
 cin>>ch;

 switch(ch)
 {
 case '1': write_student(); break;
 case '2': display_all(); break;
 case '3': cout<<"\n\n\tPlease Enter The Student number :"; cin>>num;
 display_sp(num); break;
 case '4': cout<<"\n\n\tPlease Enter The Student number :"; cin>>num;
 modify_student(num);break;
 case '5': cout<<"\n\n\tPlease Enter The Student number :"; cin>>num;
 delete_student(num);break;
 case '6': break;
 default: cout<<"\a"; entry_menu();
 }
}
