inherit "room/room";

reset(arg) {
    object cosa;
    int cont;
    if(arg) return;
    set_light(1);
   long_desc = "You reached the bottom of the stairs that link the EclYpsE to to the restaurant\n" +
               "that is built below it. You barely hear the base pumping above you, while the\n" +
               "atmosphere is pretty relaxed in here.\n";
   short_desc = "EclYpsE's Restaurant";
    dest_dir = ({ "/players/trix/castle/disco/grid14.c","up",
                  "/players/trix/castle/disco/d4.c","north",
                  "/players/trix/castle/disco/d8.c","west",
                  "/players/trix/castle/disco/d14.c","south"});
}
