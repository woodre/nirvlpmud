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
   add_action("east","east");
   add_action("south","south");
   add_action("down","down");
   ::init();
}
east() {
   this_player()->move_player("east#players/grimm/caverns/cavern1_2");
   return 1;
}
down() {
    this_player()->move_player("down#players/grimm/caverns/demonroom");
    return 1;
}
south() {
   this_player()->move_player("south#players/grimm/caverns/cavern3_2");
   return 1;
}
