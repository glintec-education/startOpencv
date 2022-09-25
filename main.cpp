#include <QCoreApplication>

#include "opencv2/opencv.hpp"
//#include "opencv4/opencv2/opencv_modules.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/core/core.hpp"
//#include "opencv2/imgproc.hpp"

#include <QDebug>

using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat img = imread("/home/glintec/Documents/repoProg/Qt/opencvTest/Glintec.jpg");
//    Mat img = imread("/home/glintec/Pictures/firmaADGS.png");
//    namedWindow("my logo");
    imshow("my logo",img);

    Mat imHSV, imbgr;
    Mat seg;

    int numCam=0;
    for(int i=0; i<10; i++){
        VideoCapture camara(i);
        if(camara.isOpened()){
            numCam++;
            qDebug()<<"Encontrada " << i;
        }
        camara.release();
    }
    qDebug()<<"\n\n Numero de Camaras "<<numCam;

//    VideoCapture camera(ui->SBox_CameraIdx->value());
         VideoCapture camera(0);


    if (!camera.isOpened()){
        printf("falla al abrir el dispositivo\n");
    }

    /* para conocer las resoluciones que maneja la cámara
     * lsusb
     * lsusb -s 001:010 | egrep "Width|Height"
     */

//        camera.set(CAP_PROP_FRAME_HEIGHT,800);
//        camera.set(CAP_PROP_FRAME_WIDTH,600);
    camera.set(CAP_PROP_FRAME_HEIGHT,480);
    camera.set(CAP_PROP_FRAME_WIDTH,640);
//        camera.set(CAP_PROP_FRAME_HEIGHT,240);
//        camera.set(CAP_PROP_FRAME_WIDTH,320);



//        namedWindow("gray",WINDOW_AUTOSIZE);
//        Mat imageUndistorted;

   char key = 0;
    while (key != 'q' /*|| !closeApp*/ ){

        camera >> imbgr;

//        if(saveImg){
//            imwrite("/home/glintec/Documents/recovery/Visual_Measure/imgCalib.jpg",imbgr);

//            Mat foto = imread("/home/glintec/Documents/recovery/Visual_Measure/imgCalib.jpg");
//            saveImg=false;
//            QThread::msleep(3000);
//        }

        cvtColor(imbgr,imHSV,COLOR_BGR2HSV);

//        Mat binaria;
//        threshold(gris,binaria,200,255,THRESH_OTSU+THRESH_BINARY_INV);

//            imshow("BINARIA",binaria);
//            imshow("Imagen RGB",Recortada); moveWindow("Imagen RGB",800,0);
//            imshow("gris", unDisImaROI);

        imshow("HSV",imHSV);

         key = waitKey(25);
    }




//    waitKey(5000);
    return a.exec();
}
