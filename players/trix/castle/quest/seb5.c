inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A corridor dug in the rock, you can see the northern end brightly lit by a warm\n"+
              "light.\n";
    short_desc = "A corridor in the rock";
    dest_dir = ({
                  "/players/trix/castle/quest/sea5","north",
                  "/players/trix/castle/quest/sec5","south"
                                                        });
}
realm(){return "NT";}
