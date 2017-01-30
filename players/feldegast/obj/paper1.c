#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("paper");
  set_alias("scrap");
  set_short("A scrap of paper");
  set_long("This is a scrap of paper with a couple of words scrawled upon it.\n");
  set_weight(1);
  set_value(50);
  set_read(BBLK+HIW+"korat"+NORM+" - "+BWHT+BLK+"tarok\n"+NORM);
}
