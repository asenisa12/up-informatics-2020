#include <iostream>
using namespace std;

int main()
{
    //zad1
    cout<<"zad 1"<<endl;
    cout<<"x y"<<endl;
    int x,y;
    cin>>x>>y;
    int res = 0;
    while(y>0)
    {
        res += x;
        y--;
    }
    cout<<"x*y="<<res<<endl;


    //zad2
    cout<<"zad 2"<<endl;
    int num;
    cout<<"num: "<<endl;
    cin>>num;
       /* 123
        123%10 3

        123 / 10
        12
        12%10 2

        12/10
        1%10 1

        1 /10
        0*/

    do{
        cout<<num%10<<endl;
        num /= 10;
    }
    while(num > 0);


    //zad3
    cout<<"zad 3"<<endl;
    int sum = 0;
    while(true)
    {
        int var;
        cout<<"var: ";
        cin>>var;

        if(var > 0)
        {
            sum += var;
            continue;
        }

        cout<<"negative number, exiting"<<endl;
        break;
    }
    cout<<"sum = "<<sum<<endl;

    //zad4
    cout<<"zad 4"<<endl;
    int N1;
    cout<<"N1: ";
    cin>>N1;
    for(int i = 2; i<= N1; i+=2)
    {
        cout << i << endl;
    }



    //zad 5
    cout<<"zad 5"<<endl;
    int N2;
    cout<<"N2: ";
    cin>>N2;

    for(int i=0, n = 2; i<N2; n++)
    {
        bool isPrime = true;
        for(int j = n - 1; j>1; j--)
        {
            if(n % j == 0)
                isPrime = false;
        }

        if(isPrime)
        {
            i++;
            cout<<n<<endl;
        }

    }

    // zad 6
    cout<<"zad 6"<<endl;
    int N3;
    cout<<"N3: ";
    cin>>N3;
    int ones = 1;
    int sum = 0;
    for(int i = 0; i < N3; i++)
    {
        cout<<ones << endl;
        sum += ones;
        ones = ones * 10 +1;
    }
    cout<<"sum="<<sum<<endl;



    //zad7
    cout<<"zad 7"<<endl;
    cout<<"x1 y1"<<endl;
    int x1,y1;
    cin>>x1>>y1;

    for(int i = 0; i < y1; i++)
    {
        for(int j = 0; j < x1; j++)
        {
            cout << "#" ;
        }
        cout<<endl;
    }


    cout<<"zad 8"<<endl;
    int x2,y2;
    cin>>x2>>y2;

    for(int i = 0; i < y2; i++)
    {
        for(int j = 0; j < x2; j++)
        {
            if((i%2 != 0 && j%2 == 0)  || (i%2 == 0 && j%2 != 0))
            {
                cout << "*" ;
            }
            else
            {
                cout << "#" ;
            }
        }


        cout<<endl;
    }



    return 0;
}

