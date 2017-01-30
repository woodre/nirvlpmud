inherit "room/room";
object zombie;
reset(arg) {
   monster();
if(arg)
   return;
short_desc="Winding Caverns";
long_desc="As you travel through the caverns you can't tell where you came\n"+
          "from!  All the directions look the same!  This is not a place to\n"+
          "be lost in!\n";
set_light(0);
}
init() {
  add_action("south","south");
  ::init();
}
south() {
  this_player()->move_player("south#players/grimm/caverns/cavern7_2");
  return 1;
}
monster() {
   if(!present("zombie")) {
      zombie = clone_object("players/grimm/monster/zombie");
      move_object(zombie,this_object());
   }
}
