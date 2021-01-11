#include <iostream>
#include <cstring>
using namespace std;

//zad1.1
bool check_perm(int *arr1, int size_arr1, int *arr2, int size_arr2)
{
    if(size_arr1 != size_arr2)
        return false;

    bool *mask = new bool[size_arr2];
    for(int i=0;i<size_arr2; i++)
    {
        mask[i] = true;
    }

    for(int i = 0; i < size_arr1; i++)
    {
        bool match = false;
        for(int j = 0; j < size_arr2; j++)
        {
            if(mask[j] && arr2[j] == arr1[i])
            {
                mask[j] = false;
                match = true;
                break;
            }
        }

        if(!match)
            return false;
    }

    delete mask;

    return true;
}

//zad1.2
int** mult_matr(int mat1[2][3], int mat2[3][3])
{
    int **result = new int*[2];
    for(int i=0; i<2; i++)
    {
        result[i] = new int[3];
    }


    for(int i = 0; i < 2; i++)
    {
        for(int x =0; x < 3; x++)
        {
            int elem = 0;
            for(int y = 0; y < 3; y++)
            {
                elem += mat1[i][y]*mat2[y][x];
            }
            result[i][x] = elem;
        }

    }
    return result;
}


//zad2.1
int num2innum1(int num1, int num2)
{
    if(num1 == 0)
        return false;
    if(num2 == 0)
        return true;

    if(num2 % 10 == num1 %10)
        num2 /= 10;

    num2innum1(num1/10, num2);
}


//zad2.2
void help(int *arr, int cnt, bool sub_arr_found, int arr_size, int start, int len, int &max_len, int &max_start)
{
    if(cnt < arr_size)
    {
        if(arr[cnt] == arr[cnt - 1])
        {
            if(!sub_arr_found)
            {
                sub_arr_found = true;
                start = cnt - 1;
            }
            len++;

        }
        else
        {
            if(sub_arr_found)
            {
                if(len > max_len)
                {
                    max_len = len;
                    max_start = start;
                    start = 0;
                    len = 0;
                }
                sub_arr_found = false;
            }
        }

        help(arr, cnt+1, sub_arr_found, arr_size, start, len, max_len, max_start);
    }

}


int *longest_subarray(int *arr, int arr_size)
{
    int max_start = 0;
    int max_len = 0;

    help(arr, 1, false, arr_size, 0, 0, max_len, max_start);

    cout<< max_start << " " << max_len << endl;
}


//zad 3.1
char *to_the_end(char *str1, char str2[4])
{
    int str1_len = strlen(str1);
    char *new_str1 = new char[str1_len + 1];
    strcpy(new_str1, str1);

    int normal_chars_cnt = str1_len;
    for(int i = 0; i < normal_chars_cnt; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(new_str1[i] == str2[j])
            {
                char ch = new_str1[i];
                strncpy(new_str1+i, new_str1+1+i, str1_len - i - 1);
                new_str1[str1_len - 1] = ch;
                normal_chars_cnt--;
                i--;
                break;
            }
        }
    }


    return new_str1;
}


//zad3.2
void remove_dup(char* str)
{
    int len = strlen(str);
    for(int i = 1; i < len;)
    {
        if(str[i] == str[i - 1])
        {
            strncpy(str+i-1, str+i, len - i - 1);
            len--;
        }
        else
        {
            i++;
        }
    }
    str[len]='\0';

}

int main()
{
    int arr1[] = {1, 2, 3, 2, 1, 1};
    int arr2[] = {2, 1, 1, 2, 1, 2};

    cout<< check_perm(arr1, 6, arr2, 5)<<endl;


    int mat1[2][3]= {
        {1,2,3},
        {4,5,6}
    };

    int mat2[3][3]= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int **res = mult_matr(mat1,mat2);

    for(int y =0; y < 2; y++)
    {
        for(int x = 0; x < 3; x++)
        {
            cout<<res[y][x]<<" ";
        }
        cout<< endl;
    }

    cout << num2innum1(112331, 122)<<endl;

    int arr[] = {1,2,2,2,3,3};
    longest_subarray(arr,6);


    char str1[] = "ashavv1g1aaa";
    cout<<to_the_end(str1, "hg1")<<endl;
    //remove_dup(str1);
    //cout<<str1<<endl;
    return 0;
}


