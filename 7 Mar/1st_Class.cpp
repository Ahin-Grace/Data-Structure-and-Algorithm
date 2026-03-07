#include<bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int age;

    Student(string _name, int _age){
        name=_name;
        age=_age;
    }


    void display(){
        cout<<"Name: "<<name<<",  Age: "<<age<<endl;
    }

    ~Student(){
        cout<<name<<" destroyed"<<endl;
    }
};

int main()
{
    Student s1("Ahin",20);
    s1.display();


    Student* s2=new Student("Rizoan",50);
    //s2->display();
    (*s2).display();
    delete s2;
}


