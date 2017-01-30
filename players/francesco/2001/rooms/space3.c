#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("bartender")) {
  move_object(clone_object("/players/francesco/2001/mobs/bartender.c"),
	this_object());  }
set_light(1);

short_desc = "Space Shuttle 5" ;
long_desc =
     "   SPACE SHUTTLE 5,  YEAR 2001\n"+
     "The lounge of the Space Shuttle 5 is very comfortable.  The light\n"+
     "is not as high as in the other rooms of the spacecraft.  Some chairs\n"+
     "are scattered in this wide room, with some tables in within.  The\n"+
     "soft and relaxed atmosphere is the best one for enjoying also long-\n"+
     "term interplanetary trips.\n",

items = ({
   "chairs","They are made by plastic and metals, yet must be very comfortable",
   "tables","Some small square tables, about 2x2 feet wide",
});

dest_dir = ({
  "/players/francesco/2001/rooms/space5.c","down",
});

}
