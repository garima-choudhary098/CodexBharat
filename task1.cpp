#include<iostream>
using namespace std;

int main(){
cout<<"Simple Calculator"<<endl;
cout<<"Performing operations: '+'(addition),'-'(substraction),'*'(multiplication),'/'(division)"<<endl;
double num1,num2;
char op;

cout<<"Enter first number:"<<endl;
if(!(cin>>num1)){
    cout<<"Invalid number";
}

cout<<"Enter operator(+,-,*,/):"<<endl;
cin>>op;
if(op!='+'  && op!='-'  && op!='*'  && op!='/'){
    cout<<"ERROR:Invalid operator"<<endl;
}

cout<<"Enter second number:"<<endl;
if(!(cin>>num2)){
    cout<<"Invalid number";
}

if(op=='/' && num2==0){
    cout<<"ERROR:Divsion by zero is not allowed."<<endl;
}

double result;
switch(op){
    case '+':
         result= num1+num2;
         break;
    case '-':
         result= num1-num2;
         break;
   case '*':
         result= num1*num2;
         break;
   case '/':
         result= num1/num2;
         break;
  default:
  cout<<"Something went wrong. Please try again." << endl;
 
}
 cout<<"The result of"<<num1<<" "<<op<<" "<<num2 <<" is: "<<result<<endl;

cout<<"Do you want to perform another calculation? (yes/no): ";
string again;
cin>>again;
if(again !="yes"){
    cout<<"Goodbye!"<<endl;
    
}
return 0;
}









