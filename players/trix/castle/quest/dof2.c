inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You reached the dead end of the gallery, many rocks have been piled up to bar\n"+
              "the way.\n";
    short_desc = "Dead end";
    dest_dir = ({
                  "/players/trix/castle/quest/dof3","east"
                                                        });
}
realm(){return "NT";}
