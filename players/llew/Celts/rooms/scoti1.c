inherit "room/room";

reset(arg) {
   mon_reset();
if(!arg) {
   set_light(1);
   short_desc="Gwynedd Shore";
   long_desc="\tThe road ends at a village burned to the ground.\n"+
      "The inhabitants gone or dead on the ground leave the place\n"+
      "deserted.  The acrid stench of smoke and blood fill the air.\n"+
      "Waves crash against the sharp rocks and several single masted\n"+
      "ships lying a few hundred yards to the east.  North the\n"+
      "shore continues to more scattered remains of the community.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/scoti2.c","north",
      "/players/llew/Celts/rooms/for_road3.c","east",
   });
   items=({
      "road","Grass lines the side of the well worn road",
      "village","Smoke rises from the burned husks of the huts",
      "waves","Small waves splashing against the rocky shore",
      "ships","Well made but tiny sailing vessals from across the sea in Ireland",
      "shore","The eastern border of Gwynedd touched by the sea seperates it from Ireland",
   });
   }
}

mon_reset() {
   object *ri;
   int amm,x;
   for(x=0;sizeof(ri=all_inventory(this_object())) > x;x++) {
      if(ri[x]->query_name() == "raider") amm++;
   }
   while(amm<4) {
      move_object(clone_object("/players/llew/Celts/monsters/scoti.c"),this_object());
      amm++;
   }
}
