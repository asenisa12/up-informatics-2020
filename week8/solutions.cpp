#include <iostream>
using namespace std;

//zad0
void input_2d_array(int arr[5][5])
{

    for(int y=0; y<5; y++)
    {
        for(int x = 0; x<5; x++)
        {
            cout<< "insert elem at x:" << x << " y:" << y<< " - ";
            cin>>arr[y][x];
        }
    }
}
//zad1
void print_2d_array(int arr[5][5])
{
    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            cout<<"[" << x << "]["<<y<<"]=" << arr[y][x] <<" ";
        }
        cout<<endl;
    }
}

//zad2
/*x+=1 y+=1

x=2,y=0
x-=1 y+=1*/

void print_daig_helper(int arr[5][5], int x_start, int x_incr)
{
    for(int x=x_start,y=0; x>=0 && x<5&&y<5; x+=x_incr,y++)
    {
        for(int i=0; i<x;i++)
        {
            cout<<"   ";
        }
        cout<< arr[y][x]<<endl;
    }
}

void print_diags(int arr[5][5])
{
    cout<<"first diagonal: "<<endl;
    print_daig_helper(arr,0,1);


    cout<<endl<<"second diagonal: "<<endl;
    print_daig_helper(arr,4,-1);

}



//zad3
void print_on_top_of_first_diag(int arr[5][5])
{
    for(int y=0; y<5;y++)
    {
        for (int x = 0; x<y+1; x++)
        {
            cout <<"   ";
        }
        for (int x = y+1; x<5; x++)
        {
            cout << arr[y][x] <<" ";
        }
        cout<<endl;
    }
}

void print_under_the_first_diag(int arr[5][5])
{
    for(int y=0; y<5;y++)
    {

        for (int x = 0; x<y; x++)
        {
            cout << arr[y][x] <<" ";
        }
        cout<<endl;
    }
}

//x0y0 x4y0 size=5-1-index_row

void print_on_top_of_the_second_diag(int arr[5][5])
{
    for(int y = 0; y<5; y++)
    {
        for(int x=0; x<5-1-y; x++)
        {
            cout<< arr[y][x] << " ";
        }
        cout<<endl;
    }
}

void print_under_the_second_diag(int arr[5][5])
{
    for(int y = 0; y<5; y++)
    {
        for (int x = 0; x<5-y; x++)
        {
            cout <<"   ";
        }
        for(int x=5-y; x<5; x++)
        {
            cout<< arr[y][x] << " ";
        }
        cout<<endl;
    }
}

//zad4
void print_sum_even(int arr[5][5], bool under)
{
    int sum = 0;
    for(int y = 0; y<5; y++)
    {
        int x_start = (under)?0:y+1, x_end = (under)?y:5;
        for(int x=x_start; x<x_end; x++)
        {
            if(arr[y][x] % 2 == 0)
            {
                sum += arr[y][x];
            }
        }
    }
    cout << "sum is " << sum<< endl;
}


//zad 5
int calc_sum_row(int arr[5][5], int row)
{
    int sum = 0;
    for(int x = 0; x < 5; x++)
    {
        sum += arr[row][x];
    }
    return sum;

}

void print_max_row_sum(int arr[5][5])
{
    int max_sum = 0;
    int row_index;
    for(int y = 0; y < 5; y++)
    {
        int sum = calc_sum_row(arr, y);
        if(max_sum < sum)
        {
            max_sum = sum;
            row_index = y;
        }
    }
    cout<< row_index <<" sum is " <<max_sum <<endl;
}


int calc_sum_col(int arr[5][5], int col)
{
    int sum = 0;
    for (int y = 0; y < 5; y++)
    {
        sum += arr[y][col];
    }
    return sum;
}

void print_max_col_sum(int arr[5][5])
{
    int max_sum = 0;
    int col_index;
    for(int x = 0; x<5;x++)
    {
        int sum = calc_sum_col(arr, x);
        if(sum>max_sum)
        {
            max_sum = sum;
            col_index = x;
        }
    }
    cout<< col_index <<" sum is " <<max_sum <<endl;
}

//zad6
void remove_col(int arr[5][5], int k)
{

    for(int x = k; x < 4; x++)
    {
        for(int y = 0; y < 5; y++)
        {
            arr[y][x] = arr[y][x + 1];
        }
    }

    for(int y = 0; y < 5; y++)
    {
        arr[y][4] = 0;
    }
}


int main()
{
    int arr1[3][3];
    //input_2d_array(arr1);
    //print_2d_array(arr1);

    int arr2[5][5]={
        {11,12,13,14,15},
        {21,22,23,24,25},
        {31,32,33,34,35},
        {41,42,43,44,45},
        {51,52,53,54,55},
    };

    print_diags(arr2);

    print_on_top_of_first_diag(arr2);
    cout<<endl;
    print_under_the_first_diag(arr2);
    //cout<<endl;
    //print_on_top_of_the_second_diag(arr2);
    //cout<<endl;
    //print_under_the_second_diag(arr2);

    print_sum_even(arr2, false);

    print_max_row_sum(arr2);
    print_max_col_sum(arr2);


    remove_col(arr2, 2);
    print_2d_array(arr2);

    return 0;
}
