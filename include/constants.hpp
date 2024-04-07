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
// const int ALL_PERMISSIONS = 0x0080| (0x0080 >> 3)  | ((0x0080 >> 3) >> 3);
const int ALL_PERMISSIONS = S_IWUSR | S_IWGRP | S_IWOTH;

enum class ErrorCodes {
    NO_ERROR = 0,
    INPUT_ERROR,
    NO_INPUT_ARGUMENTS,
    NO_FILE_NAME_NOR_WORDS,
    NO_WORDS_TO_BE_WRITTEN,
    INVALID_WRITE_OPTION,
    FAILED_TO_WRITE
};

#endif // CONSTANTS_HPP