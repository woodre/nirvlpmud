inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove");
   long_desc=
   "The Boulevard of Angel Grove.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
         "players/beck/room/street6.c","east",
         "players/beck/room/street1.c","south",
    });
}
