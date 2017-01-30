inherit "room/room";
reset(arg) {
   object invflytrap;
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "This is the middle of a large field.  All around you \n"+
   "is tall grass.  There are several trees here, as well as a path\n"+
   "leading into some sand dunes.  You notice some steep cliffs\n"+
   "on one side and more of the field on another.  It also seems you can go\n"+
"down to the waterfront from here.\n"+
   "",
   items=
   ({
         "waterfront","The waterfront lies just a little ahead.  You could walk there",
         "dunes","These are large sand dunes covered with long grass",
         "grass","The grass blows gently in the wind",
         "cliffs","These are very steep.  You could probally walk over to them",
         "path","A narrow path.  You could probally wander down it",
         "field","A large field covered with grass.  You could \n"+
         "probally walk over to the other part",
"trees","A grove of birch trees and a giant oak tree rising high above them",
    });
   dest_dir=
   ({
    });
   if(!present("flytrap", this_object())){
      move_object(clone_object("/players/beck/monster/invflytrap.c"), this_object());
   }
}
init() {
   ::init() ;
this_player()->set_fight_area();
   add_action("walk","walk");
   add_action("wander","wander");
add_action("climb","climb");
add_action("show","show");
}
exit(){ if(this_player()) this_player()->clear_fight_area(); }
walk(arg) {
   if(!arg) {write("You can walk to the waterfront, cliffs, or field.\n"); return 1;}
   if(arg=="field") {
      write("You walk to the other part of the field.\n");
      call_other(this_player(),"move_player","walk#/players/beck/room/venus6.c");
      return 1;
   }
   if(arg=="waterfront") {
      write("You walk to the waterfront.\n");
      call_other(this_player(),"move_player","walk#/players/beck/room/venus10.c");
      return 1;
   }
   if(arg=="cliffs") {
      write("You walk over to the cliffs.\n");
      call_other(this_player(),"move_player","walk#/players/beck/room/venus8.c");
      return 1;
   }
}
show(){
write("No Clean: "+no_clean+"\n");
return 1;
}
wander(arg) {
   if(!arg) {write("Where are you going to wander?\n"); return 1;}
   if(arg !="path") {
      write("The only place here to wander is the path.\n");
      return 1; }
   write("You wander up the path into the dunes.\n");
   call_other(this_player(),"move_player","path#/players/beck/room/venus4.c");
   return 1;
}
climb(arg){
if(!arg){ write("What do you want to climb?\n"); return 1; }
if(arg == "oak"){
write("You climb the giant oak tree.\n");
call_other(this_player(),"move_player","climb#/players/beck/room/venus_oak.c");
return 1;
}
write("You can only climb the oak tree.\n");
return 1;
}
