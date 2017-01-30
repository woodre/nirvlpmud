inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove");
   long_desc=
   "This is the beginning of Main Street in Angel Grove.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
         "players/beck/room/street2.c","east",
         "players/beck/room/square.c","west",
         "players/beck/room/street7.c","north",
    });
   if(!present("gym", this_object())){
      move_object("/players/beck/object/golds_gym.c", this_object()); }
   if(!present("pedestrian 1", this_object())){
      move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
   if(!present("pedestrian 2", this_object())){
      move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
}
short(){
   return "Downtown Angel Grove";
}
