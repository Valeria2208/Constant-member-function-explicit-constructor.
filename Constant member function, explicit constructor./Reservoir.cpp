//
//  Reservoir.cpp
//  Constant member function, explicit constructor.
//
//  Created by Valeria Dudinova on 25.09.2024.
//

#include "Reservoir.h"
#include <iostream>

using namespace std;

void copyString(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

Reservoir::Reservoir() : width(0), length(0), maxDepth(0)
{
    name = new char[8];
    copyString(name, "Unknown");

    type = new char[8];
    copyString(type, "Unknown");
}

Reservoir::Reservoir(const char* name, double width, double length, double maxDepth, const char* type)
    : width(width), length(length), maxDepth(maxDepth)
{
    int nameLen = 0, typeLen = 0;

    while (name[nameLen] != '\0') ++nameLen;
    this->name = new char[nameLen + 1];
    for (int i = 0; i < nameLen; ++i)
    {
        this->name[i] = name[i];
    }
    this->name[nameLen] = '\0';

    while (type[typeLen] != '\0') ++typeLen;
    this->type = new char[typeLen + 1];
    for (int i = 0; i < typeLen; ++i)
    {
        this->type[i] = type[i];
    }
    this->type[typeLen] = '\0';
}

Reservoir::Reservoir(const Reservoir& other) : width(other.width), length(other.length), maxDepth(other.maxDepth)
{
    int nameLen = 0, typeLen = 0;

    while (other.name[nameLen] != '\0') ++nameLen;
    name = new char[nameLen + 1];
    for (int i = 0; i < nameLen; ++i)
    {
        name[i] = other.name[i];
    }
    name[nameLen] = '\0';

    while (other.type[typeLen] != '\0') ++typeLen;
    type = new char[typeLen + 1];
    for (int i = 0; i < typeLen; ++i)
    {
        type[i] = other.type[i];
    }
    type[typeLen] = '\0';
}

Reservoir::~Reservoir()
{
    delete[] name;
    delete[] type;
}

void Reservoir::setName(const char* name)
{
    delete[] this->name;
    int nameLen = 0;
    while (name[nameLen] != '\0') ++nameLen;
    this->name = new char[nameLen + 1];
    for (int i = 0; i < nameLen; ++i)
    {
        this->name[i] = name[i];
    }
    this->name[nameLen] = '\0';
}

const char* Reservoir::getName() const
{
    return name;
}

void Reservoir::setDimensions(double width, double length, double maxDepth)
{
    this->width = width;
    this->length = length;
    this->maxDepth = maxDepth;
}

void Reservoir::getDimensions(double& width, double& length, double& maxDepth) const
{
    width = this->width;
    length = this->length;
    maxDepth = this->maxDepth;
}

void Reservoir::setType(const char* type)
{
    delete[] this->type;
    int typeLen = 0;
    while (type[typeLen] != '\0') ++typeLen;
    this->type = new char[typeLen + 1];
    for (int i = 0; i < typeLen; ++i)
    {
        this->type[i] = type[i];
    }
    this->type[typeLen] = '\0';
}

const char* Reservoir::getType() const
{
    return type;
}

double Reservoir::calculateVolume() const
{
    return width * length * maxDepth;
}

double Reservoir::calculateSurfaceArea() const
{
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const
{
    int i = 0;
    while (type[i] != '\0' && other.type[i] != '\0')
    {
        if (type[i] != other.type[i]) return false;
        ++i;
    }
    return type[i] == '\0' && other.type[i] == '\0';
}

bool Reservoir::isLargerSurfaceArea(const Reservoir& other) const
{
    if (isSameType(other))
    {
        return calculateSurfaceArea() > other.calculateSurfaceArea();
    }
    return false;
}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
    if (this == &other) return *this;

    delete[] name;
    delete[] type;

    width = other.width;
    length = other.length;
    maxDepth = other.maxDepth;

    int nameLen = 0, typeLen = 0;
    while (other.name[nameLen] != '\0') ++nameLen;
    name = new char[nameLen + 1];
    for (int i = 0; i < nameLen; ++i)
    {
        name[i] = other.name[i];
    }
    name[nameLen] = '\0';

    while (other.type[typeLen] != '\0') ++typeLen;
    type = new char[typeLen + 1];
    for (int i = 0; i < typeLen; ++i)
    {
        type[i] = other.type[i];
    }
    type[typeLen] = '\0';

    return *this;
}

void Reservoir::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Width: " << width << " м" << endl;
    cout << "Length: " << length << " м" << endl;
    cout << "Maximum depth: " << maxDepth << " м" << endl;
    cout << "Volume: " << calculateVolume() << " куб. м" << endl;
    cout << "Surface area: " << calculateSurfaceArea() << " кв. м" << endl;
}
