{
  ofstream outstr("PulseSeqSlow.txt");
  int TimeStep = 16384/4;

  // Set width of all four pulses to the minimum 10ns
  outstr<<"WB 12 11" <<"\r\n";
  // send first command twice, since for some reason first transmission 
  // usually fails
  outstr<<"WB 12 11" <<"\r\n";
  outstr<<"WB 13 11" <<"\r\n";

  // Set all DC voltage offsets to zero
  outstr<<"WD 0 0"<<"\r\n";
  outstr<<"WD 1 0"<<"\r\n";
  outstr<<"WD 2 0"<<"\r\n";
  outstr<<"WD 3 0"<<"\r\n";

  int TriggerBit=0;
  int HighWord=32;
  int LowWord=3;
  bool LEDNum=false;


  // Set trigger pointer to zero
  outstr<<"WW 4 0"<<"\r\n";
  
  while(HighWord<60000)
    {
      //  outstr<<"WW 4 " << uppercase<<hex<<TriggerBit<<"\r\n";
      outstr<<"WW 0 " << uppercase<<hex<<HighWord <<"\r\n";
      outstr<<"WW 2 " << uppercase<<hex<<LowWord <<"\r\n";
      TriggerBit+=1;
      HighWord+=TimeStep;
      if(LEDNum==true)
	{
	  LEDNum=false; 
	  LowWord=3;
	}
      else
	{
	  LEDNum=true;
	  LowWord=12;
	}
    }
  // Terminate the sequence with a null word in the final trigger 
  // table position
  //  outstr<<"WW 4 " <<hex<<TriggerBit<<"\r\n";
  //  outstr<<"WW 0 0000" <<"\r\n";
  // outstr<<"WW 2 0000" <<"\r\n";

  // Set trigger table pointer to zero  
  outstr<<"WW 4 0000"<<"\r\n";

  // Set sequencer for free run mode, and enabled
  outstr<<"WB 10 01"<<"\r\n";

  outstr<<"WD 0 2000"<<"\r\n";
  outstr<<"WD 1 2000"<<"\r\n";
  outstr<<"WD 2 2000"<<"\r\n";
  outstr<<"WD 3 2000"<<"\r\n";

  
  
    
    
  
}
