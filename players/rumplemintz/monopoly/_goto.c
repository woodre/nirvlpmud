#include "path.h"
inherit SQUARE;

reset() {
  name="Go To Jail";
}

land() {
  ::land();
  write("You go directly to jail.\n");
  TPMOBJ->set_square(PATH+"/_jail");
  TPMOBJ->set_in_jail(1);
  say(TP->query_name()+" goes directly to jail.\n");
  move_object(TP,PATH+"/_jail");
}

