inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You are walking along a corridor lit by torches that seem to have been there\n"+
              "for ages. Another corridor runs north.\n";
    short_desc = "An ancient corridor";
    dest_dir = ({
                  "/players/trix/castle/quest/seb3","north",
                  "/players/trix/castle/quest/sec2","west",
                  "/players/trix/castle/quest/sec4","east"
                                                        });
}
realm(){return "NT";}
