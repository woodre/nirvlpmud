inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("hall of statues");
   long_desc=
   "You stand in a forest clearing, but this is a forest like none found on\n"
+  "earth. The grass below your feet glow with a vibrant purple color, and\n"
+  "the trees are like none you have seen before. The moon beam you traveled\n"
+  "on is no where to be seen. You see some footprints on the ground before\n"
+  "you.\n";
extra_reset();
   items=
   ({
     "footprints","Several sets of footprints heading northwest",
     "forest","The forest seems to possess an unearthly vibrance to it",
   });
   dest_dir=
   ({
"players/oderus/rooms/hell11","west",
"players/oderus/rooms/hell13","east",
   });
}
extra_reset(){
object monster;
monster=clone_object("players/oderus/monsters/exa1");
if(!present("monti", this_object())){
move_object(monster,this_object());
return;
}
}
