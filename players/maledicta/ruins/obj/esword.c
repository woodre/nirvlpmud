#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sword");
set_short("a huge broadsword");
set_long(
  "  At one time you believe this must have been a beautiful sword, its\n"+
  "craftsmanship nearly unmatched in the realm.  But now, you see that\n"+
  "after long use and even longer misuse that it is now barely a reminder\n"+
  "of its formal glory. It's blade is notched from endless fights.\n");

set_type("sword"); 
set_class(14);
set_weight(3);
set_value(150);

}

