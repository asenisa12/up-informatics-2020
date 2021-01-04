#include <iostream>
using namespace std;


void func_rec(int n)
{
    if(n == 0)
        return;

    cout<<"hello world"<<endl;
    func_rec(n - 1);
}


void print_1_N(int N)
{
    if(N==0)
        return;

    print_1_N(N-1);
    cout<<N<<endl;
}


double helper_sum_rec(double sum, double x, int i, int n)
{
    if( i == n+1)
        return sum;

    return helper_sum_rec(sum*x + i, x, i + 1, n);
}

double sum_rec(double x, int n)
{
    return helper_sum_rec(1, x, 2, n);
}


double sum_rec2(double x, int n)
{
    if(n == 1)
        return 1;
    return sum_rec2(x, n-1) * x + n;
}


//zad2
int helper_sum_with_step(int k, int n, int cur_num)
{
    if(cur_num > n)
        return 0;
    return helper_sum_with_step(k, n, cur_num + k) + cur_num;
}

int sum_with_step(int k, int n)
{
    return helper_sum_with_step(k,n, 1);
}


//zad4
bool helper_isPrime(int n, int cnt)
{
    if(cnt == 1)
        return true;
    if(n % cnt != 0)
        return helper_isPrime(n, cnt - 1);
    else return false;
}
bool isPrime(int n)
{
    if(n == 1)
        return false;

    helper_isPrime(n, n - 1);
}


int sumPrimes(int a, int b)
{
    if(a>b)
        return 0;
    else{
 /*       if(isPrime(a))
            return sumPrimes(a+1,b) + a;
        else
            return sumPrimes(a+1,b);*/
        cout<<(a * isPrime(a))<<endl;
        return sumPrimes(a+1,b) + (a * isPrime(a));

    }
}


int main()
{

    //func_rec(5);



    //print_1_N(10);


    cout<< sum_rec(2,5)<<endl;
    cout<<sum_rec2(2,5)<<endl;

    cout << sum_with_step(3,15)<<endl;



    cout<< isPrime(1) <<endl;

    cout<<sumPrimes(1, 10)<<endl;
    return 0;
}
