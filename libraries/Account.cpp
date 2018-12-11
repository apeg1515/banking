#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;
//create the methods from the header file

//create the singleton
Account* Account::m_Instance = 0;

Account* Account::Instance()
{
  if (!m_Instance)
  {
    m_Instance = new Account();
  }
  return m_Instance;
}

void Account::CreateAccount()
{
  cout << "\nEnter The Account Number :";
  cin >> acno;
  cout << "\n\nEnter the name of the account holder : ";
  cin.ignore();
  cin.getline(name, 50);
  cout << "\nEnter type of the account (C/S) : ";
  cin >> type;
  type = toupper(type);
  cout << "\nEnter the initial amount (>=500 for Saving and >=1000 for current) : ";
  cin >> deposit;
  cout << "\n\n\nAccount Created..";
}

void Account::ShowAccount()
{
  cout << "\nAccount No. : " << acno;
  cout << "\nAccount Holder Name : ";
  cout << name;
  cout << "\nType of Account : " << type;
  cout << "\nBalance account : " << deposit;
}

void Account::Modify()
{
  cout << "\nAccount No. : " << acno;
  cout << "\nModify Account Holder Name : ";
  cin.ignore();
  cin.getline(name,50);
  cout << "\nModify Type of the Account : ";
  cin >> type;
  type = toupper(type);
  cout << "\nModify Balance amount : ";
  cin >> deposit;
}

void Account::Dep(int x)
{
  deposit += x;
}

void Account::Draw(int x)
{
  deposit -= x;
}

void Account::Report() const
{
  cout << acno << setw(10) << " " << name << setw(10)  << " " << type << setw(6) << deposit << endl;
}

int Account::Retacno() const
{
  return acno;
}

int Account::RetDeposit() const
{
  return deposit;
}

char Account::RetType() const
{
  return type;
}
