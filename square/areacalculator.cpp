#include "areacalculator.h"
#include <cmath>

double AreaCalculator::CalculateSquare (double lenght)
{
    return lenght*lenght;
}

double AreaCalculator::CalculateRectangle (double lenght, double width)
{
    return lenght*width;
}

double AreaCalculator::CalculateParallelogram (double lenght, double height)
{
    return lenght*height;
}

double AreaCalculator::CalculateRhombus (double lenght, double height)
{
    return lenght*height;
}

double AreaCalculator::CalculateTriangle (double lenght, double heigth)
{
    return lenght*heigth/2;
}

double AreaCalculator::CalculateTrapezoid (double lenght, double lenght2, double heigth)
{
    return (lenght+lenght2)*heigth/2;
}

double AreaCalculator::CalculateCircle (double radius)
{
    return radius*radius*M_PI;
}

double AreaCalculator::CalculateSector (double radius, double angle)
{
    return radius*radius*M_PI*angle/360;
}
