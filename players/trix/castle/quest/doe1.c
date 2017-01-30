inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "A narrow tunnel turns a corner that hides the way behind it.\n";
    short_desc = "A corner";
    dest_dir = ({
                  "/players/trix/castle/quest/dod1","north",
                  "/players/trix/castle/quest/doe2","east"
                                                        });
    guard=clone_object("/players/trix/castle/quest/monst/guard");
    move_object(guard,this_object());
}
init(){
 ::init();
   add_action("north","north");
}
north()
{ if(present("trixguard",this_object())) { write("The Guard says: You won't pass unless you want a duel!\n");
                                          return 1; }
  this_player()->move_player("north#"+"players/trix/castle/quest/dod1");
  return 1;
}
realm(){return "NT";}
