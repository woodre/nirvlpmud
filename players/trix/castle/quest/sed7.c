inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You're walking along a drainage tunnel going from west to east with a slight\n"+
              "sloping. Dirty stinking waters flows near your feet.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sed6","west",
                  "/players/trix/castle/quest/sed8","east"
                                                        });
}
realm(){return "NT";}
