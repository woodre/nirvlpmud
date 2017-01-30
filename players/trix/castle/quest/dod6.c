inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A narrow passage leads southwest to a strange giant room.\n";
    short_desc = "A narrow passage";
    dest_dir = ({
                  "/players/trix/castle/quest/doe5","southwest",
                  "/players/trix/castle/quest/doe7","southeast"
                                                        });
}
realm(){return "NT";}
