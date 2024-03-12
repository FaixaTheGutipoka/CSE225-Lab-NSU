#include <iostream>
#include "sortedtype.cpp"

using namespace std;

class timeStamp{
public:
    int hours, minutes, seconds;
    timeStamp(){

    }
    timeStamp(int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
    }
    bool operator == (const timeStamp &t){
        return (hours==t.hours&&minutes==t.minutes&&seconds==t.seconds);
    }
    bool operator != (const timeStamp &t){
        return (hours!=t.hours||minutes!=t.minutes||seconds!=t.seconds);
    }
    bool operator > (const timeStamp &t){
        int a = t.hours*3600+t.minutes*60+t.seconds;
        int b = hours*3600+minutes*60+seconds;
        return b>a;
    }
    bool operator < (const timeStamp &t){
        int a = t.hours*3600+t.minutes*60+t.seconds;
        int b = hours*3600+minutes*60+seconds;
        return b<a;
    }
    ostream& operator<< (ostream& os, const timeStamp& t1){
        os<<t1.hours<<":"<<t1.minutes<<":"<<t1.seconds;
    }
};

template <class T> void Print(SortedType<T> u){
    int len = u.LengthIs();
    T v;
    for(int i=0; i<len; i++){
        u.GetNextItem(v);
        cout<<v<<" ";
    }
}
template <class T> void Retrive(SortedType<T> u, T v){
    bool a;
    u.RetrieveItem(v, a);
    if (a)
        cout<<"Item is found";
    else
        cout<<"Item is not found";
}

template <class T> void Full(SortedType<T> u){
    bool a = u.IsFull();
    if (a)
        cout<<"List is Full";
    else
        cout<<"List is not Full";
}

int main()
{
    SortedType<int> obj1;
    obj1.MakeEmpty();

    cout<<obj1.LengthIs()<<'\n';

    obj1.InsertItem(5);
    obj1.InsertItem(7);
    obj1.InsertItem(4);
    obj1.InsertItem(2);
    obj1.InsertItem(1);

    Print(obj1);
    cout<<'\n';

    Retrive(obj1, 6);
    cout<<'\n';

    Retrive(obj1, 5);
    cout<<'\n';

    Full(obj1);
    cout<<'\n';

    obj1.DeleteItem(1);

    Print(obj1);
    cout<<'\n';

    Full(obj1);
    cout<<'\n';





    SortedType<timeStamp> t;
    timeStamp t1(15, 34, 23);
    timeStamp t2(13, 13, 02);
    timeStamp t3(43, 45, 12);
    timeStamp t4(25, 36, 17);
    timeStamp t5(52, 02, 20);

    t.InsertItem(t1);
    t.InsertItem(t2);
    t.InsertItem(t3);
    t.InsertItem(t4);
    t.InsertItem(t5);

    t.DeleteItem(t4);

    /*
    for(int i=0; i<4; i++){
        timeStamp t23;
        t[i].GetNextItem(t23);
        cout<<t23;
    }
    */

    cout<<t3;
}
