inherit "room/room";
reset(arg) {
   object flytrap1, flytrap2, flytrap3;
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "This is a large field covered with tall grass.  There is one\n"+
   "large tree here too.  You can see the ocean down below you,\n"+
   "but it is impossible to reach.  A small path here leads to some sand\n"+
   "dunes, while the field spreads out around you.  There is a large number\n"+
   "of plant species here.  Some look extremly dangerous.\n"+
   "",
   items=
   ({
         "path","This is a narrow path leading up to some sand dunes.  You can wander up it",
         "ocean","The ocean stretches out for miles and miles",
         "dunes","large sand dunes covered with tall, sharp grass",
         "grass","The grass blows gently in the wind",
         "trees","A giant elm tree stands high above the field.\n"+
         "Maybe you should try to climb them",
         "field","A large field covered with grass.  It seems you can walk to the other part",
    });
   dest_dir=
   ({
    });
   if(!present("flytrap 1", this_object())){
      move_object(clone_object("/players/beck/monster/large_flytrap.c"), this_object());
   }
   if(!present("flytrap 2", this_object())){
      move_object(clone_object("/players/beck/monster/large_flytrap.c"), this_object());
   }
   if(!present("flytrap 3", this_object())){
      move_object(clone_object("/players/beck/monster/large_flytrap.c"), this_object());
   }
}
init() {
   ::init();
   this_player()->set_fight_area();
   add_action("wander","wander");
   add_action("walk","walk");
   add_action("climb","climb");
}
exit() { if(this_player()) this_player()->clear_fight_area(); }
wander(arg) {
   if(!arg) {write("Where do you want to wander?\n");
      return 1;
   }
   if(arg !="path") {
      write("The only place to wander here is a path.\n");
      return 1;
   }
   write("You wander up the path into the dunes.\n");
   call_other(this_player(),"move_player","path#/players/beck/room/venus3.c");
   return 1;
}
walk(arg) {
   if(!arg) {write("You can walk to the waterfront or to the field.\n"); return 1;}
   if(arg=="waterfront") {
      write("You stroll down to the waterfront.\n");
      call_other(this_player(),"move_player","walk#/players/beck/room/venus9.c");
      return 1;
   }
   if(arg=="field") {
      write("You walk to the other part of the field.\n");
      call_other(this_player(),"move_player","walk#/players/beck/room/venus7.c");
      return 1;
   }
}
climb(arg) {
   if(!arg){write("What are you going to climb? \n"); return 1;}
   if(arg=="elm"){
      write("You climb the giant elm tree.\n"); 
      call_other(this_player(),"move_player","climb#/players/beck/room/venus_elm.c");
      return 1;
   }
   write("You can only climb the elm tree here.\n");
   return 1;
}
