inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc=("???");
   long_desc=
   "This part of the cave is shrouded by a thick fog.\n"+
   "The humidity is so high you begin to sweat.\n"+
   "All around you are solid granite walls.\n"+
   "On one side of the room you can see a faint green glow.\n"+
   "",
   items=
   ({
         "glow","Upon closer inspection you figure out this is a portal of some type",
         "portal","A portal to the unknown.  You can 'enter' it",
         "tunnel","A tunnel leading deep into the cave.  Try and walk there",
    });
   dest_dir=
   ({
    });
}
init() {
   ::init() ;
   add_action("walk","walk");
   add_action("enter","enter");
}
enter(arg){
   if(!arg){ write("What are you going to enter?\n"); return 1; }
   if(arg == "portal"){
      this_player()->move_player("enter#/players/beck/DarkRangers/Room/ZedChamber.c");
      return 1;
   }
   write("You can only enter the portal.\n");
   return 1;
}
walk(arg){
   if(!arg){write("Where to you want to walk to?\n");return 1;}
   if(arg=="tunnel"){
      call_other(this_player(),"move_player","walk#/players/beck/room/venus_cave1.c");
      return 1;
   }
   write("You can only walk in the tunnel.\n"); return 1;}
