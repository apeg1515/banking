
// header file

class Account
{
  int acno;
  char name[50];
  int deposit;
  char type;

  public:

    static Account* getInstance();

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
    static Account* instance;
};
