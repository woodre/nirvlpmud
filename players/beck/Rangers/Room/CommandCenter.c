inherit "room/room";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
#include "/players/beck/Rangers/Room/Regenerate.h"
reset(arg) {
   if (arg) return;
   Align = "Power Ranger";
   short_desc=("Power Ranger Command Center");
   long_desc=
   "This is the main control center of the power rangers.\n"+
   "All around you are computer consoles and strange inventions.\n"+
   "It almost seems as if one could control the entire world from here.\n"+
   "There are so many switches and buttons it almost boggles your mind.\n"+
   "Glancing around you notice one button that looks to be important.\n"+
   "Upon closer inspection you notice it is on the transporter control panel.\n"+
   "",
   set_light(1);
   enable_commands();
   items=
   ({
         "button","push it to exit the command center",
         "panel","this panel seems to run the transporter.  Look at the button",
    });
   dest_dir=
   ({
    });
   if(!present("globe", this_object())){
      move_object("/players/beck/Rangers/ViewingGlobe.c", this_object());}
   if(!present("alpha", this_object())){
      move_object("/players/beck/monster/alpha.c", this_object());}
   if(!present("zordon", this_object())){
      move_object("/players/beck/Rangers/Npc/Zordon.c", this_object()); }
}
short(){
   return "Power Ranger Command Center";
}
init() {
   ::init();
   add_action("push","push");
   add_action("ATarget","regen");
   add_action("RTarget","regen_stop");
}
push(arg){
   if(!arg){write("Push what?\n"); return 1;}
   if(arg !="button"){write("You need to push the button.\n"); return 1;}
   call_other(this_player(),"move_player","teleport#/players/beck/room/mountain1.c");
   return 1;
}
realm(){
   if(this_player())
      if(this_player()->query_guild_name() != "rangers"){
      return "NT";
   }
   else
      return;
}
query_NM(){
   if(this_player())
      if(this_player()->query_guild_name() != "rangers"){
      return 1;
   }
   else
      return;
}
heart_beat(){
   Regenerate();
}
