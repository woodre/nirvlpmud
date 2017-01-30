inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove");
   long_desc=
   "The Boulevard of Angel Grove.\n"+
   "A small alley leads to the piers of Angel Grove.\n"+
   "",
   items=
   ({
         "alley","A small dark alley that leads to some piers.  You can walk into it",
    });
   dest_dir=
   ({
         "players/beck/room/street6.c","west",
         "players/beck/room/street3.c","south",
    });
}
init() {
   ::init();
   add_action("walk","walk");
}
walk(arg){
   if(!arg){write("Where do you want to walk to?\n");return 1;}
   if(arg !="alley"){write("You can only walk down the alley.\n");return 1;}
   write("You walk down the alley to the pier.\n");
   call_other(this_player(),"move_player","walk#/players/beck/room/pier1.c"); return 1;}
