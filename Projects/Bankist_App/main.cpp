#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <cmath>

using namespace std;

#define interestRate 1.5
#define minmumBalanceForInterest 200
class account
{
private:
    string name;
    string userName;
    int size;
    int pin;
    double *movements;
    double totalBalance;
    double income;
    double outcome;
    double interest;
    bool sort;

public:
    // default constructor
    account()
    {
        name = "";
        userName = "";
        pin = 0;
        size = 0;
        totalBalance = 0.0;
        income = 0.0;
        outcome = 0.0;
        interest = 0.0;
        sort = false;
        movements = nullptr;
    }
    // parameterized constructor
    account(string name, string userName, int pin, int size, double totalBalance, double income, double outcome, double interest, bool sort, double *movements)
    {
        this->name = name;
        this->userName = userName;
        this->pin = pin;
        this->size = size;
        this->totalBalance = totalBalance;
        this->income = income;
        this->outcome = outcome;
        this->interest = interest;
        this->sort = sort;
        this->movements = movements;
    }
    // copy constructor
    account(const account &temp)
    {
        name = temp.name;
        userName = temp.userName;
        pin = temp.pin;
        size = temp.size;
        totalBalance = temp.totalBalance;
        income = temp.income;
        outcome = temp.outcome;
        interest = temp.interest;
        sort = temp.sort;
        movements = temp.movements;
        cout << "Copy constructor called:" << endl;
    }
    // setters
    void setName(string name) { this->name = name; }
    void setUserName(string userName) { this->userName = userName; }
    void setPin(int pin) { this->pin = pin; }
    void setSize(int size) { this->size = size; }
    void setTotalBalance(double totalBalance) { this->totalBalance = totalBalance; }
    void setIncome(double income) { this->income = income; }
    void setOutcome(double outcome) { this->outcome = outcome; }
    void setInterest(double interest) { this->interest = interest; }
    void setSort(bool sort) { this->sort = sort; }
    void setMovementsAddress(double *movements) { this->movements = movements; }
    void setMovementsValue()
    {
        movements = new double[size];
        for (int i = 0; i < size; i++)
        {
            cin >> *(movements + i);
        }
    }

    void setData(string name, string userName, int pin, int size, double *movements, double totalBalance, double income, double outcome, double interest, bool sort)
    {
        this->name = name;
        this->userName = userName;
        this->pin = pin;
        this->size = size;
        this->totalBalance = totalBalance;
        this->income = income;
        this->outcome = outcome;
        this->interest = interest;
        this->sort = sort;
        this->movements = movements;
    }
    // Input Data
    void createAccount()
    {
        cout << "\t\tEnter your full name = ";
        getline(cin, name);
        cout << "\t\tSet your pin code = ";
        cin >> pin;
        cout << "\t\t Are you want to deposit some balance now (y/n) :";
    }

