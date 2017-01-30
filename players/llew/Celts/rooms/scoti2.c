inherit "room/room";

reset(arg) {
   mon_reset();
if(!arg) {
   set_light(1);
   short_desc="Gwynedd Shore";
   long_desc="\tA few more scattered huts lead into the trees of\n"+
      "the forest to the north and east.   The waves continue their eternal beat\n"+
      "along the shore to the west.  The place is empty and abandoned.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/scoti1.c","south",
   });
   items=({
      "village","Smoke rises from the burned husks of the huts",
      "waves","Small waves splashing against the rocky shore",
      "shore","The eastern border of Gwynedd touched by the sea seperates it from Ireland",
      "huts","Smoke rises from the burned out empty huts",
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
