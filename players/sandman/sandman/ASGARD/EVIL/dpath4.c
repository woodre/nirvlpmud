inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a dirt path [nw,s,e]");
   long_desc=
   "The path curves to the east here leading to a small clearing. Next to\n"+
   "the path sits a ramshackle hut. Thick black smoke billows from the\n"+
   "hut's small chimeny signaling that it is inhabited.\n";
   items=
   ({
     "dirt path", "Little used dirt path",
     "trees","Tall knarled trees that seem to move when your back is turned",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/EVIL/dpath2","south",
     "players/sandman/ASGARD/EVIL/trees","east",
     "players/sandman/ASGARD/EVIL/hut1","enter",
   });
}
