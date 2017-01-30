#include "defs.h"
inherit ROOM;

void on_create() {
  set_area("area");
  set_short("Entry Hall to Earwax's Apartment");
  set_long("You're standing in the entrance hall to Earwax's apartment.  \
To the east is the apartment itself.  Not much else to do here other \
than leave, or go in.");
  add_exit("exit",APTR+"porch.c");
  add_exit("east",APTR+"living.c");
}
