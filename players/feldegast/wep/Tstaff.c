#include "defs.h"

inherit "obj/weapon.c";

string name;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  switch(random(5)) {
    case 0: name=YEL+"Force"+NORM;break;
    case 1: name=HIR+"Swift Death"+NORM;break;
    case 2: name=BOLD+BLK+"Slaying"+NORM;break;
    case 3: name=HIG+"Bedira"+NORM;break;
    case 4: name="the "+HIB+"Faestorm"+NORM;break;
  }
  set_name("sword");
  set_alias("tournament item");
  set_short("The "+HIY+"Quarterstaff"+NORM+" of "+name);
  set_long(
    short_desc+" is about two meters long, and appears to have been\n"+
    "carved from a silverwood tree.  A line of runes run up and down\n"+
    "the staff in a spiral.  On either end of the staff are hard steel\n"+
    "caps.\n"
  );
  set_type("sword");
  set_class(18);
  set_weight(5);
  set_value(0);
}
