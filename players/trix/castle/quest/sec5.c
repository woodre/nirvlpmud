inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You are in a no more used part of the sewer, the floor is dry, and another \n"+
              "smell replaced the common sewer stink, this new smell seems to hide something\n"+
              "evil.\n";
    short_desc = "Abandoned sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sec4","west",
                  "/players/trix/castle/quest/seb5","north",
                  "/players/trix/castle/quest/sec6","east"
                                                        });
}
realm(){return "NT";}
