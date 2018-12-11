#include <string>
// header file

class Account
{
  int acno;
  char name[50];
  int deposit;
  char type;

  public:

    static Account* Instance();

    void CreateAccount();
    void ShowAccount();
    void Modify();
    void Dep(int);
    void Draw(int);

    void Report() const;
    int Retacno() const;
    int RetDeposit() const;
    char RetType() const;

  private:
    Account(){}; // Private so that it can not be called
    Account(Account const&){}; // copy constructor is private
    void operator=(Account const&){}; // assignment operator is private
    static Account* m_Instance;
};
