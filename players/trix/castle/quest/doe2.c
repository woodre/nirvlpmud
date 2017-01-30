inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A large room in which several tunnels meet, you can clearly see thanks to a \n"+
              "pale and diffused green light.\n";
    short_desc = "A green room";
    dest_dir = ({
                  "/players/trix/castle/quest/dod2","north",
                  "/players/trix/castle/quest/dod3","northeast",
                  "/players/trix/castle/quest/doe1","west",
                  "/players/trix/castle/quest/doe3","east"
                                                        });
}
realm(){return "NT";}
