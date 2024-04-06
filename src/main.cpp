#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "../include/constants.hpp"

class LinuxOptionFileWrite
{
private:
    int fileDescriptor;
public:
    LinuxOptionFileWrite(std::string fileName)
    {   
        fileDescriptor = open(fileName.c_str(), O_WRONLY | O_APPEND | O_CREAT, ALL_PERMISSIONS);
        if (FILE_FUNC_ERROR == fileDescriptor)
        {   
            std::cerr << "Failed to open or create a file: " << strerror(errno) << std::endl;
        }    
    }

    ~LinuxOptionFileWrite()
    {
        if (FILE_FUNC_ERROR == close(fileDescriptor))
        {
            std::cerr << "Failed to close a file: " << strerror(errno) << std::endl;
        }        
    }

    int fWrite (int wordCount, char** dataToBeAppended){
        int retVal = NO_ERROR;
        std::string dataAsString; 
        for (size_t i = 0; i < wordCount; i++)
        {
            dataAsString = std::string(dataToBeAppended[i]) + "\n";
            if (FILE_FUNC_ERROR == write(fileDescriptor, dataAsString.c_str(), dataAsString.size()))
            {
                std::cerr << "Failed to write a word \"" << dataToBeAppended[i] << "\" to a file\t" << strerror(errno) << std::endl;
                retVal = FAILED_TO_WRITE;
            }
        }
        return retVal; //added for scalability
    }
};

class WindowsOptionFileWrite
{
private:
    std::ofstream fileToWrite;
public:
    WindowsOptionFileWrite(std::string fileName);
    ~WindowsOptionFileWrite();
    int fWrite(int wordCount, char** dataToBeAppended);
};

WindowsOptionFileWrite::WindowsOptionFileWrite(std::string fileName)
{
    fileToWrite.open(fileName, std::ios_base::app | std::ios_base::out);
    if (!fileToWrite.is_open())
    {
        std::cerr << "Failed to open or create a file: " << strerror(errno) << std::endl;
    }
}

WindowsOptionFileWrite::~WindowsOptionFileWrite()
{
    if (fileToWrite.is_open())
    {
        fileToWrite.close();
    }    
}

WindowsOptionFileWrite::fWrite(int wordCount, char** dataToBeAppended)
{   
    int retVal = NO_ERROR;    
    for (size_t i = 0; i < wordCount; i++)
    {
        fileToWrite << dataToBeAppended[i] << std::endl;
        if (fileToWrite.fail())
        {
            std::cerr << "Failed to write a word \"" << dataToBeAppended[i] << "\" to a file\t" << strerror(errno) << std::endl;
            retVal = FAILED_TO_WRITE;
        }        
    }
    return retVal;  //added for scalability
}

int main(int argc, char* argv[])
{   
    if (argc < MINIMAL_VALID_VALUE_OF_ARGUMENTS)    //incorrect amount of arguments 
    {
        switch (argc)
        {
        case 0:
            std::cerr << "Error, not even a path included!" << std::endl;
            return INPUT_ERROR;
            break;
        case 1:
            std::cerr << "No arguments inserted." <<std::endl;
            return NO_INPUT_ARGUMENTS;
            break;
        case 2:
           std::cerr << "Only write option entered." <<std::endl;
            return NO_FILE_NAME_NOR_WORDS;
            break;
        case 3:
           std::cerr << "Only the save option and file have been selected." <<std::endl;
            return NO_WORDS_TO_BE_WRITTEN;
            break;
        }        
    }

    std::string option = argv[ACCESS_OPTION];   //chosen option 0 - linux, 1 - windows
    std::string fileName = argv[FILE_NAME];
    int wordCount = argc - THINGS_OTHER_THAN_WORDS;
    char** dataToBeAppended = argv + THINGS_OTHER_THAN_WORDS;    

    if ("0" == option || "linux" == option) {          
        LinuxOptionFileWrite appendingOperationL(fileName);
        appendingOperationL.fWrite (wordCount, dataToBeAppended);
    }
    else if ("1" == option || "windows" == option) {
        WindowsOptionFileWrite appendingOperationW(fileName);
        appendingOperationW.fWrite (wordCount, dataToBeAppended);
    } else {
        std::cerr << "Wrong write option selected." << std::endl;
        return INVALID_WRITE_OPTION;
    }    

    return NO_ERROR;
}