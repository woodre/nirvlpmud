#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"
static int Pulse;
static int count;

id(str){
   return str == "ion pulse cannon";
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
      Pulse = data[1];
      if(sizeof(data) >= 3)
         Energon = data[2];
   }
   if(Online){
      Base->RegisterWeapon(TO,({"physical",0,"pulse"}));
      move_object(TO,ENV(Base));
   }
}

Configure(str){
   int temp;
   if(str == "online"){
      if(Online){
         write(Name+" is already Online.\n");
         return 1;
      }
      write(Name+" is Online.\n");
      Base->RegisterWeapon(TO,({"physical",0,"pulse"}));
      move_object(TO,ENV(Base));
      SOnline(1);
   }
   else if(str == "offline"){
      if(!Online){
         write(Name+" is already Offline.\n");
         return 1;
         }
      write(Name+" is Offline.\n");
      Base->RemoveWeapon(TO);
      move_object(TO,ENV(Base));
      SOnline(0);
   }
   else if(sscanf(str,"power %d",Pulse) == 1){
      if(Pulse < 0)
         Pulse = 0;
      if(Pulse > 100)
         Pulse = 100;
      write(Name+" is set to "+Pulse+"% power.\n");
   }
   else if(sscanf(str,"energon %d",temp) == 1){
      if(Base->QEnergon("base") >= temp){
         if(Energon + temp > 10000){
            write("That amount would overload the "+Name+"\n");
            return 1;
         }
         write("Allocating "+temp+" Energon for use on "+Name+"\n");
         AEnergon(temp);
         Base->AEnergon(-temp);
      }
      else{
         write("There is not that much energon in the base to allocate.\n");
         return 1;
      }
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
pulse(){
   object atkr;
   int X;
   if(!Online)
      return 0;
   if(!count){
      tell_room(ENVOB,"The Ion Pulse Cannon begins to charge.\n");
      count++;
      return 0;
   }
   if(count == (Pulse/4)){
      if(Energon < Pulse)
         return 0;
      say(BLUE+
         "              ***\n"+
         "            *******\n"+
         "          ***********\n"+
         "            *******\n"+
         "              ***\n"+
         OFF+
         "");
      
      count = 0;
      AEnergon(-Pulse);
      return Pulse;
   }
   else{
      count ++;
      return 0;
   }
}
