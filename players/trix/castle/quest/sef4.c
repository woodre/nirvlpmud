inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "Three narrow tunnels meet here and forms a small asymmetrical room, the air is\n"+
              "rarefied by the torches burning here. \n";
    short_desc = "An asymmetrical room";
    dest_dir = ({
                  "/players/trix/castle/quest/sef3","west",
                  "/players/trix/castle/quest/see5","northeast",
/* changed quest -Eurale  4/1/97
   changed it back -Feldegast 5/2/98 */
                  "/players/trix/castle/quest/seg4","south"
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
  this_player()->move_player("south#"+"players/trix/castle/quest/seg4");
  return 1;
}
realm(){return "NT";}
