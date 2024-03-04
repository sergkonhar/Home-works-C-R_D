#include <iostream>
#include "Vectors.h"
#include <string>
#include "Vector3d.h"

std::string vectorPositionString(VectorRelativeState state);

int main()
{
    Vector2d firstVector(12.2f, 41.9f, 1.4f, 23.f);
    Vector2d secondVector(21.2f, 11.9f, 7.f, 3.f);
    Vector2d thirdVector;
  
    std::cout << std::endl;
    Vector2d testVectorOne = firstVector - secondVector;
    std::cout << testVectorOne();
    std::cout << std::endl;

    Vector2d testVectorTwo = firstVector + secondVector;
    std::cout << testVectorTwo() << std::endl;

    std::cout << std::endl;
    std::cout << "Vector 2d instances: " << Vector2d::getInstanceCount() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << secondVector[0] <<", " << secondVector[1] << ", " << secondVector[2] << ", " << secondVector[3];
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "First and second vector scalar product " << firstVector.dotProduct(secondVector);
    std::cout << std::endl;

    Vector2d fourthVector(firstVector.negate());

    std::cout << std::endl;
    std::cout << fourthVector;
    std::cout << std::endl;

    Vector2d directionVectorOne(5.f, 5.f, 0.f, 5.f);
    Vector2d directionVectorTwo(0.f, 5.f, 5.f, 5.f);
    Vector2d directionVectorThree(5.f, 5.f, 0.f, 5.f);
    Vector2d directionVectorFour(4.f, 4.f, 0.f, 4.f);
    Vector2d directionVectorFive(0.f, 4.f, 0.f, 0.f);
    Vector2d directionVectorSix(2.f, 4.f, 0.f, 0.f);
    Vector2d directionVectorSeven(-2.f, -4.f, 0.f, 0.f);

    std::cout << std::endl;
    std::cout << "Vector's relative state " << vectorPositionString(directionVectorOne.getRelativeState(directionVectorTwo));
    std::cout << std::endl;
    std::cout << "Vector's relative state " << vectorPositionString(directionVectorOne.getRelativeState(directionVectorThree));
    std::cout << std::endl;
    std::cout << "Vector's relative state " << vectorPositionString(directionVectorOne.getRelativeState(directionVectorFour));
    std::cout << std::endl;
    std::cout << "Vector's relative state " << vectorPositionString(directionVectorOne.getRelativeState(directionVectorFive));
    std::cout << std::endl;
    std::cout << "Vector's relative state " << vectorPositionString(directionVectorOne.getRelativeState(directionVectorSix));
    std::cout << std::endl;
    std::cout << "Vector's relative state " << vectorPositionString(directionVectorOne.getRelativeState(directionVectorSeven));
    std::cout << std::endl;

    Vector3d vectorOne(22.f, 22.f, 11.f, 0.f, 0.f, 0.f);
    Vector3d vectorTwo(12.f, 16.f, -3.f, 0.f, 0.f, 0.f);

    Vector3d vectorThree = vectorOne.crossProduct(vectorTwo);
    
    std::cout << std::endl;
    std::cout << "Vector cross production " << vectorThree.getCoordinates();
    std::cout << std::endl;
}

std::string vectorPositionString(VectorRelativeState state) 
{
    if (state== VectorRelativeState::Identical)
    {
        return "Identical";
    }

    else if (state == VectorRelativeState::coDirected)
    {
        return "Co-directed";
    }

    else if (state == VectorRelativeState::OppositeDirected)
    {
        return "Opposite directed";
    }

    else if (state == VectorRelativeState::AcuteAngle)
    {
        return "Acute angle";
    }

    else if (state == VectorRelativeState::ObtuseAngle)
    {
        return "Obtuse angle";
    }

    else if (state == VectorRelativeState::RightAngle)
    {
        return "Right angle";
    }

}