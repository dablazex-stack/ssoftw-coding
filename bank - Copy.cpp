#include <iostream>
#include <string>
using namespace std;

class Person {
     string name,password;
     int id;
 public :
                                                      //Parent-getters
     string getName(){
        return this->name;
     }
     string getPassword(){
        return this->password;
     }
     int getId(){
        return this->id;
     }
     void Printinfo(){
     }
                                                     //Parent-setters
     void setName(string n){
        name = n;
     }
     void setPassword(string p){
        password = p;
     }
     void setId(int i){
        id = i;
     }
};

class Client : public Person {
     double balance = 0;
 public :
                                                                       //Structs
     Client (string n , string p , int i){
        setName(n);
        setPassword(p);
        setId(i);
     }
                                   //Methods
     double getBalance (){
        return balance;
     }
     void setBalance (double b){
        this->balance = b;
     }
     void printinfo (){ 
        cout << getName() << endl;
        cout << getId() << endl;
        cout << getPassword() << endl;
        cout << getBalance() << endl;
     }
     void deposit (double count){
        if (count < 0)
           cout << "\nyou can't enter a negative number\n";
        else{
            balance += count;
            cout << "\nyou deposited " << count << " into " <<this->getName()<< " Bank Account\n";
        }
     }
     void withdraw (double count){
        if (count > this->balance)
           cout << "\nThe amount is insufficient... \n";
        else{
            this->balance -= count;
            cout << "\nyou withdrew " << count << " from " <<this->getName()<< " Bank Account\n";
        }
     }
     void transfer (Client &c,int money){
        if (money > this->balance)
           cout << "\nThe amount is insufficient... \n";
        else {
            c.balance += money;
            this->balance -= money;
            cout << "\nyou transferred " << money << "from" << this->getName() << " to " << c.getName() << endl;
        }
     }
};

class Employee : public Person {
     double salary;
 public :
                                                                       //Structs
     Employee (){}
     Employee (double s , string n , string p , int i){
        this->salary = s;
        setName(n);
        setPassword(p);
        setId(i);
     }
                                   //Getter & Setter
     double getSalary (){
        return salary;
     }
     void setSalary (double s){
        this->salary = s;
     }
                                              //accessing information
     void printclientinfo (Client &c){ 
        cout << c.getName() << endl;
        cout << c.getId() << endl;
        cout << c.getPassword() << endl;
        cout << c.getBalance() << endl;
     }
     void printinfo (){ 
        cout << getName() << endl;
        cout << getId() << endl;
        cout << getPassword() << endl;
        cout << getSalary() << endl;
     }
                                                                     //add clients
     void addneditclient (Client &A ,string n , string p , int i){
       A.setName(n);
       A.setId(i);
       A.setPassword(p);
     }
                                                         //adding money to clients
     void addmoney (Client &C , double money){
        double amount = C.getBalance();
        amount += money;
        C.setBalance(amount);
     }
                                                           //removing money from clients
     void submoney (Client &C , double money){
        double amount = C.getBalance();
        amount -= money;
        C.setBalance(amount);
     }

    };