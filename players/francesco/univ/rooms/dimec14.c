#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("bachelor")) {
  move_object(clone_object("/players/francesco/univ/mob/bachelor.c"),
	this_object());  }
if (!present("bachelor")) {
  move_object(clone_object("/players/francesco/univ/mob/bachelor.c"),
	this_object()); }
if (!present("bachelor")) {
  move_object(clone_object("/players/francesco/univ/mob/bachelor.c"),
	this_object()); }

set_light(1);

short_desc = "Undergraduate students room." ;
long_desc =
     "   Several desks are present in this room.  The students which are\n"+
     "enrolled in the Department of Mechanical Engineering are allowed to\n"+
     "come here for studying,  waiting for their teachers, taking a little\n"+
     "talk with their colleagues or even for simple resting.\n",
items = ({
     "desks","They are cheap and resistant, made by strong steel frame",   

});

dest_dir = ({
     "/players/francesco/univ/rooms/dimec12.c","west",
});

}
