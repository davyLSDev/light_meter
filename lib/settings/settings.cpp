#include "settings.h"
using namespace std;

settings::settings()
{
    // Defaults . . .
    apertureIDX = 8;
    apertureDeltaIDX = 0;
    isoIDX = 8;
    isoDeltaIDX = 0;
    shutterIDX = 3;
    shutterDeltaIDX = 0;
    aperture = 16;
    iso = 100.0;
    shutter = "1/125";
    numberOfSettings = 3; // aperture, iso, shutter
    // later add: display brightness, choice of meter style
//    getInitialVariableValues();
}

void settings::setup (float potentiometerReading)
{
    for ( int i = 0; i < numberOfSettings; i++ )
    {
        lastSettingValue[i] = 300.0 ; // potentiometerReading;
        settingValue[i] = potentiometerReading;
    }
    apertureDeltaIDX = 0;
    isoDeltaIDX = 0;
    shutterDeltaIDX = 0;
}

float settings::getLastSetting (int settingNumber)
{
    return lastSettingValue[settingNumber];
}

void settings::setIso (double isoValue)
{
    iso = isoValue;
}

double settings::getAperture ()
{
    return aperture = apertureTable[apertureIDX];
}

double settings::getIso ()
{
    return iso = isoTable[isoIDX];
}

String settings::getShutter ()
{
    return shutter = shutterTable[shutterIDX];
}