inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Gwynedd";
   long_desc="\tDeep within a green forest in the land of Gwynedd.\n"+
      "Tall trees surround you as you travel along a north-south dirt road.\n"+
      "Sun seeps through the tall canopy of leaves casting a green tinge on all.\n"+
      "A creek trickles by over the road from the east.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/for_entrance.c","south",
      "/players/llew/Celts/rooms/for_road2.c","north",
   });
   items=({"trees","The trees rise far above blocking out some of the light.\n",
   "road","The road is packed from well use, but there is no traffic at the moment.\n",
   "leaves","The leaves rustle in the wind.\n",
   "creek","The creek is thin and crystal clear.  Light shines through boucing of the rocks.\n"+
   "It seems to come from only a short distance east. You can almost see it...\n",
   });
   move_object(clone_object("/players/llew/Celts/misc/standing_stone.c"),this_object());
   }
}

init() {
   ::init();
   add_action("go_east","east");
   add_action("go_west","west");
   add_action("search","search");
}

go_east() {
   this_player()->move_player("east#players/llew/Celts/rooms/for_pool");
   return 1;
}

go_west() {
   this_player()->move_player("west#players/llew/Celts/rooms/for_clearing");
return 1;
}
search() {
   write("You find nothing of interest.\n");
   return 1;
}
