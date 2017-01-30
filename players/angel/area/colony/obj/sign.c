#include <ansi.h>

id(str) {
  return str=="new sign" || str== "sign";
}


long()
 {
  write("\n\
    Two main types of Land Measurement:\n\
\n\
A unit of area in the U.S. Customary System, used in land\n\
and sea floor measurement and equal to 160 square rods, 4,840\n\
square yards, or 43,560 square feet which is called an acre\n\
\n\
A square meter is by definition the area enclosed by a square\n\
with sides each 1 meter long. It is the SI unit of area. One\n\
square meter is equal to 0.000 247 105 381 acre.\n\n");
}

short() {
  return "A land measurement "+HIM+"sign"+NORM+"";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "sign") return 0;
  long();
  return 1;
}