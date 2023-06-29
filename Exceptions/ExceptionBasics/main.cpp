#include<iostream>
using namespace std;

void functionCanThrow()
{
    bool error1 = false;
    bool error2 = false;
    bool error3 = true;

    if(error1)
        throw "Something is wrong";
    
    if(error2)
        throw 8;

    if(error3)
        throw string("Something else went wrong");
}

int main( int argC , char ** argV )
{
    try
    {
        functionCanThrow();
    }
    catch(int e)
    {
        cout<<"Exception Thrown "<<e<<endl;
    }
    catch(char const * c)
    {
        cout<<"Exception Thrown "<<c<<endl;
    }
    catch(string& strEx)
    {
        cout<<"Exception Thrown "<<strEx<<endl;
    }
}