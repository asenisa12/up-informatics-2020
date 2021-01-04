#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;


char *to_str(unsigned int num)
{
    int num_len = log10(num)+ 1;
    char * str = new char[num_len + 1];
    for(int i = num_len-1; i>=0; i--)
    {
        str[i] = '0' + num%10;
        num=num/10;
    }
    str[num_len] ='\0';
    return str;
}

int to_int(const char *str)
{
    int num = 0;

    for(int i = 0; str[i]!='\0' && str[i] >= '0' && str[i] <= '9'; i++)
    {
        num*=10;
        num += str[i] - '0';
    }

    return num;

}


char *get_first_n(const char*str, int N)
{
    if(N > strlen(str))
    {
        return NULL;
    }
    char *new_str = new char[N+1];
    strncpy(new_str, str, N);
    new_str[N] = '\0';
    return new_str;
}


void remove_word_v1(char *str, const char *word)
{

    int len = strlen(str);
    int word_len = strlen(word);
    for(int i = 0; i < len; i++)
    {
        if(strncmp(word, str+i, word_len) == 0)
        {
            for(int j = i; j < len - word_len; j++)
            {
                str[j] = str[j+word_len];
            }
            len -= word_len;
        }
    }

    str[len] = '\0';
}


void remove_word_v2(char *&str, const char *word)
{

    int len = strlen(str);
    int word_len = strlen(word);
    for(int i = 0; i < len; i++)
    {
        if(strncmp(word, str+i, word_len) == 0)
        {
            for(int j = i; j < len - word_len; j++)
            {
                str[j] = str[j+word_len];
            }
            len -= word_len;
        }
    }

    char *new_str = new char[len+1];
    new_str[len] = '\0';
    strncpy(new_str, str, len);
    delete [] str;
}



void print_rec(const char *str)
{
    if(*str == '\0')
        return;

    cout<<*str<<endl;
    print_rec(str+1);
}



void copy_rec(const char *str1, char *& str_cpy, int cnt)
{
    if(cnt == 0)
    {
        str_cpy = new char[strlen(str1) + 1];
    }
    str_cpy[cnt] = str1[cnt];

    if(str1[cnt] != '\0')
        copy_rec(str1, str_cpy, cnt + 1);

}


bool helper(const char * str1, int str1_len, const char *str2, int str2_len)
{
    cout<<str1<<"   "<<str2<<endl;

    if(str1_len < str2_len)
        return false;
    else if(strncmp(str1,str2, str2_len) == 0)
    {
        return true;
    }
    else
    {
        return helper(str1+1, str1_len - 1, str2, str2_len);
    }
}

bool str_in_rec(const char * str1, const char *str2)
{
    return helper(str1, strlen(str1), str2, strlen(str2));
}
int main()
{

    /*
    char *str = to_str(12347845);
    cout<<str<<endl;

    int num =  atoi("12asadasd12");
    cout << num << endl;
    cout<< to_int("122131adsa")<< endl;
    delete [] str;

    char *new_str = get_first_n("ala12123",2);
    if(new_str == NULL)
    {
        cout<< "empty string" << endl;
    }else
    {
        cout<< new_str << endl;
    }

    char str2[]="alabalaanitsa";
    remove_word_v1(str2,"ala");
    cout<<str2<<endl;*/


    char str_0[] = "abcde123";
    char *str_ptr = str_0;
    //cout<<*(str_ptr + 1) << str_ptr[3]<<endl;

    //print_rec(str_ptr);

    char *str_cpy;
    copy_rec(str_0, str_cpy, 0);

    //print_rec(str_cpy);

    char str_123[] = "123";

    cout<<str_in_rec(str_0, str_123)<<endl;
    return 0;
}
