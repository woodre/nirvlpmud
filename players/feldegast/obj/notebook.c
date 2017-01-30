#include "defs.h"

inherit "/players/feldegast/std/book.c";

void reset(int arg) {
  if(arg) return;
  set_id("notebook");
  set_alias("book");
  set_short("Archivist's notebook");
  set_long(
"This notebook contains a set of notes written by a neat hand.\n"
  );
  set_weight(1);
  set_value(500);
  set_file(OBJ_PATH+"text/notebook.txt");
}
