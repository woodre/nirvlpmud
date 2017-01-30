#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("assistant")) {
  move_object(clone_object("/players/francesco/univ/mob/assistant.c"),
	this_object());  }

set_light(1);

short_desc = "An office" ;
long_desc =
     "   This small room must be very suitable for studying.  It is very\n"+
     "silent and well lighted.  Many books in the library create the best\n"+
     "atmosphere for that scope.  A simple desk with a chair behind are \n"+
     "the only other furniture here.\n",
items = ({
   "books","Mainly scientific books rather than textbooks",
   "library","Metallic shelf to hold the books, about 8 feet tall",
   "desk","Plain wood desk incorporating a small chest of drawers for holding documents",
   "chair","Plain comfortable office chair",
});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec18.c","west",
   
   
});

}
