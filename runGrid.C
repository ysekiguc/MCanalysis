{
  string gridMode="full";
  Bool_t iAODAnalysis =kTRUE;
  Bool_t useMC =kTRUE;
  Bool_t frun2=kTRUE;
  Bool_t mac=kTRUE;

  //Load common libraries
  gSystem->Load("libCore.so");
  gSystem->Load("libTree.so");
  gSystem->Load("libGeom.so");
  gSystem->Load("libVMC.so");
  gSystem->Load("libPhysics");
  gSystem->Load("libSTEERBase");
  gSystem->Load("libSTEER");
  gSystem->Load("libRAWDatabase");
  gSystem->Load("libRAWDatarec");
  gSystem->Load("libHist");
  gSystem->Load("libRIO");
  //gSystem->Load("libEveDet");
  //gSystem->Load("libCDB");
  //gSystem->Load("libESDfilter");
  gSystem->Load("libAOD");
  gSystem->Load("libESD");
  gSystem->Load("libANALYSIS");
  gSystem->Load("libANALYSISalice");
  gSystem->Load("libCORRFW");
  gSystem->Load("libADbase");
  gSystem->Load("libADrec");
  gSystem->Load("libADsim");
  gSystem->Load("libOADB");

  //ANALYSIS
  gSystem->Load("libVZERObase.so");
  gSystem->Load("libVZEROrec.so");
  gSystem->Load("libVZEROsim.so");
  gSystem->Load("libANALYSIScalib.so");
  gSystem->Load("libEventMixing.so");
  gSystem->Load("libTender.so");
  gSystem->Load("libTenderSupplies.so");

  // PWG
  gSystem->Load("libPWGTools.so");
  gSystem->Load("libPWGGlauber.so");
  gSystem->Load("libPWGflowBase.so");
  gSystem->Load("libPWGflowTasks.so");
  gSystem->Load("libPWGmuon.so");
  gSystem->Load("libPWGmuondep.so");
  gSystem->Load("libPWGCaloTrackCorrBase.so");
  //PWGCF
  gSystem->Load("libPWGCFCorrelationsBase.so");
  gSystem->Load("libPWGCFCorrelationsDPhi.so"); //comment out on 19.12.2017
  //gSystem->Load("libPWGCFCorrelationsJCORRAN.so");
  gSystem->Load("libPWGCFChaoticity.so");
  //gSystem->Load("libPWGCFFEMTOSCOPYAOD.so");
  //gSystem->Load("libPWGCFfemtoscopy.so");

  gSystem->Load("libPWGCFfemtoscopyUser.so");

  gSystem->Load("libPWGCFunicor.so");
  gSystem->Load("libPWGCFebye.so");
  gSystem->Load("libPWGCFflowCME.so");
  gSystem->Load("libPWGCFK0Analysis.so");
  gSystem->Load("libPWGCFflowBW.so");

  gSystem->Load("libPWGflowBase");
  gSystem->Load("libPWGflowTasks");

  gSystem->Load("libTPCbase.so");
  gSystem->Load("libTPCrec.so");
  gSystem->Load("libTPCsim.so");
  gSystem->Load("libTPCupgrade.so");
  gSystem->Load("libTPCutil.so");

  gSystem->Load("libACORDEbase.so");

  //gSystem->Load("libESD.so");
  //gSystem->Load("libMinuit");

  // Use AliRoot includes to compile our task
  gROOT->ProcessLine(".include $ROOTSYS/include");
  gROOT->ProcessLine(".include $ALICE_ROOT/include");
  gROOT->ProcessLine(".include $ALICE_PHYSICS");
  gROOT->ProcessLine(".include $ALICE_PHYSICS/lib");
  gROOT->ProcessLine(".include $ALICE_ROOT/lib");

  gSystem->SetIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include  -I$ALICE_ROOT/ITS -I$ALICE_ROOT/TPC -I$ALICE_ROOT/CONTAINERS -I$ALICE_ROOT/STEER/STEER -I$ALICE_ROOT/STEER/STEERBase -I$ALICE_ROOT/STEER/ESD -I$ALICE_ROOT/STEER/AOD -I$ALICE_ROOT/TRD -I$ALICE_ROOT/macros -I$ALICE_ROOT/ANALYSIS  -I$ALICE_ROOT/OADB -I$ALICE_PHYSICS/OADB -I$ALICE_PHYSICS/PWG -I$ALICE_PHYSICS/PWGCF -I$ALICE_ROOT/PWGHF -I$ALICE_ROOT/PWGHF/base -I$ALICE_ROOT/PWGHF/vertexingHF -I$ALICE_ROOT/PWG/FLOW/Base -I$ALICE_ROOT/PWG/FLOW/Tasks -I$ALICE_ROOT/PWGDQ/dielectron -I$ALICE_ROOT/AD/macros -I/$ALICE_ROOT/STAT/Macros -I$ALICE_ROOT/VZERO -I$ALICE_PHYSICS/OADB -g");

  AliAnalysisManager *mgr = new AliAnalysisManager("testAnalysis");
  // Create and configure the alien handler plugin
  TChain* chain;
  if(gridMode!=""){
    gROOT->ProcessLine(".L CreateAlienHandler.C");
	//    gROOT->ProcessLine("CreateAlienHandler.C");
    AliAnalysisGrid *alienHandler = CreateAlienHandler(useMC,iAODAnalysis);
    mgr->SetGridHandler(alienHandler);
    //  if (!alienHandler) return;
  }else{
    if(useMC){
      if(iAODAnalysis){
        chain=new TChain("aodTree");
	if(mac){
	  //chain->Add("~/workalice/alice_data/2019/LHC19h12a_fast/265525/AOD/001/AliAOD.root");//pPb AMPT
	  
	  //chain->Add("~/workalice/alice_data/2018/LHC18a9_extra/281961/AOD209/0001/AliAOD.root");　//PYTHIA
												   
	  //chain->Add("~/workalice/alice_data/2018/LHC18k3b/294925/001/AliAOD.root");//PYTHIA
	  chain->Add("~/workalice/alice_data/2017/LHC17if2/245068/AOD217/0001/AliAOD.root"); //PbPb AMPT

	  //  chain->Add("~/workalice/alice_data/2018/LHC18c12_extra/273103/AOD231/0001/AliAOD.root"); //
	  //chain->Add("~/workalice/alice_data/2019/LHC19h11/LHC19h11a_extra/287658/AOD230/0001/AliAOD.root"); //AMPT pPb
	  //chain->Add("~/workalice/alice_data/2017/LHC17i2/246994/AOD/001/AliAOD.root");
	  //	  chain->Add("~/workalice/MCESDtoAOD/08072019_1100/AliAOD.root");

	  //	  chain->Add("~/workalice/alice_data/2018/LHC18c12/271953/AOD231/0002/AliAOD.root");
	  //chain->Add("~/workalice/alice_data/2017/LHC17f2a_fast_fix/265309/002/AliAOD.root");
	  //	  chain->Add("~/workalice/alice_data/EPOS/ESDtoAOD/265309/AliAOD_001.root");
	  //	  chain->Add("~/workalice/alice_data/2017/LHC17f2a_fast_fix/265309/AOD228/0002/AliAOD.root");
	  //

	  //
	  //	  chain->Add("~/workalice/alice_data/2017/LHC17f2a_cent_woSDD_fix/265309/AOD228/0026/AliAOD.root");
	  //	  chain->Add("~/workalice/alice_data/2017/LHC17f2b_fast/265309/AOD202/001/AliAOD.root");
	  
	  //chain->Add("~/workalice/alice_data/2016/LHC16d3/226500/AOD209/0001/AliAOD.root");
	}else{
	  //	chain->Add("/home/sekiguchi/work/local_alicework/alice_data/2017/LHC17f2b_fast/265309/001/AliAOD.root");//EPOS
	}
      }else{
        chain=new TChain("esdTree");
	//        chain->Add("/Users/sekiguchi/alicework/alice_data/2017/LHC17f2a_fast_fix/265309/001/AliESDs.root");//DPMJET
      }

    }else{
      if(!iAODAnalysis){
        chain =new TChain("esdTree");
	//	chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_CENT_wSDD/16000265309019.100/AliESDs.root");
}
      else{
	chain =new TChain("aodTree");
	//	chain->Add("$HOME/alicework/alice_data/2016/LHC16q/000265309/pass1_FAST/002/AliAOD.root");
      }
    }

  }

//  Create the analysis manager
  // if AOD , AliMCEventHander is not necessary
     if (useMC && !iAODAnalysis) {
      AliMCEventHandler* mcHandler = new AliMCEventHandler();
     mgr->SetMCtruthEventHandler(mcHandler);
     mcHandler->SetReadTR(useMC);
    }

   if(!iAODAnalysis){
     AliESDInputHandler* esdH = new AliESDInputHandler();
     mgr->SetInputEventHandler(esdH);
   }else{
     AliAODInputHandler *aodHandler = new AliAODInputHandler();
     mgr->SetInputEventHandler(aodHandler);
   }

   if(frun2){
     if(mac){
       gROOT->ProcessLine(".L $ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
       AddTaskPhysicsSelection(useMC,true);

       gROOT->ProcessLine(".L $ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/macros/AddTaskMultSelection.C");
       AliMultSelectionTask *multSelTask=AddTaskMultSelection(false);
       //       multSelTask->SetUseDefaultMCCalib(1);
       //       multSelTask->SetPreferSuperCalib(true);
       
       //multSelTask->SetAlternateOADBFullManualBypassMC("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/data/OADB-LHC16q-DefaultMC-EPOSLHC.root");
       //       multSelTask->SetAlternateOADBFullManualBypassMC("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/data/OADB-LHC16q.root");
       //       multSelTask->SetAlternateOADBforEstimators("LHC16q");
       multSelTask->SetAlternateOADBFullManualBypassMC("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/data/OADB-LHC16q-DefaultMC-DPMJet.root ");
     }else{
       gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
       AddTaskPhysicsSelection(useMC,true);
       gROOT->LoadMacro("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/macros/AddTaskMultSelection.C");
       AliMultSelection* mult=AddTaskMultSelection();
     }
   }
   if(mac)      gROOT->ProcessLine(".L $ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C");
   else  gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C");
   
   AddTaskPIDResponse(useMC);
   //   AddTaskPIDResponse(kTRUE, kTRUE, kTRUE, 2, kFALSE, "", kTRUE, kTRUE);
   
 //  //   gROOT->LoadMacro("AddTaskPIDResponse.C");
 //  Bool_t isMC = kFALSE;
   
   Bool_t autoMCesd = kTRUE;
   Bool_t tuneOnData = kTRUE;
   Int_t recoPass = 2;
   Bool_t cachePID = kFALSE;
   Bool_t useTPCEtaCorrection = kTRUE;
   Bool_t useTPCMultiplicityCorrection = kTRUE;
   Int_t recoDataPass = 2;
 //
 //  AliAnalysisTaskSE *setupTask =AddTaskPIDResponse(isMC,autoMCesd,tuneOnData,recoPass,cachePID,"",useTPCEtaCorrection,useTPCMultiplicityCorrection,recoDataPass);
   
   AddTaskPIDResponse(useMC,autoMCesd,tuneOnData,recoPass,cachePID,"",useTPCEtaCorrection,useTPCMultiplicityCorrection,recoDataPass);

//
   
   if(mac){
     gROOT->ProcessLine(".x AliAnalysisTaskSEpPbCorrelationsForward.cxx++g");
     gROOT->ProcessLine(".x AddTaskpPbCorrelationsForward.C");
   }else{
     gROOT->LoadMacro("AliAnalysisTaskSEpPbCorrelationsForward.cxx++g");
     gROOT->LoadMacro("AddTaskpPbCorrelationsForward.C");
   }

   //   AliAnalysisTaskSEpPbCorrelationsForward* ana =AddTaskpPbCorrelationsForward();
   

   // Enable debug printouts

   mgr->SetDebugLevel(0);

   if (!mgr->InitAnalysis()) return;

   mgr->PrintStatus();
   // Start analysis in grid.
   if(gridMode!=""){
     mgr->StartAnalysis("grid");
   }
   else{
     mgr->StartAnalysis("local",chain);
   }
};
