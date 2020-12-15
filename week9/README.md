# **Пойнтери и динамични масиви**
<br />
<br />



#### **Пойнтери и динамична памет**
```cpp
#include <iostream>
using namespace std;

void test_func(int *&p)
{
    static int num = 6;
    num++;
    cout<<num<<endl;
    p = &num;

}

int main()
{
    int *p;
    int a = 34;

    p = &a;
    cout<<p<<endl;
    (*p)++;
    cout<<*p<<endl;

    int arr[5] = {1,2,3,4,5};
    
    cout<<arr<<endl;
    int *arr_ptr = arr;
    
    //*(arr+4) == arr[4]
    cout<<*(arr+4)<<endl;

    int *const ptr_test2 = &min_elem;
    //ptr_test2 = &max_elem; //error
    const int *ptr_test3;
    ptr_test3 = &min_elem;
    ptr_test3 = &max_elem;
    //(*ptr_test3)++; //error


    int *ptr_test;
    test_func(ptr_test);
    test_func(ptr_test);
    test_func(ptr_test);
    cout<<*ptr_test<<endl;

    int size_of_arr;
    cin>>size_of_arr;

    // creates dynamic array;
    int *test_arr = new int[size_of_arr];

    //only one integer with value 12
    int *dynint = new int(12);


    //deletes dynamic array
    delete test_arr;
    
    //create dynamic 2d array
    int rowCount = 5;
    int **arr2d = new int*[rowCount];

    int colCount = 6
    for(int i =0; i < rowCount; i++)
    {
        arr2d[i] = new int[colCount];
    }

    //delete dynamic 2d array
    for(int i =0; i < rowCount; i++)
    {
        delete [] arr2d[i];
    }

    delete  [] arr2d


    return 0;
}
```
<br />



# **Задачи**

## **Направете функция, която:**
<br />
<br />


### **Задача 1:**
    намира най-малкия и най-големия елемент в масив
<br />   

### **Задача 2:**
    записва диагонала на даден двумерен масив в едномерен масив
<br />

### **Задача 3:**
    създава двумерен масив с N елемента
<br />

### **Задача 4:**
    създава двумерен масив с N реда и M колони
<br />

### **Задача 5:**
    трие динамичен масив
<br />

### **Задача 6:**
    приема двумерен масив, и връща такъв с първите m колони и n реда на първия
<br />

### **Задача 7:**
    приема едномерен масив от числа и връща двумерен масив от bool, като всеки ред да представлява число от едномрения мсаив в двуичен вид
<br />
    
    
