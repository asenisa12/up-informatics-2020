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

/*str = "adasd dafafa "
arr = {1,2,3,4}
char *p = str+2;
*(p+1)*/

//zad4
char* find_longest_word(char *sentence)
{
    int max_length = 0;
    int max_word_start = 0;
    int current_word_len=0;
    int cnt=0;
    do
    {
        if(sentence[cnt] == ',' || sentence[cnt] == ' ' || sentence[cnt] == '.' || sentence[cnt] == '\0')
        {
            if(current_word_len > max_length)
            {

                max_length = current_word_len;
                max_word_start = cnt - current_word_len;
            }

            current_word_len = 0;
            if(sentence[cnt] == '\0')
                break;
        }
        else
        {
            current_word_len++;

        }

        cnt++;
    }
    while(true);

    char *max_word = new char[max_length + 1];

    strncpy(max_word, sentence + max_word_start, max_length);
    max_word[max_length] = '\0';
    return max_word;
}


char** get_words(char *sentence, int &word_cnt)
{

    int cnt=0;
    int word_count = 0;
    do
    {
        if(sentence[cnt] == ' ' || sentence[cnt] == '.' || sentence[cnt] == '\0')
        {
            word_count++;
        }

        if(sentence[cnt] == '\0' ||  sentence[cnt] == '.')
                break;
        cnt++;
    }
    while(true);
    cout<< word_count<<endl;

    char** words = new char*[word_count];
    int current_word_len = 0;
    word_cnt = 0;
    cnt = 0;
    do
    {
        if(sentence[cnt] == ' ' || sentence[cnt] == '.' || sentence[cnt] == '\0')
        {
            words[word_cnt] = new char[current_word_len + 1];
            int start_pos = cnt - current_word_len;
            if(cnt - 1 >= 0 && sentence[cnt-1] == ',')
            {
                start_pos--;
            };
            strncpy(words[word_cnt], sentence + start_pos, current_word_len);
            words[word_cnt][current_word_len] = '\0';
            cout<<start_pos << " " << current_word_len<<endl;
            cout<<words[word_cnt]<<endl;
            current_word_len = 0;
        }
        else
        {
            if(sentence[cnt] != ',')
                current_word_len++;

        }

        if(sentence[cnt] == '\0' ||  sentence[cnt] == '.')
                break;
        cnt++;
    }while(true);

    return words;
}


int main()
{
    /*
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
    */
    char *sentence = "ala bala nitsa";
    char *longest_word = find_longest_word(sentence);
    cout<< longest_word<<endl;
    delete [] longest_word;

    int word_cnt;
    char **words = get_words(sentence, word_cnt);

    for(int i = 0; i < word_cnt; i++)
    {
        delete [] words[i];
    }
    delete [] words;


    return 0;
}
