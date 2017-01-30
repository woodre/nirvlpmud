inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The gallery you are following turns around a corner, you can see a light of a\n"+
              "different colour behind the corner.\n";
    short_desc = "A gallery";
    dest_dir = ({
                  "/players/trix/castle/quest/doe5","west",
                  "/players/trix/castle/quest/dog6","south"
                                                        });
}
realm(){return "NT";}
