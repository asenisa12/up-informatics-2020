#include <iostream>
#include <cstring>
using namespace std;

//struct problems
//1)
struct Book
{
    char *book_title;
    char author[20];
    char genre[10];
    int sales;
    int price;
};

//2)
void initialize(Book &book, const char *title, const char *author, const char *genre, int sales, int price)
{

    int len_book_title = strlen(title);
    int len_author = strlen(author);
    int len_genre = strlen(genre);

    book.book_title = new char[len_book_title + 1];
    strncpy(book.book_title, title, len_book_title + 1);
    strncpy(book.author, author, len_author+1);
    strncpy(book.genre, genre, len_genre+1);

    book.sales = sales;
    book.price = price;
}

void copy_book(Book &b1, Book &b2)
{
    initialize(b2,b1.book_title, b1.author, b1.genre, b1.sales, b1.price);
}


void print(Book &b)
{
    cout << "title:" << b.book_title << " author:"<<b.author<<" genre:"<<b.genre;
    cout << " sales:"<<b.sales<< " price:"<<b.price<<endl;
}

//5)
void printBookWithLowestPrice(Book* books, size_t count)
{
    //for home
}

void printBookWithHighestPrice(Book books[], size_t count)
{
    int price_max = 0;
    int index = 0;
    for(int i = 0; i<count; i++)
    {
        if(books[i].price > price_max)
        {
            price_max = books[i].price;
            index = i;
        }
    }

    cout<<"Book with highest price:"<<endl;
    print(books[index]);
}

//6)
Book& getBestBook(Book* books, size_t count)
{
    int sales_max = 0;
    int index = 0;
    for(int i = 0; i<count; i++)
    {
        if(books[i].sales > sales_max)
        {
            sales_max = books[i].sales;
            index = i;
        }
    }

    return books[index];
}


struct price{
    int dolars;
    int cents;
};

bool compare(price &p1, price &p2)
{
    return p1.cents == p2.cents && p1.dolars == p2.dolars;
}

bool compare_books(Book &b1, Book &b2)
{
    if(strcmp(b1.book_title, b2.book_title) != 0)
    {
        return false;
    }
    else if(strcmp(b1.author, b2.author) != 0)
    {
        return false;
    }
    else if(strcmp(b1.genre, b2.genre) != 0)
    {
        return false;
    }
    else if(b1.price != b2.price)
    {
        return false;
    }
    else if(b1.sales != b2.sales)
    {
        return false;
    }

    return true;
}


bool bookInArray(Book *books, int count, Book &b)
{
    for(int i=0; i<count; i++)
    {
        if(compare_books(books[i], b))
            return true;
    }
    return false;
}

int main()
{

    price p1 = {1,2};
    price p2 = {1,3};

    cout<<compare(p1, p2)<<endl;


    Book books[5];

    initialize(books[0], "horror", "IT", "Steven King", 10000, 5);
    initialize(books[1], "random", "book1", "Milena", 20300, 6);
    initialize(books[2], "fantastic", "book2", "Mitko", 40000, 2);
    initialize(books[3], "love", "book3", "Gosho", 1200, 4);
    initialize(books[4], "history", "book4", "Pesho", 14141, 12);

    for(int i = 0; i<5; i++)
    {
        print(books[i]);
    }

    printBookWithHighestPrice(books, 5);


    Book best_book_ref = getBestBook(books, 5);

    Book *best_book = new Book;
    copy_book(getBestBook(books, 5), *best_book);

    print(*best_book);


    Book best_book2;
    copy_book(getBestBook(books, 5), best_book2);

    print(best_book2);

    cout<<compare_books(books[1], books[1])<<endl;


    Book b1;
    Book b2;
    initialize(b1, "horror", "IT", "Steven King", 10000, 5);
    initialize(b2, "fantasy", "LOTR", "J.R.Tolkin", 20000, 15);

    cout<< bookInArray(books, 5, b2)<<endl;
    cout<< bookInArray(books, 5, b1)<<endl;

    return 0;
}
