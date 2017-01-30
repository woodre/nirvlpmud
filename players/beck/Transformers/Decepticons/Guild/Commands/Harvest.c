#include "/players/beck/Defs.h"

DecepticonCommand(str){
   string temp1, temp2;
int temp3;
   if(!str){
      write("What do you wish to harvest?\n");
      return 1;
   }
   if(sscanf(str, "%s %d",temp1, temp3) == 2){
      if(ENVTP->UseResource(temp1,temp3))
         {
         PO->AResource(({temp1,temp3}));
         return 1;
      }
   }
else if(sscanf(str,"%s %s %d",temp1, temp2, temp3) == 3){
      temp2 = temp1+"|"+temp2;
      if(ENVTP->UseResource(temp2,temp3))
         {
         PO->AResource(({temp2,temp3}));
         return 1;
         }
   }
   else{
      write("You cannot harvest that.\n");
return 1;
   }
return 1;
}
