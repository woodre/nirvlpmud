/*
  alchemist_skin.c - skinned from a corpse. used by alchemists to make items.
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/treasure";

string skin_msg;
int skin_strength;

query_save_flag() { return 1; }

reset(arg) {
  set_id("skin");
  set_value(0);
  set_weight(1);
}

short() { return NORM+CYN+"The skin of "+skin_msg+NORM; }

long(str) {
  write(NORM+CYN+"It is a skin from the corpse of "+skin_msg+" ["+
        skin_strength+"]"+".\n"+NORM);
}

set_skin_msg(arg) {
  sscanf(arg, "corpse of %s", skin_msg);
  skin_msg=capitalize(skin_msg);
}
set_skin_strength(arg) { skin_strength=arg; }
query_skin_strength() { return skin_strength; }
