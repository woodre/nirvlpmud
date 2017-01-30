inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc=
"  You stand in front of the enormous facade of a gothic cathedral that\n"+
"seems very ancient.  You see a huge portal that leads inside.\n";
   short_desc = "A cathedral entrance";
    dest_dir = ({ "/players/trix/castle/primo/nave2.c", "portal",
                  "/players/trix/castle/center.c", "south"});
 
}
