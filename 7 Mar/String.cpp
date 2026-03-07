#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Data Structure";
    string str1 = "Algorithm";

    int l=str.length();

    char c= str.at(5);

    cout<<"Length :"<<l<<endl;
    cout<<"Character at index: "<<c<<endl;

    string full= str+  " and "+str1+" with Nusaiba Ma'am.";

    int f = full.find("Nusaiba");
    string sub =full.substr(34,13);

    cout<<"Full String before insert: "<<full<<endl;
    full.insert(28," II");

    cout<<"Full String before replace: "<<full<<endl;
    full.replace(29,2,"2");

    cout<<"Full String After: "<<full<<endl;
    cout<<"Word index at : "<<f<<endl;
    cout<<"SubString: "<<sub<<endl;

}



