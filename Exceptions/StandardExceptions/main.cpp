#include<iostream>
using namespace std;

class ClassCanThrow{
public:
    ClassCanThrow(){
        char * pMemory = new char [999999999999999];
        delete [] pMemory;
    }

};

int main( int charC , char ** argV)
{
    try{
        ClassCanThrow c;
    }
    catch(bad_alloc& e)
    {
        cout<<e.what()<<endl;
    }
}