#include "defs.h"

inherit "obj/weapon.c";

string name;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  switch(random(5)) {
    case 0: name=HIM+"Soulstealing"+NORM;break;
    case 1: name=HIR+"Kruarg"+NORM;break;
    case 2: name=BOLD+BLK+"Slaying"+NORM;break;
    case 3: name=HIC+"Swiftness"+NORM;break;
    case 4: name="the "+HIB+"Fae"+NORM;break;
  }
  set_name("dagger");
  set_alias("tournament item");
  set_short("The "+BOLD+"Dagger"+NORM+" of "+name);
  set_long(
"The dagger of "+name+" is a long dagger, practically a short sword,\n"+
"with a forward sweeping guard and a silver hilt.  It seems to thrum\n"+
"with untapped magic.\n"
  );
  set_type("sword");
  set_class(16);
  set_weight(4);
  set_value(0);
}
