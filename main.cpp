#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

//NoLevel: no rooms
//GreenLevel : Class Room, Lecture Room
//YellowLevel : GreenLevel + Cabinet
//RedLevel : YellowLevel + Conference Room + Director Cabinet

//Student : GreenLevel
//Professor : YellowLevel
//LabEmployee : YellowLevel
//Director : RedLevel
//Admin: RedLevel


using namespace std;

class UniversityAccessSystem{
public:

    virtual void OpenClassRoom(string name, int number)=0;
    virtual void OpenLectureRoom(string name, int number)=0;
    virtual void OpenCabinet(string name, int number)=0;
    virtual void OpenConferenceRoom(string name, int number)=0;
    virtual void OpenDirectorCabinet(string name)=0;

};

class NoLevel : public UniversityAccessSystem{
public:
    void OpenClassRoom(string name, int number) override {
        cout<<name<<", You don't have access for any room ";
    }
    void OpenLectureRoom(string name, int number) override {
        cout<<name<<", You don't have access for any room ";
    }
    void OpenCabinet(string name, int number) override {
        cout<<name<<", You don't have access for any room ";
    }
    void OpenConferenceRoom(string name, int number) override {
        cout<<name<<", You don't have access for any room ";
    }
    void OpenDirectorCabinet(string name) override {
        cout<<name<<", You don't have access for any room ";
    }
};

class GreenLevel : public UniversityAccessSystem{
public:
    void OpenClassRoom(string name, int number) {
        if(number>200 && number<400)
            cout<<name<<" opened a "<<number<<" Class Room ";
        else cout<<name<<" try to open "<<number<<" Class Room, but we have only Class Room numbers from 200 to 300. You can! However, you try to open not a Class Room ";
    }
    void OpenLectureRoom(string name, int number) {
        if(number==105 || number==106 || number==107 || number==108)
            cout<<name<<" opened a "<<number<<" Lecture Room ";
        else cout<<name<<" try to open "<<number<<" Lecture Room, but we have only 105, 106, 107 or 108 Lecture Room. You can! However, you try to open not a Lecture Room ";
    }
    void OpenCabinet(string name, int number) override {
        cout<<name<<", You don't have access for Cabinet ";
    }
    void OpenConferenceRoom(string name, int number) override {
        cout<<name<<", You don't have access for Conference Room ";
    }
    void OpenDirectorCabinet(string name) override {
        cout<<name<<", You don't have access for Director Cabinet ";
    }

};

class YellowLevel : public UniversityAccessSystem{

public:

    void OpenClassRoom(string name, int number)override {
        if(number>200 && number<400)
            cout<<name<<" opened a "<<number<<" Class Room ";
        else cout<<name<<" try to open "<<number<<" Class Room, but we have only Class Room numbers from 200 to 300. You can! However, you try to open not a Class Room ";
    }
    void OpenLectureRoom(string name, int number) override{
        if(number==105 || number==106 || number==107 || number==108)
            cout<<name<<" opened a "<<number<<" Lecture Room";
        else cout<<name<<" try to open "<<number<<" Lecture Room, but we have only 105, 106, 107 or 108 Lecture Room. You can! However, you try to open not a Lecture Room ";
    }
    void OpenCabinet(string name, int number) override{
        if(number>400 && number<500)
            cout<<name<<" opened a "<<number<<" Cabinet ";
        else cout<<name<<" try to open "<<number<<" Cabinet, but we have only Cabinet numbers from 400 to 500. You can! However, you try to open not a Cabinet ";
    }
    void OpenConferenceRoom(string name, int number) override {
        cout<<name<<", You don't have access for Conference Room ";
    }
    void OpenDirectorCabinet(string name) override {
        cout<<name<<", You don't have access for Director Cabinet ";
    }
};

class RedLevel : public UniversityAccessSystem{
public:
    void OpenClassRoom(string name, int number) override{
        if(number>200 && number<400)
            cout<<name<<" opened a "<<number<<" Class Room ";
        else cout<<name<<" try to open "<<number<<" Class Room, but we have only Class Room numbers from 200 to 300. You can! However, you try to open not a Class Room ";
    }
    void OpenLectureRoom(string name, int number) override{
        if(number==105 || number==106 || number==107 || number==108)
            cout<<name<<" opened a "<<number<<" Lecture Room ";
        else cout<<name<<" try to open "<<number<<" Lecture Room, but we have only 105, 106, 107 or 108 Lecture Room. You can! However, you try to open not a Lecture Room ";
    }
    void OpenCabinet(string name, int number) override{
        if(number>400 && number<500)
            cout<<name<<" opened a "<<number<<" Cabinet ";
        else cout<<name<<" try to open "<<number<<" Cabinet, but we have only Cabinet numbers from 400 to 500. You can! However, you try to open not a Cabinet ";
    }
    void OpenConferenceRoom(string name, int number) override{
        if(number==1 ||  number ==2 || number==3)
            cout<<name<<" opened a "<<number<<" Conference Room ";
        else cout<<name<<" try to open "<<number<<" Conferene Room, but we have only 1st, 2nd and 3rd Conference Room. You can! However, you try to open not a Conference Room ";
    }
    void OpenDirectorCabinet(string name) override{
        cout<<name<<" opened a Director Cabinet ";
    }

};

