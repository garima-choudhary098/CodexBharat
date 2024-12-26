#include<iostream>
 #include<fstream>
 #include<string>
#include<iomanip>
using namespace std;
 
const int MAX_ACCOUNTS=100;

 class Account{
    private:
    string accountHolderName;
    int accountNumber;
    double balance;
   
    public:
    Account(): accountNumber(0), balance(0.0){}

    

    void createAccount(int accNo,const string &name,double initialBalance=0.0){
        accountNumber = accNo;
         accountHolderName=name;
         balance=initialBalance;
    }

    void deposit(double amount){
        if(amount>0){
            balance += amount;
            cout<<"Deposit Successful! New Balance : "<<fixed<<setprecision(2)<<balance<<endl;
} else{
    cout<<"Invalid amount.Deposite failed.\n";

    }}

    void withdraw(double amount){
   if(amount>balance){
    cout<<"Insufficient balance! withdrawn failed.\n";
    
   }else if(amount<=0){
    cout<<"Invalid amount.Withdrawn failed.\n";
   }
   balance -= amount;
   cout<<"Withdrawl Sucessful !New balance: "<<fixed<<setprecision(2)<<balance<<endl;
    }

    void displayAccounts()const{
        cout<<"Account Number: "<<accountNumber<<endl;
          cout<<"Account holder: "<<accountHolderName<<endl; 
           cout<<"Balance : "<<fixed <<  setprecision(2)  <<balance<<endl;
            }

   bool isActive()const{
    return accountNumber != 0;
   }
  int getAccountNumber() const {
        return accountNumber;
    }
   
    void saveToFile(ofstream &outfile) const {
        if(isActive()){
        outfile << accountNumber << " " << accountHolderName << " " << balance << endl;
    }}

 void loadFromFile(ifstream &infile) {
       
        infile >> accountNumber ; 
        infile.ignore();
        getline(infile,accountHolderName, ' '); // Read account holder name
        infile >> balance;
        
    }
};

void createAccount(Account accounts[], int &numAccounts);
void displayAccounts(const Account accounts[], int numAccounts);
void depositMoney(Account accounts[], int numAccounts);
void withdrawMoney(Account accounts[], int numAccounts);
void saveAccountsToFile(const Account accounts[], int numAccounts);
void loadAccountsFromFile(Account accounts[], int &numAccounts);



  const string FILENAME="accounts.txt";
 
 int main(){
    Account account[MAX_ACCOUNTS];
  int numAccounts =0;

 loadAccountsFromFile(account,numAccounts);

    int choice;
    do {
        cout << "\n*** Banking System ***\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createAccount(account,numAccounts);
                break;
            case 2:
                displayAccounts(account,numAccounts);
                break;
            case 3:
                depositMoney(account,numAccounts);
                break;
            case 4:
                withdrawMoney(account,numAccounts);
                break;
            case 5:
                saveAccountsToFile(account,numAccounts);
                cout << "Exiting... Account data saved successfully!\n";
                  break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

  void createAccount(Account accounts[], int &numAccounts){
     if(numAccounts >= MAX_ACCOUNTS){
     cout<<"Cannot create more accounts. Maximum limit reached.\n";
     return;
     }
  int accNo;
  string name;
  double initialBalance;

    cout<<"Enter Account Holder Name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"ENter Account number: ";
    cin>>accNo;
    cout<<"ENter Initial Balance : ";
    cin>>initialBalance;

    for(int i=0;i<numAccounts;i++){
        if(accounts[i].getAccountNumber( )== accNo){
  cout<<"Account number already axsits!Try again.\n";
      return;  }
    }

    accounts[numAccounts].createAccount(accNo, name, initialBalance );
    numAccounts++;
    cout <<"Account created successfully!\n";
  }

  void depositMoney(Account accounts[], int numAccounts){
    int accNo;
    double a;
    cout<<"Enter Account number: ";
    cin>>accNo;
    for(int i=0; i<numAccounts;i++){
    if(accounts[i].getAccountNumber()==accNo){
        cout<<"Enter ammount to deposite: ";
        cin>>a;
        accounts[i].deposit(a);

        return;
    }
   
  }}

   void withdrawMoney(Account accounts[], int numAccounts){
    int accNo;
    double a;//amount
    cout<<"Enter Account number: ";
    cin>>accNo;
    for(int i=0;i<numAccounts;i++){
    if(accounts[i].getAccountNumber()==accNo){
        cout<<"Enter ammount to withdraw: ";
        cin>>a;
        accounts[i].withdraw(a);
        return;
    }}
    cout<<"Account not found!\n";
  }

  void displayAccounts  (const Account accounts[], int numAccounts){
     if(numAccounts ==0){
        cout<<"No accounts available.\n";
        return;
     }
     for(int i=0;i<numAccounts;i++){
        if(accounts[i].isActive()){
            accounts[i].displayAccounts();
            cout<<"---------------------------\n";
        }
     }}
     void saveAccountsToFile(const Account accounts[], int numAccounts) {
    ofstream outfile(FILENAME);
    if (!outfile) {
        cout << "Error saving accounts to file!\n";
        return;
    }
    for (int i = 0; i < numAccounts; i++) {
        accounts[i].saveToFile(outfile);
    }
    outfile.close();}
   
   void loadAccountsFromFile(Account accounts[], int &numAccounts) {
    ifstream infile(FILENAME);
    if (!infile) {
        cout << "No existing account data found. Starting fresh...\n";
        return;
    }
    while (infile && numAccounts < MAX_ACCOUNTS) {
        accounts[numAccounts].loadFromFile(infile);
        if (accounts[numAccounts].isActive()) {
            numAccounts++;}}}
  