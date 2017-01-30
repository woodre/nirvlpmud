inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The tunnel runs down along the latitudinal direction. You feel the air heavy\n"+
              "in your lungs because of the depth.\n";
    short_desc = "A tunnel";
    dest_dir = ({
                  "/players/trix/castle/quest/dof5","north",
                  "/players/trix/castle/quest/doh5","south"
                                                        });
}
realm(){return "NT";}
