#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"
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
      Energon = data[2];
   }
   if(Online){
      move_object(TO,ENV(Base));
      call_out("collect",500);
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
      call_out("collect",500);
      move_object(TO,ENV(Base));
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
      move_object(TO,ENV(Base));
      SOnline(0);
   }
   else if(sscanf(str,"power %d",Pulse) == 1){
      if(Pulse < 0)
         Pulse = 0;
      if(Pulse > 100)
         Pulse = 100;
      if(Base->QEnhancementNum("Xenon Refractor Shield")){
         temp = Base->QCurrEnhancement("Xenon Refractor Shield 1");
         if(temp->QPower() > (75 - (Pulse/2))){
            write("Your Xenon Refractor Shield is set too high.\n");
            return 1;
         }
         }
      write(Name+" is set to "+Pulse+"% power.\n");
   }
   else if(str == "energon"){
      Base->AEnergon(Energon);
      write("Transporting "+Energon+" Energon into the Base.\n");
      AEnergon(-Energon);
   }
   else {
      write("That is not a configuration option for "+Name+"\n");
      return 1;
   }
   Base->AData(Name, ({Online,Pulse,Energon}));
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
      if(temp->QPower() > (75 - (Pulse/2))){
         Pulse = temp->QPower();
         Pulse = 75-Pulse;
         Pulse = 2*Pulse;
         if(Pulse > 100)
            Pulse = 100;
         if(Pulse < 0)
            Pulse = 0;
      }
   }
   Energon += Pulse;
   if(Energon > 1000){
      Energon = 1000;
Pulse = 0;
Online = 0;
      Base->AData(Name, ({Online,Pulse,Energon}));
      return;
   }
   else
      call_out("collect",500);
   Base->AData(Name, ({Online,Pulse,Energon}));
}
