inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "A large circular room with rock walls, there is a passage in the western edge\n"+
              "of the room.\n";
    short_desc = "A circular room";
    dest_dir = ({
                  "/players/trix/castle/quest/Esec1","west",
                  "/players/trix/castle/quest/sec3","east"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
/* quest change additions next 4 lines  -Eurale  */
guard->set_level(20);
guard->set_hp(500);
guard->set_wc(30);
guard->set_ac(18);
}
init(){
 ::init();
   add_action("west","west");
}
west()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("west#players/trix/castle/quest/Esec1");
  return 1;
}
realm(){return "NT";}
