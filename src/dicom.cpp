//
// Created by dungpb on 25/12/2019.
//

#include "dicom.h"

const std::string &Dicom::getFileName() const {
    return file_name;
}

void Dicom::setFileName(const std::string &fileName) {
    file_name = fileName;
}

const std::string &Dicom::getPatientPosition() const {
    return patient_position;
}

void Dicom::setPatientPosition(const std::string &patientPosition) {
    patient_position = patientPosition;
}

const std::string &Dicom::getUid() const {
    return uid;
}

void Dicom::setUid(const std::string &uid) {
    Dicom::uid = uid;
}

const std::string &Dicom::getSex() const {
    return sex;
}

void Dicom::setSex(const std::string &sex) {
    Dicom::sex = sex;
}

const cv::Mat &Dicom::getImgData() const {
    return img_data;
}

void Dicom::setImgData(const cv::Mat &imgData) {
    img_data = imgData;
}

const cv::Mat &Dicom::getImgVis() const {
    return img_vis;
}

void Dicom::setImgVis(const cv::Mat &imgVis) {
    img_vis = imgVis;
}
