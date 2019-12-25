//
// Created by dungpb on 25/12/2019.
//

#ifndef DICOM_EXTRACT_DICOM_H
#define DICOM_EXTRACT_DICOM_H

#include "core.h"

class Dicom {

public:
    std::string file_name;
    std::string patient_position;
    std::string uid;

    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);

    const std::string &getPatientPosition() const;

    void setPatientPosition(const std::string &patientPosition);

    const std::string &getUid() const;

    void setUid(const std::string &uid);

    const std::string &getSex() const;

    void setSex(const std::string &sex);

    const cv::Mat &getImgData() const;

    void setImgData(const cv::Mat &imgData);

    const cv::Mat &getImgVis() const;

    void setImgVis(const cv::Mat &imgVis);

    std::string sex;

private:
    cv::Mat img_data;
    cv::Mat img_vis;
};


#endif //DICOM_EXTRACT_DICOM_H
