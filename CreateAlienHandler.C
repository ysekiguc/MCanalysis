
AliAnalysisGrid* CreateAlienHandler(Bool_t isMC,Bool_t fAOD)
{
  //  TString data     = "LHC17f2a_fast";//epos
  //TString data     = "LHC17f2b_fast";//dpmjet
  TString data     = "LHC17f2b_cent_wosdd";//dpmjet
  //  TString data="LHC18h2_extra";//PYTHIA anchored to LHC18f
  //  TString data ="LHC18a9_extra";//PYTHIA
  //  TString data ="LHC16d3";//EPOS_pp
  
  //   TString data ="LHC18c12";//PYTHIApp
  
  // TString data     = "LHC19h12a_fast";//AMPT default
  //  TString data     = "LHC19h12b_fast";//LHC17i2f";
  //TString data     = "LHC19h12c_fast";//LHC17i2f";
  //  TString data     = "LHC19h12a_cent_wosdd";//LHC17i2f";
  TString datatype = "FAST"  ;//Fast,wSDD,woSDD
  Int_t method   =  1;
  // Check if user has a valid token, otherwise make one. This has limitations.
  // One can always follow the standard procedure of calling alien-token-init then
  // source /tmp/gclient_env_$UID in the current shell.
  
  // if (!AliAnalysisGrid::CreateToken()) return NULL;
  AliAnalysisAlien *plugin = new AliAnalysisAlien();
  plugin->SetOverwriteMode();
  
  plugin->SetMergeViaJDL(1);//
   plugin->SetRunMode("full");
  //  plugin->SetRunMode("terminate");
  //  plugin->SetRunMode("test");
  
  //Set versions of used packages
  plugin->SetAPIVersion("V1.1x");
  //  plugin->SetAliPhysicsVersion("vAN-20170628-1");
  //plugin->SetAliPhysicsVersion("vAN-20170722-1");//have issuse to deal wth primary particle so it is removed.
  //plugin->SetAliPhysicsVersion("vAN-20170824-1");


 //plugin->SetAliPhysicsVersion("vAN-20171218-1");
 //lugin->SetAliPhysicsVersion("vAN-20180325-1");
 // plugin->SetAliPhysicsVersion("vAN-20180708-1");
 //plugin->SetAliPhysicsVersion("vAN-20180919-1");
 //  plugin->SetAliPhysicsVersion("vAN-20190214-1");
 // plugin->SetAliPhysicsVersion("vAN-20190422-1");
 //plugin->SetAliPhysicsVersion("vAN-20190615-1");
  // plugin->SetAliPhysicsVersion("vAN-20190920_ROOT6-1");

  //plugin->SetAliPhysicsVersion("vAN-20190920_ROOT6-1");
  plugin->SetAliPhysicsVersion("vAN-20200301_ROOT6-1");
  //plugin->SetAliPhysicsVersion("v5-09-53c-01-1");
  // Declare input data to be processed.
  // Method 1: Create automatically XML collections using alien 'Contains' command.
  // Define production directory LFN

  if(!isMC){
    plugin->SetRunPrefix("000"); // IMPORTANT!
  }
  plugin->SetCheckCopy(kFALSE);
  if(!isMC){
  if(method==1){
    if(data.Contains("LHC16q")){
      plugin->SetGridDataDir("/alice/data/2016/LHC16q");
      if(datatype.Contains("wSDD"))plugin->SetDataPattern("*pass1_CENT_wSDD/AOD/*/AliAOD.root");
      else if(datatype.Contains("woSDD"))plugin->SetDataPattern("*pass1_CENT_woSDD/AOD/*/AliAOD.root");
      else if(datatype.Contains("FAST"))plugin->SetDataPattern("*pass1_FAST/AOD/*/AliAOD.root");
      //plugin->AddDataFile("/alice/cern.ch/user/y/ysekiguc/01122017_MC/265305); // remove because no ZDC
      // plugin->AddRunNumber(265308);  // remove because no ZDC
      plugin->AddRunNumber(265309);
      /*
      plugin->AddRunNumber(265332);
      plugin->AddRunNumber(265334);
      //      plugin->AddRunNumber(265335); // remove because of no TOF in data taking
      plugin->AddRunNumber(265336);
      plugin->AddRunNumber(265338);
      plugin->AddRunNumber(265339);
      plugin->AddRunNumber(265342);
      plugin->AddRunNumber(265343);
      plugin->AddRunNumber(265344);
      plugin->AddRunNumber(265377);
      plugin->AddRunNumber(265378);
      plugin->AddRunNumber(265381);
      plugin->AddRunNumber(265383);
      plugin->AddRunNumber(265384);
      plugin->AddRunNumber(265385);
      plugin->AddRunNumber(265387);
      plugin->AddRunNumber(265388);
      plugin->AddRunNumber(265419);
      plugin->AddRunNumber(265420);
      plugin->AddRunNumber(265421);
      plugin->AddRunNumber(265422);
      plugin->AddRunNumber(265424);
      plugin->AddRunNumber(265425);
      plugin->AddRunNumber(265426);
      plugin->AddRunNumber(265427);
      plugin->AddRunNumber(265435);
      plugin->AddRunNumber(265499);
      plugin->AddRunNumber(265500);
      plugin->AddRunNumber(265501);
      plugin->AddRunNumber(265521);
      plugin->AddRunNumber(265525);
      */
    }
  }
  }else{
	
    if(data.Contains("LHC17i2f")){
      plugin->SetGridDataDir("/alice/sim/2017/LHC17i2f");
      plugin->SetDataPattern("AOD217/*/AliAOD.root");
	  plugin->AddRunNumber(245068);
	  plugin->AddRunNumber(245066);
	  plugin->AddRunNumber(245064);
	  plugin->AddRunNumber(244917);
	}

    if(data.Contains("LHC17i2f_extra")){
      plugin->SetGridDataDir("/alice/sim/2017/LHC17i2f_extra");
      plugin->SetDataPattern("AOD217/*/AliAOD.root");
      plugin->AddRunNumber(245064);
    }

    if(data.Contains("LHC18a9_extra")){
      plugin->SetGridDataDir("/alice/sim/2018/LHC18a9_extra");
      plugin->SetDataPattern("AOD209/*/AliAOD.root");
      plugin->AddRunNumber(281961);
    }


    
    if(data.Contains("LHC18c12")){
      plugin->SetGridDataDir("/alice/sim/2018/LHC18c12");
      plugin->SetDataPattern("AOD231/*/AliAOD.root");
      plugin->AddRunNumber(271868);
      plugin->AddRunNumber(271870);
      plugin->AddRunNumber(271871);
      plugin->AddRunNumber(271873);
      plugin->AddRunNumber(271874);
      plugin->AddRunNumber(271880);
      plugin->AddRunNumber(271881);
      plugin->AddRunNumber(271881);
      plugin->AddRunNumber(272036);
      plugin->AddRunNumber(272038);
      plugin->AddRunNumber(272039);
      plugin->AddRunNumber(272040);
      plugin->AddRunNumber(272041);
      plugin->AddRunNumber(272100);
      plugin->AddRunNumber(272101);
      plugin->AddRunNumber(272123);
      plugin->AddRunNumber(272152);
      plugin->AddRunNumber(272153);
      plugin->AddRunNumber(272154);
      plugin->AddRunNumber(272155);
      plugin->AddRunNumber(272156);
      plugin->AddRunNumber(272194);
      plugin->AddRunNumber(272335);
      plugin->AddRunNumber(272359);
      plugin->AddRunNumber(272360);
      plugin->AddRunNumber(272388);
      plugin->AddRunNumber(272389);
      plugin->AddRunNumber(272394);
      plugin->AddRunNumber(272395);
      plugin->AddRunNumber(272399);
      plugin->AddRunNumber(272400);
      plugin->AddRunNumber(272411);
      plugin->AddRunNumber(272413);
      plugin->AddRunNumber(272461);
      plugin->AddRunNumber(272462);
      plugin->AddRunNumber(272463);
      plugin->AddRunNumber(272468);
      plugin->AddRunNumber(272521);
      plugin->AddRunNumber(272574);
      plugin->AddRunNumber(272575);
      plugin->AddRunNumber(272577);
      plugin->AddRunNumber(272585);
      plugin->AddRunNumber(272607);
      plugin->AddRunNumber(272608);
      plugin->AddRunNumber(272610);
      plugin->AddRunNumber(272692);
      plugin->AddRunNumber(272712);
      plugin->AddRunNumber(272746);
      plugin->AddRunNumber(272746);
      plugin->AddRunNumber(272747);
      plugin->AddRunNumber(272749);
      plugin->AddRunNumber(272760);
      plugin->AddRunNumber(272763);
      plugin->AddRunNumber(272764);
      plugin->AddRunNumber(272782);
      plugin->AddRunNumber(272784);
      plugin->AddRunNumber(272828);
      plugin->AddRunNumber(272829);
      plugin->AddRunNumber(272833);
      plugin->AddRunNumber(272836);
      plugin->AddRunNumber(272870);
      plugin->AddRunNumber(272871);
      plugin->AddRunNumber(272903);
      plugin->AddRunNumber(272905);
      plugin->AddRunNumber(272932);
      plugin->AddRunNumber(272933);
      plugin->AddRunNumber(272934);
      plugin->AddRunNumber(272935);
      plugin->AddRunNumber(272939);
      plugin->AddRunNumber(272947);
      plugin->AddRunNumber(272949);
      plugin->AddRunNumber(273099);
      plugin->AddRunNumber(273100);
      plugin->AddRunNumber(273103);

      
    }

    
    if(data.Contains("LHC18a9_extra")){
      plugin->SetGridDataDir("/alice/sim/2018/LHC18a9_extra");
      plugin->SetDataPattern("AOD209/*/AliAOD.root");
      plugin->AddRunNumber(281961);
      //     plugin->AddRunNumber(281959 : return 1;
      plugin->AddRunNumber(281956);
      plugin->AddRunNumber(281953); //2;
      plugin->AddRunNumber(281940);// 3;
      plugin->AddRunNumber(281939);// 4;
      plugin->AddRunNumber(281932);// 5;
      plugin->AddRunNumber(281931);// 6;
      plugin->AddRunNumber(281928);// 7;
      plugin->AddRunNumber(281920);// 8;
      plugin->AddRunNumber(281918);// 9;
      plugin->AddRunNumber(281915);// 10;//
      plugin->AddRunNumber(281895);// 11;//
      plugin->AddRunNumber(281894);// 12;//
      plugin->AddRunNumber(281892);// 13;//
      plugin->AddRunNumber(281633);// 14;//
      plugin->AddRunNumber(281583);// 15;
      plugin->AddRunNumber(281574);// 16;
      plugin->AddRunNumber(281569);// 17;
     plugin->AddRunNumber(281568);// 18;
     plugin->AddRunNumber(281562);// 19;
     plugin->AddRunNumber(281557);// 20;
     plugin->AddRunNumber(281511);// 21;
     plugin->AddRunNumber(281509);// 22;
     plugin->AddRunNumber(281477);// 23;
     plugin->AddRunNumber(281475);// 24;
     plugin->AddRunNumber(281450);// 25;
     plugin->AddRunNumber(281449);// 26;
     plugin->AddRunNumber(281444);// 27;
     plugin->AddRunNumber(281443);// 28;
     plugin->AddRunNumber(281441);// 29;
     plugin->AddRunNumber(281415);// 30;
     plugin->AddRunNumber(281321);// 31;
     plugin->AddRunNumber(281301);// 32;
     plugin->AddRunNumber(281277);// 33;
     plugin->AddRunNumber(281275);// 34;
     plugin->AddRunNumber(281273);// 35;
     plugin->AddRunNumber(281271);// 36;
     plugin->AddRunNumber(281243);// 37;
     plugin->AddRunNumber(281242);// 38;
     plugin->AddRunNumber(281241);// 39;
     plugin->AddRunNumber(281240);// 40;
     plugin->AddRunNumber(281213);// 41;
     plugin->AddRunNumber(281212);// 42;
     plugin->AddRunNumber(281191);// 43;
     plugin->AddRunNumber(281190);// 44;
     plugin->AddRunNumber(281189);// 45;
     plugin->AddRunNumber(281181);// 46;
     plugin->AddRunNumber(281180);// 47;//
     plugin->AddRunNumber(281179);// 48;
     plugin->AddRunNumber(281081);// 49;
     plugin->AddRunNumber(281080);// 50;
     plugin->AddRunNumber(281062);// 51;
     plugin->AddRunNumber(281061);// 52;
     plugin->AddRunNumber(281060);// 53;
     plugin->AddRunNumber(280999);// 54;
     plugin->AddRunNumber(280998);// 55;
     plugin->AddRunNumber(280997);// 56;
     plugin->AddRunNumber(280994);// 57;
     plugin->AddRunNumber(280990);// 58;
     plugin->AddRunNumber(280947);// 59;
     plugin->AddRunNumber(280940);// 60;
     plugin->AddRunNumber(280936);// 61;
     plugin->AddRunNumber(280897);// 62;
     plugin->AddRunNumber(280890);// 63;//
     plugin->AddRunNumber(280881);// 64;//
     plugin->AddRunNumber(280880);// 65;
     plugin->AddRunNumber(280856);// 66;
     plugin->AddRunNumber(280849);// 67;
     plugin->AddRunNumber(280848);// 68;
     plugin->AddRunNumber(280847);// 69;
     plugin->AddRunNumber(280845);// 70;//
     plugin->AddRunNumber(280844);// 71;
     plugin->AddRunNumber(280842);// 72;
     plugin->AddRunNumber(280793);// 73;
     plugin->AddRunNumber(280792);// 74;
     plugin->AddRunNumber(280787);// 75;
     plugin->AddRunNumber(280786);// 76;
     plugin->AddRunNumber(280768);// 77;
     plugin->AddRunNumber(280767);// 78;
     plugin->AddRunNumber(280766);// 79;
     plugin->AddRunNumber(280765);// 80;
     plugin->AddRunNumber(280764);// 81;
     plugin->AddRunNumber(280763);// 82;
     plugin->AddRunNumber(280762);// 83;
     plugin->AddRunNumber(280761);// 84;
     plugin->AddRunNumber(280757);// 85;
     plugin->AddRunNumber(280756);// 86;
     plugin->AddRunNumber(280755);// 87;
     plugin->AddRunNumber(280754);// 88;
     plugin->AddRunNumber(280753);// 89;
     plugin->AddRunNumber(280729);// 90;
     plugin->AddRunNumber(280706);// 91;
     plugin->AddRunNumber(280705);// 92;
     plugin->AddRunNumber(280681);// 93;
     plugin->AddRunNumber(280679);// 94;
       //     plugin->AddRunNumber(280676);// 88;
       //     plugin->AddRunNumber(280673);// 89;
     plugin->AddRunNumber(280671);// 95;
       //     plugin->AddRunNumber(280650);// 91;
       //     plugin->AddRunNumber(280648);// 92;
     plugin->AddRunNumber(280647);// 96;
     plugin->AddRunNumber(280645);// 97;
     plugin->AddRunNumber(280639);// 98;
     plugin->AddRunNumber(280637);// 99;
     plugin->AddRunNumber(280636);// 100;
     plugin->AddRunNumber(280634);// 101;
     plugin->AddRunNumber(280613);// 102;
     plugin->AddRunNumber(280583);// 103;
     plugin->AddRunNumber(280581);// 104;
     plugin->AddRunNumber(280576);// 105;//
     plugin->AddRunNumber(280575);// 106;//
     plugin->AddRunNumber(280574);// 107;
     plugin->AddRunNumber(280551);// 108;
     plugin->AddRunNumber(280550);// 109;
     plugin->AddRunNumber(280547);// 110;
     plugin->AddRunNumber(280546);// 111;
     plugin->AddRunNumber(280519);// 112;
     plugin->AddRunNumber(280518);// 113;
     plugin->AddRunNumber(280499);// 114;
     plugin->AddRunNumber(280448);// 115;
     plugin->AddRunNumber(280447);// 116;
     plugin->AddRunNumber(280446);// 117;
     plugin->AddRunNumber(280445);// 118;
     plugin->AddRunNumber(280443);// 119;
     plugin->AddRunNumber(280419);// 120;
     plugin->AddRunNumber(280415);// 121;
     plugin->AddRunNumber(280413);// 122;//
     plugin->AddRunNumber(280406);// 123;
     plugin->AddRunNumber(280405);// 124;
     plugin->AddRunNumber(280403);// 125;
     plugin->AddRunNumber(280375);// 126;
     plugin->AddRunNumber(280374);// 127;
       //     plugin->AddRunNumber(280352);// 122;
     plugin->AddRunNumber(280351);// 128;
     plugin->AddRunNumber(280350);// 129;
     plugin->AddRunNumber(280349);// 130;
     plugin->AddRunNumber(280348);// 131;
     plugin->AddRunNumber(280312);// 132;
     plugin->AddRunNumber(280310);// 133;
     plugin->AddRunNumber(280290);// 134;
     plugin->AddRunNumber(280286);// 135;
     plugin->AddRunNumber(280285);// 136;
     plugin->AddRunNumber(280284);// 137;
     plugin->AddRunNumber(280283);// 138;
     plugin->AddRunNumber(280282);// 139;

     

	}

    if(data.Contains("LHC16d3")){
      plugin->SetGridDataDir("/alice/sim/2016/LHC16d3");
      plugin->SetDataPattern("AOD209/*/AliAOD.root");
      
      plugin->AddRunNumber(225000);
      plugin->AddRunNumber(225011);
      plugin->AddRunNumber(225016);
      plugin->AddRunNumber(225026);
      plugin->AddRunNumber(225031);
      plugin->AddRunNumber(225035);
      plugin->AddRunNumber(225037);
      plugin->AddRunNumber(225041);
      plugin->AddRunNumber(225043);
      plugin->AddRunNumber(225050);
      plugin->AddRunNumber(225051);
      plugin->AddRunNumber(225052);
      plugin->AddRunNumber(225106);
      plugin->AddRunNumber(225305);
      plugin->AddRunNumber(225307);
      plugin->AddRunNumber(225309);
      plugin->AddRunNumber(225310);
      plugin->AddRunNumber(225313);
      plugin->AddRunNumber(225314);
      plugin->AddRunNumber(225315);
      plugin->AddRunNumber(225322);
      plugin->AddRunNumber(225576);
      plugin->AddRunNumber(225578);
      plugin->AddRunNumber(225579);
      plugin->AddRunNumber(225580);
      plugin->AddRunNumber(225582);
      plugin->AddRunNumber(225586);
      plugin->AddRunNumber(225587);
      plugin->AddRunNumber(225705);
      plugin->AddRunNumber(225707);
      plugin->AddRunNumber(225708);
      plugin->AddRunNumber(225709);
      plugin->AddRunNumber(225710);
      plugin->AddRunNumber(225716);
      plugin->AddRunNumber(225717);
      plugin->AddRunNumber(225719);
      plugin->AddRunNumber(225753);
      plugin->AddRunNumber(225757);
      plugin->AddRunNumber(225762);
      plugin->AddRunNumber(225763);
      plugin->AddRunNumber(225766);
      plugin->AddRunNumber(225768);
      plugin->AddRunNumber(226062);
      plugin->AddRunNumber(226170);
      plugin->AddRunNumber(226220);
      plugin->AddRunNumber(226225);
      plugin->AddRunNumber(226444);
      
    }

    
    if(data.Contains("LHC17f2b") ||data.Contains("LHC17f2a_fast")||data.Contains("LHC19h12")){
	if(data.Contains("LHC17f2b_fast")) plugin->SetGridDataDir("/alice/sim/2017/LHC17f2b_fast");
	else if(data.Contains("LHC17f2b_cent_wosdd")) plugin->SetGridDataDir("/alice/sim/2017/LHC17f2b_cent_woSDD");
	else if(data.Contains("LHC17f2a_fast")) plugin->SetGridDataDir("/alice/sim/2017/LHC17f2a_fast_fix");
	else if(data.Contains("LHC19h12a_fast")) plugin->SetGridDataDir("/alice/sim/2019/LHC19h12a_fast");
	else if(data.Contains("LHC19h12b_fast")) plugin->SetGridDataDir("/alice/sim/2019/LHC19h12b_fast");
	else if(data.Contains("LHC19h12c_fast")) plugin->SetGridDataDir("/alice/sim/2019/LHC19h12c_fast");
	else if(data.Contains("LHC19h12a_cent_wosdd")) plugin->SetGridDataDir("/alice/sim/2019/LHC19h12a_cent_woSDD");
	if(data.Contains("LHC17f2b")) plugin->SetDataPattern("AOD202/*/AliAOD.root");
	   else plugin->SetDataPattern("AOD228/*/AliAOD.root");
	//LHC16t
	plugin->AddRunNumber(267166);
	plugin->AddRunNumber(267165);
	plugin->AddRunNumber(267164);
	plugin->AddRunNumber(267163);
	plugin->AddRunNumber(265309);

	plugin->AddRunNumber(265332);
	plugin->AddRunNumber(265334);
	plugin->AddRunNumber(265335); // remove because of no TOF in data taking
	plugin->AddRunNumber(265336);
	plugin->AddRunNumber(265338);

	plugin->AddRunNumber(265339);
	plugin->AddRunNumber(265342);
	plugin->AddRunNumber(265343);
	plugin->AddRunNumber(265344);
	plugin->AddRunNumber(265377);

	plugin->AddRunNumber(265378);
	plugin->AddRunNumber(265381);
	plugin->AddRunNumber(265383);
	
	
	//10/06
	plugin->AddRunNumber(265384);
	plugin->AddRunNumber(265385);
	plugin->AddRunNumber(265387);
	plugin->AddRunNumber(265388);
	plugin->AddRunNumber(265419);
	
	plugin->AddRunNumber(265420);
	
	//10_05
	plugin->AddRunNumber(265421);
	plugin->AddRunNumber(265422);
	plugin->AddRunNumber(265424);
	plugin->AddRunNumber(265425);
	
	plugin->AddRunNumber(265426);
	plugin->AddRunNumber(265427);
	plugin->AddRunNumber(265435);
	plugin->AddRunNumber(265499);
	
	
	//10/02
	plugin->AddRunNumber(265500);
	plugin->AddRunNumber(265501);
	plugin->AddRunNumber(265521);
	plugin->AddRunNumber(265525);
	
	}
  }
  
  
  //    plugin->SetGridWorkingDir("21092019_AMPTpPb_TPCFMD");
  //    plugin->SetGridWorkingDir("21092019_AMPTpPb_TPCFMDC");
  //      plugin->SetGridWorkingDir("22092019_AMPTpPb_TPCFMDC");
  //   plugin->SetGridWorkingDir("22092019_AMPTpPb_TPCFMD");
  //     plugin->SetGridWorkingDir("22092019_AMPTpPb_FMDFMD");
  //  plugin->SetGridWorkingDir("test_EPOS_refiltering");

  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_FMDFMD");
  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_FMDFMD_OADB");
  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_FMDFMD_OADBfix_fine");
  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_TPCFMD_OADBfix_fine");
  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_TPCFMDC_OADBfix_fine");
  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_FMDFMD_OADBfix_fine_wosdd");
  //  plugin->SetGridWorkingDir("26092019_AMPTpPb_TPCFMD_OADBfix_fine_wosdd1");

  //    plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_reco");
  //plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //   plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //      plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_reco");

  //plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_plusmaterial_reco");
  //  plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_plusmaterial_prim");

  //    plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_plusmaterial_prim"); 
  //plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_plusmaterial_reco");

  //  plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_minusmaterial_reco");
  //  plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_minusmaterial_prim");
  //  plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_minusmaterial_prim"); 
  //  plugin->SetGridWorkingDir("28092019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_minusmaterial_reco"); 

  
  //  plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_reco");
  //  plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //      plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_reco");

  //  plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_wosdd_defaultmaterial_reco");
  //  plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_wosdd_defaultmaterial_prim");
  //      plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_wosdd_defaultmaterial_prim");
  //  plugin->SetGridWorkingDir("02102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_wosdd_defaultmaterial_reco");


  //  plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_reco");
  //    plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //  plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //    plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_reco");


  //     plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_wosdd_defaultmaterial_reco");
  //  plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_wosdd_defaultmaterial_prim");
  //    plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_wosdd_defaultmaterial_prim");
  //  plugin->SetGridWorkingDir("05102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_wosdd_defaultmaterial_reco");

  //  plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_reco");
  //      plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //  plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_prim");
  //      plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_defaultmaterial_reco");

  //plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_wosdd_defaultmaterial_reco");
  //  plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_wosdd_defaultmaterial_prim");
  //  plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_wosdd_defaultmaterial_prim");
  //  plugin->SetGridWorkingDir("06102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_wosdd_defaultmaterial_reco");


  //   plugin->SetGridWorkingDir("08102019_AMPTpPb_centrality_multiplicity");
  //    plugin->SetGridWorkingDir("08102019_EPOSpPb");

  
  //    plugin->SetGridWorkingDir("11102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_minusmaterial_prim");
  //  plugin->SetGridWorkingDir("11102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_minusmaterial_reco");

  //          plugin->SetGridWorkingDir("11102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_minusmaterial_prim");
  //          plugin->SetGridWorkingDir("11102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_minusmaterial_reco");

  
  //  plugin->SetGridWorkingDir("13102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_plusmaterial_prim");
  //  plugin->SetGridWorkingDir("13102019_AMPTpPb_TPCFMD_AOD228_OADBfix_fine_fast_plusmaterial_reco");
  //      plugin->SetGridWorkingDir("13102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_plusmaterial_prim");
  //  plugin->SetGridWorkingDir("13102019_AMPTpPb_TPCFMDC_AOD228_OADBfix_fine_fast_plusmaterial_reco");


  //      plugin->SetGridWorkingDir("15102019_AMPTpPb_FMDFMD_AOD228_fast_prim_part1");
  //      plugin->SetGridWorkingDir("hoge_v4");

  //  plugin->SetGridWorkingDir("15102019_AMPTpPb_FMDFMD_AOD228_wosdd_prim_part1");
  //  plugin->SetGridWorkingDir("15102019_AMPTpPb_FMDFMD_AOD228_wosdd_prim_part2");


  //      plugin->SetGridWorkingDir("17102019_AMPTpPb_TPCFMD_AOD228_fast_prim_part1_calib");
  //plugin->SetGridWorkingDir("17102019_AMPTpPb_TPCFMD_AOD228_fast_prim_part2_calib");
  
  //  plugin->SetGridWorkingDir("17102019_AMPTpPb_TPCFMD_AOD228_wosdd_prim_part1_calib");
  //    plugin->SetGridWorkingDir("17102019_AMPTpPb_TPCFMD_AOD228_wosdd_prim_part2_calib");

  //    plugin->SetGridWorkingDir("21102019_AMPTpPb_V0mult");
  //  plugin->SetGridWorkingDir("21102019_AMPTpPb_V0cut_half");
  //    plugin->SetGridWorkingDir("21102019_AMPTpPb_V0cut_half_modified");
  //     plugin->SetGridWorkingDir("21102019_AMPTpPb_tightV0cut_half_modified_v3");
  //  plugin->SetGridWorkingDir("22102019_AMPTpPb_calibprimaryV0A_test");

  //  plugin->SetGridWorkingDir("22102019_AMPTpPb_calibprimaryV0A_FMDFMD_part1");
  //  plugin->SetGridWorkingDir("22102019_AMPTpPb_calibprimaryV0A_FMDFMD_modifieddeltaphibin_part1");
  //plugin->SetGridWorkingDir("22102019_AMPTpPb_calibprimaryV0A_FMDFMD_modifieddeltaphibin_part2");

  //  plugin->SetGridWorkingDir("22102019_AMPTpPb_calibprimaryV0A_FMDFMD_modifieddeltaphibin_fast_part1");
  //  plugin->SetGridWorkingDir("22102019_AMPTpPb_calibprimaryV0A_FMDFMD_modifieddeltaphibin_fast_part2");


  //  plugin->SetGridWorkingDir("20112019_AMPTpPB_calibcentbyfixedV0Amult");

  //  plugin->SetGridWorkingDir("20112019_AMPTpPB_calibprimaryV0A_TPCFMDA_reconst_LHC19h12afast_part1_");
  //
  //  plugin->SetGridWorkingDir("21112019_EPOSpPB_V0A_TPCFMDA_reconst_LHC19h12afast_part1");


  //plugin->SetGridWorkingDir("02122019_AMPTpPB_calibcentbyfixedV0Amult");
  //    plugin->SetGridWorkingDir("03122019_PHYTHIA");
  //  plugin->SetGridWorkingDir("05122019_PHYTHIA_all");
  //  plugin->SetGridWorkingDir("17122019_EPOS_pp");
  //plugin->SetGridWorkingDir("pPb_Efficiency_AMPT_20200302");
  


  //plugin->SetGridWorkingDir("pPb_Efficiency_EPOS_20200302");
  
  //  plugin->SetGridWorkingDir("pp_Efficiency_18c12_20200302");

  //  plugin->SetGridWorkingDir("pp_Efficiency_18c12_20200302_properaliroot");
  //  plugin->SetGridWorkingDir("pp_Efficiency_18c12_20200302_properaliroot_modiOCDB");
  //  plugin->SetGridWorkingDir("pp_Efficiency_18c12_20200302_properaliroot_modiAODB");
  //  plugin->SetGridWorkingDir("hoge");
  //  plugin->SetGridWorkingDir("hoge_properaliroot");
  //  plugin->SetGridWorkingDir("hoge_properaliroot_1");
  //  plugin->SetGridWorkingDir("hoge_properaliroot_2");
  //  plugin->SetGridWorkingDir("hoge_properaliroot_3");
  //  plugin->SetGridWorkingDir("pp_18c12_20200302");
  //  plugin->SetGridWorkingDir("pp_18c12_20200304");
  plugin->SetGridWorkingDir("pPb_Efficiency_DPMJETcent_20200309_filterbit32");

  // Declare alien output directory. Relative to working directory.
  plugin->SetGridOutputDir("output"); // In this case will be $HOME/work/output
  plugin->SetUser("ysekiguc");
  // Declare the analysis source files names separated by blancs. To be compiled runtime
  // using ACLiC on the worker nodes.

  plugin->SetAnalysisSource("AliAnalysisTaskSEpPbCorrelationsForward.cxx");
  // Declare all libraries (other than the default ones for the framework. These will be
  // loaded by the generated analysis macro. Add all extra files (task .cxx/.h) here.

  plugin->AddIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include  -I$ALICE_ROOT/ITS -I$ALICE_ROOT/TPC -I$ALICE_ROOT/CONTAINERS -I$ALICE_ROOT/STEER/STEER -I$ALICE_ROOT/STEER/STEERBase -I$ALICE_ROOT/STEER/ESD -I$ALICE_ROOT/STEER/AOD -I$ALICE_ROOT/TRD -I$ALICE_ROOT/macros -I$ALICE_ROOT/ANALYSIS  -I$ALICE_ROOT/OADB -I/$ALICE_PHYSICS/OADB -I$ALICE_ROOT/PWGHF -I$ALICE_ROOT/PWGHF/base -I$ALICE_ROOT/PWGHF/vertexingHF -I$ALICE_ROOT/PWG/FLOW/Base -I$ALICE_ROOT/PWG/FLOW/Tasks -I$ALICE_ROOT/PWGDQ/dielectron -I$ALICE_ROOT/PWGCF/Correlations/macros/underlyingevent -I$ALICE_ROOT/VZERO -I$ALICE_ROOT/PWG/Tools -I$ALICE_ROOT/PWGCF/Correlations/Base -I$ALICE_ROOT/PWGCF/Correlations/DPhi -I$ALICE_ROOT/PWGLF/FORWARD/analysis2  -I$ALICE_ROOT/OADB/COMMON    -g");

   plugin->SetAdditionalLibs("libCore.so  libTree.so  libGeom.so  libVMC.so  libPhysics.so libSTEERBase.so libESD.so  libAOD.so  libANALYSIS.so  libANALYSISalice.so libCORRFW.so  libPWGTools.so  libPWGGlauber.so libPWGflowBase.so libPWGCFCorrelationsBase.so libPWGCFCorrelationsDPhi.so  libPWGCFCorrelationsJCORRAN.so libPWGLFforward2.so  libOADB.so  libADbase.so libADrec.so libADsim.so libVZERObase.so libVZEROrec.so  libVZEROsim.so AliAnalysisTaskSEpPbCorrelationsForward.h  AliAnalysisTaskSEpPbCorrelationsForward.cxx");

   // Declare the output file names separated by blancs.
   // (can be like: file.root or file.root@ALICE::Niham::File)
     plugin->SetDefaultOutputs("");
   //  plugin->SetDefaultOutputs();

   // Optionally define the files to be archived.
   //   plugin->SetOutputArchive("log_archive.zip:stdout,stderr@ALICE::NIHAM::File root_archive.zip:*.root@ALICE::NIHAM::File");
   //   plugin->SetOutputArchive("log_archive.zip:stdout,stderr");

   // Optionally set a name for the generated analysis macro (default MyAnalysis.C)
   plugin->SetAnalysisMacro("TaskPt.C");

   // Optionally set maximum number of input files/subjob (default 100, put 0 to ignore)
   if(data.Contains("LHC16q") )plugin->SetNrunsPerMaster(35);
   else if(data.Contains("LHC15n"))plugin->SetNrunsPerMaster(35);
   else if(  data.Contains("LHC17f2b_fast") ||data.Contains("LHC17f2a_fast") )plugin->SetNrunsPerMaster(35);
   else if(  data.Contains("LHC19h12") )plugin->SetNrunsPerMaster(35);
   else plugin->SetNrunsPerMaster(35);

   if(isMC){
	 //plugin->SetSplitMaxInputFileNumber(5);
     	//plugin->SetSplitMaxInputFileNumber(5);

     
     if(data.Contains("18a9"))plugin->SetSplitMaxInputFileNumber(200);
     //     else      plugin->SetSplitMaxInputFileNumber(10);
     else      plugin->SetSplitMaxInputFileNumber(200);
   }else{
     if(fAOD){
       //plugin->SetSplitMaxInputFileNumber(10);
       //       plugin->SetSplitMaxInputFileNumber(20);
       //       plugin->SetSplitMaxInputFileNumber(20);
       //        plugin->SetSplitMaxInputFileNumber(50);
       plugin->SetSplitMaxInputFileNumber(10);

     }else{
       plugin->SetSplitMaxInputFileNumber(100);
     }
   }

   // Optionally modify the executable name (default analysis.sh)
   plugin->SetExecutable("TaskPt.sh");

   // Optionally set number of failed jobs that will trigger killing waiting sub-jobs.
   //   plugin->SetMaxInitFailed(5);

   // Optionally resubmit threshold.
   //   plugin->SetMasterResubmitThreshold(90);

   // Optionally set time to live (default 30000 sec)
   plugin->SetTTL(30000);

   // Optionally set input format (default xml-single)
   plugin->SetInputFormat("xml-single");

   // Optionally modify the name of the generated JDL (default analysis.jdl)
   plugin->SetJDLName("TaskPt.jdl");

   // Optionally modify job price (default 1)
   plugin->SetPrice(1);

   // Optionally modify split mode (default 'se')
   plugin->SetSplitMode("se");

   return plugin;
}
