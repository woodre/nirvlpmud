#include "/bin/ghost.c"

#define V this_player()->query_name()
#pragma strict_types
#pragma save_types

int
cmd_exclaim(string str)
{
    if (ghost())
	return 0;
  if(!str) {
    write("Exclaim what?\n");
    return 1;
    }

    write("You exclaim: " + str + "\n");
    say(V + " exclaims: " + str + "\n");
    return 1;
}

