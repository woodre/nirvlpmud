inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = "The corridor runs down east to its dead end, that part of the building seems\n"+
               "less lit.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/inhall4.c","west",
                 "/players/trix/castle/town/inclass9.c","north",
                 "/players/trix/castle/town/inclass10.c","south",
                 "/players/trix/castle/town/inhall6.c","east"});
}

