inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = "You walked half of the corridor, that runs from the west to the east, you see\n"+
               "the western and the eastern end at the same distance.\n";
   short_desc = "Trixtown Municipal Infant House";
   dest_dir = ({ "/players/trix/castle/town/inhall2.c","west",
                 "/players/trix/castle/town/inclass5.c","north",
                 "/players/trix/castle/town/inclass6.c","south",
                 "/players/trix/castle/town/inhall4.c","east"});
}

