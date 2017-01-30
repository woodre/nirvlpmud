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
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   ::init();
}
south() {
    this_player()->move_player("south#players/grimm/caverns/cavern8");
    return 1;
}
north() {
   if(!present("zombie")) {
      this_player()->move_player("north#players/grimm/caverns/cavern12");
      return 1; 
   }
   write("The zombie prevents you!\n");
   return 1;
}
east() {
   this_player()->move_player("east#players/grimm/caverns/cavern15");
   return 1;
}
monster() {
   object monster;
   if(!present("cavern zombie")) {
      monster = clone_object("players/grimm/monster/zombie");
      move_object(monster,this_object());
   }
}
