#include "/players/beck/Defs.h"
DecepticonCommand(str){
   if(!str){
      ENVTP->MonitorResources();
      return 1;
   }
   else{
      if(present(str,TP)){
         present(str,TP)->MonitorResources();
         return 1;
      }
      else if(present(str,ENVTP)){
         present(str,ENVTP)->MonitorResources();
         return 1;
      }
      else {
         write("That is not present to be scanned.\n");
         return 1;
      }
      return 1;
   }
}
