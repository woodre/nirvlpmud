inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"This is a double room with two grand pillars stand here this is\n"+
"obviously the main gallery paintings of the lords of the castle line\n"+
"the walls. The room is dusty and is lit in an ere glow.\n"+
"Moans of pain and torture echo through the halls. The north east\n"+
"pillar is encircled by a staircase leading to the balcony that\n"+
"surrounds the gallery. To the north is a set of double doors.\n"+
"There are three halls leading from this room one to the east, one to\n"+
"the west, and one to the southeast. \n";
    short_desc ="A corridor";
    dest_dir = ({
            /*      "/players/trix/closed/guild/castle/second","up", */
                  "/players/trix/closed/guild/castle/first4.c","north",
                  "/players/trix/closed/guild/castle/first2.c","south",
                  "/players/trix/closed/guild/castle/first12.c","east",
                  "/players/trix/closed/guild/castle/first11.c","southeast",
                  "/players/trix/closed/guild/castle/first8.c","west"
                                                        });
}
realm(){return "NT";}
