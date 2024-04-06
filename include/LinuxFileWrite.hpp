#ifndef LINUX_FILE_WRITE_HPP
#define LINUX_FILE_WRITE_HPP
#include "constants.hpp"
class LinuxFileWrite
{
private:
    int fileDescriptor;
public:
    LinuxFileWrite(std::string fileName);
    ~LinuxFileWrite();
    int fWrite (int wordCount, char** dataToBeAppended);    
};

#endif // LINUX_FILE_WRITE_HPP