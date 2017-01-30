#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  set_name("chainmail");
  set_short("A suit of silvery chainmail");
  set_type("armor");
  set_long(
    "Glinting somewhat, this light suit of chainmail hangs down to the\n\
knees, and is cinched at the waist with a thick golden belt.\n");
  set_ac(3);
  set_weight(3);
  set_value(500);
}
