inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in the entrance hallway of the disco.  You hear a crazy noise coming\n"+
"up to you from the south.  To the west there's a wardrobe and to the east the\n"+
"ticket seller's room.\n";
   short_desc = "A dark hallway";
    dest_dir = ({ "/players/trix/castle/disco/in8.c","north",
                  "/players/trix/castle/disco/hall5.c","south",
                  "/players/trix/castle/disco/ward2.c","west",
                  "/players/trix/castle/disco/tick4.c","east"});
}
