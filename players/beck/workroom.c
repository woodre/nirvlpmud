inherit "room/room";
#include "/players/beck/Rangers/RangerDefs.h"
#include "/players/beck/Rangers/Room/Regenerate.h"
reset(arg) {
   object wiztool;
   if(arg) return;
   short_desc=("Ompompannusic");
enable_commands();
set_light(1);
   long_desc=
   items=
   ({
    });
   dest_dir=
   ({
    });
Align = "Power Test";
}
init(){
   add_action("check_power","cpower");
   add_action("wizard_log","wlog");
add_action("Kombat","kombat");
add_action("ATarget","regen");
}
check_power(str){
   int amount;
   if(str){
      if(sscanf(str,"%df",amount) != 1){
         return 1;
      }
   }
   if(str) "/players/beck/closed/Master"->APowerPoints(amount,"Power Test")
      ;
   write("Power:"+"/players/beck/closed/Master"->QPowerPoints("Power Ranger")+"\n");
   write("Test:"+"/players/beck/closed/Master"->QPowerPoints("Power Test")+"\n");
   return 1;
}
wizard_log(str) {
   string reason, action;
   if(!str) {
      command("tail /log/WR/"+this_player()->query_real_name()+"_workreport",this_player());
      return 1;
   }
   if(sscanf(str,"%s#%s",action,reason) != 2) {
      write("Usage: wlog action#reason\ni.e. wlog heal me#I was hurt.\n");
      return 1;
   }
   else {
      write_file("/log/WR/"+this_player()->query_real_name()+"_workreport",ctime()+"--Action: "+action+" Reason: "+reason+"\n");
      write("Wrote: Action: "+action+" Reason: "+reason+", to /log/WR/"+this_player()->query_real_name()+"_workreport.\n");
      return 1;
   }
}
Kombat(){
this_player()->move_player("Mortal Kombat#/players/beck/MortalKombat/Temple.c");
return 1;
}
heart_beat(){
Regenerate();
}
