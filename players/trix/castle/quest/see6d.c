inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "The water, coming from a little cascade above your head, squirts you and flows\n"+
              "flows east along the tunnel.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/see6","up",
                  "/players/trix/castle/quest/see7","east"
                                                        });
}
realm(){return "NT";}
