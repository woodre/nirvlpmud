#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("broom");
  set_alias("rod");
  set_short(YEL+"Broom of Seven Parts"+NORM);
  set_long("An artifact from ancient times, said to have once been wielded by\n"+
           "Walter the Tidy himself.  The broom was mysteriously broken into\n"+
           "seven parts during the time of chaos known as "+BOLD+"The Janitorial Strike"+NORM+".\n");
  set_weight(1);
  set_value(5);
}
