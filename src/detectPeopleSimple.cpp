// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;

class Detector
{
    //Atributos (Privados)
    // Enumerador {algoritmos que utilizo para detectar personas}
    enum Mode { Default, Daimler } m;//el tipo de dato se llamara "m",es un tipo de enumerador
    // Algoritimo de deteccion de personas
    HOGDescriptor hog, hog_d;

public:
    //m tomara el valor default,el hog_d->el tamaño de busqueda de iamgen sera de tamaño..
    Detector() : m(Default), hog(), hog_d(Size(48, 96), Size(16, 16), Size(8, 8), Size(8, 8), 9){
        hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());//
        hog_d.setSVMDetector(HOGDescriptor::getDaimlerPeopleDetector());
    }    
    //Va a seleccionar el modo de deteccion del algoritmo//si es default sera daimler y viceversa
    void toggleMode() { m = (m == Default ? Daimler : Default); }
    //es para saber en que modo estoy
    string modeName() const { return (m == Default ? "Default" : "Daimler"); }

    vector<Rect> detect(InputArray img){
        // Run the detector with default parameters. to get a higher hit-rate
        // (and more false alarms, respectively), decrease the hitThreshold and
        // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
        vector<Rect> found;
        if (m == Default)
            hog.detectMultiScale(img, found, 0, Size(2,2), Size(4,4), 1.05, 2, false);
        else if (m == Daimler)
            hog_d.detectMultiScale(img, found, 0, Size(4,4), Size(8,8), 1.01, 3, true);

        // Convierto los objetos Rect a Persona
        
            
        return found;
    }

    void adjustRect(Rect & r) const{
        // The HOG detector returns slightly larger rectangles than the real objects,
        // so we slightly shrink the rectangles to get a nicer output.
        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
    }

};

int main(int argc, char** argv)
{

    // Es una clase que tiene metodos para detectar personas
    Detector detector;
    // Declaro una estructura de tipo matriz (Mat)
    Mat imagen;
    // Cargo la estructura de datos con una imagen
    imagen = imread("/home/jbekios/CODE/opencvTests/personas.png");

    // Cambia el tipo de algoritmo de deteccion de personas
    //detector.toggleMode();

    // Ejecuto el detector llamando al metodo detect
    vector<Rect> found = detector.detect(imagen);

    // Recorrer el vector, obtener el rectangulo y dibujar un rectangulo en la imagen
    //Voy a crear un iterador de tipo vector que se llama "i",
    //obtengo el puntero del inicio del vector y hasta del final
    for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i)
    {
        //Voy obtebiendo los rectangulos y los dibujo arriba de la imagen
        Rect &r = *i;
        cout << r << endl;
        // Los puntos de deteccion que hace el algoritmo muy grande
        detector.adjustRect(r);//Ajusta los puntos de deteccion
        // Dibujar el rectangulo
        rectangle(imagen, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
        //paso la imagen
        //dibuja el rectangulo
    }

    imshow("People detector", imagen);//creo el cuadro con la imagen
    waitKey(0);

    return 0;
}