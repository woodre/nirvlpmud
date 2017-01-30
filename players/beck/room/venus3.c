inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "You are on top of a large sand dune.  The grass here blows\n"+
   "gently in the sea breeze.  There is a small path that starts here\n"+
   "and leads toward a large field.  Looking down towards the ocean\n"+
   "you see a small beach covered with white sand.  The grass here is so\n"+
   "high that is near impossible to go through.\n",
   items=
   ({
         "beach","You see a sandy beach down below.  Maybe you can climb down to it",
         "path","This small path is only one person wide.  You can wander down it to\n"+
         "a large field that lies off in the distance",
         "field","You see a field covered with tall grass at the end of the path",
         "grass","This razor sharp grass sways in the breeze",
         "ocean","The ocean stretches out for miles and miles",
    });
   dest_dir=
   ({
    });
   if(!present("flytrap", this_object())){
move_object(clone_object("/players/beck/monster/giant_flytrap.c"), this_object());
   }
   if(!present("flytrap 2", this_object())){
move_object(clone_object("/players/beck/monster/large_flytrap.c"), this_object());
   }
   if(!present("flytrap 3", this_object())){
move_object(clone_object("/players/beck/monster/large_flytrap.c"), this_object());
   }
   if(!present("flytrap 4", this_object())){
move_object(clone_object("/players/beck/monster/large_flytrap.c"), this_object());
   }
}
init() {
   ::init() ;
   add_action("climb","climb");
   add_action("wander","wander");
}
wander(arg) {
   if(!arg) {write("Where do you want to wander?\n"); return 1;}
   if(arg !="path") {
      write("The only place to wander here is the path.\n");
      return 1;
   }
   write("You wander the path into the field.\n");
call_other(this_player(),"move_player","path#/players/beck/room/venus6.c");
   return 1;
}
climb(arg) {
   if(!arg) {write("Where do you want to climb?\n");
      return 1;
   }
   if(arg !="down") {
      write("The only way you can climb here is down.\n");
      return 1;
   }
call_other(this_player(),"move_player","climb#/players/beck/room/venus1.c");
   return 1;
}
