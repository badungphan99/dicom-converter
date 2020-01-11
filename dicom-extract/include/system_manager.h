//
// Created by HUS-AutoConotur on 22/10/2019.
//

#ifndef AUTOCONTOUR_SYSTEM_MANAGER_H
#define AUTOCONTOUR_SYSTEM_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>

#ifdef __linux__
#include <dirent.h>
#include <sys/stat.h>
#endif
#ifdef _WIN32
#include "dirent/dirent.h"
#include <windows.h>
#endif
#ifdef __APPLE__
#include <sys/stat.h>
#include <dirent.h>
#endif

namespace sysm {
    int createDir(std::string &path);

    int removeDir(std::string &path);

    int removeFile(std::string &path);

    int loadSubDir(std::string &path, std::vector<std::string> &res);

    int loadFile(const std::string &path, std::vector<std::string> &res);

    int writeInfo(std::string &path, std::string content, bool overWrite = false);
};


#endif //DICOM_EXTRACT_SYSTEM_MANAGER_H
