#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
#include "/players/beck/Rangers/CommandCenter/Enhancement.h"

static object Target;
static int Autolook;
static object CommTower;
static status LiveUpdate;

static int Transmission;

id(str){
   return str == "remote camera" || str == "ranger_camera" || str == Name;
}

short(){
   if(TP){
      if(TP->query_guild_name() == "rangers"){
         return Name;
      }
   }
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
   }
   if(Online){
      enable_commands();
      CHANNEL->AddChannel("Power Ranger",TO);
   }
}

Configure(str){
   string target;

   if(COMM){
      if(COMM->QuerySkillLevel("communication") < 12){
         write("You do not have the skill to configure the Remote Camera.\n");
         return 1;
      }
   }

   if(str == "online"){
      if(Online){
         write(Name+" is already Online.\n");
         return 1;
      }
      write(Name+" is Online.\n");
      CHANNEL->AddChannel("Power Ranger",TO);
      enable_commands();
      SOnline(1);
   }
   else if(str == "offline"){
      if(!Online){
         write(Name+" is already Offline.\n");
         return 1;
     }
      write(Name+" is Offline.\n");
      CHANNEL->RemoveChannel("Power Ranger",TO);
      Autolook = 0;
      Target = 0;
      SOnline(0);
   }
   else if(str == "liveupdate"){
      if(!LiveUpdate){
         write(Name+" is in Live Update mode.\n");
         LiveUpdate = 1;
         return 1;
      }
      else {
         write(Name+" is in sleep mode.\n");
         LiveUpdate = 0;
         return 1;
      }

   }
   else if(str == "help"){
      write("Configuration options for "+Name+"\n");
      
      write("syntax is 'configure <option>'\n\n"+
            "online - Turn the Remote Locator on.\n"+
            "offline - Turn the Remote Locator off.\n"+
            "transmit <amt> - The time period between broadcasts.  Longer time saves power.\n"+
            "liveupdate - Turn on update mode which allows the camera to watch the room in real time.\n"+
/*
            "track <person> - Allows the satellite to automatically track a person.\n"+
            "return - Returns the satellite to the Command Center (outside)\n"+
            "<direction> - moves the satellite in the given direction\n"+
*/
            "");
      return 1;
   }

   else if(sscanf(str,"transmit %d",Autolook) == 1){
      write(Name+" is configured to transmit every "+Autolook+" seconds.\n");
      call_out("Autolook",Autolook);
   }
/*
   else if(sscanf(str,"track %s",target) == 1){
      if(present(target, environment(TO))){
         Target = present(target, environment(TO));
         if(Target->query_invis()){
            write(capitalize(str)+" is not present to track.\n");
            return 1;
         }
         if(!(living(Target))){
            write("You don't need to track a non-living object.\n");
            return 1;
         }

         write(Name+" is configured to track "+capitalize(target)+".\n");
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
*/
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
   if(Target->query_invis()){
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
   if(Transmission == 1){
      tell_object(CommTower,BLUE+"---------------------------"+OFF+RED+Name+OFF+BLUE+"-------------------------"+OFF+"\n\n");
   }
   else if(Transmission == 2){
      tell_object(CommTower, str);
   }
   else if(Transmission == 3){
      tell_object(CommTower,"\n\n"+BLUE+"------------------------------"+OFF+RED+"End Trasmission"+OFF+BLUE+"----------------------------"+OFF+"\n");
   }
   else{
      tell_object(CommTower,BLUE+"---------------------------"+OFF+RED+Name+OFF+BLUE+"-------------------------"+OFF+"\n\n");
      tell_object(CommTower,str);
      tell_object(CommTower,"\n\n"+BLUE+"------------------------------"+OFF+RED+"End Trasmission"+OFF+BLUE+"----------------------------"+OFF+"\n");
   }
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
   Transmission = 1;
   write("");
   Transmission = 2;
   environment(this_object())->long();
   for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
      if(ob != this_object()){
         if(ob->short())
            write(ob->short()+"\n");
       }
   }
   Transmission = 3;
   write("");
   Transmission = 0;

 
   return 1;
}

get(){ 
   if(TP->query_guild_name() == "rangers")
      if(COMM->QuerySkillLevel("communication") >= 12)
         return 1;
      else
         return 0;
   else
      return 0;
}

drop(){ return 0; }

query_name(){ return Name; }

QRangerAnsi(){ return ""; }

QRangerColor(){ return ""; }

QRangerType(){ return "<<>>"; }

query_invis(){
   if(TP)
      if(COMM)
         if(COMM->QuerySkillLevel("communication") >= 12)
            return 0;
        
   return 1;
}

valid_teleport(){ 
   return 0;
   if(TP)
      if(COMM)
         if(COMM->QuerySkillLevel("communication") >= 15 && COMM->QuerySkillLevel("teleport") >= 10)
            return 1;
        
   return 0;
} 

query_weight(){ return 3; }   

QMuffles(){ return 1; }
