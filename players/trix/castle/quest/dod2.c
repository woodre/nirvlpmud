inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "This is a simple recess in the northern wall of the room, you notice nothing\n"+
              "interesting here.\n";
    short_desc = "A recess in the rock";
    dest_dir = ({
                  "/players/trix/castle/quest/doe2","south"
                                                        });
}
realm(){return "NT";}
