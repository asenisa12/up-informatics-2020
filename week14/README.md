# **Структури и указатели към функции**
<br />
<br />

# **Структури**
#### **Дефиниране на структура**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct person{
    char name[10];
    int age;
    char *job_title;
};
int main()
{
    person p;
    p.age = 15;

    strncpy(p.name, "Pesho",6);

    p.job_title = new char[11];
    strncpy(p.job_title, "Programmer",11);

    cout<<p.name<<" "<<p.age<<" "<<p.job_title<<endl;


    person *p_ptr = &p;
    cout<<p_ptr->name<<" "<<p_ptr->age<<" "<<p_ptr->job_title<<endl;


    person people[10];
    person *p_ptr2 = new person;
    delete p_ptr2;

    return 0;
}

```

## Задача:

1) Да се напише структура "Book", която съдържа следната информация(полета):
	
	- име на книгата
	- име на автора
	- жанр
	- цена
	- брой продажби
	- други по ваш избор

2) Напишете функция, която прочита въведени стойности и ги задава като стойности на полетата 
   на подаден обект от горния тип.

		void initialize(Book& b);

3) Въведете масив от 10 книги, като използвате горната функция.

4) Напишете функция, която отпечатва информацията от даден обект горния тип.

		void print(const Book& b);

5) Напишете функиции, която отпечатва книгата с най-ниска цена и с най-висока цена:

	- void printBookWithLowestPrice(Book* books, size_t count);

	- void printBookWithHighestPrice(Book* books, size_t count);

6) Напишете функция, която намира книгата с най-много продажби:

		Book& getBestBook(Book* books, size_t count);

7) Напишете функция, която проверява дали книга се среща в масив от книги:

<br />
<br />

# **Указател към функция**
#### **Пример:**
```cpp
#include <iostream>
using namespace std;

void my_int_func(int x)
{
    cout<< x<< endl;
}

void other_func( void (*func)(int))
{
    func(5);
}

int main()
{
    void (*foo)(int);
    foo = &my_int_func;

    foo( 2 );

    other_func(foo);

    return 0;
}

```


## Задачи:
1) Имплементирайте функцията map, която прилага функция върху всеки елемент от даден масив.

2) Имплементирайте функция, която връща първия елемент, отговарящ на дадено условие, подадено като аргумент.