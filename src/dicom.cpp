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

const std::string &Dicom::getPatientId() const {
    return patient_id;
}

void Dicom::setPatientId(const std::string &patientId) {
    patient_id = patientId;
}

const std::string &Dicom::getPhotometricNterpretation() const {
    return photometric_nterpretation;
}

void Dicom::setPhotometricNterpretation(const std::string &photometricNterpretation) {
    photometric_nterpretation = photometricNterpretation;
}

const std::string &Dicom::getBitsAllocated() const {
    return bits_allocated;
}

void Dicom::setBitsAllocated(const std::string &bitsAllocated) {
    bits_allocated = bitsAllocated;
}

const std::string &Dicom::getBitsStored() const {
    return bits_stored;
}

void Dicom::setBitsStored(const std::string &bitsStored) {
    bits_stored = bitsStored;
}

const std::string &Dicom::getHighBit() const {
    return high_bit;
}

void Dicom::setHighBit(const std::string &highBit) {
    high_bit = highBit;
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
