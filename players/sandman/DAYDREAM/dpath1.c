inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a dirt path [e,w]");
   long_desc=
     "This is a small dirt path running east and west. To the east you\n"+
     "can see a football field.\n";
   dest_dir=
   ({
     "players/sandman/DAYDREAM/grypath1","west",
     "players/sandman/DAYDREAM/fball", "east"
   });
}
