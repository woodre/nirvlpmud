inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc = 
"  This is Trixtown 2nd street.  You can see Trix Plaza south of here, while\n"+
"there are shops on both sides of the street.  The road continues to the north.\n";
   short_desc = "Trixtown 2nd street";
    dest_dir = ({ "/players/trix/castle/town/2str2n.c","north",
                  "/players/trix/castle/town/trixplaza.c","south",
                  "/players/trix/castle/town/butchers.c","west",
                  "/players/trix/castle/town/news.c","east"});
}
