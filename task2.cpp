#include<iostream>
#include<string>
#include<vector>

using namespace std;
class student{
    private:
       int Marks[3];
       int Totalmarks;
       double Average;
       char Grade;
       
    public:
       string Name;
    //Function to input student details.
        void Inputdetails(){
         cout << "Enter student name: "<<endl;
         cin.ignore();
        getline(cin,Name);
         
         cout << "Enter marks for three subjects: ";
         for(int i=0;i<3;i++){
            cin>>Marks[i];
         }
        }
//function to calculate total marks,average and grade
void calculate(){
    Totalmarks =0;
    for(int i=0;i<3;i++){
        Totalmarks += Marks[i];
    }
    Average =Totalmarks/3.0;

    //conditions for grading
    if(Average>90){
        Grade='A';
        }
        else if(Average>80){
            Grade='B';
    }
     else if(Average>70){
            Grade='C';
    }
     else if(Average>60){
            Grade='D';
    }
     else 
            Grade='F';
    }

//Function to display student details
void DisplayDetails() const {
    cout<<"Name is: "<<Name<<endl;
     cout<<"Total marks is: "<<Totalmarks<<endl;
      cout<<"Average is: "<<Average<<endl;
       cout<<"Grade is: "<<Grade<<endl;
       cout<<"---------------------------"<<endl;
}

};

int main(){
    
cout<<"Students grading sysytem"<<endl;;
int numstudents;//details of number of students

cout<<"Enter number of students:"<<endl;
cin>>numstudents;

   student s;//object 

for(int i=1;i<=numstudents;i++){
    cout<<"Enter details for students "<<i<<" : "<<endl;
   s.Inputdetails();
   s.calculate();
//Display Details for all students.
cout<<"Students Details"<<endl;
cout<< "-----------------------------\n";
         s.DisplayDetails();
   }

return 0;
 }