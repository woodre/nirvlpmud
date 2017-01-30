inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("???");
   long_desc=
   "Here is a small clearing surrounded by dense forest.\n"+
   "Before you stands a small castle with high granite walls\n"+
   "and a bronze gate.  From within you hear a clashing of weapons.\n"+
   "The path appears to be toward the east.\n"+
   "",
   items=
   ({
         "castle","This is the backside of the castle which houses\n"+
         "the Paladin guild.  It appears unaccessible from this side",
    });
   dest_dir=
   ({
    });
   if(!present("protege", this_object())){
move_object("/players/beck/monster/protege.c",this_object());
   }
}
init() {
   ::init();
   add_action("east","east");
}
east(arg){
   call_other(this_player(),"move_player","east#/players/beck/room/path1.c");
   return 1;
}
