inherit "room/room";

init() {
   ::init();
   add_action("read","read");
}

read(str) {
   if(str == "sign") {
   cat("/players/sandman/DAYDREAM/SIGN1");
   return 1;
   }
}

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a path [n,s,e,w]");
   long_desc=
     "The road is intersected here by a road paved with green stone.\n"+
     "There is a small sign posted in the center of the intersection.\n"+
     "The green road runs north and south; while, the yellow road\n"+
     "continues to the east.\n";
   items=
   ({
     "green road","This road is paved with crushed emeralds",
     "sign","It is a nice sign, perhaps you should 'read' it",
   });
   dest_dir=
   ({
     "players/sandman/DAYDREAM/teacher","north",
     "players/sandman/DAYDREAM/gpath1","south",
     "players/sandman/DAYDREAM/path2","east",
     "players/sandman/DAYDREAM/entrance","west",
   });
}
