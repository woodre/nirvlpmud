#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("master")) {
  move_object(clone_object("/players/francesco/games/mobs/questmaster.c"),
	this_object());  }
set_light(1);

short_desc = "Games room" ;
long_desc =
     "   This square room is the center of the mastermind game area.  It has\n"+
     "some passageways to the game rooms.  Each of those passageways  is marked\n"+
     "with different nouns to remind what games are played inside.\n",

items = ({
   "passageways","Just doors to the game rooms",
   "nouns",HIR+"M A S T E R M I N D   C O L O R "+NORM+"    "+HIC+"M A S T E R M I N D"+NORM,
});

dest_dir = ({
    "/players/francesco/games/rooms/mastermindcol1.c","n",
    "/players/francesco/games/rooms/mastermindcol0.c","e",
    "/players/francesco/games/rooms/mastermind1.c","s",
    "/players/francesco/games/rooms/mastermind0.c","w",
    "/players/francesco/games/rooms/hubnew.c","exit",
});

}



query_no_fight() {return 1;}
