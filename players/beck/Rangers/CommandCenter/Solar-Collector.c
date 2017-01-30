#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/CommandCenter/Enhancement.h"
static int Pulse;
static int count;

id(str){
   return str == "solar collector";
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
      Pulse = data[1];
      Power = data[2];
   }
   if(Online){
      move_object(TO,(Base));
      call_out("collect",300);
   }
}

Configure(str){
   object temp;
   if(str == "online"){
      if(Online){
         write(Name+" is already Online.\n");
         return 1;
      }
      write(Name+" is Online.\n");
      call_out("collect",300);
      move_object(TO,(Base));
      SOnline(1);
   }
   else if(str == "offline"){
      if(!Online){
         write(Name+" is already Offline.\n");
         return 1;
         }
      Pulse = 0;
      write(Name+" is Offline.\n");
      remove_call_out("collect");
      move_object(TO,(Base));
      SOnline(0);
   }
   else if(sscanf(str,"power %d",Pulse) == 1){
      if(Pulse < 0)
         Pulse = 0;
      if(Pulse > 100)
         Pulse = 100;
      if(Base->QEnhancementNum("Xenon Refractor Shield")){
         temp = Base->QCurrEnhancement("Xenon Refractor Shield 1");
         if(temp->QPulse() > (75 - (Pulse/2))){
            write("Your Xenon Refractor Shield is set too high.\n");
            return 1;
         }
         }
      write(Name+" is set to "+Pulse+"% power.\n");
   }
   else if(str == "transfer"){
      Base->APower(Power);
      write("Transporting "+Power+" Power into the Base.\n");
      APower(-Power);
   }
   else if(str == "help"){
      write("Configuration options for "+Name+"\n");
      
      write("syntax is 'configure <option>'\n\n"+
            "online - Turn the Solar Collector on.\n"+
            "offline - Turn the Solar Collector off.\n"+
            "power <amt> - set the collector power as a %.\n"+
            "              The higher the power, the more damage the collector absorbs,\n"+
            "              but it can only be set inversly to the power of the xenon shield.\n"+
            "transfer - move Power from the Solar Collector to the Power Pool.\n"+
            "");
      return 1;
   }
   else {
      write("That is not a configuration option for "+Name+"\n");
      return 1;
   }
   Base->AData(Name, ({Online,Pulse,Power}));
   return 1;
}

Monitor(){
   int i;
   int j;
   write(Name+"\n\n");
   write(Online ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
   write("\n");
   if(Online && Pulse){
      write("Power: [");
      i = Pulse/5;
      if(i <= 5)
         write(RED);
      else if(i >= 15)
         write(GREEN);
      else
         write(YELLOW);
      j = 20 - i;
      while(i){
         write("|");
         i--;
      }
      while(j){
         write(" ");
         j--;
      }
      write(OFF+"] "+Pulse+"%\n");
   }   
   return 1;
}
collect(){
   object temp;
   if(!Online)
      return;
   if(Base->QEnhancementNum("Xenon Refractor Shield")){
      temp = Base->QCurrEnhancement("Xenon Refractor Shield 1");
      if(temp->QPulse() > (75 - (Pulse/2))){
         Pulse = temp->QPulse();
         Pulse = 75-Pulse;
         Pulse = 2*Pulse;
         if(Pulse > 100)
            Pulse = 100;
         if(Pulse < 0)
            Pulse = 0;
      }
   }
   Power += Pulse;
   if(Power > 1000){
      Power = 1000;
      Pulse = 0;
      Online = 0;
      Base->AData(Name, ({Online,Pulse,Power}));
      return;
   }
   else
      call_out("collect",300);
      Base->AData(Name, ({Online,Pulse,Power}));
}
