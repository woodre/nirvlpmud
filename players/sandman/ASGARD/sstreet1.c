inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "a red brick road";
   long_desc=
     "The brick paved street runs north and south. To the south you can\n" +
     "make out the outline of a white tower.\n";
   items=
   ({
     "red road","This road is paved with glazed brick",
     "tower","A white ivory tower that spirals up to the clouds",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/sstreet2","south",
     "players/sandman/ASGARD/mstreet1","north",
   });
}
