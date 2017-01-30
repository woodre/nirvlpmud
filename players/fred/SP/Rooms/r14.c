#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object ned;
object jimbo;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Town Bar";
long_desc =
"  As you enter the smoke filled bar everything grows quiet.  You\n"+
"can see a dartboard on the wall next to a couple of neon beer signs.\n"+  
"There is a large pool table in the middle of the room, and an old\n"+
"Pac-man video game in the corner.\n";

items = ({
  "dartboard",
  "The dartboard is old and dusty.  From the looks of the wall\n"+
  "next to it most of the patrons play while drinking",
  "table",
  "The pool table has 3 or 4 balls still left on the table from\n"+
  "the last game",
  "balls",
  "The balls are scuffed and have small chips in them, the cue ball\n"+
  "has small blue chalk marks on it",
  "signs",
  "The neon signs are bright and colorful.  They are the only items\n"+
  "in the whole bar that look new",
  "game",
  "The Pac-man game has seen it's better days.  There is tape over the\n"+
  "one coin slot, and the knob is broken off the joystick", 
  "wall",
  "The wall has hundreds of holes in it from people with bad aim\n"+
  "trying to play darts",
  "holes",
  "Small holes caused by the sharp tips of darts",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r13.c","exit",
  });
  ned = clone_object("/players/fred/SP/Mon/ned.c");
  jimbo = clone_object("/players/fred/SP/Mon/jimbo.c");
  move_object(ned, this_object());
  move_object(jimbo, this_object());
}
