#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("pole");
set_alt_name("trap_defense");
set_short("10' pole");
set_long(
"  This is a very long wooden pole. It is more of a tool\n"+
"rather than a weapon, but can be used as such. If wielded\n"+
"it could protect you against some forms of traps.\n");
set_type("polearm"); 
set_class(7);
set_weight(3);
set_value(20);
}

query_trap_defense(){ return 50; }