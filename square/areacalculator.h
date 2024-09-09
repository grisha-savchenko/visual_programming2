#ifndef AREACALCULATOR_H
#define AREACALCULATOR_H


class AreaCalculator
{
public:
    double CalculateSquare (double lenght);
    double CalculateRectangle (double lenght, double width);
    double CalculateParallelogram (double lenght, double height);
    double CalculateRhombus (double lenght, double height);
    double CalculateTriangle (double lenght, double heigth);
    double CalculateTrapezoid (double lenght, double lenght2, double heigth);
    double CalculateCircle (double radius);
    double CalculateSector (double radius, double angle);
};


#endif // AREACALCULATOR_H
