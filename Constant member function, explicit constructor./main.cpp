//
//  main.cpp
//  Constant member function, explicit constructor.
//
//  Created by Valeria Dudinova on 25.09.2024.
//

#include "Reservoir.h"
#include <iostream>

using namespace std;

int main()
{
    Reservoir lake("Great Lake", 500, 200, 30, "озеро");

    Reservoir copyLake(lake);

    copyLake.setName("Small Lake");
    copyLake.setDimensions(300, 150, 20);
    copyLake.setType("озеро");

    cout << "Information about reservoirs:\n";
    lake.displayInfo();
    cout << endl;
    copyLake.displayInfo();

    if (lake.isLargerSurfaceArea(copyLake))
    {
        cout << "\nGreat Lake has a large water surface area.\n";
    } else {
        cout << "\nSmall Lake has a large or equal water surface area.\n";
    }

    if (lake.isSameType(copyLake))
    {
        cout << "\nBoth reservoirs are recognized as lakes.\n";
    } else {
        cout << "\nDifferent types of reservoirs.\n";
    }

    return 0;
}
