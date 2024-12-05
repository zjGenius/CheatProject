#include "ImplBook.h"

class ImplBook
{
public:
    ImplBook();
    ImplBook(std::string bookName, double price);
    ~ImplBook();

    void display();
    void setPrice(double);
    double getPrive();

private:
    std::string bookName;
    double bookPrice;
};

ImplBook::ImplBook() = default;

ImplBook::ImplBook(std::string name, double price) : bookName(name), bookPrice(price)
{

}
ImplBook::~ImplBook()
{}

void ImplBook::display()
{
    std::cout << "PIMPL模式" << std::endl; 
    std::cout << "book name: " << bookName << std::endl;
    std::cout << "book price: " << bookPrice << std::endl;
}

void ImplBook::setPrice(double price)
{
    bookPrice = price;
}

double ImplBook::getPrive()
{
    return bookPrice;
}

/******************/

PBook::PBook() : impl(std::make_unique<ImplBook>())
{}

PBook::PBook(std::string name, double price) : impl(std::make_unique<ImplBook>(name, price))
{}

PBook::~PBook() = default;

PBook& PBook::operator=(PBook&&) = default;

void PBook::display()
{
    impl->display();
}