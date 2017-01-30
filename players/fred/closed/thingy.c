inherit "/obj/treasure.c";
#include <ansi.h>
#define ENV environment()->query_name()
reset (arg) {
	set_id("chunky_monkey");
      set_weight(0);
}

extra_look()
{ return ENV+" has a small "+BLU+"blue"+NORM+" tattoo of a penguin on his leg."; }

drop(){
  return 1;
}

