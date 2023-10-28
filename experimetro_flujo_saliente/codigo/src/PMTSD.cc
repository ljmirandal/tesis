
// Geant4 Libraries
//
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4ios.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"


// Local Libraries
//
#include "PMTSD.hh"
#include "PMTHit.hh"
#include "DetectorConstruction.hh"
//#include "UserTrackInformation.hh"


// C++ Libraries
//


PMTSD::PMTSD()
  : phoHit(),
  phoDetec(0.)
//  : G4VSensitiveDetector(name),
{
  //G4cout << "...PMTSD..." << G4endl;
  phoHit = new PMTHit;
  kinEnergy = 0.;
  phoDetec = 0;
}


PMTSD::~PMTSD()
{}


G4int PMTSD::ProcessHits(const G4Step* aStep)
{
  kinEnergy = aStep->GetTrack()->GetTotalEnergy();
  phoDetec = phoHit->askDetected(kinEnergy);

  return phoDetec;
}


void PMTSD::resetPMTSD()
{
  phoDetec = 0;
  kinEnergy = 0.;
}
