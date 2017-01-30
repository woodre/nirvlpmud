#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("instructor")) {
  move_object(clone_object("/players/francesco/2001/mobs/instructor.c"),
	this_object());  }
if (!present("child")) {
  move_object(clone_object("/players/francesco/2001/mobs/child.c"),
	this_object());  }
set_light(1);

short_desc = "The Moon" ;
long_desc =
     "   MOON,  YEAR 2001\n"+
     "The low gravity Gymnasium is filled with items which have been \n"+
     "designed to best suit the Moon special environment.  Several \n"+
     "body-building machines can be seen.  The low gravity definately \n"+
     "produces a sense of general well-being. The movements are slower\n"+
     "yet very gracious.\n",

items = ({
      "machines","Basically the same that are used on Earth, but with reinforced wires and weights",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon4.c","east",
  "/players/francesco/2001/rooms/moon2.c","southeast",
  "/players/francesco/2001/rooms/moon9.c","northwest",
});

}
