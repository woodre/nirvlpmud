inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a green path [n,s,e]");
   long_desc=
     "This is a road paved with emeralds that runs north and south.\n"+
     "You can hear barking to the east.\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/gpath1","north",
     "players/sandman/DAYDREAM/pound","east",
   });
}
