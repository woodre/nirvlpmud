#pragma strong_types

inherit "obj/treasure";
#include <ansi.h>

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("remains");
  set_alias("turtle remains");
  set_short("Turtle remains");
  set_long("\
These are the remains of what be the largest turtle in all of\n\
history. The shell makes it very heavy. If you found the right\n\
person they might be able to make something useful from it.\n");
  set_value(1000);
  set_weight(5);
}
