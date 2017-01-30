inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A narrow tunnel, you can hear strange noises coming from somewhere east of here.\n";
    short_desc = "A narrow tunnel";
    dest_dir = ({
                  "/players/trix/castle/quest/dog6","west",
                  "/players/trix/castle/quest/dog8","east"
                                                        });
}
realm(){return "NT";}
