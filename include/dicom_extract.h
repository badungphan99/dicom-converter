//
// Created by dungpb on 25/12/2019.
//

#ifndef DICOM_EXTRACT_DICOM_EXTRACT_H
#define DICOM_EXTRACT_DICOM_EXTRACT_H

#include "core.h"
#include "dicom.h"

namespace dicom_extract {

    /**
     * @brief
     * @param pathIn
     * @param pathOut
     * @param res
     * @return
     */
    int extract_info(const std::string &pathIn, std::string &pathOut, std::vector<Dicom> &res);

    /**
     * @brief convert dicom image to OpenCV Mat
     * @param dirPath
     * @param fileName
     * @param res
     * @return
     */
    int dicom_img_to_mat(const std::string &dirPath, const std::string &fileName, Dicom &res);

//    int convert_rt_to_mat(std::string &pathRT, std::map<OFString, std::pair<DcmDataset, std::string>> &SOPInstances,
//                          std::vector<Dicom> &res);
//
//    int getRoiNames(DcmDataset &dataset, std::vector<OFString> &res);


};


#endif //DICOM_EXTRACT_DICOM_EXTRACT_H
