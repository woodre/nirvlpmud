inherit "room/room";
reset(arg) {
   if (arg) return;
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
   items=
   ({
         "button","push it to exit the command center",
         "panel","this panel seems to run the transporter.  Look at the button",
    });
   dest_dir=
   ({
    });
}
short(){
   return "Power Ranger Command Center";
}
init() {
call_other(this_player(),"move_player","X#/players/beck/Rangers/Room/CommandCenter.c");
   ::init();
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
