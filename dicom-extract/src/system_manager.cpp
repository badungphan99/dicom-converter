//
// Created by HUS-AutoConotur on 22/10/2019.
//

#include "system_manager.h"

int sysm::createDir(std::string &path) {
#ifdef _WIN32
    CreateDirectory(path.c_str(),NULL);
#endif
#ifdef __linux
    mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
#ifdef __APPLE__
    mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
    return 0;
}

int sysm::removeDir(std::string &path) {
    return 0;
}

int sysm::removeFile(std::string &path) {
    return 0;
}

int sysm::loadSubDir(std::string &path, std::vector<std::string> &res) {
    DIR *dir;
    struct dirent *ent = nullptr;
    res.clear();
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            if (ent->d_type == DT_DIR) {
                std::string path = ent->d_name;
                if (path.substr(0, 1) == ".") {
                    continue;
                }if (path.substr(0, 1) == "_") {
                    continue;
                }
                res.push_back(std::string(ent->d_name));
            }
        }
    } else {
        std::cerr << "ERROR: Cannot load sub directory: " << path << "\n";
    }
    delete ent;
    closedir(dir);
    return 0;
}

int sysm::loadFile(const std::string &path, std::vector<std::string> &res) {
//    std::cout << path << "\n";
    DIR *dir;
    struct dirent *ent;
    res.clear();
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            std::string path = ent->d_name;
            if (path.substr(0, 1) == ".") {
                continue;
            }
            res.push_back(std::string(ent->d_name));
        }
    } else {
        std::cerr << "ERROR: Could not load file: " << path << "\n";
    }
    delete ent;
    closedir(dir);
    return 0;
}

int sysm::writeInfo(std::string &path, std::string content, bool overWrite) {
    std::ofstream outfile;
    if(overWrite)
    {
        outfile.open(path);
        outfile.close();
    } else {
        outfile.open(path, std::ios_base::app);
        outfile << content << "\n";
        outfile.close();
    }

    return 0;
}
