#include <fstream>
#include "Account.cpp"
#include "AccountActions.h"

Account* account = Account::Instance();

void AccountActions::WriteAccount()
{
  ofstream outFile;
  outFile.open("account.dat", ios::binary|ios::app);
  account->CreateAccount();
  outFile.write(reinterpret_cast<char *> (&account), sizeof(Account));
  outFile.close();
}

void AccountActions::DisplaySP(int n){
  bool flag = false;
  ifstream inFile;
  inFile.open("account.dat",ios::binary);

  if (!inFile)
  {
    cout << "File could not be open !! Press any Key..." << endl;
    return;
  }
  while(inFile.read(reinterpret_cast<char *> (&account), sizeof(Account)))
  {
    if(account->Retacno() == n)
    {
      account->ShowAccount();
      flag = true;
    }
  }
  inFile.close();
  if(flag == false)
  {
    cout << "\n\nAccount number doesn't exist" << endl;
  }
}

void AccountActions::ModifyAccount(int n)
{
  bool found = false;
  fstream File;
  File.open("account.dat", ios::binary|ios::in|ios::out);
  if(!File)
  {
    cout << "File could not be open !! Press any Key ..." << endl;
    return;
  }
  while(!File.eof()  && found == false)
  {
    File.read(reinterpret_cast<char *> (&account), sizeof(Account));
    if(account->Retacno() == n)
    {
      account->ShowAccount();
      cout<<"\n\nEnter The New Details of account"<<endl;
      account->Modify();
      int pos = (-1)*static_cast<int>(sizeof(Account));
      File.seekp(pos, ios::cur);
      File.write(reinterpret_cast<char *> (&account), sizeof(Account));
      cout << "";
    }
  }
}
