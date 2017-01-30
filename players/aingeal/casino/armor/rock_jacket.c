/* Gladys Knight's Rock 'n Roll Hall of Fame jacket */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("jacket");
  set_alias("leather jacket");
  set_short(" "+HBRED+HIW+"ROCK and ROLL HALL of FAME"+NORM+" Jacket");
  set_long("The heavy leather jacket of deepest ebony is lined with dark grey\n\
silk.  The small, brightly colored insignia in the shape of a guitar\n\
on the front of the jacket matches the large logo across the back of\n\
the jacket advertising\n"+HBRED+BLINK+HIW+
"The ROCK and ROLL HALL OF FAME"+NORM+".\n");
  set_weight(3);
  set_value(750);
  set_ac(3);
  set_type("armor");
}
