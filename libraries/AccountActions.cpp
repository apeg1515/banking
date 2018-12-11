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
    cout << "File could not be open !! Press any Key...";
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
    cout << "\n\nAccount number doesn't exist";
  }
}

void AccountActions::ModifyAccount(int n)
{
  bool found = false;
  fstream File;
  File.open("account.dat", ios::binary|ios::in|ios::out);
  if(!File)
  {
    cout << "File could not be open !! Press any Key ...";
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
      cout << "\n\n\t Record Updated";
      found=true;
    }
  }
}

void AccountActions::DeleteAccount(int n)
{
  ifstream inFile;
  ofstream outFile;
  inFile.open("account.dat", ios::binary);
  if(!inFile)
  {
    cout << "File could not be open !! Press and Key...";
    return;
  }
  outFile.open("Temp.dat", ios::binary);
  inFile.seekg(0, ios::beg);
  while(inFile.read(reinterpret_cast<char *> (&account), sizeof(Account)))
  {
    if(account->Retacno() != n)
    {
      outFile.write(reinterpret_cast<char *> (&account), sizeof(Account));
    }
  }
  inFile.close();
  outFile.close();
  remove("account.dat");
  rename("Temp.dat","account.dat");
  cout << "\n\n\tRecord Deleted..";
}

void AccountActions::DisplayAll()
{
  ifstream inFile;
  inFile.open("account.dat", ios::binary);
  if(!inFile)
  {
    cout << "File could not be open !! Press and Key...";
    return;
  }
  cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
  while(inFile.read(reinterpret_cast<char *> (&account), sizeof(Account)))
  {
    account->Report();
  }
  inFile.close();
}

void AccountActions::DepositWithdraw(int n, int option)
{
  int amt;
  bool found = false;
  fstream File;
  File.open("account.dat", ios::binary|ios::in|ios::out);
  if(!File)
  {
    cout << "File could not be open !! Press and Key...";
    return;
  }
  while(!File.eof() && found == false)
  {
    File.read(reinterpret_cast<char *> (&account), sizeof(Account));
    if(account->Retacno() == n)
    {
      account->ShowAccount();
      if(option == 1)
      {
        cout << "\n\n\tTO DEPOSITE AMOUNT";
        cout << "\n\nEnter The amount to be deposited";
        cin >> amt;
        account->Dep(amt);
      }

      if(option == 2)
      {
        cout << "\n\n\tTO WITHDRAW AMOUNT";
        cout << "\n\nEnter The amount to be withdraw";
        cin >> amt;
        int bal = account->RetDeposit() - amt;

        if((bal < 500  && account->RetType() == 'S') || (bal < 100 && account->RetType() == 'C'))
        {
          cout << "Insufficience balance";
        } else {
          account->Draw(amt);
        }
      }

      int pos =(-1)*static_cast<int>(sizeof(account));
      File.seekp(pos, ios::cur);
      File.write(reinterpret_cast<char *> (&account), sizeof(Account));
      cout << "\n\nRecord Updated";
      found=true;
    }
  }
  File.close();
  if(found == false)
  {
    cout << "\n\n Record Not Found";
  }
}

void AccountActions::Intro()
{
  cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : your name";
	cout<<"\n\nSCHOOL : your school name";
  cin.get();
}
