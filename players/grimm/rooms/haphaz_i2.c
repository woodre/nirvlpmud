inherit "room/room";
object duck, feather;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Feathered Room";
long_desc="This room is the home of a rather large duck.  The walls are\n"+
"covered in feathers of all different colors.  The floor is one huge nest.\n"+
"And the ceiling looks to have been pecked at many times.\n";
  dest_dir=({"players/grimm/rooms/haphaz_h3","southwest"});
set_light(1);

}
init() {
   add_action("southwest","southwest");
   add_action("take","take");
   ::init();
   }
southwest() {
   this_player()->move_player("southwest#players/grimm/rooms/haphaz_h3");
   return 1;
   }
monster() {
int count;

   if(!present("duck")) {
      duck = clone_object("players/grimm/monster/sea_duck");
      move_object(duck, this_object());
   }
}

take(str) {
  if ((str == "feather" || str == "feather from corpse" || str == "feather from duck") && !present("duck")) {
  write("OK.\n");
  feather = clone_object("players/grimm/object/feather");
   move_object(feather,this_player());
   return 1;
 }
return 0;
}
