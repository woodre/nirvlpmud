#include "defs.h"

inherit "obj/weapon.c";

string name;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  switch(random(6)) {
    case 0: name=HIM+"Soulstealing"+NORM;break;
    case 1: name=HIC+"Ice"+NORM;break;
    case 2: name=BOLD+BLK+"Slaying"+NORM;break;
    case 3: name=HIC+"Heroism"+NORM;break;
    case 4: name=BOLD+BLK+"Death"+NORM+" and "+HIR+"Destruction"+NORM;break;
    case 5: name=HIR+"Flames"+NORM;break;
  }
  set_name("sword");
  set_alias("tournament item");
  set_short("The "+BOLD+"Sword"+NORM+" of "+name);
  set_long(
    short_desc+" is a magnificent weapon.  You can scarcely recall\n"+
    "ever having seen finer.  It's pommelstone is a black ruby, and\n"+
    "the guard is encrusted with other small stones.  Cryptic runes\n"+
    "run along the edge of the razor sharp blade which tapers to a\n"+
    "fine point.\n"
  );
  set_type("sword");
  set_class(20);
  set_weight(6);
  set_value(0);
}
