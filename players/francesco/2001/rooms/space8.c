#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("pilot")) {
  move_object(clone_object("/players/francesco/2001/mobs/pilot2.c"),
	this_object());  }
set_light(1);

short_desc = "Space Shuttle 5" ;
long_desc =
     "   SPACE SHUTTLE 5,  YEAR 2001\n"+
     "The control deck is a small and uncomfortable room.  Only one chair\n"+
     "in front of a console desk, surrounded by some monitors, leverages\n"+
     "and other instruments to control the functions of the whole spacecraft.\n",

items = ({
   "desk","It is a metallic desk about 3 feet tall and 3 feet wide",
   "monitors", "They have modern 15 inch, LCD screens",
   "chair","It has also security belts",
   "leverages","Small poles emerging from the desk",
   "instruments","Only the most skilled co-pilots can understand their use",
});

dest_dir = ({
  "/players/francesco/2001/rooms/space4.c","south",
  "/players/francesco/2001/rooms/space7.c","west",
  "/players/francesco/2001/rooms/space9.c","northwest",
});

}
