#include "/players/linus/def.h"
inherit "/obj/armor.c";
id(str) { return str=="shirt" || str=="blue shirt"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("A "+BLU+"shirt"+NORM);
 set_short("A "+BLU+"shirt"+NORM);
 set_long("A small "+BLU+"shirt"+NORM+" that Roo likes to wear.\n");
 set_type("armor");
 set_ac(1);
 set_weight(1);
 set_value(200);
}
