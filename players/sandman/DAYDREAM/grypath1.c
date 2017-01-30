inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a grey path [n,s,e]");
   long_desc=
     "This is a road paved with grey stone that runs north and south.\n"+
     "A dirt path leads east.\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/grypath2","north",
     "players/sandman/DAYDREAM/dpath1","east",
     "players/sandman/DAYDREAM/path2", "south"
   });
}
