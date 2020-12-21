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




int main()
{

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
    cout<<str2<<endl;
    return 0;
}
