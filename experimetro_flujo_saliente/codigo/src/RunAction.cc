#include "G4Timer.hh"
#include "RunAction.hh"
#include "G4Run.hh"
#include "g4root.hh"
#include "G4SystemOfUnits.hh"



RunAction::RunAction()
 : G4UserRunAction(),
   fTimer(0)
{
  fTimer = new G4Timer;

	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

	analysisManager->SetVerboseLevel(1);
	analysisManager->SetActivation(true);



analysisManager->CreateH1("entran_al_suelo"," ", 2, 0., 2.);
analysisManager->CreateH1("energia_n"," ", 10000, 0, 10);
   





/*analysisManager->CreateH1("total_particulas_generadas_detector_1"," ", 6, 0., 6.);
analysisManager->CreateH1("total_particulas_generadas_detector_2"," ", 6, 0., 6.);
analysisManager->CreateH1("total_particulas_generadas_detector_3"," ", 6, 0., 6.);
analysisManager->CreateH1("total_particulas_generadas_detector_4"," ", 6, 0., 6.);
analysisManager->CreateH1("total_particulas_generadas_detector_5"," ", 6, 0., 6.);*/


//analysisManager->CreateH1("angulo_tetta"," ", 10000, 0., 180.)
/*analysisManager->CreateH1("energia_gamma"," ", 10000, 0., 100.);
//analysisManager->CreateH1("energia_n"," ", 10000, 0., 100.);
analysisManager->CreateH1("energia_p"," ", 10000, 0., 100.);
analysisManager->CreateH1("e_detectados"," ", 3, 0., 3.);
analysisManager->CreateH1("gamma_detectados"," ", 3, 0., 3.);
analysisManager->CreateH1("energia_e_detectados"," ", 10000, 0., 100.);
analysisManager->CreateH1("energia_gamma_detectados"," ", 10000, 0., 100.*MeV);
analysisManager->CreateH1("n_detectados"," ", 3, 0., 3.);
analysisManager->CreateH1("p_detectados"," ", 3, 0., 3.);
analysisManager->CreateH1("energia_n_detectados"," ", 10000, 0., 100.);
analysisManager->CreateH1("energia_p_detectados"," ", 10000, 0., 100.);*/
//analysisManager->CreateH1("ener0_p"," ", 1000, 0.*MeV, 1.*MeV);
//analysisManager->CreateH1("ener1_p"," ", 1000, 0.*MeV, 1.*MeV);
//analysisManager->CreateH1("ener2_p"," ", 1000, 0.*MeV, 1.*MeV);
//analysisManager->CreateH1("dis0_p"," ", 1000, 0.*cm, 1.*cm);
//analysisManager->CreateH1("dis1_p"," ", 1000, 0.*cm, 1.*cm);
//analysisManager->CreateH1("dis2_p"," ", 1000, 0.*cm, 1.*cm);
//analysisManager->CreateH1("ener_p"," ", 1000, 0.*MeV, 1.*MeV);
//analysisManager->CreateH1("dis_p"," ", 1000000, 0.*m, 2.*m);
//analysisManager->CreateH1("ener1_g"," ", 1000, 0.*MeV, 10.*MeV);
//analysisManager->CreateH1("ener2_g"," ", 1000, 0.*MeV, 10.*MeV);
//analysisManager->CreateH1("ener3_g"," ", 1000, 0.*MeV, 10.*MeV);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
  delete fTimer;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  fTimer->Start();

  G4AnalysisManager* analysisManager
     = G4AnalysisManager::Instance();

  G4String rootFile = "minas";
  analysisManager->OpenFile(rootFile);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  fTimer->Stop();
 G4cout << "number of event = " << aRun->GetNumberOfEvent();

  G4AnalysisManager* analysisManager
     = G4AnalysisManager::Instance();
  analysisManager->Write(); 
  analysisManager->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
