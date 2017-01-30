#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"
static object Target;
static int Autolook;
static object CommTower;
static status LiveUpdate;

id(str){
   return str == "spy satellite";
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
   }
   if(Online){
      enable_commands();
      move_object(TO,ENV(Base));
   }
}

Configure(str){
   string target;
   if(str == "online"){
      if(Online){
         write(Name+" is already Online.\n");
         return 1;
      }
      write(Name+" is Online.\n");
      enable_commands();
      move_object(TO,ENV(Base));
      SOnline(1);
   }
   else if(str == "offline"){
      if(!Online){
         write(Name+" is already Offline.\n");
         return 1;
     }
      write(Name+" is Offline.\n");
      move_object(TO,ENV(Base));
      Autolook = 0;
      Target = 0;
      SOnline(0);
   }
   else if(sscanf(str,"transmit %d",Autolook) == 1){
      write(Name+" is configured to transmit every "+Autolook+" seconds.\n");
      call_out("Autolook",Autolook);
   }
   else if(sscanf(str,"track %s",target) == 1){
      if(present(target, environment(TO))){
         write(Name+" is configured to track "+capitalize(target)+".\n");
         Target = present(target, environment(TO));
         call_out("Track",20);
      }
      else {
         write(capitalize(str)+" is not present to track.\n");
         return 1;
      }
   }
   else if(command(str, TO)){
      write(Name+" is doing "+str+".\n");
      return 1;
   }
   else {
      write(capitalize(str)+" is not a configuration option for "+Name+"\n");
      return 1;
   }
   Base->AData(Name, ({Online}));
   return 1;
}

Monitor(){
   write(Name+"\n\n");
   write(Online ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
   write("\n");
   if(Online && Autolook)
      write("Transmitting data every "+Autolook+" seconds.\n");
   if(Online && Target)
      write("Tracking is ON.  Target: "+Target->query_name()+"\n");
   return 1;
}

   
Autolook(){
   object ob;
   if(!Autolook)
      return;
   if(!Online)
      return;
   lookout();
   call_out("Autolook",Autolook);
   return 1;
}

Track(){
   if(!Online)
      return;
   if(!Target){
      Target = 0;
      return;
   }
   if(!present(Target, environment(TO)))
      move_object(TO,ENV(Target));
   call_out("Track",20);
   return 1;
}

catch_tell(str){
    if(TP != TO && !LiveUpdate)
      return;
    if(!CommTower)
      CommTower = (object) Base->QCurrEnhancement("Communications Tower 1");
    if(!Online)
      return;
   if(!CommTower)
      return;
   tell_object(CommTower,str);
}
/*
* This routine is called from objects that moves the player.
* Special: direction "X" means teleport.
*/
move_player(dir_dest)
{
   string msgout, msgin;
   string dir, dest;
   object ob;
   int is_light;
   
   if(!dir_dest)
      return 0;
   
   if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
      tell_object(this_object(), "Move to bad dir/dest\n");
      return;
   }
   if (!msgout)
      msgout = "leaves";
   is_light = set_light(0);
   if (is_light < 0)
      is_light = 0;
   move_object(this_object(), dest);
   is_light = set_light(0);
   if (is_light < 0)
      is_light = 0;
   if (!msgin)
      msgin = "arrives";
   lookout();
}

lookout(){
   object ob;
   write(BLUE+"---------------------------"+OFF+RED+"Satellite Trasmission"+OFF+BLUE+"-------------------------"+OFF+"\n");
   environment(this_object())->long();
   for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
      if(ob != this_object()){
if(ob->short())
         write(ob->short()+"\n");
       }
   }
   write(BLUE+"------------------------------"+OFF+RED+"End Trasmission"+OFF+BLUE+"----------------------------"+OFF+"\n");
   return 1;
}
