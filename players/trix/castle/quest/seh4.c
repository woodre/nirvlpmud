inherit "room/room";
reset(arg) {
   object casee;
   if(arg) return;
   set_light(1);
   long_desc =
              "You reached the end of the path you were following, this is a tiny and warm\n"+
              "room with walls covered with wood, an arch stands north of here.\n";
    short_desc = "A small warm room";
    dest_dir = ({
                  "/players/trix/castle/quest/seg4","north"
                                                        });
        casee=clone_object("players/trix/castle/quest/monst/case");
        move_object(casee,this_object());
}
realm(){return "NT";}
