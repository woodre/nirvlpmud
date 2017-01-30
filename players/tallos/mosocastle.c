#include "/players/mosobp/ansi.h"
#define NAME "Mosobp"
#define DEST "/room/farmroad3"
#define PATH "/players/mosobp/areas/TEMPLE/rooms"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "ship" || str == "spaceship" ;}

short() {
    return ""+HIK+"A Spaceship"+NORM+"";
}

long() {
  write("Perhaps this spaceship can take you to another planet if you enter it.\n");
}

init() {
  add_action("enter","enter");
}
enter() {
  string str2;
  str2= PATH+"/ship.c";
  move_object(this_player(), PATH+"/ship.c");
  command("look",this_player());
  return 1;
}
reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
