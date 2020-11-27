#include <iostream>
#include <cmath>
using namespace std;

//zad1
void smalles_and_biggest(int num, int &min_dig, int &max_dig)
{
    min_dig = 9;
    max_dig = 0;
    while(num>0)
    {
        int cur_dig = num % 10;
        if(cur_dig < min_dig)
            min_dig = cur_dig;
        if(cur_dig > max_dig)
            max_dig = cur_dig;
        num /= 10;
    }


}

//zad2
bool is_pow_of_2(int num)
{
    int count = 0;
    int copy_of_num = num;
    while(num > 1)
    {
        if(num % 2 != 0)
            return false;

        num /= 2;
        count++;
    }
    cout <<copy_of_num <<" == 2^"<<count << endl;
    return true;
}


//zad3
bool is_div_by_3(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return (sum % 3 == 0)? true : false;
}


/*int ost = 1231415 % 10^(k-1) = 15
1231415 / 10^k =1231
1231 * 10^(k-1) + ost= 123115

len - k
ost = 1231415 % 10^ (len-k)
1231415 / 10^(len-k-1)
12*10^ (len-k) +ost*/

void remove_digit(int &num, int k)
{
    int num_cpy = num;
    int len = 0;
    //12345 /10 len++, 1234 /10 len++ .... 1/10 len++ 0
    while(num_cpy > 0)
    {
        len++;
        num_cpy/=10;
    }//equal to

    //len = log10(num)+1;
    int pow_of10 = pow(10, len-k);
    int ost = num % pow_of10;
    num /= pow(10, len-(k-1));
    num = num * pow(10, len-k) + ost;

    cout<<len<<endl;

}


//zad5
void draw_pattern()
{
    int count_letters = 26;
    for(int i = 0; count_letters>0; i++)
    {
        for(int j = 0; j< i+1 && count_letters>0; j++)
        {
            char letter = 'A' + (26 - count_letters);
            cout<< letter << " ";
            count_letters--;
        }
        cout<<endl;
    }

}

//zad6
int count_odd(int arr[], int arr_size)
{

    int sum = 0;
    for(int i = 0; i<arr_size; i++)
    {
        if(arr[i]%2 != 0)
            sum += arr[i];
    }

    return sum;
}



//arr[0] num=12345 / 10^(len-1), num = 12345% 10^((len-1)= 2345
//arr[1] num=2345 / 10^(len-2), num = 2345%10^(len-2)= 345
//zad7
void num_to_arr(long num, int arr[], int max_size)
{
    int len = log10(num) + 1;
    for(int i=0;i<len && i<max_size; i++)
    {
        int pow_of_10 =  pow(10, len - ( i + 1));
        arr[i] = num / pow_of_10;
        num = num % pow_of_10;
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}


//zad8
int cmp_arrs(int arr1[], int size1, int arr2[], int size2)
{
    int count_match=0;

    for(int i=0;i<size1 && i<size2; i++)
    {
        if(arr1[i] == arr2[i])
        {
            count_match++;
        }
    }

    return count_match;
}


//
bool is_sorted(int arr[], int arr_size)
{
    for(int i=1;i<arr_size; i++)
    {
        if(arr[i] < arr[i-1])return false;
    }
    return true;
}

//1 2 3 1 22 31 56 6 7

int max_sorted_part_len(int arr[], int arr_size)
{
    int max_srt=1;
    int srt_cnt=1;
    for(int i=1;i<arr_size; i++)
    {

        if(arr[i] < arr[i-1])
        {
            if(max_srt < srt_cnt)
                max_srt = srt_cnt;
            srt_cnt = 1;
        }
        else{
            srt_cnt++;
        }
    }
    return max_srt;
}

int main()
{
    int min_dig;
    int max_dig;
    smalles_and_biggest(12346, min_dig, max_dig);
    cout<<"min:"<< min_dig << ", max:" <<max_dig<<endl;

    cout << is_pow_of_2(64)<<endl;

    cout << is_div_by_3(28) <<endl;

    int num = 12345;
    remove_digit(num,2);
    cout<<num<<endl;


    draw_pattern();


    int arr1[] = {1,2,313,10, 33};
    cout<<count_odd(arr1, 5)<<endl;


    int arr2[10];
    num_to_arr(1234567891, arr2, 10);

    cout<< cmp_arrs(arr1, 5, arr2, 10)<<endl;

    cout<<is_sorted(arr1,3)<<endl;

    cout<< max_sorted_part_len(arr2, 10)<<endl;

    return 0;
}
