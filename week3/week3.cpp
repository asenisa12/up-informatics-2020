#include <iostream>
using namespace std;

int main()
{
    /*zad1 */
    int x, y;
    cout<<"x: ";
    cin>> x;
    cout<<"y: ";
    cin>> y;
    int res = (x<y)? x+y : x-y;
    cout<< res << endl;

    /*zad2 */
    int var;
    int a, b, c;
    cout<<"a: ";
    cin>> a;
    cout<<"b: ";
    cin>> b;
    var = ( (a==b) || (b<a && a-b>2) )? 10 : 20;

    cout << var << endl;

    /*zad3*/
    cout<<"c: ";
    cin>> c;
    int max_num;
    if(a > b){
        max_num = (a>c)?a:c;
    }
    else if(b>c)
    {
        max_num = b;
    }
    else
    {
        max_num = c;
    }
    cout<< max_num <<endl;

    /*zad4*/
    int year, month, day;
    cin>> year >> month >> day;
    if(year>=0)
    {
        if(month >= 1 && month <= 12)
        {
            if(day>=1 && day<=28)
            {
                cout << "valid date" << endl;
            }
            else if((month % 2 != 0) && (day>=29 && day<=31))
            {
                cout << "valid date" << endl;

            }
            else if(month == 2 && year % 4 == 0 && day == 29)
            {
                cout << "valid date" << endl;

            }
            else if((month % 2 == 0) && month!=2  && day>=29 && day<=30)
            {
                cout << "valid date" << endl;
            }
            else
            {
                cout<< "invalid day" << endl;
            }

        }
        else
        {
            cout<<"invalid month"<<endl;
        }

    }
    else
    {
        cout<<"invalid year"<<endl;
    }
    /*zad5*/
    int year1, month1, day1;
    cout<<"input year1, month1, day1: ";
    cin>> year1 >> month1 >> day1;

    int year2, month2, day2;
    cout<<"input year2, month2, day2: ";
    cin>> year2 >> month2 >> day2;

    if(year1 > year2)
    {
        cout << "Date1 > Date2" << endl;
    }
    else if(year1< year2)
    {
        cout << "Date1 < Date2" << endl;
    }
    else
    {
        if(month1 > month2)
        {
            cout << "Date1 > Date2" << endl;
        }
        else if(month1 < month2)
        {
            cout << "Date1 < Date2" << endl;
        }
        else
        {
            if(day1 > day2)
            {
                cout << "Date1 > Date2" << endl;
            }
            else if(day1 < day2)
            {
                cout << "Date1 < Date2" << endl;
            }
            else
            {
                cout << "Date1 == Date2" << endl;
            }

        }
    }
    /* zad 6*/
    int x, y;
    cout<<"(x,y): ";
    cin>>x>>y;
    if( x >= 0 && x <= 10 && y>=0 && y <= 10)
    {
        cout<<"inside the square"<<endl;
    }
    else
    {
        cout<<"outside the square"<<endl;

    }


    /*zad7*/
    int score1, score2, score3;
    cout<<"score1: ";
    cin>>score1;
    if(score1 >=0 && score1 <=100)
    {
        cout<<"score2: ";
        cin>>score2;
        if(score2 >=0 && score2 <=100)
        {
            cout<<"score3: ";
            cin>>score3;
            if(score3 >=0 && score3 <=100)
            {
                cout<< "avg score: "<<(score1 + score2 + score3)/3<<endl;
            }else
            {
                cout << "invalid score3" << endl;
            }
        }else
        {
            cout << "invalid score2" << endl;
        }
    }
    else
    {
        cout << "invalid score1" << endl;
    }


    /*zad8*/
    int num1,num2;
    char op;
    cin>>num1>>op>>num2;
    cout<<"= ";
    switch(op){
        case '+':
            cout<<num1+num2<<endl;
            break;
        case '-':
            cout<<num1-num2<<endl;
            break;
        case '/':
            cout<<num1/num2<<endl;
            break;
        case '*':
            cout<<num1*num2<<endl;
            break;
        default:
            cout<<"invalid"<<endl;
    }


    /*zad9*/
    int dayOfWeek;
    cin>>dayOfWeek;
    switch(dayOfWeek){
        case 1:
            cout<<"Monday"<<endl;
            break;
        case 2:
            cout<<"Tuesday"<<endl;
            break;
        case 3:
            cout<<"Wednesday"<<endl;
            break;
        //for homework
        default:
            cout<<"invalid"<<endl;
    }



    return 0;
}
