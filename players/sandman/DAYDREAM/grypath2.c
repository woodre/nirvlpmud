inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a grey path [n,s]");
   long_desc=
     "This is a road paved with grey stone that runs north and south.\n"+
     "You hear giggling to the north.\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/cheer","north",
     "players/sandman/DAYDREAM/grypath1", "south"
   });
}
