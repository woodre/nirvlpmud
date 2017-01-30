inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You continue your walk along the drainage tunnel that leads Trixtown's waste\n"+
              "waters down to unknown depths.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sed7","west",
                  "/players/trix/castle/quest/sed9","east"
                                                        });
}
realm(){return "NT";}
