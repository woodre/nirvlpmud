inherit "room/room";

reset(arg) {

   if(!arg) {
   short_desc="Blue Crystal";
   long_desc="\tBlue light reflects off of mirrored walls.  The light has no source,\n"+
      "but seems to eminate from the walls themselves.  Crystal walls in perfect\n"+
      "geometric symmetry rise around you with one passage leading down.\n"+
      "Melodic chimes can be heard from all directions.\n";
   dest_dir=({
      "/players/llew/closed/crystal/crys4.c","down",
      });
   items=({
      "walls","You look at the mirrored walls and see your own reflection,\n"+
         "but it is not quite you.  It is yourself without any flaws. It is perfect.\n",
   });
   }
   
  if(!present("xetra 3"))
   mon_reset();
}

mon_reset() {
   object *ri;
   int amm,x;
   for(x=0;sizeof(ri=all_inventory(this_object())) > x;x++) {
      if(ri[x]->query_name() == "xetra") amm++;
   }
   while(amm<3) {
      move_object(clone_object("/players/llew/closed/crystal/demon.c"),this_object());
      amm++;
   }
}
