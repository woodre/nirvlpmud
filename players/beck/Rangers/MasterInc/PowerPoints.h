/* The Guild Power Level (pool) */
mapping PowerPoints;

SPowerPoints(){ 
   PowerPoints = ([ ]);
   PowerPoints["Power Ranger"] = 0;
   PowerPoints["Dark Ranger"] = 0;
   return 1; 
}

QPowerPoints(string channel){
   if(!PowerPoints)
      SPowerPoints();
   return PowerPoints[channel];
}

ResetPowerPoints(string channel){
   PowerPoints[channel] = 0;
}

/*  Called by object or function to add or subtract from guild power */
APowerPoints(num,string channel){
   if(!PowerPoints)
      SPowerPoints();
   if("/players/beck/Rangers/CommandCenter/CommandCenter.c"->PowerCheck(channel))
      PowerPoints[channel] += num;
   else
      return 0;
   if(PowerPoints[channel] > 15000) PowerPoints[channel] = 15000;
"/players/beck/Rangers/CommandCenter/CommandCenter.c"->APower(num,channel);
   return 1;
}

CheckPower(string channel){  /* For Player to Check Guild Power Level */ 
   string msg;
   if(!PowerPoints)
      SPowerPoints();
   if(PowerPoints[channel] == 0){
      msg = "Guild Power is GONE"; }
   if(PowerPoints[channel] > 0){
      msg = "Guild Power Levels are critical"; }
   if(PowerPoints[channel] > 100){
      msg = "Guild Power is very low"; }
   if(PowerPoints[channel] > 300){
      msg = "Guild Power is low"; }
   if(PowerPoints[channel] > 600){
      msg = "Guild Power is at normal levels"; }
   if(PowerPoints[channel] > 1200){
      msg = "Guild Power is in good shape"; }
   if(PowerPoints[channel] > 2000){
      msg = "Guild Power levels are very good"; }
   if(PowerPoints[channel] > 9999){
      msg = "Guild Power levels are Full"; }
   if(!this_player())
      return "GUILD POWER LEVEL: "+QPowerPoints(channel)+".\n";
   write("GUILD POWER LEVEL: "+QPowerPoints(channel)+".\n");
   return 1;
}

