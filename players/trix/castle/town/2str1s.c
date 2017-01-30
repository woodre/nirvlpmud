inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
    long_desc = 
"  You're on the southern part of Trixtown 2nd street.  Trix Plaza is north of\n"+
"here.  The bank stands to the south, there's a pub to the west and the bank is\n"+
"to the south.\n";
    short_desc = "Trixtown 2nd street";
    dest_dir = ({ "/players/trix/castle/town/trixplaza.c","north",
                  "/players/trix/castle/town/bank3.c","south",
                  "/players/trix/castle/town/pub.c","west"});
}
