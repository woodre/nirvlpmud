#include "/obj/ansi.h"
#define PLAN "/players/data/PLAN"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIR+"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+NORM+NORM);
  write_file(PLAN, " "+HIK+"\n\n");
  write_file(PLAN, HIK+"\n");
  write_file(PLAN, HIR+"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+NORM+NORM);
  destruct(this_object());
}
