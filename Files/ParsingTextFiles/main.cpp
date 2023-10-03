/* File parsing */

#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>

void ParseTextFile(std::fstream &iofstream)
{
    std::string line;
    std::string anim;
    std::string sound;
    iofstream.seekg(std::ios_base::beg);
    while(getline(iofstream,line))
    {
        std::istringstream tokenizer(line);
        std::getline(tokenizer,anim,':') ;
        std::getline(tokenizer,sound,':') ;
        std::cout<<"Animal : "<< anim << "-- Sound : "<<sound<<std::endl;
    }

}


int main(int argC, char ** argV)
{
    std::fstream iofstream;
    iofstream.open("/home/rohit/Code/CPPAdv/Files/Temp/textparsing.txt",std::ios_base::out );
    if(!iofstream.is_open())
    {
        std::cout<<"Unable to open file."<<std::endl;
        return 1;
    }
    
    iofstream.write("Dog:Woof\n",strlen("Dog:Woof\n"));
    iofstream.write("Cat:Meaw\n",strlen("Cat:Meaw\n"));
    iofstream.write("Cow:Moo\n",strlen("Cow:Moo\n"));

    iofstream.close();
    //reading
    iofstream.open("/home/rohit/Code/CPPAdv/Files/Temp/textparsing.txt",std::ios_base::in );
    ParseTextFile(iofstream);
    iofstream.close();
    return 0;
}