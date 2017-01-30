#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"
static int Pulse;
static int count;

id(str){
   return str == "xenon refractor shield";
}

QPower(){
   return Pulse;
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
      Base->RegisterArmor(TO,({"physical",0,0,"pulse"}));
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
      Base->RegisterArmor(TO,({"physical",0,0,"pulse"}));
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
   int X;
   if(!Online)
      return 0;
   if(Pulse <= 0){
      Pulse = 0;
      return 0;
   }
   if(Energon < 10*Pulse){
      Pulse = Energon/10;
      write("The shield begins to weaken.\n");
      Base->AData(Name, ({Online,Pulse,Energon}));
   }
   if(!Pulse){
      write("The shield has shut down.\n");
   }
   X = Pulse*100;
   AEnergon(-Pulse);
   return X;
}
