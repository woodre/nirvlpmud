inherit "/players/darkfire/castle/circus/monsters/ghost/_ghost";
inherit "/players/darkfire/obj/color";

#include <ansi.h>

#define LABEL "panther"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name(LABEL);
  set_short("A Ghostly " + capitalize(LABEL));
  set_long("A ghostly " + LABEL +".\n");
}
