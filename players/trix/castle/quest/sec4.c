inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You realize that you're not in the city sewer anymore, walls made of irregular\n"+
              "stone bricks have taken the place of the previous cement walls, and torches\n"+
              "have replaced electric light.\n";
    short_desc = "An ancient corridor";
    dest_dir = ({
                  "/players/trix/castle/quest/sec3","west",
                  "/players/trix/castle/quest/sec5","east",
                  "/players/trix/castle/quest/sed4","south"
                                                        });
}
realm(){return "NT";}
