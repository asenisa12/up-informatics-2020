#include <iostream>
using namespace std;


int map(int arr[], int count, int(*func)(int))
{
    for(int i = 0; i < count; i++)
    {
        arr[i] = func(arr[i]);
    }
}

int plus1(int num)
{
    return num + 1;
}

int power(int num)
{
    return num*num;
}

int first_elem(int arr[], int count, bool(*func)(int))
{
    for(int i = 0; i < count; i++)
    {
        if(func(arr[i]))
            return arr[i];
    }

    return -1;
}

bool less_than16(int num)
{
    return num < 16;
}

bool bigger_than16(int num)
{
    return num > 16;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    map(arr,5,plus1);
    map(arr,5,power);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i]<<", ";
    }
    cout<<endl;


    cout<< first_elem(arr, 5, less_than16)<<endl;
    cout<< first_elem(arr, 5, bigger_than16)<<endl;
    return 0 ;
}
