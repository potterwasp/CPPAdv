#include<iostream>
#include<fstream>

void WriteToFile(std::string textToWrite)
{
    std::ofstream outFile;
    outFile.open("/home/rohit/Code/Temp/textfiles.txt",std::ios_base::app);
    if(outFile.is_open())
    {
        outFile << textToWrite << std::endl;
        outFile << textToWrite << std::endl;
        std::cout<<"Written Size : "<<outFile.tellp()<<std::endl;
        outFile.close();
    }
    else
    {
        std::cout<<"Failed to open the output file"<<std::endl;
    }

}

void ReadFromFile()
{
    std::ifstream inputFile;
    inputFile.open("/home/rohit/Code/Temp/textfiles.txt");
    if(inputFile.is_open())
    {
        char * buff = new char[1024];
        inputFile.read(buff,1024);
        std::cout<<"File contents : \n"<<buff<<std::endl;
    }
    else
    {
        std::cout<<"Failed to open file for reading"<<std::endl;
    }

}
int main()
{
    WriteToFile("hello world");
    ReadFromFile();
}