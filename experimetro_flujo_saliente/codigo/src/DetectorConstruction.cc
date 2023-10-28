
// Geant4 Libraries
//
#include "G4Material.hh"
#include "G4Element.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4VPhysicalVolume.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4UnitsTable.hh"
#include "G4PhysicalConstants.hh"
#include "G4UserLimits.hh"
#include "G4RunManager.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"

// Local Libraries
//
#include "DetectorConstruction.hh"
#include "PMTSD.hh"

DetectorConstruction::DetectorConstruction()
 : G4VUserDetectorConstruction()
{ 
 /*   O = H = C = NULL;
  water = glass = alum = NULL;
  expHall_mat = glass = alum = NULL;
*/ 
}


DetectorConstruction::~DetectorConstruction()
{}


// ****************************
// Doing Elements and Materials
// ****************************
G4VPhysicalVolume* DetectorConstruction::Construct()
{

G4NistManager* nist = G4NistManager::Instance();

G4double z, a, density;
G4String name, symbol;
G4int ncomponents, natoms;

a = 1.01*g/mole;
G4Element* elH  = new G4Element(name="Hydrogen",symbol="H" , z= 1., a);

a = 16.00*g/mole;
G4Element* elO  = new G4Element(name="Oxygen"  ,symbol="O" , z= 8., a);

a= 14.00*g/mole;
G4Element* elN = new G4Element(name="Nitrogen", symbol="N", z= 7., a);

a = 26.98*g/mole;
G4Element* elAl = new G4Element(name="Aluminium", symbol="Al", z=13., a);

a = 28.09*g/mole;
G4Element* elSi = new G4Element(name="Silicon", symbol="Si", z=14., a);

a = 22.98*g/mole;
G4Element* elNa = new G4Element(name="Sodium", symbol="Na", z=11., a);

a = 39.09*g/mole;
G4Element* elK = new G4Element(name="Potassium", symbol="K", z=19., a);

a = 40.07*g/mole;
G4Element* elCa = new G4Element(name="Calcium", symbol="Ca", z=20., a);

a = 24.31*g/mole;
G4Element* elMg = new G4Element(name="Magnesium", symbol="Mg", z=12., a);

a = 32.07*g/mole;
G4Element* elS= new G4Element(name="Sulphur", symbol="S", z=16., a);

a = 30.97*g/mole;
G4Element* elP = new G4Element(name="Phosphorus", symbol="P", z=15., a);

a = 47.87*g/mole;
G4Element* elTi = new G4Element(name="Titanium", symbol="Ti", z=22., a);

a = 55.85*g/mole;
G4Element* elFe = new G4Element(name="Iron"    ,symbol="Fe", z=26., a);

a=12.00*g/mole;
G4Element* elC =new G4Element(name="Carbon",symbol="C", z=6., a);

G4double  fractionmass;

//TIPOS DE SUELO
//Suelo base seca
density=2700*kg/m3;
G4Material* SueloBS= new G4Material(name="SueloBS",density, ncomponents=14);
SueloBS->AddElement(elO, fractionmass=49*perCent);
SueloBS->AddElement(elSi, fractionmass=33*perCent);
SueloBS->AddElement(elAl, fractionmass=7.13*perCent);
SueloBS->AddElement(elNa, fractionmass=0.63*perCent);
SueloBS->AddElement(elK, fractionmass=1.36*perCent);
SueloBS->AddElement(elCa, fractionmass=1.37*perCent);
SueloBS->AddElement(elFe, fractionmass=3.80*perCent);
SueloBS->AddElement(elMg, fractionmass=0.60*perCent);
SueloBS->AddElement(elC, fractionmass=2.0*perCent);
SueloBS->AddElement(elS, fractionmass=0.08*perCent);
SueloBS->AddElement(elN, fractionmass=0.10*perCent);
SueloBS->AddElement(elP, fractionmass=0.09*perCent);
SueloBS->AddElement(elTi, fractionmass=0.46*perCent);
SueloBS->AddElement(elH, fractionmass=0.38*perCent);


//Agua
G4Material* elH2O= nist->FindOrBuildMaterial("G4_WATER");

//Suelo base humeda 1, 5% humedad
density=2700*kg/m3;
G4Material* SueloBH5= new G4Material(name="SueloBH5",density, ncomponents=2); 
SueloBH5->AddMaterial(SueloBS, fractionmass=95*perCent);
SueloBH5->AddMaterial(elH2O, fractionmass=5*perCent);

//Suelo base humeda 1, 10% humedad
density=2700*kg/m3;
G4Material* SueloBH10= new G4Material(name="SueloBH10",density, ncomponents=2); 
SueloBH10->AddMaterial(SueloBS, fractionmass=90*perCent);
SueloBH10->AddMaterial(elH2O, fractionmass=10*perCent);

//Suelo base humeda 1, 15% humedad
density=2700*kg/m3;
G4Material* SueloBH15= new G4Material(name="SueloBH15",density, ncomponents=2); 
SueloBH15->AddMaterial(SueloBS, fractionmass=85*perCent);
SueloBH15->AddMaterial(elH2O, fractionmass=15*perCent);

/*//Suelo base humeda 1, 10% humedad
density=2700*kg/m3;
G4Material* SueloBH1= new G4Material(name="SueloBH1",density, ncomponents=2); 
SueloBH1->AddMaterial(SueloBS, fractionmass=90*perCent);
SueloBH1->AddMaterial(elH2O, fractionmass=10*perCent);
*/
//Suelo base humeda 2, 25% humedad
density=2700*kg/m3;
G4Material* SueloBH25= new G4Material(name="SueloBH25",density, ncomponents=2);  
SueloBH25->AddMaterial(SueloBS, fractionmass=75*perCent);
SueloBH25->AddMaterial(elH2O, fractionmass=25*perCent);


//Suelo base humeda, 30%humedad
density=2700*kg/m3;
G4Material* SueloBH30= new G4Material(name="SueloBH30",density, ncomponents=2); 
SueloBH30->AddMaterial(SueloBS, fractionmass=70*perCent);
SueloBH30->AddMaterial(elH2O, fractionmass=30*perCent);


// ****************************
// Doing the geometries
// ****************************
   
G4bool checkOverlaps = true;

  //
  // First World
  //
  G4double fworld_sizeX = 105.*m;
  G4double fworld_sizeY = 105.*m;
  G4double fworld_sizeZ = 5.2*m;
  G4Material* fworld_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* fsolidWorld =    
    new G4Box("fWorld",
		fworld_sizeX,
		fworld_sizeY,
		fworld_sizeZ);    
      
  G4LogicalVolume* flogicWorld =                   
    new G4LogicalVolume(fsolidWorld, 
			fworld_mat,
               		"fWorld",
			0,0,0);  
         
  G4VPhysicalVolume* fphysWorld =                         
    new G4PVPlacement(0,                    
                      G4ThreeVector(),       
                      flogicWorld,   
                      "fWorld",  
                      0,   
                      false,   
                      0,    
                      checkOverlaps);    


  //     
  // World
  //
  G4double world_sizeX = 102.*m;
  G4double world_sizeY = 102.*m;
  G4double world_sizeZ = 5.1*m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",
		world_sizeX,
		world_sizeY,
		world_sizeZ);    
      
  G4LogicalVolume* logicWorld =                   
    new G4LogicalVolume(solidWorld, 
			world_mat,
               		"World",
			0,0,0);  
                                   
  new G4PVPlacement(0,                    
                      G4ThreeVector(),       
                      logicWorld,   
                      "World",  
                      flogicWorld,   
                      false,   
                      0,    
                      checkOverlaps);

  //G4UserLimits* userLimits = new G4UserLimits(1.0*cm);
  //logicWorld->SetUserLimits(userLimits);

  //     
  //Suelo_0
  //     
  G4double suelo_0_sizeX = 100*m;
  G4double suelo_0_sizeY = 100*m;
  G4double suelo_0_sizeZ = 0.5*m;
  
  G4Box* solidsuelo_0 =    
    new G4Box("suelo_0",
       		suelo_0_sizeX,
		suelo_0_sizeY,
		suelo_0_sizeZ);     
      
  G4LogicalVolume*  logicsuelo_0 =                         
    new G4LogicalVolume(solidsuelo_0, 
                        SueloBH30,//cambiar aquí el material del suelo
                        "suelo_0",
			0,0,0); 
                                   
    new G4PVPlacement(0,                     
                      G4ThreeVector(0.,0.,-0.5*m),       
                      logicsuelo_0,          
                      "suelo_0",        
                      logicWorld,         
                      false,                
                      0,                     
                      checkOverlaps);


  //
  //detector                     
  // 
  
 /* G4Material* detector_mat = nist->FindOrBuildMaterial("G4_AIR");

  G4Orb* soliddetector =
  	new G4Orb("detector", 1*m);
  
  G4LogicalVolume* logicdetector =
  	new G4LogicalVolume(soliddetector,
  				elH2O,
  				"detector",
  				0,0,0);
  
  	new G4PVPlacement(0, 
  			G4ThreeVector(0.,0.,3*m),
  			logicdetector,
  			"detctor",
  			logicWorld,                
  			false,                   
  			0,                       
  			checkOverlaps);
	
	G4UserLimits * fStepLimit = new G4UserLimits(1.*cm);
	logicdetector->SetUserLimits(fStepLimit);*/

    //     
    // detector
    //      
    G4double detector_sizeX = 1.*m;
    G4double detector_sizeY = 1.*m;
    G4double detector_sizeZ = 1*m;
    G4Material* detector_mat = nist->FindOrBuildMaterial("G4_AIR");
                     
    G4Box* soliddetector =    
    	new G4Box("detector",
    		detector_sizeX,
   		detector_sizeY,
    		detector_sizeZ);    
     
    G4LogicalVolume* logicdetector =                   
    	new G4LogicalVolume(soliddetector, 
    		        detector_mat,
    			"detector",
    			0,0,0);  

    	new G4PVPlacement(0,                    
    			G4ThreeVector(0.,0.,3*m),       
                        logicdetector,   
   			"detector",  
    			logicWorld,   
    			false,   
    			0,    
   			checkOverlaps);  

  //
  //Ground
  //
  G4double ground_sizeX = 100*m;
  G4double ground_sizeY = 100*m;
  G4double ground_sizeZ = 0.5*cm;
  
  G4Box* solidground =    
    new G4Box("ground",
       		ground_sizeX,
		ground_sizeY,
		ground_sizeZ);     
                
  G4LogicalVolume* logicground =                         
    new G4LogicalVolume(solidground, 
                        world_mat,     
                        "ground",
			0,0,0); 
                                   
    new G4PVPlacement(0,                     
                      G4ThreeVector(0.,0.,-0.6*cm),       
                      logicground,          
                      "ground",        
                      logicWorld,         
                      false,                
                      0,                     
                      checkOverlaps);   
  

     
  
  //always return the physical World
  return fphysWorld;


}
