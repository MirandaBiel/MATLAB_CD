  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (identifica_srv02l_problem_P)
    ;%
      section.nData     = 54;
      section.data(54)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% identifica_srv02l_problem_P.EncoderCalibrationradcount_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% identifica_srv02l_problem_P.EncoderHighPassFilter_A
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% identifica_srv02l_problem_P.EncoderHighPassFilter_C
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 20;
	
	  ;% identifica_srv02l_problem_P.PosSrc_Value
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 22;
	
	  ;% identifica_srv02l_problem_P.TachometerCalibrationradsV_Gain
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 23;
	
	  ;% identifica_srv02l_problem_P.SpdSrc_Value
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 24;
	
	  ;% identifica_srv02l_problem_P.DirectionConventionRightHandsys
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 25;
	
	  ;% identifica_srv02l_problem_P.AmplifierSaturationV_UpperSat
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 26;
	
	  ;% identifica_srv02l_problem_P.AmplifierSaturationV_LowerSat
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 27;
	
	  ;% identifica_srv02l_problem_P.InverseAmplifierGainVV_Gain
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 28;
	
	  ;% identifica_srv02l_problem_P.DACBSaturationV_UpperSat
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 29;
	
	  ;% identifica_srv02l_problem_P.DACBSaturationV_LowerSat
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 30;
	
	  ;% identifica_srv02l_problem_P.AmplifierGainVV_Gain
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 31;
	
	  ;% identifica_srv02l_problem_P.TransferFcn_A
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 32;
	
	  ;% identifica_srv02l_problem_P.TransferFcn_C
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 33;
	
	  ;% identifica_srv02l_problem_P.TransportDelay_Delay
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 34;
	
	  ;% identifica_srv02l_problem_P.TransportDelay_InitOutput
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 35;
	
	  ;% identifica_srv02l_problem_P.RateTransition1_X0
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 36;
	
	  ;% identifica_srv02l_problem_P.Definesinaldeentrada_Value
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 37;
	
	  ;% identifica_srv02l_problem_P.SquareWave_Amplitude
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 38;
	
	  ;% identifica_srv02l_problem_P.SquareWave_Frequency
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 39;
	
	  ;% identifica_srv02l_problem_P.Step_Time
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 40;
	
	  ;% identifica_srv02l_problem_P.Step_Y0
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 41;
	
	  ;% identifica_srv02l_problem_P.Step_YFinal
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 42;
	
	  ;% identifica_srv02l_problem_P.Integrator_IC
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 43;
	
	  ;% identifica_srv02l_problem_P.DiscreteTransferFcn_A
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 44;
	
	  ;% identifica_srv02l_problem_P.DiscreteTransferFcn_C
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 45;
	
	  ;% identifica_srv02l_problem_P.DiscreteTransferFcn_D
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 46;
	
	  ;% identifica_srv02l_problem_P.InverseAmplifierGainVV_Gain_k
	  section.data(46).logicalSrcIdx = 50;
	  section.data(46).dtTransOffset = 47;
	
	  ;% identifica_srv02l_problem_P.DACBSaturationV_UpperSat_f
	  section.data(47).logicalSrcIdx = 51;
	  section.data(47).dtTransOffset = 48;
	
	  ;% identifica_srv02l_problem_P.DACBSaturationV_LowerSat_g
	  section.data(48).logicalSrcIdx = 52;
	  section.data(48).dtTransOffset = 49;
	
	  ;% identifica_srv02l_problem_P.AmplifierGainVV_Gain_k
	  section.data(49).logicalSrcIdx = 53;
	  section.data(49).dtTransOffset = 50;
	
	  ;% identifica_srv02l_problem_P.AmplifierSaturationV_UpperSat_d
	  section.data(50).logicalSrcIdx = 54;
	  section.data(50).dtTransOffset = 51;
	
	  ;% identifica_srv02l_problem_P.AmplifierSaturationV_LowerSat_a
	  section.data(51).logicalSrcIdx = 55;
	  section.data(51).dtTransOffset = 52;
	
	  ;% identifica_srv02l_problem_P.StepAmplitude_Gain
	  section.data(52).logicalSrcIdx = 56;
	  section.data(52).dtTransOffset = 53;
	
	  ;% identifica_srv02l_problem_P.StepAmplitude_Gain_j
	  section.data(53).logicalSrcIdx = 57;
	  section.data(53).dtTransOffset = 54;
	
	  ;% identifica_srv02l_problem_P.PotentiometerCalibrationradV_Ga
	  section.data(54).logicalSrcIdx = 58;
	  section.data(54).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 3;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 4;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 5;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 6;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 7;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 65;
	  section.data(7).dtTransOffset = 8;
	
	  ;% identifica_srv02l_problem_P.HILReadAnalogTimebase_Clock
	  section.data(8).logicalSrcIdx = 66;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 8;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 16;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 24;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 32;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 33;
	
	  ;% identifica_srv02l_problem_P.HILReadAnalogTimebase_Channels
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 41;
	
	  ;% identifica_srv02l_problem_P.HILReadAnalogTimebase_SamplesIn
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 43;
	
	  ;% identifica_srv02l_problem_P.HILReadEncoder_Channels
	  section.data(9).logicalSrcIdx = 75;
	  section.data(9).dtTransOffset = 44;
	
	  ;% identifica_srv02l_problem_P.HILWriteAnalog_Channels
	  section.data(10).logicalSrcIdx = 76;
	  section.data(10).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_P.Constant_Value
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 84;
	  section.data(6).dtTransOffset = 5;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 85;
	  section.data(7).dtTransOffset = 6;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 86;
	  section.data(8).dtTransOffset = 7;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 87;
	  section.data(9).dtTransOffset = 8;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 88;
	  section.data(10).dtTransOffset = 9;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 89;
	  section.data(11).dtTransOffset = 10;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 90;
	  section.data(12).dtTransOffset = 11;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 91;
	  section.data(13).dtTransOffset = 12;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 92;
	  section.data(14).dtTransOffset = 13;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 93;
	  section.data(15).dtTransOffset = 14;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 94;
	  section.data(16).dtTransOffset = 15;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 95;
	  section.data(17).dtTransOffset = 16;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 96;
	  section.data(18).dtTransOffset = 17;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 97;
	  section.data(19).dtTransOffset = 18;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 98;
	  section.data(20).dtTransOffset = 19;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 99;
	  section.data(21).dtTransOffset = 20;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 100;
	  section.data(22).dtTransOffset = 21;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 101;
	  section.data(23).dtTransOffset = 22;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 102;
	  section.data(24).dtTransOffset = 23;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 103;
	  section.data(25).dtTransOffset = 24;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 104;
	  section.data(26).dtTransOffset = 25;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 105;
	  section.data(27).dtTransOffset = 26;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 106;
	  section.data(28).dtTransOffset = 27;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 107;
	  section.data(29).dtTransOffset = 28;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 108;
	  section.data(30).dtTransOffset = 29;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 109;
	  section.data(31).dtTransOffset = 30;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 110;
	  section.data(32).dtTransOffset = 31;
	
	  ;% identifica_srv02l_problem_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 111;
	  section.data(33).dtTransOffset = 32;
	
	  ;% identifica_srv02l_problem_P.HILReadAnalogTimebase_Active
	  section.data(34).logicalSrcIdx = 112;
	  section.data(34).dtTransOffset = 33;
	
	  ;% identifica_srv02l_problem_P.HILReadEncoder_Active
	  section.data(35).logicalSrcIdx = 113;
	  section.data(35).dtTransOffset = 34;
	
	  ;% identifica_srv02l_problem_P.HILWriteAnalog_Active
	  section.data(36).logicalSrcIdx = 114;
	  section.data(36).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (identifica_srv02l_problem_B)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_B.HILReadAnalogTimebase_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_B.HILReadAnalogTimebase_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_srv02l_problem_B.HILReadEncoder
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_srv02l_problem_B.EncoderCalibrationradcount
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_srv02l_problem_B.EncoderHighPassFilter
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_srv02l_problem_B.PositionSourceSwitch
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% identifica_srv02l_problem_B.TachometerCalibrationradsV
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% identifica_srv02l_problem_B.VelocitySourceSwitch
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% identifica_srv02l_problem_B.DirectionConventionRightHandsys
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% identifica_srv02l_problem_B.AmplifierSaturationV
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% identifica_srv02l_problem_B.InverseAmplifierGainVV
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% identifica_srv02l_problem_B.DACBSaturationV
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% identifica_srv02l_problem_B.AmplifierGainVV
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% identifica_srv02l_problem_B.TransferFcn
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% identifica_srv02l_problem_B.TransportDelay
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% identifica_srv02l_problem_B.RateTransition1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% identifica_srv02l_problem_B.SquareWave
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% identifica_srv02l_problem_B.Step
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% identifica_srv02l_problem_B.SwitchControl
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% identifica_srv02l_problem_B.Integrator
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% identifica_srv02l_problem_B.Sum
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% identifica_srv02l_problem_B.RateTransition
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% identifica_srv02l_problem_B.DiscreteTransferFcn
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% identifica_srv02l_problem_B.InverseAmplifierGainVV_e
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% identifica_srv02l_problem_B.DACBSaturationV_j
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% identifica_srv02l_problem_B.AmplifierGainVV_h
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% identifica_srv02l_problem_B.AmplifierSaturationV_h
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% identifica_srv02l_problem_B.PotentiometerCalibrationradV
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% identifica_srv02l_problem_B.MultiportSwitch
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% identifica_srv02l_problem_B.StepAmplitude
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% identifica_srv02l_problem_B.StepAmplitude_k
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (identifica_srv02l_problem_DWork)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.DiscreteTransferFcn_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 9;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_AOMinimums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 17;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_AOMaximums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_AOVoltages
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 33;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_FilterFrequency
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 41;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_POSortedFreqs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 49;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_POValues
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 57;
	
	  ;% identifica_srv02l_problem_DWork.HILReadAnalogTimebase_Buffer
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% identifica_srv02l_problem_DWork.RateTransition1_Buffer0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 67;
	
	  ;% identifica_srv02l_problem_DWork.TransportDelay_RWORK.modelTStart
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 68;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_DWork.HILWriteAnalog_PWORK
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_srv02l_problem_DWork.TransportDelay_PWORK.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_srv02l_problem_DWork.ToWorkspaceModeloExperimental_P.LoggedData
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 4;
	
	  ;% identifica_srv02l_problem_DWork.ToWorkspaceSistemaReal_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 5;
	
	  ;% identifica_srv02l_problem_DWork.VmV_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 6;
	
	  ;% identifica_srv02l_problem_DWork.VmV1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 7;
	
	  ;% identifica_srv02l_problem_DWork.theta_lrad_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 8;
	
	  ;% identifica_srv02l_problem_DWork.w_lrads_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 3;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 11;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 19;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 27;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 35;
	
	  ;% identifica_srv02l_problem_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 43;
	
	  ;% identifica_srv02l_problem_DWork.HILReadEncoder_Buffer
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.HILReadAnalogTimebase_Task
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.TransportDelay_IWORK.Tail
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_srv02l_problem_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1466030293;
  targMap.checksum1 = 1192082236;
  targMap.checksum2 = 2260852482;
  targMap.checksum3 = 681723487;

