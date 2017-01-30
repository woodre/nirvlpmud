inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove");
   long_desc=
   "This is Main Street of Angel Grove.\n"+
"Angel Grove park begins to the east.\n"+
   "",
   items=
   ({
         "park","Angel Grove town park...try to walk there",
    });
   dest_dir=
   ({
         "players/beck/room/street3.c","west",
"players/beck/room/park2.c","east",
    });
}
short(){
return "Angel Grove";
}
init(){
   ::init();
   add_action("walk","walk");
}
walk(arg){
   if(!arg){ write("Where do you want to walk to?\n"); return 1;}
   if(arg == "park"){
      write("You walk to the park.\n");
      
      call_other(this_player(),"move_player","walk#/players/beck/room/park.c");
      return 1;
   }
   write("You may only walk to the park from here.\n");
   return 1;
}
