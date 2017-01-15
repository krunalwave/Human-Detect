#ifndef HUMANDETECT_H
#define HUMANDETECT_H

#include <QtGui>
#include <QString>
#include <QVector>
#include <QRect>
#include <QTimer>
#include <cv.h>
#include <highgui.h>

class HumanDetect
{
public:
    HumanDetect();
    ~HumanDetect();
    void setCascadeFile(QString cascadeFile);
    QString cascadeName() const;
    void setFlags(int flags);
    QVector<QRect> detectBody(IplImage *cvImage);
    CvRect region;
    IplImage *bodyImage;

private:
    CvHaarClassifierCascade *cascade;




    CvMemStorage *storage;
    int flags;
    QString cascadeFile;


    /***********************/

    QString cascadeFile_palm;
    QString cascadeFile_fist;

    CvHaarClassifierCascade *cascadepalm;
    CvHaarClassifierCascade *cascadefist;



    /***********************/




    QTimer saveTimer;
    CvSize size;


};

#endif // HUMANDETECT_H
