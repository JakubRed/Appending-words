#include "../include/constants.hpp"
#include "../include/LinuxFileWrite.hpp"
#include "../include/WindowsFileWrite.hpp"
// #include "WindowsFileWrite.cpp"
// #include "LinuxFileWrite.cpp"
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
        LinuxFileWrite appendingOperationL(fileName);
        appendingOperationL.fWrite (wordCount, dataToBeAppended);
    }
    else if ("1" == option || "windows" == option) {
        WindowsFileWrite appendingOperationW(fileName);
        appendingOperationW.fWrite (wordCount, dataToBeAppended);
    } else {
        std::cerr << "Wrong write option selected." << std::endl;
        return INVALID_WRITE_OPTION;
    }

    return NO_ERROR;
}