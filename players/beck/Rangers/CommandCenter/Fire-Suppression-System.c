#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/CommandCenter/Enhancement.h"
static int Pulse;
static int count;

id(str){
   return str == "fire suppression system";
}

QPulse(){
   return Pulse;
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
   }
   if(Online){
      Base->RegisterArmor(TO,({"other|fire",0,0,"pulse"}));
      move_object(TO,(Base));
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
      Base->RegisterArmor(TO,({"other|fire",0,0,"pulse"}));
      move_object(TO,(Base));
      SOnline(1);
   }
   else if(str == "offline"){
      if(!Online){
         write(Name+" is already Offline.\n");
         return 1;
         }
      write(Name+" is Offline.\n");
      Base->RemoveArmor(TO);
      move_object(TO,(Base));
      SOnline(0);
   }
   
   
   else if(str == "help"){
      write("Configuration options for "+Name+"\n");
      
      write("syntax is 'configure <option>'\n\n"+
            "online - Turn the Fire Suppression System on.\n"+
            "offline - Turn the Fire Suppression System off.\n"+

            "");
      return 1;
   }
   else {
      write("That is not a configuration option for "+Name+"\n");
      return 1;
   }
   Base->AData(Name, ({Online}));
   return 1;
}

Monitor(){
   int i;
   int j;
   write(Name+"\n\n");
   write(Online ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
   write("\n");
   
   return 1;
}

pulse(){
   
   if(!Online)
      return 0;
   write("The Fire Suppression System puts out a large fire.\n");
   return 5000;
}
