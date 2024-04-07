#ifndef WINDOWS_FILE_WRITE_HPP
#define WINDOWS_FILE_WRITE_HPP

#include "constants.hpp"

class WindowsFileWrite
{
private:
    std::ofstream fileToWrite;
public:
    WindowsFileWrite(std::string fileName);
    ~WindowsFileWrite();
    ErrorCodes fWrite(int wordCount, char** dataToBeAppended);
};

#endif // WINDOWS_FILE_WRITE_HPP