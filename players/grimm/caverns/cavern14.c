inherit "room/room";
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
   add_action("west","west");
   add_action("east","east");
   ::init();
}
south() {
   if(!present("zombie")) {
      this_player()->move_player("south#players/grimm/caverns/cavern15");
      return 1; 
   }
   write("The zombie prevents you!\n");
   return 1;
}
west() {
   this_player()->move_player("west#players/grimm/caverns/cavern12");
   return 1;
}
east() {
  this_player()->move_player("east#players/grimm/caverns/cavern16");
  return 1;
}
monster() {
   object monster;
   if(!present("cavern zombie")) {
      monster = clone_object("players/grimm/monster/zombie");
      move_object(monster,this_object());
   }
}
