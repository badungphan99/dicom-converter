//
// Created by dungpb on 25/12/2019.
//

#ifndef DICOM_EXTRACT_DICOM_H
#define DICOM_EXTRACT_DICOM_H

#include "core.h"

class Dicom {

private:
    std::string file_name;
    std::string patient_position;
    std::string uid;
    std::string sex;
    std::string patient_id;
    std::string photometric_nterpretation;
    std::string bits_allocated;
    std::string bits_stored;
    std::string high_bit;

private:
    cv::Mat img_data;
    cv::Mat img_vis;

public:
    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);

    const std::string &getPatientPosition() const;

    void setPatientPosition(const std::string &patientPosition);

    const std::string &getUid() const;

    void setUid(const std::string &uid);

    const std::string &getSex() const;

    void setSex(const std::string &sex);

    const std::string &getPatientId() const;

    void setPatientId(const std::string &patientId);

    const std::string &getPhotometricNterpretation() const;

    void setPhotometricNterpretation(const std::string &photometricNterpretation);

    const std::string &getBitsAllocated() const;

    void setBitsAllocated(const std::string &bitsAllocated);

    const std::string &getBitsStored() const;

    void setBitsStored(const std::string &bitsStored);

    const std::string &getHighBit() const;

    void setHighBit(const std::string &highBit);

    const cv::Mat &getImgData() const;

    void setImgData(const cv::Mat &imgData);

    const cv::Mat &getImgVis() const;

    void setImgVis(const cv::Mat &imgVis);


};


#endif //DICOM_EXTRACT_DICOM_H
