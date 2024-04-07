#include "../include/WindowsFileWrite.hpp"

WindowsFileWrite::WindowsFileWrite(std::string fileName)
{
    fileToWrite.open(fileName, std::ios_base::app | std::ios_base::out);
    if (!fileToWrite.is_open())
    {
        std::cerr << "Failed to open or create a file: " << strerror(errno) << std::endl;
    }
}

WindowsFileWrite::~WindowsFileWrite()
{
    if (fileToWrite.is_open())
    {
        fileToWrite.close();
    }
}

ErrorCodes WindowsFileWrite::fWrite(int wordCount, char** dataToBeAppended)
{   
    ErrorCodes retVal = ErrorCodes::NO_ERROR;    
    for (size_t i = 0; i < wordCount; i++)
    {
        fileToWrite << dataToBeAppended[i] << std::endl;
        if (fileToWrite.fail())
        {
            std::cerr << "Failed to write the word \"" << dataToBeAppended[i] << "\" to a file\t" << strerror(errno) << std::endl;
            retVal = ErrorCodes::FAILED_TO_WRITE;
        }        
    }
    return retVal;  //added for scalability
}