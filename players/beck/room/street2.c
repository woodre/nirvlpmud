inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove");
   long_desc=
   "This is part of Main Street in the town of Angel Grove.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
         "players/beck/room/street3.c","east",
         "players/beck/room/street1.c","west",
         "players/beck/room/street6.c","north",
    });
if(!present("war memorial", this_object()))
move_object("/players/beck/object/WarMemorial.c", this_object());
   if(!present("taco bell", this_object())){
      move_object("/players/beck/object/taco.c", this_object());}
   if(!present("pedestrian 1", this_object())){
      move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
   if(!present("pedestrian 2", this_object())){
      move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
}
short(){
   return "Downtown Angel Grove";
}
