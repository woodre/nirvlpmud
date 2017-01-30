#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("guardian")) {
  move_object(clone_object("/players/francesco/univ/mob/guardian.c"),
	this_object()); }
set_light(1);

short_desc = "The main entrance" ;
long_desc =
     "    What a solemnity in this room:  you have taken your decision\n"+
     "and you will be rewarded for it.  This ample room has a high ceiling\n"+
     "and is well lighted by the sun passing through the windows.  From\n"+
     "here you can reach all the areas of the University,  classrooms,\n"+
     "Departments, administrative offices and libraries.  On the northeast\n"+
     "there is what looks like an info center.\n",

items = ({
      "ceiling","About 35 feet tall",
      "windows","Wide windows, positioned at the top part of the walls",
});

dest_dir = ({
  "/players/francesco/univ/rooms/booth.c","northeast",
  "/players/francesco/univ/rooms/corridor1.c","east",
  "/players/francesco/univ/rooms/scala.c","descend",
});

}
