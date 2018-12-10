#include "Account.h"

class AccountActions
{
  public:
    Account account;
    void WriteAccount();
    void DisplaySP(int);
    void ModifyAccount(int);
    void DeleteAccount(int);
    void DepositWithdraw(int, int);
    void Intro();
};
