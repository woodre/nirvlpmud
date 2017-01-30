inherit "room/room";

init() {
   ::init();
   add_action("read","read");
}

read(str) {
   if(str == "sign") {
   cat("/players/sandman/ASGARD/SIGN1");
   return 1;
   }
}

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "a street";
   long_desc=
     "The road is intersected here by a road paved with red stone.\n"+
     "There is a SMALL SIGN posted in the center of the intersection.\n"+
     "The red road runs north and south; while, the main road\n"+
     "continues to the east.\n";
   items=
   ({
     "red road","This road is paved with glazed brick",
     "sign","It is a nice sign, perhaps you should 'read' it",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/nstreet1","north",
     "players/sandman/ASGARD/sstreet1","south",
     "players/sandman/ASGARD/mstreet2","east",
     "players/sandman/ASGARD/entrance","west",
   });
}
