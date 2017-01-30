/* inherited clean by verte 2002 */
inherit "/obj/clean";
/* Made misc changes.  - Feldegast 9-30-01 */
#include <ansi.h>
#define NAME "Ultramagnus"
#define DEST "room/jetty"
/* #include "room.h"  -- remove by Rumplemintz */
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

/* Added the id "aura" - Feldegast */
id(str) { return str == "south" || str == "aura"; }

/* Added some color. - Feld */
short() {
   return "There is a "+HIM+"Beautiful Purple Aura"+NORM+" coming from the south";
}

/* Added a long description.  It WAS the default! - Feld */
long() {
    write("The purple aura to the south seems to lead into a realm of ancient myth\n"+
          "and legend, a land of wizards and hobbits, magic rings and elven maidens.\n");
}

init() {
  add_action("south", "south");
}

south(str) {
    call_other(this_player(),"move_player", "south#players/ultramagnus/hall.c");
    return 1;
}

reset(arg) {
    if(arg) return;
    /* added if(arg) check, set_no_clean(1) verte 2002 */
  set_no_clean(1);
    move_object(this_object(), DEST);
}

/* Need this so the castle doesn't get cleaned! - Feld */
is_castle() { return 1; }
