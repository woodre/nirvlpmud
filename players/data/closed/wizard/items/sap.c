#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sap");
set_short("sap");
set_long(
"  This is a leather sap, used for knocking someone\n"+
"unconscious. It has a short wooden handle that is\n"+
"attached to a leather strap with a weighted bulbous\n"+
"end.\n");
set_type("blunt"); 
set_class(13);
set_weight(1);
set_value(25);
}
