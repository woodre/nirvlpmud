#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"
static status type;
static int count;

id(str){
   return str == "missile launcher";
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
   }
   if(Online){
      Base->RegisterWeapon(TO,({"physical",0,"blast"}));
      move_object(TO,ENV(Base));
   }
}

Configure(str){
   if(str == "online"){
      if(Online){
         write(Name+" is already Online.\n");
         return 1;
      }
      write(Name+" is Online.\n");
     Base->RegisterWeapon(TO,({"physical",0,"blast"}));
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
      type = 0;
      SOnline(0);
   }
   else if(str == "explosive"){
      write(Name+" is configured for impact missiles.\n");
      type = 1;
   }
   else {
      write("That is not a configuration option for "+Name+"\n");
      return 1;
   }
   Base->AData(Name, ({Online}));
   return 1;
}


blast(){
   object atkr;
   int X;
   if(!type)
      return 0;
   if(!count){
      tell_room(ENVOB,"A missile goes screaming out of the launcher.\n");
      count++;
      return 0;
   }
   if(count == 3){
      X = random(35);
say(
   BOLD+RED+"     *****  *       ***   **   **  *****\n"+
       "     *      *      *   *  * * * *  *    \n"+
       "     ***    *      *****  *  *  *  ***  \n"+
OFF);
say(BOLD+RED+
       "     *      *      *   *  *     *  *    \n"+
       "     *      *****  *   *  *     *  *****\n"+
       "    ENGULFS THE ROOM AS A MISSILE STRIKES!"+OFF+"\n");
      count = 0;
      return X;
   }
   else{
      count ++;
      return 0;
   }
}
