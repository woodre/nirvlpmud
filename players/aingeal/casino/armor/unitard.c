/* Contortionist's Unitard */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit"obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("unitard");
  set_alias("unitard");
  set_short(RED+"U"+BLU+"n"+GRN+"i"+YEL+"t"+WHT+"a"+MAG+"r"+CYN+"d"+NORM+"");
  set_long(RED+"The brightly colored "+BLU+"unitard is made "+GRN+
           "of thin, clingy\n"+YEL+"material that shimmers "+WHT+"as it moves.  "+MAG+"It molds itself\n"+CYN+"to the body "+RED+
           "like a second skin,"+BLU+"showing every line\n"+GRN+
           "and curve beneath."+NORM+"\n");
  set_weight(1);
  set_value(300);
  set_ac(1);
  set_type("armor");
}
