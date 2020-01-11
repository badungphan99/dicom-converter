//
// Created by dungpb on 25/12/2019.
//

#include <opencv2/imgcodecs.hpp>
#include "../include/dicom_extract.h"
#include "../include/system_manager.h"

int dicom_extract::extract_info(const std::string &pathIn, std::string &pathOut, std::vector<Dicom> &res) {

    pathOut = "/tmp/dungpbhoangnvcucntkhanhptt";

    sysm::createDir(pathOut);

    std::vector<std::string> listFile;
    sysm::loadFile(pathIn, listFile);
    for(int i = 0; i < listFile.size(); i++){
        Dicom dicom;
        dicom_img_to_mat(pathIn, listFile[i], dicom);
        std::string pathImg = pathOut + "/" + listFile[i] + ".png";
        cv::imwrite(pathImg, dicom.getImgData());
//        std::cout << pathImg << "\n";
        res.push_back(dicom);
    }
    return 0;
}

int dicom_extract::dicom_img_to_mat(const std::string &dirPath, const std::string &fileName, Dicom &res) {
    std::string imgPath = dirPath + "/" + fileName;
    DicomImage *image = new DicomImage(imgPath.c_str());
    DcmFileFormat fileformat;
    DcmDataset dataset;

    OFCondition status = fileformat.loadFile(imgPath.c_str());
    dataset = DcmDataset(*fileformat.getDataset());

    if (image->getStatus() == EIS_Normal) {
        OFString patient_position;
        OFString uid;
        OFString sex;
        OFString patient_id;
        OFString photometric_nterpretation;
        OFString bits_allocated;
        OFString bits_stored;
        OFString high_bit;

        dataset.findAndGetOFString(DCM_PatientPosition, patient_position);
        dataset.findAndGetOFStringArray(DCM_SOPInstanceUID, uid);
        dataset.findAndGetOFString(DCM_PatientSex, sex);
        dataset.findAndGetOFString(DCM_PatientID, patient_id);
        dataset.findAndGetOFString(DCM_PhotometricInterpretation, photometric_nterpretation);
        dataset.findAndGetOFString(DCM_BitsAllocated, bits_allocated);
        dataset.findAndGetOFString(DCM_BitsStored, bits_stored);
        dataset.findAndGetOFString(DCM_HighBit, high_bit);

        image->setWindow(0);
        cv::Mat img(image->getHeight(), image->getWidth(), CV_16U, (long *) image->getOutputData(16));
        cv::normalize(img, img, 0, 255, cv::NORM_MINMAX);
        img.convertTo(img, CV_8UC1);
        res.setFileName(fileName);
        res.setImgData(img);
        res.setPatientPosition(patient_position.c_str());
        res.setUid(uid.c_str());
        res.setSex(sex.c_str());
        res.setPatientId(patient_id.c_str());
        res.setPhotometricNterpretation(photometric_nterpretation.c_str());
        res.setBitsAllocated(bits_allocated.c_str());
        res.setBitsStored(bits_stored.c_str());
        res.setHighBit(high_bit.c_str());

    } else {
        std::cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << "\n";
        std::cerr << "Path DICOM file: " << fileName << "\n";
        return 12;
    }
    delete image;
    return 0;
}
