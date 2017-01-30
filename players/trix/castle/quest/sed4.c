inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "You are in a small room paved with smooth bricks, you notice two small passages\n"+
              "that lead southwest and east.\n";
    short_desc = "A small room";
    dest_dir = ({
                  "/players/trix/castle/quest/sec4","north",
                  "/players/trix/castle/quest/see3","southwest",
                  "/players/trix/castle/quest/sed5","east"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("southwest","southwest");
   add_action("east","east");
}
southwest()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("southwest#"+"players/trix/castle/quest/see3");
  return 1;
}
east()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("east#"+"players/trix/castle/quest/sed5");
  return 1;
}
realm(){return "NT";}
