//
//  Reservoir.h
//  Constant member function, explicit constructor.
//
//  Created by Valeria Dudinova on 25.09.2024.
//

#ifndef RESERVOIR_H
#define RESERVOIR_H

class Reservoir
{
private:
    char* name;
    double width;
    double length;
    double maxDepth;
    char* type;

public:
    Reservoir();
    explicit Reservoir(const char* name, double width, double length, double maxDepth, const char* type);

    Reservoir(const Reservoir& other);

    ~Reservoir();

    void setName(const char* name);
    const char* getName() const;

    void setDimensions(double width, double length, double maxDepth);
    void getDimensions(double& width, double& length, double& maxDepth) const;

    void setType(const char* type);
    const char* getType() const;

    double calculateVolume() const;
    double calculateSurfaceArea() const;

    bool isSameType(const Reservoir& other) const;

    bool isLargerSurfaceArea(const Reservoir& other) const;

   
    Reservoir& operator=(const Reservoir& other);

  
    void displayInfo() const;
};

#endif 
