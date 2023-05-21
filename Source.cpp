#include <iostream>

using namespace std;

class PaymentType
{
public:
    virtual void type() = 0;
    virtual double sum() = 0;
    virtual double Balance() = 0;

};
class Cash :public PaymentType
{
public:
    double amount;
    double balance = 10000;
    void type()
    {
        cout << "Paying with cash ! " << endl;
    }
    double sum()
    {
        cout << "Enter the amount you would like to pay :";
        cin >> amount;
        balance = balance - amount;
        cout << "Payment has been finished succesfully ! " << endl;
        return amount, balance;
    }
    double Balance()
    {
        cout << "Your balance is : " << balance << endl;
        return balance;
    }

};
class CreditCard :public PaymentType
{
public:
    double balance = 10000;
    double amount;
    int pin;
    void type()
    {
        cout << "Paying with credit card ! " << endl;
    }
    double sum()
    {
        cout << "Enter the amount you would like to pay :";
        cin >> amount;
        balance = balance - amount;
        cout << "Enter your PIN :";
        cin >> pin;
        cout << "Payment has been finished succesfully ! " << endl;
        return amount, pin, balance;
    }
    double Balance()
    {
        cout << "Your balance is : " << balance << endl;
        return balance;
    }

};
int main()
{
    Cash csh;

    CreditCard cc;
    int tip, pay, w = 1, nextMove;
    double amount;
    int pin;
    while (w = 1)
    {
        system("CLS");
        cout << "If you would like to pay , press <1> . If you would like to see the balance , press <2> " << endl;
        cin >> pay;
        if (pay == 1)
        {
            cout << "Choose the type of payment : \n   1~cash \n   2~credit card" << endl;
            cin >> tip;
            if (tip == 1)
            {
                csh.type();
                csh.sum();

            }
            else if (tip == 2)
            {
                cc.type();
                cc.sum();
            }

        }
        else if (pay == 2)
        {
            cout << "Would you like to see the balance of cash or credit card ?\n Press \n   1~cash \n   2~credit card " << endl;
            cin >> nextMove;
            if (nextMove == 1)
                csh.Balance();
            if (nextMove == 2)
                cc.Balance();
        }
        cout << "You may press <1> to do another operations or <2> to finish ." << endl;
        cin >> nextMove;
        if (nextMove == 1)
            continue;
        if (nextMove == 2)
            break;
    }
    return 0;
}