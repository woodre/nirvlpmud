inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You are following a huge gallery that goes down in the heart of the Earth under\n"+
              "Trixtown.\n";
    short_desc = "A sloping gallery";
    dest_dir = ({
                  "/players/trix/castle/quest/doe5","north",
                  "/players/trix/castle/quest/dog5","south"

                                                        });
}
realm(){return "NT";}
