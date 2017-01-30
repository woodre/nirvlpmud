inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "This is a large tunnel, you can see its end west of here.\n";
    short_desc = "A rock tunnel";
    dest_dir = ({
                  "/players/trix/castle/quest/Edof2","west",
                  "/players/trix/castle/quest/dof4","east"
                                                        });
}
realm(){return "NT";}
