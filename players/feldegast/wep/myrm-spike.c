#include "/players/feldegast/defines.h"
inherit "obj/weapon";

void reset(int arg)
{
  set_name("spike");
  set_short(BOLD+BLK+"Myrmidar spike"+NORM);
  set_long("This is a sharp spike about seven inches in length, broken off\n"+
          "a Myrmidar.  You could probably use it like a dirk, or stilletto.\n");
  set_class(14);
  set_value(500);
  set_weight(1);
  set_type("knife");
}
