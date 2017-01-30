inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
              "You are in a dark and deep pit, you can see a ladder disappearing in the \n"+
              "darkness below you.\n";
    short_desc = "A deep pit";
    dest_dir = ({
                  "/players/trix/castle/quest/sea4","up",
                  "/players/trix/castle/quest/pit2","down"
                                                        });
}
realm(){return "NT";}
