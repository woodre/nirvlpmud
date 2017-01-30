inherit "obj/armor";
#include "/players/jareel/ansi.h"
#define USER environment(this_object())

reset(arg) { /* uhhh.. this was reset() with no checks */
  ::reset(arg);
  if(arg) return;
  set_name("a party hat");
  set_alias("hat");

set_short(BOLD+RED+"A "+BOLD+BLU+"Par"+RED+"ty"+BOLD+YEL+" Hat"+NORM);
  set_long(
"This hat is to celebrate the Wizards Stardreams birthday.\n"+
"The bright colors make you want to cheer in delight as we\n"+
"celebrate her special day.\n");
  set_ac(0);
  set_light(1);
  set_type("helmet");
  set_weight(1);
  set_value(0);
}

