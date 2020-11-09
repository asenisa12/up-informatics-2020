#include <iostream>
using namespace std;

//zad1
int fibonachi(int n)
{
    if(n < 3)
        return 1;

    int prev1 = 1;
    int prev2 = 1;
    for(int i = 3; i<= n; i++)
    {
        int tmp = prev2;
        prev2 = prev1 + prev2;
        prev1 = tmp;
    }
    return prev2;
}

//zad2
void printRev(int num)
{
  do
  {
    cout<<num%10;
    num/=10;

  }
  while(num != 0);
  cout<<endl;
}

//zad3
int power(int num, int powof)
{
    int powerofNum = 1;

    for(int i=0;i<powof; i++)
    {
        powerofNum*=num;
    }

    return powerofNum;
}

//zad4
int fact(int num)
{
    int fact = 1;

    //fact = 1*1 *2 *3 * 4 *5 * 6 *7 *8
    for(int i=1;i<=num; i++)
    {
        fact *= i;
    }

    return fact;
}

//zad5
int series(int n, int x)
{
    int sum = 0;
    for(int i = 0; i<= n; i++)
    {
        sum += power(x,i)/fact(i);
    }

    return sum;
}

//zad 6
bool isPrime(int num)
{
    for(int i = num - 1; i>1; i--)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

//zad7
bool isSumOfPrime(int num)
{

    for(int i=1; i<=num/2; i++)
    {

        if(isPrime(i))
        {
            if(isPrime(num - i))
            {
                return true;
            }
        }
    }
    return false;
}

//zad 8
int biggestPair(int num)
{
    if(num >= 10 && num <=99)
    {
        return num;
    }

    int last = num % 10;
    int max_pair = 0;
    do
    {
        num/=10;
        int curr_pair = (num%10) * 10 + last;
        if( curr_pair > max_pair)
        {
            max_pair = curr_pair;
        }
        last = num%10;
    }while(num!=0);

    return max_pair;
}


//zad 9
bool is_ordered(int num)
{
    int last = num % 10;
    do
    {
        num/=10;
        if(num%10 > last)
            return false;
        last = num%10;
    }while(num!=0);

    return true;
}

int main()
{
    cout<<fibonachi(6)<<endl;

    printRev(334145);

    cout<<power(2,3)<<endl;

    cout<<fact(3)<<endl;

    cout<<series(3,2)<<endl;

    cout << isPrime(17)<<endl;

    cout << isSumOfPrime(10) <<endl;

    cout << biggestPair(123452141) << endl;

    cout << is_ordered(12345)<<endl;

    return 0;
}
