inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A large drainage tunnel, the water comes out of a hole on the northern walls\n"+
              "and flows south. You can see a dried zone west of here.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sec5","west",
                  "/players/trix/castle/quest/sed6","south"
                                                        });
}
