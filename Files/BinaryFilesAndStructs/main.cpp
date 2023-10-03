#include<iostream>
#include<fstream>

#pragma pack(push,1)
struct Person{
    char name[50];
    int age;  
    double weight;
};
#pragma pack(pop)


int main()
{
    std::ofstream writer;
    writer.open("binary_file",std::ios_base::binary);
    if(!writer.is_open())
    {
        std::cout<<"Failed to open file"<<std::endl;
        return 1;
    }

    Person p = {"Frodo",25,90};
    writer.write(reinterpret_cast<char*>(&p),sizeof(Person));
    writer.close();

    std::ifstream reader;
    Person pRead;
    reader.open("binary_file",std::ios_base::binary);
    if(!reader.is_open())
    {
        std::cout<<"Failed to open file for reading"<<std::endl;
        return 2;
    }
    reader.read(reinterpret_cast<char*>(&pRead),sizeof(Person));
    std::cout<<"Name : "<<pRead.name<<std::endl;
    

}