class Human {
public:
    string name;
    Human(string Name){
        this->name=Name;
    }
};

class Student : public Human, public GreenLevel{
public:
    Student(string Name) :  Human(Name){
        this->name=Name;
    }
};

class Professor : public Human,public YellowLevel{
public:
    Professor(string Name) :  Human(Name){
        this->name=Name;
    }
};

class LabEmployee : public Human,public YellowLevel{
public:
    LabEmployee(string Name) :  Human(Name){
        this->name=Name;
    }
};

class Director : public Human,public RedLevel{
public:
    Director(string Name) :  Human(Name){
        this->name=Name;
    }
};

class Admin : public Human,public RedLevel{
public:
    Admin(string Name) :  Human(Name){
        this->name=Name;
    }
    //additional function for Admins which can give someone temprorary access for any room except Director Cabinet
    void GetAdditionalAccess(Human human, int number, string AdminName){
        string Name=human.name;
        Admin *TempAdminForOneSession= new Admin(AdminName);
        if(number>=1 && number<=3) {
            TempAdminForOneSession->OpenConferenceRoom(Name, number);
            cout<<"due to the Admin "<<TempAdminForOneSession->name;
        }
        else if(number==105 || number==106 || number==107 || number==108){
            TempAdminForOneSession->OpenLectureRoom(Name, number);
            cout<<"due to the admin "<<TempAdminForOneSession->name;
        }
        else if(number>200 && number<400){
            TempAdminForOneSession->OpenClassRoom(Name, number);
            cout<<"due to the admin "<<TempAdminForOneSession->name;
        }
        else if(number>400 && number<500){
            TempAdminForOneSession->OpenCabinet(Name, number);
            cout<<"due to the admin "<<TempAdminForOneSession->name;
        }
        else {
            cout<<human.name<<", there is no Rooms with such number : "<<number<<". Probably, you want to get acces to Director Cabinet, but there are a lot of secret information, admin can not give you acces";
        }
        delete TempAdminForOneSession ;
    }
};

class Guest : public Human, public NoLevel{
public:
    Guest(string Name) : Human(Name){
        this->name=Name;
    }
};

vector<Student> students;
vector<Professor> professors;
vector<LabEmployee> employees;
vector<Director> directors;
vector<Admin> admins;
vector<Guest> guests;

int main() {
    void Random();

    int decision;
    string name;
    cout <<"Hello! Welcome to our University. Do you want to create our people by yourself ? Or let the program generate it itself \n";
    cout<<  "1) I would like to it myself \n2) Let create it by program"<<endl;
    cin>>decision;

    if(decision==1){
        cout<<"OK! Please, create 1 director: \n Director name : "<<endl;
        cin>>name;
        Director director(name);
        directors.push_back(director);
        cout<<"OK! Please, create 2 admins: Admins names :"<<endl;
        for(int i=0; i< 2; i++){
            cin>>name;
            admins.emplace_back(name);
        }
        cout<<"OK! Please, create 4 professors \n Professors names :"<<endl;
        for(int i=0; i<4; i++){
            cin>>name;
            directors.emplace_back(name);
        }
        cout<<"OK! Please, create 8 employees \n Employees names :"<<endl;
        for(int i=0; i<8; i++){
            cin>>name;
            employees.emplace_back(name);
        }
        cout<<"OK! Please, create 16 students \n Students names :"<<endl;
        for(int i=0; i<16; i++){
            cin>> name;
            students.emplace_back(name);
        }
        cout<<"OK! And finally add 3 guests who can just visit our University \n Guests names :";
        for(int i=0; i<3; i++){
            cin>>name;
            guests.emplace_back(name);
        }
    }
    else {
        directors.emplace_back("Max");
        admins.emplace_back("Vlad");
        admins.emplace_back("Alexander");
        professors.emplace_back("Mansur");
        professors.emplace_back("Eugene");
        professors.emplace_back("Nikolay");
        professors.emplace_back("Joseph");
        employees.emplace_back("LabEmployer1");
        employees.emplace_back("LabEmployer2");
        employees.emplace_back("LabEmployer3");
        employees.emplace_back("LabEmployer4");
        employees.emplace_back("LabEmployer5");
        employees.emplace_back("LabEmployer6");
        employees.emplace_back("LabEmployer7");
        employees.emplace_back("LabEmployer8");
        students.emplace_back("Sasha");
        students.emplace_back("Masha");
        students.emplace_back("Tasha");
        students.emplace_back("Ivan");
        students.emplace_back("Anya");
        students.emplace_back("Gleb");
        students.emplace_back("Karina");
        students.emplace_back("Misha");
        students.emplace_back("Artem");
        students.emplace_back("Egor");
        students.emplace_back("Vladimir");
        students.emplace_back("Damir");
        students.emplace_back("Lev");
        students.emplace_back("Tanya");
        students.emplace_back("Katya");
        students.emplace_back("Sergey");
        guests.emplace_back("Guest Sasha");
        guests.emplace_back("Guest Anatoliy");
        guests.emplace_back("Guest Mark");

    }
    cout<<"Let's look how people within the University can do different actions: \n\n";
    admins[0].GetAdditionalAccess(students[2], 10, admins[0].name); cout<<endl<<endl;
    admins[1].GetAdditionalAccess(employees[2].name, 1, admins[1].name); cout<<endl<<endl;
    cout<<"Now lets generate random actions \n Enter the number of actions : \n";
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        Random();
        cout<<endl<<endl;
    }


    return 0;
}

