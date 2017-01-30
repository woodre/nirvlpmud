inherit "room/room";
init() {
   ::init();
   add_action("walk","walk");
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove Pier");
   long_desc=
   "This is one of the piers along the waterfront of Angel Grove.\n"+
   "There are several boats that can take you places here.\n"+
   "Maybe you should look at a boat and see where you can go.\n"+
   "There is a small alley located at one end of the pier.\n"+
   "",
   items=
   ({
         "arctic", "Bring some warm clothes!",
         "alley", "It appears you can walk through this alley",
    });
   dest_dir=
   ({
    });
if(!present("boat", this_object())){
move_object("/players/beck/object/arctic_boat.c", this_object());
}
}
walk(arg) {
   if(!arg){write("Where do you want to walk?\n");return 1;}
   if(arg=="pier"){write("Sorry the other pier is closed.\n");return 1;}
   if(arg=="alley"){write("You walk through the alley.\n");
      call_other(this_player(),"move_player","walk#/players/beck/room/street5.c");
      return 1;
   }
   write("You can only walk in the alley or to the other pier.\n");return 1;}
