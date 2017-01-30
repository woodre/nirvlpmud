inherit "room/room";
reset(arg) {
if(arg)
   return;
short_desc="Winding Caverns";
long_desc="As you travel through the caverns you can't tell where you came\n"+
          "from!  All the directions look the same!  This is not a place to\n"+
          "be lost in!\n";
set_light(0);
}
init() {
   add_action("north","north");
   add_action("south","south");
   add_action("west","west");
   ::init();
}
south() {
   this_player()->move_player("south#players/grimm/caverns/cavern9_2");
   return 1;
}
west() {
   this_player()->move_player("west#players/grimm/caverns/cavern4_2");
   return 1;
}
north() {
   this_player()->move_player("north#players/grimm/caverns/cavern2_2");
   return 1;
}
