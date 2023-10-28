// Geant4 Libraries
//
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4OpticalPhoton.hh"

#include "CLHEP/Units/SystemOfUnits.h" // para definir constantes físicas en Geant4

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "g4root.hh"
#include "G4SDManager.hh"
#include "G4TransportationManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "PMTSD.hh"
#include "PMTHit.hh"
#include "UserEventAction.hh"
#include "PrimarySpectrum.hh"
#include "iostream"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
SteppingAction::SteppingAction()
  : G4UserSteppingAction()
{

  G4TransportationManager::GetTransportationManager()
    ->GetNavigatorForTracking()->SetPushVerbosity(0);

fEventNumber = -1;
alsuelo=0;
generadas = 0;
ener_e=0;
ener_g=0;
ener_n=0;
ener_p=0;
detect_g=0;
detect_e=0;
ener_e_det=0;
ener_g_det=0;

  detectorConstruction 
     = static_cast < const DetectorConstruction* 
     > (G4RunManager::GetRunManager()
         ->GetUserDetectorConstruction());
}

SteppingAction::~SteppingAction()
{}


void SteppingAction::UserSteppingAction(const G4Step* step)
{

  //ofstream file;
  //file.open("/root/humedad-0%/out2.txt"); 

  // ==========================
  // Get current PhysicalVolume
  thePostPV = step->GetPostStepPoint()->GetPhysicalVolume()->GetName();
  thePrePV = step->GetPreStepPoint()->GetPhysicalVolume()->GetName();


  // =========
  // Get Track
  G4Track* track = step->GetTrack();

  // ============
  // Get Event Id
  G4int eventNumber                
    = G4RunManager::GetRunManager()
    ->GetCurrentEvent()
    ->GetEventID();
  
  // =================
  // Get Particle Name
  G4String ParticleName 
    = track->GetDynamicParticle()->GetParticleDefinition()->GetParticleName();

  // =================
  // Get Histograms
  G4AnalysisManager* analysisManager
    = G4AnalysisManager::Instance();

  //==========================
  // Global time
  //G4double tiempo = track->GetGlobalTime();

  // =================
  // Get parent ID
  G4double parentID = step->GetTrack()->GetParentID();

  // =================
  // Get current step number
  G4double paso  = step->GetTrack()->GetCurrentStepNumber();
  // Get energy step number 
  //G4double energia = track->GetKineticEnergy();
  // ******************************
  // Reset variables fog each event
  // ******************************
  
  G4ThreeVector position = step->GetPreStepPoint()->GetPosition(); 
  G4double x = step->GetPreStepPoint()->GetPosition().x()/m;
  G4double y = step->GetPreStepPoint()->GetPosition().y()/m;
  G4double z = step->GetPreStepPoint()->GetPosition().z()/m; // determinar la posicion de la particula

  // Obtener el momentum en MeV/c
  G4ThreeVector momentum = step->GetPreStepPoint()->GetMomentum();
  G4double px = momentum.x();
  G4double py = momentum.y();
  G4double pz = momentum.z();
  
  // Obtener los ángulos de dirección en grados
  G4double theta = momentum.theta(); // en radianes
  G4double phi = momentum.phi();     // en radianes
  G4double theta_deg = theta*180./CLHEP::pi; // en grados
  G4double phi_deg = phi*180./CLHEP::pi;     // en grados

 const G4StepPoint* lastPoint = step->GetPostStepPoint();

 // Obtener la posición del último punto en metros
 G4ThreeVector pos_last = lastPoint->GetPosition()/CLHEP::m;
 G4double x_last = pos_last.x();
 G4double y_last = pos_last.y();
 G4double z_last = pos_last.z();

 // Obtener el momento en el último punto en MeV/c
 G4ThreeVector momentum_last = lastPoint->GetMomentum();
 G4double px_last = momentum_last.x();
 G4double py_last = momentum_last.y();
 G4double pz_last = momentum_last.z();

 // Obtener los ángulos de dirección en el último punto en grados
 G4double theta_last = momentum_last.theta(); // en radianes
 G4double phi_last = momentum_last.phi();     // en radianes
 G4double theta_deg_last = theta_last*180./CLHEP::pi; // en grados
 G4double phi_deg_last = phi_last*180./CLHEP::pi;     // en grados

	if (eventNumber != fEventNumber)
  	{
		fEventNumber = eventNumber;
     		ener_e=0;
     		ener_g=0;
     		ener_n=0;
     		ener_p=0;
     		ener_e_det=0;
     		ener_g_det=0;
	}
  
   	if( parentID == 0 && thePostPV == "ground")
    		track->SetTrackStatus(fStopAndKill);

  	if ( thePostPV == "fWorld" || thePostPV  == "ground" )
    		track->SetTrackStatus(fStopAndKill);
                                          
  	
	if (ParticleName == "neutron" && thePostPV == "detector" )
	{       
		//G4cout << eventNumber << G4endl;

		//if (paso == 1)
		//{
		//	G4cout << eventNumber << " " <<  parentID << " " << x << " " << y << " " << z << " " << px << " " << py << " " << pz << " " << theta_deg << " " << phi_deg << G4endl;
		//analysisManager->FillH1(2,theta_deg);
		
		//}
  		//G4cout << eventNumber << " " << parentID << " " << x_last << " "  << y_last << " " << z_last << " " << px_last << " " << py_last << " " << pz_last << " " << theta_deg_last << " " << phi_deg_last << G4endl;    
               //analysisManager->FillH1(2,theta_deg_last);
  		
		generadas = 1;
		analysisManager->FillH1(0,generadas);
		ener_n =step->GetPreStepPoint()->GetKineticEnergy();
		ener_g = ener_n*1e6;
		analysisManager->FillH1(1,ener_g);		
		//G4cout << ener_g<< G4endl;

		track->SetTrackStatus(fStopAndKill);
  		
	}
   

}
