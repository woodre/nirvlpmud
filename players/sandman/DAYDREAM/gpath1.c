inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a green path [n,s]");
   long_desc=
     "This is a road paved with emeralds that runs north and south.\n"+
     "You can hear the voices of children to the southwest.\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/path1","north",
     "players/sandman/DAYDREAM/gpath2","south",
     "players/sandman/DAYDREAM/pground","southwest",
   });
}
