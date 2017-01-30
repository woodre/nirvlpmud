/*
 * mack.c - Macklemore
 *
 */
#pragma strong_types
#include <ansi.h>

inherit "obj/monster";

void
reset(status arg) {
  if (arg)
    return;
  monster::reset(arg);
  set_name("macklemore");
  set_short("Macklemore");
  set_long(""+
"American hip hop artist from Seattle, Washington.  He is best known for his\n"+
"song, \"Thrift Shop\" - which has over 99 million views on YouTube.\n");
  set_level(10);
}
