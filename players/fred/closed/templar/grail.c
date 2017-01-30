inherit "/obj/treasure.c";
#include <ansi.h>

reset(arg)
{
  set_id("grail");
  set_alias("templar_quest_grail");
  set_short(BOLD+YEL+"The Holy Grail"+NORM);
  set_long(
    "  This is the fabled Holy Grail.\n");
  set_weight(0);
  set_value(0);
}
