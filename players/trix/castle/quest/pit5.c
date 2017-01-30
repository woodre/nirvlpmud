inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
              "You reached the bottom of the pit, looking above your head you can see the \n"+
              "ladder going up and disappearing in the darkness, a rift opened in the wall \n"+
              "leads south.\n";
    short_desc = "A deep pit";
    dest_dir = ({
                  "/players/trix/castle/quest/pit4","up",
                  "/players/trix/castle/quest/dob4","south"
                                                        });
}
realm(){return "NT";}
