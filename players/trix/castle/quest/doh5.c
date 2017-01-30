inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The curve continues from west to north, completing the elbow.\n";
    short_desc = "A curved gallery";
    dest_dir = ({
                  "/players/trix/castle/quest/dog5","north",
                  "/players/trix/castle/quest/doh4","west"
                                                        });
}
realm(){return "NT";}
