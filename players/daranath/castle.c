#define NAME "Daranath"
#define DEST "room/deep_forest1"
#include <ansi.h>
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

 id(str) { return str == "portal" ||
                  str == "stone portal" || 
                  str == "stone"  ||
                  str == "mist" ||
                  str == "castle" ||
                  str == "dar's castle";
}

short() {
  return "A dark grey stone portal sits here";
}

long() {
write("A stone portal made entirly of a unique dark grey stone.\n"+
      "A swirling mist inside the portal itself might lead to another\n"+
      "realm, one that might hold adventure.\n"+
      "To explore that realm, simply <"+HIR+"enter"+NORM+"> the portal.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
  if(!str) {write("What do you want to enter?\n"); return 1; }
    if (!id(str))
	return 0;
    write("The mist surrounds you as you enter the portal.\n");
this_player()->move_player("disappears into the portal#/players/daranath/qualtor/hilltop.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
autoloads(); 
}
is_castle(){return 1;}

autoloads() {
/*   no more necro guild stuff for me    -Dar
  clone_object("/players/daranath/guild/guildob.c");
*/
  clone_object("/players/daranath/druid/guildob.c");
/*
  clone_object("/players/daranath/closed/stuff/sigil.c");
*/
  clone_object("/players/daranath/closed/stuff/ring_kat.c");
  clone_object("/players/daranath/closed/stuff/ring_me.c");
  clone_object("/players/daranath/closed/market/badge.c");
  clone_object("/players/daranath/closed/wizclan/clanobj.c");
}