//Just a random function to create different actions for users randomly
//In this function we suppose that :
//RandomHuman= random type of human ( from 1 to 6, where 1-student, 6-guest)
//RandomFunction= random type of function
//RandomNumberOfHuman= random number of explicit human
void Random() {

    int RandomHuman = (rand() % 6) + 1;
    int RandomFunction = (rand() % 5) + 1;
    int RandomNumberOfHuman;
    switch (RandomHuman) {
        case 1:
            RandomNumberOfHuman = rand() % students.size();
            if (RandomFunction == 1) {
                students[RandomNumberOfHuman].OpenClassRoom(students[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 2) {
                students[RandomNumberOfHuman].OpenLectureRoom(students[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 3) {
                students[RandomNumberOfHuman].OpenCabinet(students[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 4) {
                students[RandomNumberOfHuman].OpenConferenceRoom(students[RandomNumberOfHuman].name,
                                                                 (rand() % 499) + 1);
            } else {
                students[RandomNumberOfHuman].OpenDirectorCabinet(students[RandomNumberOfHuman].name);
            }
            break;
        case 2:
            RandomNumberOfHuman = rand() % employees.size();
            if (RandomFunction == 1) {
                employees[RandomNumberOfHuman].OpenClassRoom(employees[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 2) {
                employees[RandomNumberOfHuman].OpenLectureRoom(employees[RandomNumberOfHuman].name,(rand() % 499) + 1);
            } else if (RandomFunction == 3) {
                employees[RandomNumberOfHuman].OpenCabinet(employees[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 4) {
                employees[RandomNumberOfHuman].OpenConferenceRoom(employees[RandomNumberOfHuman].name,(rand() % 499) + 1);
            } else {
                employees[RandomNumberOfHuman].OpenDirectorCabinet(employees[RandomNumberOfHuman].name);
            }
            break;
        case 3:
            RandomNumberOfHuman = rand() % admins.size();
            if (RandomFunction == 1) {
                admins[RandomNumberOfHuman].OpenClassRoom(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 2) {
                admins[RandomNumberOfHuman].OpenLectureRoom(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 3) {
                admins[RandomNumberOfHuman].OpenCabinet(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 4) {
                admins[RandomNumberOfHuman].OpenConferenceRoom(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else {
                admins[RandomNumberOfHuman].OpenDirectorCabinet(admins[RandomNumberOfHuman].name);
            }
            break;
        case 4:
            RandomNumberOfHuman = rand() % directors.size();
            if (RandomFunction == 1) {
                directors[RandomNumberOfHuman].OpenClassRoom(directors[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 2) {
                directors[RandomNumberOfHuman].OpenLectureRoom(directors[RandomNumberOfHuman].name,
                                                               (rand() % 499) + 1);
            } else if (RandomFunction == 3) {
                directors[RandomNumberOfHuman].OpenCabinet(directors[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 4) {
                directors[RandomNumberOfHuman].OpenConferenceRoom(directors[RandomNumberOfHuman].name,
                                                                  (rand() % 499) + 1);
            } else {
                directors[RandomNumberOfHuman].OpenDirectorCabinet(directors[RandomNumberOfHuman].name);
            }
            break;
        case 5:
            RandomNumberOfHuman = rand() % admins.size();
            if (RandomFunction == 1) {
                admins[RandomNumberOfHuman].OpenClassRoom(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 2) {
                admins[RandomNumberOfHuman].OpenLectureRoom(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 3) {
                admins[RandomNumberOfHuman].OpenCabinet(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 4) {
                admins[RandomNumberOfHuman].OpenConferenceRoom(admins[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else {
                admins[RandomNumberOfHuman].OpenDirectorCabinet(admins[RandomNumberOfHuman].name);
            }
            break;
        case 6:

            RandomNumberOfHuman = rand() % guests.size();
            if (RandomFunction == 1) {
                guests[RandomNumberOfHuman].OpenClassRoom(guests[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 2) {
                guests[RandomNumberOfHuman].OpenLectureRoom(guests[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 3) {
                guests[RandomNumberOfHuman].OpenCabinet(guests[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else if (RandomFunction == 4) {
                guests[RandomNumberOfHuman].OpenConferenceRoom(guests[RandomNumberOfHuman].name, (rand() % 499) + 1);
            } else {
                guests[RandomNumberOfHuman].OpenDirectorCabinet(guests[RandomNumberOfHuman].name);
            }
            break;

    }
}
