#include <iostream>
using namespace std;

void get_min_and_max(int *arr, int arr_size, int &min_elem, int *max_elem)
{
    (*max_elem) = arr[0];
    min_elem = arr[0];
    for(int i=1; i<arr_size; i++)
    {
        // C style
        if((*max_elem) < *(arr+i))
        {
            (*max_elem) = *(arr+i);
        }

        // C++ style
        if(min_elem > arr[i])
        {
            min_elem = arr[i];
        }
    }

}

const unsigned int SIZE = 5;

//zad2
void diag_to_array(int arr2D[SIZE][SIZE], int *arr1D)
{
    for(int i = 0; i < SIZE; i++)
    {
        //arr2D[i][i] == *(*(arr2D+i)+i);
        *(arr1D+i) = *(*(arr2D+i)+i);

    }

    for(int i = 0; i < SIZE; i++)
    {
        cout << arr1D[i] << endl;
    }


}

//зад3

//
void create_array1(int *&arr, int arr_size)
{
    arr = new int[arr_size];
}

int* create_array2(int arr_size)
{
    return new int[arr_size];
}


//zad4
void delete_array(int *arr)
{
    delete [] arr;
}

int main()
{
    int arr[5] = {1,2,3,4,5};

    int min_elem;
    int max_elem;
    get_min_and_max(arr, 5, min_elem, &max_elem);
    cout<<"max: "<<max_elem << ", min: "<<min_elem<<endl;


    int arr2[5][5]={
        {11,12,13,14,15},
        {21,22,23,24,25},
        {31,32,33,34,35},
        {41,42,43,44,45},
        {51,52,53,54,55},
    };
    int diag[5];
    diag_to_array(arr2,diag);

    int *dyn_arr = create_array2(25);
    delete_array(dyn_arr);
    cout<<dyn_arr[7]<<endl;


    return 0;
}