    // getters
    string getName() { return name; }
    string getUserName() { return userName; }
    int getPin() { return pin; }
    int getSize() { return size; }
    double getTotalBalance() { return totalBalance; }
    double getIncome() { return income; }
    double getOutcome() { return outcome; }
    double getInterest() { return interest; }
    bool getSort() { return sort; }
    double *getMovementsAddress() { return movements; }
    void getMovementsValue()
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(movements + i) << endl;
        }
    }
    void getData()
    {
        cout << "\t\t Your name : " << name << endl;
        cout << "\t\t Your userName : " << userName << endl;
        cout << "\t\t Your pin code : " << pin << endl;
        cout << "\t\t Your total Balance : " << totalBalance << endl;
        cout << "\t\t Your total incomes : " << income << endl;
        cout << "\t\t Your total outcomes : " << outcome << endl;
        cout << "\t\t Your total interest amount : " << interest << endl;
        cout << "\t\t Your movements : " << endl;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) > 0)
                cout << "\t\tDeposited : " << *(movements + i) << endl;
            if (*(movements + i) < 0)
                cout << "\t\tWithdrawl : " << *(movements + i) << endl;
        }
        cout << endl;
    }

    // destructor
    ~account()
    {
        cout << "Destructor called:" << endl;
    }

    // Member Functions

    // 1-Calculating UserName
    void calculateUserName()
    {

        userName = "";
        userName.push_back(tolower(name[0]));
        bool flag = false;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] == ' ')
            {
                flag = true;
            }
            if (name[i] != ' ' && flag == true)
            {
                userName.push_back(tolower(name[i]));
                flag = false;
            }
        }
    }

    // 2- Calculating Total Balance
    double calculateTotalBalance()
    {
        double total = calculateTotalIncome() - calculateTotalOutcome();
        totalBalance = total;
        return total;
    }

    // 3-Calculating Summary
    // a-Income
    double calculateTotalIncome()
    {
        double totalIncome = 0.0;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) >= 0)
                totalIncome += (*(movements + i));
        }
        income = totalIncome;
        return totalIncome;
    }
    // b-Outcome
    double calculateTotalOutcome()
    {
        double totalOutcome = 0.0;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) < 0)
                totalOutcome += (abs(*(movements + i)));
        }
        outcome = totalOutcome;
        return totalOutcome;
    }
    // c-InterestRate
    double calculateTotalInterest()
    {
        double totalInterest = 0.0;
        for (int i = 0; i < size; i++)
        {
            double deposit = 0.0;
            if (*(movements + i) > 0)
            {
                deposit = *(movements + i) * (interestRate / 100);
                if (deposit >= 1)
                {
                    totalInterest += deposit;
                }
            }
        }
        interest = totalInterest;
        return totalInterest;
    }

    // 4-sortingAlgorithum(selection-sort)
    void sortMovements()
    {
        int min_index;
        for (int i = 0; i < size - 1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (*(movements + j) < *(movements + min_index))
                {
                    min_index = j;
                }
            }
            int temp;
            temp = *(movements + i);
            *(movements + i) = *(movements + min_index);
            *(movements + min_index) = temp;
        }
    }
};

// Supporting-Functions
void spaces1()
{
    for (int i = 0; i < 4; i++)
        cout << endl;
    cout << "\t\t\t SALIK BANK LIMITED (SBL) " << endl;
}
void spaces2()
{
    for (int i = 0; i < 2; i++)
        cout << endl;
}

// LOGIN-PAGE
void loginPage(char &login)
{
    spaces1();
    spaces2();
    cout << "\t\t\t\t LOGIN " << endl;
    spaces2();
    cout << "\t\t If you have already an account then press \'L\' for login your account : " << endl;
    cout << "\t\t If you don't have an account then press \'C\' for create your account : " << endl;
    login = getch();
    login = tolower(login);
    while (login != 'l' && login != 'c')
    {
        cout << "\t\tError->Invalid Input :" << endl;
        cout << "\t\tPlease enter the valid input as \'L\' or \'C\':" << endl;
        login = getch();
        login = tolower(login);
    }
}

// Login
void Login(string &username, int &pin)
{
    cout << endl;
    cout << "\t\t ----------------------------" << endl;
    cout << "\t\t Enter username:";
    getline(cin, username);
    cout << "\t\t Enter pin :";
    cin >> pin;
    cout << "\t\t ----------------------------" << endl;
}

// AFTER-SUCCESFFULY-CREATED-ACCOUNT
void successfullyCreatedAccount(account &newAccount)
{
    spaces2();
    cout << "\t\tCongratulations ! You have successfully created your first Account :" << endl;
    newAccount.calculateUserName();
    newAccount.calculateTotalBalance();
    newAccount.calculateTotalIncome();
    newAccount.calculateTotalOutcome();
    newAccount.calculateTotalInterest();
    spaces2();
    cout << "\t\t\t *YOUR ACCOUNT DETAILS* " << endl;
    newAccount.getData();
}

