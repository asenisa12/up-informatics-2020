#include <iostream>
using namespace std;

//zad 1
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//zad 2
//round_conunt=3
//num = 0.3314141

//num = 0.331
//331.4141
//int temp_num = 331
//331/100.0 =0.331
void round(float &num, int round_conunt)
{
    float pow = 1;
    for(int i=0;i<round_conunt;i++)
    {
        pow*=10;
    }
    int temp_num = num*pow;
    num = temp_num / pow;
}

//zad3
//(egn / 10^(7-(digit_index*2)))
//910321431
int get_digit_couple(int egn, int digit_index)
{
    int pow = 1;
    for(int i=0; i< 7-(digit_index*2);i++)
    {
        pow*=10;
    }
    cout<<(egn/pow) % 100<<endl;
    return (egn/pow) % 100;
}

//we wont check February
bool is_egn_valid(int egn)
{
    int month = get_digit_couple(egn,1);
    int day = get_digit_couple(egn,2);

    if(month>12)
    {
        return false;
    }
    else if(month%2!=0 && day <=31)
    {
        return true;
    }
    else if(month%2==0 && day <=30)
    {
        return true;
    }
    return false;

}


//zad4
int fib(int n)
{
    if(n<3){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
void print_n(int N)
{

    if(N==0) return;
    print_n(N-1);
    cout<<N<<endl;
}

//zad 5
void print_arr(int arr[], size_t arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

void print_arr_rec(int arr[], size_t arr_size)
{
    if(arr_size > 0)
    {
        print_arr_rec(arr, arr_size-1);

        cout<< arr[arr_size-1] << endl;
    }
}

//zad 6
void fill_1_N(int arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
}

//zad 7
int sum_arr(int arr[], size_t arr_size)
{
    int sum = 0;
    for(int i = 0; i < arr_size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

//zad8
void fill_div_5(int arr[], int N)
{
    int div_5 = 1;
    for(int i = 0; i < N; i++)
    {
        arr[i] = (i + 1)*5;
    }
}

int main() {

    int a = 1, b=2;
    swap(a,b);
    //cout<<"a:"<<a<<", b:"<<b<<endl;

    float num_f = 1.3314141;
    round(num_f,5);
    cout << num_f <<endl;
    get_digit_couple(910321431, 2);


    cout<<fib(6)<<endl;

    print_n(10);


    int arr[] = {1,2,3,4,5};
    int arr_size = 5;

    //print_arr(arr, arr_size);
    //print_arr_rec(arr, arr_size);

    int arr2[12];
    fill_1_N(arr2,12);
    print_arr(arr2,12);

    cout<<"sum arr: "<<sum_arr(arr2,12)<<endl;

    fill_div_5(arr2,12);
    print_arr(arr2,12);

    return 0;
}
