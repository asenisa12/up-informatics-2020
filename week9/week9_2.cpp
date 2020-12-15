#include <iostream>
using namespace std;

//zad4
int** create2dArray(int N, int M)
{
    int **arr2d = new int*[N];
    for (int i = 0; i < N; i++)
    {
        arr2d[i] = new int[M];
    }

    return arr2d;
}

//zad5
void delete2dArray(int **arr2d, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete [] arr2d[i];
    }
    delete [] arr2d;
}

//zad6
void resize_2d_dyn_array(int **&arr2d, int N, int m, int n)
{
    int **arr2d_resized = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr2d_resized[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            arr2d_resized[i][j] = arr2d[i][j];
        }
    }
    delete2dArray(arr2d, N);
    arr2d = arr2d_resized;
}

bool **returnbin(int *arr, int size_arr)
{
    const int varSize = 32;
    bool **arrBin = new bool*[size_arr];
    for (int i = 0; i < size_arr; i++)
    {
        arrBin[i] = new bool[varSize];
        for(int j = 0; j < varSize; j++)
        {
            //10101 & 1 == 001     arr[i]>>0 == 10101
            //1010 & 1  == 000     arr[i]>>1 == 1010
            //101 & 1 == 1         arr[i]>>2 == 101
            //...
            arrBin[i][varSize-j-1] = (arr[i] >> j) & 1;
        }

        for(int j = 0; j < varSize; j++)
        {
            cout << arrBin[i][j];
        }
        cout<<endl;
    }



}

int main()
{



    int **arr2d = create2dArray(5, 6);
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            arr2d[i][j] = (i+1)*10+j+1;
            cout << arr2d[i][j]<< ", ";
        }
        cout<< endl;
    }

    resize_2d_dyn_array(arr2d, 5, 3, 2);

    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2d[i][j]<< ", ";
        }
        cout<< endl;
    }



    int arr[] = {312512255,5121254};

    returnbin(arr,2);
}