#include<iostream>
using namespace std;

class MyException:public exception
{
public:
    const char* what() const _GLIBCXX_USE_NOEXCEPT{
        return "Something bad happened";
    }
};

class Test{
    public:
    Test()
    {
        throw MyException();
    }
};
int main(int charC , char ** argV)
{
    try{
        const Test t;
    }
    catch(MyException e)
    {
        cout<<e.what()<<endl;
    }
}