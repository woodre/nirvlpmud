inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "The light becomes dim, almost non existant as you enter the cave.\n"+
   "Looking around you see stalagtites of lime dripping from the ceiling.\n"+
   "The ground is solid granite with tiny streams of water running\n"+
   "across in all directions.  There is a pile of crumbled rocks on one\n"+
   "side while the tunnel seems to continue on straight ahead.\n"+
   "The further you get the less light there is.\n"+
   "You can see daylight coming from the entrance of the cave.\n"+
   "",
   items=
   ({
         "entrance","This leads out of the cave.  Perhaps you can walk there",
         "tunnel","A tunnel leading deep into the cave.  Try and walk there",
    });
   dest_dir=
   ({
    });
}
init() {
   ::init() ;
   add_action("walk","walk");
}
walk(arg){
   if(!arg){write("Where do you want to walk to?\n");return 1;}
   if(arg=="entrance"){
      call_other(this_player(),"move_player","walk#/players/beck/room/venus5.c");
      return 1;
   }
   else if(arg == "tunnel"){
      this_player()->move_player("walk#/players/beck/room/venus_cave2.c");
      return 1;
   }
   write("You can only walk in the tunnel, or to the entrance.\n"); return 1;}
