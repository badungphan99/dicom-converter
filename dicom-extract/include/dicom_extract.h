//
// Created by dungpb on 25/12/2019.
//

#ifndef DICOM_EXTRACT_DICOM_EXTRACT_H
#define DICOM_EXTRACT_DICOM_EXTRACT_H

#include "core.h"
#include "dicom.h"

namespace dicom_extract {

    /**
     * @brief extract infomation from dicom package to image and text file
     * @param pathIn:
     * @param pathOut
     * @param info
     * @param saveImg
     * @param saveInfo
     * @return
     */
    int extract_info(const std::string &pathIn, const std::string &pathOut, std::string &info, const int &saveImg, const int &saveInfo);

    /**
     * @brief convert dicom image to OpenCV Mat
     * @param dirPath
     * @param fileName
     * @param res
     * @return
     */
    int dicom_img_to_mat(const std::string &dirPath, const std::string &fileName, Dicom &res);

//    int convert_rt_to_mat(const std::string &path_rt_file, )
};


#endif //DICOM_EXTRACT_DICOM_EXTRACT_H
