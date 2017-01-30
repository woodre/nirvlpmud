inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = "You just walked by the middle part of the corridor, which continues to the\n"+
               "east and west.  There are other rooms to the north and south of here.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/inhall3.c","west",
                 "/players/trix/castle/town/inclass7.c","north",
                 "/players/trix/castle/town/inclass8.c","south",
                 "/players/trix/castle/town/inhall5.c","east"});
}

