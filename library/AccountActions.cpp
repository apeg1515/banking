#include <fstream>
#include "Account.cpp"
#include "AccountActions.h"

void AccountActions::WriteAccount()
{
  account* acc = account::getInstance();
  ofstream outFile;
  outFile.open("account.dat", ios::binary|ios::app);
  acc.CreateAccount();
  outFile.write(reinterpret_cast<char *> (&acc), sizeof(account));
  outFile.close();
}
