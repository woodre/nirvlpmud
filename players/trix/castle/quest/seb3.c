inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A narrow corridor curves northeast, behind the corner you can see a strong and\n"+
              "warm light.\n";
    short_desc = "A narrow corridor";
    dest_dir = ({
                  "/players/trix/castle/quest/sea4","northeast",
                  "/players/trix/castle/quest/sec3","south"
                                                        });
}
realm(){return "NT";}
