inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "A large circular and lowlit room, on the walls some cruel fight scenes stand \n"+
              "out. An arch stands on the southern edge of the room.\n";
    short_desc = "A circular room";
    dest_dir = ({
                  "/players/trix/castle/quest/Esec1","north",
                  "/players/trix/castle/quest/seh4","south"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/chief");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("south","south");
}
south()
{ if(present("trixguard",this_object())) { write("The Chief says: You silly tiny man, do u really think I'll let you pass?!?!\n");
                                          return 1; }
  this_player()->move_player("south#"+"players/trix/castle/quest/seh4");
  return 1;
}
realm(){return "NT";}
