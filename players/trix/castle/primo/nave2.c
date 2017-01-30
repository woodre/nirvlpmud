inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc=
"  You have entered a huge gothic church.  The atmosphere that surrounds\n"+
"you makes you feel small and unimportant.  A variegated coloured light\n"+
"pierces through the great rosette above the portal.  Staring at it,\n"+
"you notice mystic scenes of far-off crusades.\n";
   short_desc = "A long nave";
    dest_dir = ({ "/players/trix/castle/primo/nave3.c", "north",
                  "/players/trix/castle/primo/laisle7.c","west",
                  "/players/trix/castle/primo/raisle12.c","east",
                  "/players/trix/castle/primo/entrance1.c", "out"});
 
}
