/* Test Character bag - don't use this you cheater!!
 * Rump
 */

#include <ansi.h>
inherit "obj/container.c";

void long() {
  write(HIB + "Rump's bag" + NORM + ".  This is not your bag baby! ");
  if (first_inventory(this_object()))
    write("There is something in it.\n");
  else
    write("You can put stuff in it.\n");
}

void reset(int arg) {
  if (arg)
    return;
  set_weight(0);
  set_value(0);
  set_max_weight(100000);
}


string short() {
  return HIB + "Rump's Bag Baby" + NORM;
}

int id(string str) {
  return str == "bag" || str == "rumpbag";
}
