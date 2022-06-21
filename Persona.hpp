#ifndef PERSONA_H
#define PERSONA_H

#include "Detector.hpp"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

class Persona
{
private:
    int xComienzo;
    int yComienzo;
    int xFin;
    int yFin;
    double xCentro;
    double yCentro;
public:
    Persona(cv::Rect&);

    int getXComienzo();
    int getYComienzo();
    int getXFin();
    int getYFin();
    double getXCentro();
    double getYCentro();
};

#endif