inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Gwynedd";
   long_desc="\tDeep within a green forest in the land of Gwynedd.\n"+
      "Tall deciduous trees make up this dense forest.  Full of singing birds,\n"+
      "rustling leaves in the wind, it is not a quiet place, but filled with life.\n"+
      "Gwynedd is a land of magic and nature.  Strange things may happen...\n"+
      "To the North a road emerges, well used, but made of soft earth not stone.\n"+
      "West is a fort, called a Caer to the Cymry of the area, made of stout timber\n"+
      "pilings for protection.  A special exit, 'out' leads to the chaotic realm\n"+
      "of Nirvana.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/for_road1.c","north",
      "/players/llew/Celts/rooms/dyvi1.c","west",
      "/room/eastroad4.c","out",
   });
   items=({"trees","The tall trees rise far above blocking out some of the light.\n",
      "road","The road is packed from much use, but there is no traffic at the moment.\n",
      "caer","The caer is sturdy and you hear friendly voices from within.\n",
      });
   }
}

init() {
   ::init();
   add_action("search","search");
}
search() {
   write("You find nothing of importance.\n");
   return 1;
}
