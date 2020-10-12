#include <iostream>
using namespace std;


int main()
{


    cout << "problem 1:" << endl;
    float x1 = 6.7, x2 = 3.3;
    const float x3 = x1 + x2;
    cout << x3 << endl;
    cout << endl;

    float x = 5, y = 6.7, z = 5.7;

    //((x*y)*(y-z))/z

    // bad
    float xy = x * y;
    float yz = y - z;
    float xyyz = xy * yz;
    float xyyzz = xyyz / z;

    cout << "problem 2:" << endl;
    cout << "(x * y) = " <<  (x*y) << endl;
    cout << "(y - z) = " <<  (y-z) << endl;
    cout << "(x*y)*(y-z) = "<< (x*y)*(y-z) << endl;

    // good
    cout << "((x*y)*(y-z))/z = " <<((x*y)*(y-z))/z << endl;
    cout << endl;
    // op = int * or + or / or -
    // float op float op int op float returns float
    // int op float op int op float returns int
    float f = (8.0*1)/3;
    cout << "(8.0*1)/3 = " << f << endl;


    cout << "problem 3:" << endl;
    cout << "8 x 1 = " << 8*3 << endl;
    cout << "8 x 2 = " << 8*2 << endl;
    cout << "8 x 3 = " << 8*3 << endl;
    cout << "8 x 4 = " << 8*4 << endl;
    cout << "8 x 5 = " << 8*5 << endl;
    cout << "8 x 6 = " << 8*6 << endl;
    cout << "8 x 7 = " << 8*7 << endl;
    cout << "8 x 8 = " << 8*8 << endl;
    cout << "8 x 9 = " << 8*9 << endl;
    cout << "8 x 10 = " << 8*10 << endl;
    cout << endl;

    cout << "problem 4:" << endl;
    float a=2.7, b = 5.0;
    int c = 5, d = 3;
    cout << a + b << " " << d + c << " " << c * a << " " << c/d << /*gives error */endl;
    cout << endl;

    cout << "problem 5:" << endl;
    char e = ' ', s = '*', n = '\n';
    cout << e << e << e << s << n;
    cout << e << e << s << s << s<< n;
    cout << e << s << s << s << s << s<< n;
    cout << e << e << e << s << e << e << n;
    cout << e << e << e << s << e << e << n;

    // problem 6
    cout << "problem 6:" << endl;
    char ch = 'A';
    int ascii_ch = ch;
    cout << ascii_ch << endl;
    return 0;
}
