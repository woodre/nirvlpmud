inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A corner in the rock corridor, west of here a strong light projects your sharp\n"+
              "shadow on the floor behind you.\n";
    short_desc = "A corridor in the rock";
    dest_dir = ({
                  "/players/trix/castle/quest/sea4","west",
                  "/players/trix/castle/quest/seb5","south"
                                                        });
}
realm(){return "NT";}
