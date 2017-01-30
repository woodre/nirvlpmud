#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("tecnico")) {
  move_object(clone_object("/players/francesco/univ/mob/tecnico5.c"),
	this_object()); }

set_light(0);

short_desc = "A dark room" ;
long_desc =
     "   On a wall of this room there is a window made with one-way\n"+
     "transparent glass.  Thus it permits one to see what happens in the\n"+
     "University Auditorium without disturbing the lessons there.  From\n"+
     "other small openings it is possible to send images to the main \n"+
     "screen of the Auditorium,  such as scientific movies or presentations.\n"+
     "There is also one projector.\n",

items = ({
  "window","About 2x2 feet wide",
  "projector","Large projector for movies",
  "openings","Made on the same wall, communicating to the Auditorium",
});

}
init() {
  ::init();
  
  add_action("out","exit");
}

out() {

  tp->move_player("out#/players/francesco/univ/rooms/corridor2.c");
  return 1; }