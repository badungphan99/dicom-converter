//
// Created by dungpb on 25/12/2019.
//

#include "dicom_extract.h"
#include "system_manager.h"

int dicom_extract::extract_info(const std::string &pathIn, std::vector<Dicom> &res) {
    std::vector<std::string> listFile;
    sysm::loadFile(pathIn, listFile);
    for(int i = 0; i < listFile.size(); i++){
        Dicom dicom;
        dicom_img_to_mat(pathIn, listFile[i], dicom);
        res.push_back(dicom);
    }
    return 0;
}

int dicom_extract::dicom_img_to_mat(const std::string &dirPath, const std::string &fileName, Dicom &res) {
    std::string imgPath = dirPath + "/" + fileName;
    DicomImage *image = new DicomImage(imgPath.c_str());
    DcmFileFormat fileformat;
    OFCondition status = fileformat.loadFile(imgPath.c_str());

    if (image->getStatus() == EIS_Normal) {

        image->setWindow(0);
        cv::Mat img(image->getHeight(), image->getWidth(), CV_16U, (long *) image->getOutputData(16));
        cv::normalize(img, img, 0, 255, cv::NORM_MINMAX);
        img.convertTo(img, CV_8UC1);
        res.setFileName(fileName);
        res.setImgData(img);
    } else {
        std::cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << "\n";
        std::cerr << "Path DICOM file: " << fileName << "\n";
        return 12;
    }
    delete image;
    return 0;
}
