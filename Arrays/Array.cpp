#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i];
    }

    cout << endl;
    cout << arr;
    // 0x61ff00
    cout << endl;
    cout << &arr;
    // 0x61ff00
    cout << endl;
    cout << arr[0];
    // 1
    cout << endl;
    cout << &arr[0];
    // 0x61ff00
    cout << endl;
    cout << &arr[1];
    // 0x61ff04
    cout << endl;

    return 0;
}