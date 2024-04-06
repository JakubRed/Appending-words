#include <sys/stat.h> 

const int MINIMAL_VALID_VALUE_OF_ARGUMENTS = 4;
const int ACCESS_OPTION = 1;
const int FILE_NAME = 2;
const int FILE_FUNC_ERROR = -1;
const int THINGS_OTHER_THAN_WORDS = 3;
const int ALL_PERMISSIONS = S_IWUSR | S_IWGRP | S_IWOTH;

//errorcodes //CHECK IF THERE ARE SOME CREATED
const int NO_ERROR = 0;
const int INPUT_ERROR = 1;
const int NO_INPUT_ARGUMENTS = 2;
const int NO_FILE_NAME_NOR_WORDS = 3;
const int NO_WORDS_TO_BE_WRITTEN = 4;
const int INVALID_WRITE_OPTION = 5;
const int FAILED_TO_WRITE = 6;