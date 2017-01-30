#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"

id(str){
   return str == "system";
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name,1);
   if(data)
    Online = data[0];
}


Configure(str){
   if(!str){
      write("Configuration Error.  Report to Beck.\n");
      return 1;
   }
   if(str == "online"){
      SOnline(1);
      write(Name+" is now Online\n");
   }
   else if (str == "offline"){
      SOnline(0);
      write(Name+" is now Offline\n");
   }
   else {
      write(str+" is not valid configuration data.\n");
      return 1;
   }
   Base->AData(Name, ({Online}));
   return 1;
}

