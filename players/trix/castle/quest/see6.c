inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You are walking along a drainage tunnel, the dirty water creates wierd reflexes\n"+
              "upon walls and ceiling, and falls down to a little cascade.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sed6","north",
                  "/players/trix/castle/quest/see6d","down"
                                                        });
}
realm(){return "NT";}
