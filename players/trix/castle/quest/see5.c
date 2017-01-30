inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "A tunnel in the rock, the walls are raw and painted with shimmering shadows\n"+
              "projected by a wooden torch.\n";
    short_desc = "A tunnel";
    dest_dir = ({
                  "/players/trix/castle/quest/sed5","north",
                  "/players/trix/castle/quest/sef4","southwest"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("southwest","southwest");
}
southwest()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("southwest#"+"players/trix/castle/quest/sef4");
  return 1;
}
realm(){return "NT";}
