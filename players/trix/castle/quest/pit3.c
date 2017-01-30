inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
              "You are going down down a dark and deep pit, the ladder you're using seems to\n"+
              "disappear in the darkness above and below you. \n";
    short_desc = "A deep pit";
    dest_dir = ({
                  "/players/trix/castle/quest/pit2","up",
                  "/players/trix/castle/quest/pit4","down"

                                                        });
}
realm(){return "NT";}
