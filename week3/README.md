# **Оператори if и switch. Област на действие**
<br />
<br />


#### **БУЛЕВИ ПРОМЕНЛИВИ И ОПЕРАТОРИ**
```cpp
#include <iostream> 
using namespace std;

int main() {
    bool t = true; // true има стойност 1
    bool f = false; // false има стойност 0

    cout << t << endl; // принтира 1
    cout << f << endl; // принтира 0

    bool res;

    //Логически оператори
    res = t || t; // res получава стойност true
    res = t || f; // res получава стойност true
    res = f || f; // res получава стойност false

    res = t && t; // res получава стойност true
    res = t && f; // res получава стойност false
    res = f && f; // res получава стойност false


    int a = 10;
    int b = -20;

    /* Релационни и сравнителни оператори
        ==	равно на
        !=	различно от 
        <	по-малко
        >	по-голямо
        <=	по-малко или равно
        >=	по-голямо или равно
    */
    res = a == a; // res получава стойност true
    res = a == b; // res получава стойност false

    res = a != a; // res получава стойност false
    res = a != b; // res получава стойност true

    res = b < a; // res получава стойност true
    res = a > b; // res получава стойност true

    res = b <= a; // res получава стойност true
    res = b <= b; // res получава стойност true

    res = a >= b; // res получава стойност true

    res = a > b || a==b; // еквивалентно на a >= b
    res = a < b || a==b; // еквивалентно на a <= b

    return 0;
}
```


#### **?: (тернарен оператор), if/else и switch/case**
```cpp
#include <iostream> 
using namespace std;

int main() {
    int var;
    
    // ТЕРНАРЕН ОПЕРАТОР
    var = (true)? 1 : 2; // var приема стойност 1
    var = (false)? 1 : 2; // var приема стойност 2

    // if/else
    int var;
    cin >> var;
    if(var > 100)
        cout<< "var is bigger than 100" << endl;
    else
        cout<< "var is smaller than 100" << endl;
    
    int a = 10, b = 5;
    
    // SCOPE
    {
        int a = 42;
        int c = 12;
        
        a += 2;
        
        cout << a << endl; // принитира 44
        cout << b << endl; // принитира 5
        cout << c << endl; // принитира 12
        
        b+=2;
    }
    cout << a << endl; // принитира 10
    cout << b << endl; // принитира 7
    /*ERROR*/cout << c << endl; //дава компилационна грешка

    if(a > b)
    {
        b += 20;
        a -= b;
    }
    else
    {
        a += b;
        b += 12;
    }
    
    // switch/case
    int n;
    cin >> n;
    switch (n)
    {
        case 1: 
            // code to be executed if n = 1;
            break;
        case 2: 
            // code to be executed if n = 2;
            break;
        default: 
            // code to be executed if n doesn't match any cases
    }

    n = 1;
    switch (n)
    {
        case 1: 
            n=2;
            cout<<" Тук сме " << endl;
        case 2:
            n = 12;
            cout<<" Тук сме " << endl;
        default:
            cout<<" Тук сме " << endl;
    }

    return 0;
}
```

<br />

# **Задачи**

## **Направете програма, която:**
<br />
<br />

### **Задача 1:**
    при въвеждане на 2 цели числа (x и y),
    да принтира в конзолата  x+y, ако x<y, или x-y в противен случай
<br />   

### **Задача 2:**
    дефинира променлива var, която при въвеждане на две цели числа (a и b),
    приема стойност 10, ако a e равна на b или b<a и a-b>2. 
    В противен случай var приема стойност 20.
<br />

### **Задача 3:**
    въвежда 3 цели числа (a, b, c) и принитра най-голямото от тях
<br />

### **Задача 4:**
    въвежда 3 цели числа (year, month, day) и проверяваме
    дали са валидна дата
<br />

### **Задача 5:**
    въвежда 6 цели числа: year1, month1, day1 (Date1) и year2, month2, day2 (Date2).
    След това принитраме дали Date1 > Date2, Date1 < Date2 или Date1 == Date2
<br />

### **Задача 6:**
    при въведени цели числа x и y, да принтира стойността дали точката (x,y)
    e вътре в квадрат, започващ от точка (0,0) и имащ дължина на страните 10
<br />

### **Задача 7:**
    при въведени 3 оценки от контролни (от 0 до 100),
    да принира колко е средния резултат от тях
<br />

### **Задача 8:**
    при въвеждане на 3 променливи (int num1, char op-(*,/,+,-)операция, int num2),
    да принитира резултата от num1 op num2 (представлява конзлоен калкулатор)
<br />

### **Задача 9:**
    при въведенa променливa day, да принтира кой ден от седмицата репрезентира
    (1-Понеделник, 2-Вторник....)
    
    
