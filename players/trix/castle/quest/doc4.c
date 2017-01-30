inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(0);
   long_desc =
              "This is the southern part of a long and narrow room, three passages lead to \n"+
              "lateral rooms.\n";
    short_desc = "A rectangular room";
    dest_dir = ({
                  "/players/trix/castle/quest/dob4","north",
                  "/players/trix/castle/quest/doc3","west",
                  "/players/trix/castle/quest/doc5","east",
                  "/players/trix/castle/quest/dod4","south"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("south","south");
   add_action("west","west");
   add_action("east","east");
}
south()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("south#"+"players/trix/castle/quest/dod4");
  return 1;
}
west()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("west#"+"players/trix/castle/quest/doc3");
  return 1;
}
east()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("east#"+"players/trix/castle/quest/doc5");
  return 1;
}
realm(){return "NT";}
