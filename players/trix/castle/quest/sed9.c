inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The tunnel describes a curve from west to south, forcing the dirty water in\n"+
              "the latter direction.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sed8","west",
                  "/players/trix/castle/quest/see9","south"
                                                        });
}
realm(){return "NT";}
