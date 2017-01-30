inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The tunnel gets larger, so u can walk almost erect, the stinking water still\n"+
              "flows near your feet. A gallery in the wall leads south.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/see6d","west",
                  "/players/trix/castle/quest/see8","east",
                  "/players/trix/castle/quest/sef7","south"
                                                        });
}
realm(){return "NT";}
