#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1


// Geant4 Libraries
//
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Cache.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Ellipsoid.hh"
#include "G4Tubs.hh"
#include "G4OpticalSurface.hh"


// Local Libraries
//
//#include "PMTSD.hh"

class G4LogicalVolume; 


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

  public:
    virtual G4VPhysicalVolume* Construct();
    
  /*  G4VPhysicalVolume* GetWaterVolume() const 
    {
       return fwaterVolume;
    }*/

  private:



    
};

#endif
