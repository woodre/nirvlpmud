inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("stairs");
   long_desc=
   "A gigantic set of stairs leading up the mountain side.\n";
   dest_dir=
   ({
     "players/sandman/ASGARD/high_top","climb",
     "players/sandman/ASGARD/mstreet3","down",
   });
}
