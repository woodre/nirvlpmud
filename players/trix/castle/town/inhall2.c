inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = "You are walking along the corridor of the infant house, it runs from east to\n"+
               "west, opened doors to the north and to the south.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/inhall1.c","west",
                 "/players/trix/castle/town/inclass3.c","north",
                 "/players/trix/castle/town/inclass4.c","south",
                 "/players/trix/castle/town/inhall3.c","east"});
}

