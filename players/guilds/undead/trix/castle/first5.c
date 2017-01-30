inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"This ancient altar was once devoted to an ancient god unknown in this\n"+
"day. A skeleton of what seems to be a woman is bound to the ancient\n"+
"stone. A dagger is plunged deep into its ribcage, to the east an organ\n"+
"plays continuously by itself, to the north you find a door hidden\n"+
"behind a curtain.\n";
    short_desc ="An altar";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first6.c","north",
                  "/players/trix/closed/guild/castle/first4.c","south",
                  "/players/trix/closed/guild/castle/first14.c","east"
                                                        });
}
realm(){return "NT";}
