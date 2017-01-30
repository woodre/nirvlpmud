#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("blade");
set_short("A Doona Wrist blade");
set_long(
"  This is a wickedly long pair of blades that extends from a\n"+
"steel bracer which latches comfortably to a wrist. It seems\n"+
"to be a very sharp and dangerous weapon.\n");
set_weight(2);
set_class(16);
set_type("sword");
set_value(500);

}

