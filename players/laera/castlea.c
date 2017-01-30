#include "/players/laera/closed/ansi.h"
#define DEST "room/forest8"

object autoloadtell;

id(str) { return str == "hole"; }

short() { return BOLD+"A Small Hole"+NORM; }

long() { write(
  "There is a small, eerily hovering hole near the forest edge.  Be\n" +
  "careful if you 'examine' it.\n");
}

init()
{
    add_action("Hole", "examine");
}

Hole(string str)
{
	if(str == "hole")
	{
		write("You are sucked into the hole!\n");
		this_player()->move_player("quietly#players/laera/jump.c");
  		return 1;
  	}
}

reset(arg) {
if(arg) return;
  move_object(this_object(),DEST);
  /*start_autoloads();*/
  autoloadtell = clone_object("/players/laera/closed/ltellAL.c");
  destruct (autoloadtell);

}
is_castle(){return 1;}

/*start_autoloads()
  {
  	autoloadtell = clone_object("/players/laera/closed/ltellAL.c");
  	destruct (autoloadtell);
  }*/
