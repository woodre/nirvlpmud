inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "Another small room dug in the rock, a passage that leads south catches your\n"+
              "attention.\n";
    short_desc = "A small room";
    dest_dir = ({
                  "/players/trix/castle/quest/sed4","northeast",
                  "/players/trix/castle/quest/sef3","south"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("south","south");
}
south()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("south#"+"players/trix/castle/quest/sef3");
  return 1;
}
realm(){return "NT";}
