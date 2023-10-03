#include<iostream>
using namespace std;

void FuncCanThrow()
{
    bool error1 = true;
    bool error2 = false;
    if(error1)
    {
        throw bad_alloc();
    }
    if(error2)
    {
        throw exception();
    }
}

int main(int charC , char ** argV)
{
    try{
        FuncCanThrow();
    }
    catch(exception e){
        cout<<"Exception Happened : "<<e.what()<<endl;

    }
    catch(bad_alloc& e)///this will never be caught as std exception will be caught before this 
    {
        cout<<"Exception Happened :"<<e.what()<<endl;
    }
}