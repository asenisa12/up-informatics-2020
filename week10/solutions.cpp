#include <iostream>
#include <cstring>
using namespace std;


int ourstrlen(char *str)
{
    int cnt = 0;
    while(str[cnt] != '\0')
    {
        cnt++;
    }
    return cnt;
}

int ourstrcmp(char *str1, char *str2)
{
    int i;
    for(i = 0; str1[i]!='\0' && str2[i]!='\0'; i++)
    {
        if(str1[i] != str2[i])
            return -1;
    }
    if(str1[i]=='\0' && str2[i]=='\0')
        return 0;
    else
        return -1;
}

void tocapital(char *str)
{
    int cnt = 0;
    while(str[cnt] != '\0')
    {
        if(str[cnt] >= 'a' && str[cnt] <= 'z')
        {
            str[cnt] = str[cnt] - ('a' - 'A');
        }
        cnt++;
    }
}
//word = "ala"
//str = "alabalagaala"
int word_count_v1(char *str, char *word)
{
    int cnt = 0;
    int word_count = 0;
    while(str[cnt] != '\0')
    {
        bool contained = true;
        for(int i =0; word[i] != '\0'; i++)
        {
            if(str[cnt+i] != word[i])
            {
                contained = false;
                break;
            }
        }
        if(contained)
            word_count++;

        cnt++;
    }
    return word_count;
}
 int word_count_v2(char *str, char *word)
 {
    int cnt = 0;
    int word_count = 0;
    int word_size = strlen(word);
    while(str[cnt] != '\0')
    {
        if(strncmp(str + cnt,word, word_size) == 0)
            word_count++;
        cnt++;
    }
    return word_count;
 }



int main()
{
    char str[] = "my first string!"; // == char str[] ={'m','y',' ', 'f',.....,'\0'};
    char str2[] = "my ";
    cout<< str << endl;
    cout << str[1]<<endl;

    cout<< ourstrlen(str)<<endl;
    bool res = ourstrcmp(str, str2)==0;
    cout << res << endl;
   // cout << strncmp(str, str2,3)==0  << endl;

    tocapital(str);
    cout<<str<<endl;

    char test[] = "alabalagaala";
    cout<<word_count_v2(test, "ala")<<endl;
    return 0;
}
