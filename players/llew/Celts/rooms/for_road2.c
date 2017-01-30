inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Gwynedd";
   long_desc="\t A crossroad in the forest of Gwynedd.\n"+
   "The trees open up slightly into a crossroad splitting into the four\n"+
   "cardinal directions.  The sun shines, warming you from overhead.\n"+
   "To the west you hear the sound of the ocean waves crashing\n"+
   "on the rocks.  Northward, a great wall stretches the horizen.\n"+
   "East in the distance a castle graces the skyline.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/for_road3.c","west",
      "/players/llew/Celts/rooms/picti1.c","north",
      "/players/llew/Celts/rooms/for_road4.c","east",
      "/players/llew/Celts/rooms/for_road1.c","south",
   });
   items=({
      "trees","The trees rise high on the sides of the roads",
      "road","The crossroad appears well used in all directions",
   });
   }
}

init() {
   ::init();
   add_action("search","search");
}

search() {
   write("You find nothing of interest.\n");
   return 1;
}
