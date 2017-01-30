inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Gwynedd";
   long_desc="\tTravelling a road in a forest in the land of Gwynedd.\n"+
      "Tall trees surround you as you travel the east-west road.  Further\n"+
      "east you hear the continued sound of waves crashing against rocks.\n"+
      "You catch sight of the sea and a small ship in the water.  West\n"+
      "the road continues to a crossroad.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/scoti1.c","west",
      "/players/llew/Celts/rooms/for_road2.c","east",
   });
   items=({"trees","The trees rise far above, blocking out some of the light",
      "sea","The sea is dark colored and choppy from many storms",
      "ship","The ship looks to be a raider from across the channel",
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