// CREATE-NEW-ACCOUNT
void createNewAccount(account *&accs,int &noOfAccounts)
{
    system("cls");
    spaces1();
    spaces2();
    cout << "\t\t Create an account : " << endl;
    spaces2();
    account newAccount;
    char boolDeposit;
    newAccount.createAccount();
    boolDeposit = getch();
    boolDeposit = tolower(boolDeposit);
    switch (boolDeposit)
    {
    case 'y':
    {
        spaces2();
        cout << "\t\t Do your first movement by depositing at least $200:";
        newAccount.setSize(1);
        newAccount.setMovementsValue();
        while (*(newAccount.getMovementsAddress() + 0) < 200)
        {
            cout << "\t\t Error : Low balance you must have deposit at leat $200 :";
            newAccount.setMovementsValue();
        }
        successfullyCreatedAccount(newAccount);
        break;
    }
    case 'n':
    {
        successfullyCreatedAccount(newAccount);
        break;
    }
    }
        //Adding to accounts array
    account *tempAccounts = new account[noOfAccounts+1];
    for(int i=0;i<noOfAccounts;i++)
    {
        *(tempAccounts+i)=*(accs+i);
    }
    delete[] accs;
    accs=tempAccounts;
    accs[noOfAccounts]=newAccount;
    noOfAccounts++;
}
int main()
{

    /*=============================Already DEFAULT ACCOUNTS IN BANKIST=========================*/

    /*------------Deafult Data------------------*/
    int noOfAccounts = 3;
    int *defaultPins = new int[noOfAccounts]{111, 222, 333};
    double *movementsAcc0 = new double[5]{2000, 1000, -500, 20000, -6000};
    double *movementsAcc1 = new double[5]{5000, -2000, 10000, 5000, -8000};
    double *movementsAcc2 = new double[5]{8000, 10000, 4000, -12000, -1000};
    /*------------RunTime Information------------------*/
    account *accounts = new account[noOfAccounts];
    account currentUser;

    /*------------ Deafult Accounts------------------*/
    // account-1
    accounts[0].setName("Muhib Arshad");
    accounts[0].calculateUserName();
    accounts[0].setPin(defaultPins[0]);
    accounts[0].setSize(5);
    accounts[0].setMovementsAddress(movementsAcc0);
    accounts[0].calculateTotalBalance();
    accounts[0].calculateTotalIncome();
    accounts[0].calculateTotalOutcome();
    accounts[0].calculateTotalInterest();
    // accounts[0].getData();

    // account-2
    accounts[1].setName("Ali Abdullah");
    accounts[1].calculateUserName();
    accounts[1].setPin(defaultPins[1]);
    accounts[1].setSize(5);
    accounts[1].setMovementsAddress(movementsAcc1);
    accounts[1].calculateTotalBalance();
    accounts[1].calculateTotalIncome();
    accounts[1].calculateTotalOutcome();
    accounts[1].calculateTotalInterest();
    // accounts[1].getData();

    // account-3
    accounts[2].setName("Bilal Sharafat");
    accounts[2].calculateUserName();
    accounts[2].setPin(defaultPins[2]);
    accounts[2].setSize(5);
    accounts[2].setMovementsAddress(movementsAcc2);
    accounts[2].calculateTotalBalance();
    accounts[2].calculateTotalIncome();
    accounts[2].calculateTotalOutcome();
    accounts[2].calculateTotalInterest();
    // accounts[2].getData();

    /*=============================LOGICAL PORTION STARTS HERE=========================*/

    // SIGN-IN OR SIGN-UP
    string username;
    int pin;
    char login;
    loginPage(login);
    switch (login)
    {
    case 'l':
    {
        Login(username, pin);
        break;
    }
    case 'c':
    {
        createNewAccount(accounts,noOfAccounts);
        break;
    }
    }

    //Testing ;
    for(int i=0;i<noOfAccounts;i++)
    {
    accounts[i].getData();
    }
    

    // Deallocating memeory-To avoid memeory leakages
    delete[] movementsAcc0;
    movementsAcc0 = nullptr;
    delete[] movementsAcc1;
    movementsAcc0 = nullptr;
    delete[] movementsAcc2;
    movementsAcc0 = nullptr;
    delete[] accounts;
    accounts = nullptr;

    return 0;
}