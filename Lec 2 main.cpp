#include <iostream>
#include "box.h"


using namespace std;

int main()
{
    int a,b;
    cin >> a;
    int *arr = new int[a];
    for(int i=0; i<=a; i++){
        cin >> b;
        arr[i]=b;
    }
    for(int i=0; i<=a; i++){
        cout << arr[i];
        cout << '\n';
    }
    delete []arr;

    cout << '\n';
    for(int i=0; i<=a; i++){
        cout << arr[i];
        cout << '\n';
    }
    return 0;
}
