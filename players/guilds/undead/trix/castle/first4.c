inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"As you enter you can hear music from a pipe organ playing as you look\n"+
"around you see a huge chapel. Lightning flashes though broken boarded\n"+
"up stain glass windows allowing you to see. A robed figure lies on an\n"+
"altar while the organ seems to play on its own, to the north is the\n"+
"altar, to the east  there is an ornately decorated door, to the west is\n"+
"an open doorway, to the south is the main gallery.\n";
    short_desc ="A chapel";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first5.c","north",
                  "/players/trix/closed/guild/castle/first3.c","south",
                  "/players/trix/closed/guild/castle/first12.c","east",
                  "/players/trix/closed/guild/castle/first9.c","west"
                                                        });
}
realm(){return "NT";}
