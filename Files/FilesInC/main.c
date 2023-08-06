#include<stdio.h>

int WriteToFile(const char * content,const char * fileName)
{
    int bytesWritten = 0 ;
    int fileSize = 0;
    FILE * fp = fopen(fileName,"a");
    if(fp == NULL)
    {
        printf("File could not be opened!\n");
        return -1;
    }
    else
    {
        printf("%s open success\n",fileName);
    }
    
    fileSize = ftell(fp);
    printf("File size is %d\n",fileSize);

    bytesWritten = fprintf(fp,"%s",content);
    fclose(fp);
    printf("%d Bytes Written\n",bytesWritten);
    return bytesWritten;
}

int main(int argC , char ** argV)
{
    WriteToFile("Line no 1\n","/home/rohit/Code/CPPAdv/abc.txt");
    WriteToFile("Line no 2.\n","/home/rohit/Code/CPPAdv/abc.txt");
    return 0;
}