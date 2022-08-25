// AtmController.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "AtmController.h"
#include <iostream>

using namespace std;


// This is an example of an exported variable
ATMCONTROLLER_API int nAtmController=0;

// This is an example of an exported function.
ATMCONTROLLER_API int fnAtmController(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CAtmController::CAtmController()
{
    return;
}

void CAtmController::foo()
{
    cout << "foo" << endl;
}

int CAtmController::sayFive()
{
    return 5;
}

bool CAtmController::isAlive()
{
    return false;
}
