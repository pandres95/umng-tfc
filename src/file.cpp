#include <sys/stat.h>
#include "file.h"

bool File::exists(std::string filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}
