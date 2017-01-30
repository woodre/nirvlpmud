#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);
if (!present("bowman")) {
  move_object(clone_object("/players/francesco/2001/mobs/bowman.c"),
	this_object());  }

short_desc = "Discovery" ;
long_desc =
       "   DISCOVERY SPACECRAFT,  1,000,000 MILES FROM EARTH\n"+
       "The control deck of the Discovery is a small and uncomfortable\n"+
       "room.  Only one chair in front of a console desk, surrounded by \n"+
       "some monitors and other instruments to assess and to control\n"+
       "the functions of the whole spacecraft.\n",

items = ({
   "desk","It is a metallic desk about 3 feet tall and 3 feet wide",
   "monitors", "The monitors have old, small, 12 inch, black and white screens",
   "chair","It has also security belts",
   "instruments","Only the most skilled navigators can understand their use",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery21.c","west",
  "/players/francesco/2001/rooms/discovery20.c","southeast",
  "/players/francesco/rooms/the_end.c","conclusion",
});

}

init(){
      ::init();
      add_action("the_end","conclusion");
      }

the_end() 
  {
  write("All of a sudden a brilliant blast of light surrounds the room.\n"+
        "Your mind blows,  your eyes close, your body feels weightless.\n"+
        " ....... ......... ........... ........... ......... .......\n"+
        "   ...     .....     .......     .......     .....     ...\n"+
        "    .        .         ...         ...         .        .\n"+
        "                        .           . \n"+
        "             You are transported elsewhere.\n");
  this_player()->move_player("to another space#players/francesco/2001/rooms/the_end.c");
  return 1;
  }

