inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
"You seem to have found a secret passage that leads north, and south. It is\n"+
"filled with dust and old cobwebs.\n";
    short_desc ="A secret passage";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first6.c","north",
                  "/players/trix/closed/guild/castle/first12.c","south"
                                                        });
}
realm(){return "NT";}
