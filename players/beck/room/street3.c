inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove");
   long_desc=
"This is part of Main Street of Angel Grove.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
"players/beck/room/street4.c","east",
"players/beck/room/street2.c","west",
"players/beck/room/street5.c","north",
    });
   if(!present("center", this_object())){
move_object("/players/beck/object/youth_center.c", this_object());}
   if(!present("pedestrian 1", this_object())){
move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
   if(!present("pedestrian 2", this_object())){
move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
   if(!present("pedestrian 3", this_object())){
move_object(clone_object("/players/beck/monster/pedestrian.c"), this_object());}
}
short(){
return "Downtown Angel Grove";
}
