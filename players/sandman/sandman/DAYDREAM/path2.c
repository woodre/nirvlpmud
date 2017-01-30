inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a path [n,e,w]");
   long_desc=
     "The road is intersected here by a road paved with grey stone.\n"+
     "The grey road runs north; while, the yellow road\n"+
     "continues to the east.\n";
   items=
   ({
     "grey road", "This road is paved with a dull grey stone",
   });
   dest_dir=
   ({
     "players/sandman/DAYDREAM/grypath1","north",
     "players/sandman/DAYDREAM/path3","east",
     "players/sandman/DAYDREAM/path1","west",
   });
}
