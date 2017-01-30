inherit "obj/armor";
#include "/players/fred/ansi.h";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_name("speedo");
set_alias("suit");
set_short("A bright"+BOLD+RED+" red"+NORM+" speedo");
set_long("A flamboyantly bright red speedo. David Hasselhoff would be envious.\n");
set_type("underwear");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
