#include "../include/LinuxFileWrite.hpp"
#include <io.h>

LinuxFileWrite::LinuxFileWrite(std::string fileName)
{   
    fileDescriptor = open(fileName.c_str(), O_WRONLY | O_APPEND | O_CREAT, ALL_PERMISSIONS);
    if (FILE_FUNC_ERROR == fileDescriptor)
    {   
        std::cerr << "Failed to open or create a file: " << strerror(errno) << std::endl;
    }    
}

LinuxFileWrite::~LinuxFileWrite()
{
    if (FILE_FUNC_ERROR == close(fileDescriptor))
    {
        std::cerr << "Failed to close a file: " << strerror(errno) << std::endl;
    }        
}

ErrorCodes LinuxFileWrite:: fWrite (int wordCount, char** dataToBeAppended){
    ErrorCodes retVal = ErrorCodes::NO_ERROR;
    std::string dataAsString; 
    for (size_t i = 0; i < wordCount; i++)
    {
        dataAsString = std::string(dataToBeAppended[i]) + "\n";
        if (FILE_FUNC_ERROR == write(fileDescriptor, dataAsString.c_str(), dataAsString.size()))
        {
            std::cerr << "Failed to write the word \"" << dataToBeAppended[i] << "\" to a file\t" << strerror(errno) << std::endl;
            retVal = ErrorCodes::FAILED_TO_WRITE;
        }
    }
    return retVal; //added for scalability
}