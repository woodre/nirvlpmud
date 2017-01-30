inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You're in a sewer under Trixtown, the place is lit by a low electric light. The\n"+
              "smell of organic and industrial wastes makes the air barely breatheable. Three\n"+
              "drainage tunnels meet right here.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sec6","north",
                  "/players/trix/castle/quest/sed7","east",
                  "/players/trix/castle/quest/see6","south",
                  "/players/trix/castle/town/mainroad3","up"
                                                        });
}
realm(){return "NT";}
