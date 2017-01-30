inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(0);
   long_desc =
              "A long and narrow rectangular room that looks like a corridor reveales walls   \n"+
              "painted with every sort of pagan ritual scenes.\n";
    short_desc = "A rectangular room";
    dest_dir = ({
                  "/players/trix/castle/quest/pit5","north",
                  "/players/trix/castle/quest/doc4","south"
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
  this_player()->move_player("south#"+"players/trix/castle/quest/doc4");
  return 1;
}
realm(){return "NT";}
