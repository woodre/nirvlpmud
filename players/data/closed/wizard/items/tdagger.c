#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dagger");
set_short("a small throwing dagger");
set_long(
"  This is a small dagger that is perfectly balanced for\n"+
"throwing.\n");

set_type("knife"); 
set_class(12);
set_weight(1);
set_value(10);
}
