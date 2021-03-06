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
   add_action("west","west");
   ::init();
}
west() {
   if(!present("zombie")) {
      this_player()->move_player("west#players/grimm/caverns/cavern6_2");
      return 1; 
   }
   write("The zombie prevents you!\n");
   return 1;
}
north() {
   this_player()->move_player("north#players/grimm/caverns/cavern4_2");
   return 1;
}
monster() {
   object monster;
   if(!present("cavern zombie")) {
      monster = clone_object("players/grimm/monster/zombie");
      move_object(monster,this_object());
   }
}
