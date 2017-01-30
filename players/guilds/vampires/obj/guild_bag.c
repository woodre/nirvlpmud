/*
 guild_bag.c
*/

#define TP this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/container";
reset(arg) {
  ::reset(arg);

short_desc = GRY+"grey silk bag"+NORM;
long_desc=
  "A grey silk bag that shimmers in the light.  Embroidered on its side are\n"+
  "the words: "+HIR+"Property of Vampire Guild"+NORM+"\n";
value=0;
max_weight = 29;
local_weight=0;
set_weight(1);
}

prevent_insert() {
  write("The bag appears to resist....\n");
  return 1;
}

id(str) { return (
		str == "bag" ||
		str == "guild bag" ||
		str == "silk bag" ||
		str == "grey bag");
}

query_save_flag() { return 1; }
