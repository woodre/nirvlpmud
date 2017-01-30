inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A narrow tunnel, you walk packed in between the walls and notice that the pale\n"+
              "green light comes from a wierd kind of musk, that learnt to live here producing\n"+
              "by itself the light necessary for the photosynthesis.\n";
    short_desc = "A narrow tunnel";
    dest_dir = ({
                  "/players/trix/castle/quest/doe2","west",
                  "/players/trix/castle/quest/doe4","east"
                                                        });
}
realm(){return "NT";}
