#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <sys/stat.h> 

const int MINIMAL_VALID_VALUE_OF_ARGUMENTS = 4;
const int ACCESS_OPTION = 1;
const int FILE_NAME = 2;
const int FILE_FUNC_ERROR = -1;
const int THINGS_OTHER_THAN_WORDS = 3;
const int ALL_PERMISSIONS = 0x0080| (0x0080 >> 3)  | ((0x0080 >> 3) >> 3);

//error codes
const int NO_ERROR = 0;
const int INPUT_ERROR = 1;
const int NO_INPUT_ARGUMENTS = 2;
const int NO_FILE_NAME_NOR_WORDS = 3;
const int NO_WORDS_TO_BE_WRITTEN = 4;
const int INVALID_WRITE_OPTION = 5;
const int FAILED_TO_WRITE = 6;

#endif // CONSTANTS_HPP