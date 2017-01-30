#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
set_id("abyss_mark");
set_alias("mark");
set_short(BOLD+"Mark of the Abyss"+NORM);
set_long(
  "  This permanent black scar is somewhat of a badge of honor.  It\n"+
  "can only be gotten by defeating the mighty and powerful Diva of\n"+
  "the Abyss named Despoina.  Wear it proudly.\n");
set_weight(0);
set_value(0);
set_no_clean(1);
}

drop() { return 1; }

query_auto_load() { return "players/eurale/Abyss/OBJ/mark.c:"; }
