inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "You climb up over the rocks, and end up in a hidden clearing.\n"+
   "You are surrounded by large pieces of granite on all sides.  Grass covers\n"+
   "this tiny oasis.  You spot a small cave in one of the rocks.  It looks\n"+
   "very dark inside.  A tiny stream here runs through the rock and leads\n"+
   "into the ocean.\n"+
   "",
   items=
   ({
         "rocks","These are large boulders of granite",
         "stream","A brook of crystal clear water. Maybe you can go for a swim."+
         "Be careful though.  Some of the fish appear to be quite hungry",
         "grass","The grass here is dark green.  It is perfectly sheltered\n"+
         "from any harsh enviornment",
         "cave","A small cave.  It is hard to see inside without entering it",
    });
   dest_dir=
   ({
    });
   if(!present("morihei", this_object())){
move_object("/players/beck/monster/aikido.c", this_object());
   }
}
init() {
   ::init() ;
   add_action("enter","enter");
   add_action("climb","climb");
   add_action("swim","swim");
}
climb(arg) {
   if(!arg) {write("What do you want to climb?\n"); return 1;}
   if(arg !="rocks") {
      write("You can only climb the rocks.\n");
      return 1;
   }
   write("You climb over the rocks.\n");
   call_other(this_player(),"move_player","climb#/players/beck/room/venus8.c");
   return 1;
}
swim(arg) {
   if(!arg) {write("Where do you want to swim?\n"); return 1;}
   if(arg !="stream") {write("You can only swim in the stream.\n"); return 1;}
   write("You take a swim in the stream.\n");
   call_other(this_player(),"move_player","swim#/players/beck/room/vstream.c");
   return 1;
}
enter(arg){
   if(!arg){ write("What will you enter?\n"); return 1;}
   if(arg == "cave"){
      write("You cautiously enter the cave.\n");
      call_other(this_player(),"move_player","enter#/players/beck/room/venus_cave1.c");
      return 1;
   }
   write("You can only enter the cave.\n");
   return 1;
}

query_no_fight(){ return 1; }
