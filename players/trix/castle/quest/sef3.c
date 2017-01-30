inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "The path you're following curves, forming a corner that hides what's behind it.\n";
    short_desc = "A path in the rock";
    dest_dir = ({
                  "/players/trix/castle/quest/see3","north",
                  "/players/trix/castle/quest/sef4","east"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("east","east");
}
east()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("east#"+"players/trix/castle/quest/sef4");
  return 1;
}
realm(){return "NT";}
