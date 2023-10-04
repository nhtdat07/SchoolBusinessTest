#include <iostream>
#include <string>
using namespace std;

/*class BankAccount {
private:
    int number;
    string name;
    double balance;
public:
    BankAccount(int num = 0, string holdname = "", double hBalance = 0) : number(num), name(holdname), balance(hBalance) {}
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successfully!\n\n";
    }
    void withdraw(double amount) {
        if (balance < amount) cout << "Your balance is not enough!\n\n";
        else {
            balance -= amount;
            cout << "Withdraw successfully!\n\n";
        }
    }
    void check() {
        cout << "Your balance is now " << balance << " !\n\n";
    }
};

int main()
{
    int num;
    string holdname, s;
    int hBalance, amount;
    cout << "Enter your account number: ";
    cin >> num;
    cout << "Enter your name: ";
    getline(cin, holdname);
    char c = getchar();
    cout << "Enter your balance: ";
    cin >> hBalance;
    BankAccount* bankAcc = new BankAccount(num, holdname, hBalance);
    while (true) {
        cout << "\nOPTIONS\n1. Deposit\n2. Withdraw\n3. Check balance\n4. Exit\n\nYour option is: ";
        cin >> s;
        if (s.length() > 1 || s[0] < '1' || s[0] > '4') {
            cout << "Invalid input!\n\n";
            continue;
        }
        switch (s[0]) {
        case '4': goto x;
        case '3': bankAcc->check(); break;
        case '2': {
            cout << "Enter the amount you want to withdraw: ";
            cin >> amount;
            bankAcc->withdraw(amount);
            break;
        }
        case '1': {
            cout << "Enter the amount you want to deposit: ";
            cin >> amount;
            bankAcc->deposit(amount);
            break;
        }
        }
    }
x:;
    return 0;
}*/
class Person {
protected:
    string name;
    string address;
public:
    Person(string name = "", string address = ""): name(name), address(address) {}
    string getName() { return name; }
    string getAddress() { return address; }
    void setAddress(string address) { this->address = address; }
    virtual string toString() {
        return "Person[name=" + name + ",address=" + address + "]";
    }
};

class Student : public Person {
private:
    string program;
    int year;
    double fee;
public:
    Student(string name = "", string address = "", string program = "", int year = 0, double fee = 0) {
        this->name = name;
        this->address = address;
        this->program = program;
        this->year = year;
        this->fee = fee;
    }
    string getProgram() { return program; }
    void setProgram(string program) { this->program = program; }
    int getyear() { return year; }
    void setYear(int year) { this->year = year; }
    double getFee() { return fee; }
    void setFee(double fee) { this->fee = fee; }
    string toString() {
        return "Student[" + Person::toString() + ",program=" + program 
            + ",year=" + to_string(year) + ",fee=" + to_string(fee) + "]";
    }
};

class Staff : public Person {
private:
    string school;
    double pay;
public:
    Staff(string name = "", string address = "", string school = "", double pay = 0) {
        this->name = name;
        this->address = address;
        this->school = school;
        this->pay = pay;
    }
    string getSchool() { return school; }
    void setSchool(string school) { this->school = school; }
    double getPay() { return pay; }
    void setPay(double pay) { this->pay = pay; }
    string toString() {
        return "Staff[" + Person::toString() + ",school=" + school + ",pay=" + to_string(pay) + "]";
    }
};

class SchoolBusinessTest {
public:
    void work() {
        Student** list = new Student * [5];
        for (int i = 0; i < 5; i++) {
            list[i] = new Student();
            list[i]->setYear(2023);
            cout << list[i]->toString() << "\n";
        }
        Staff* staff = new Staff();
        staff->setAddress("268 Ly Thuong Kiet");
    }
};

int main() {
    SchoolBusinessTest* sbt = new SchoolBusinessTest();
    sbt->work();
    return 0;
}