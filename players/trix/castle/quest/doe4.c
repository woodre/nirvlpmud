inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The tunnel describes a right corner, going further down in unknown depths. \n";
    short_desc = "A right corner";
    dest_dir = ({
                  "/players/trix/castle/quest/doe3","west",
                  "/players/trix/castle/quest/dof4","south"
                                                        });
}
realm(){return "NT";}
