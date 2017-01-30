#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

id(str) { return str == "colorob"; }

init()
{
  add_action("do_color","do_color");
}

do_color()
{
  find_player("arrina")->set_title(HIR+"the Wicked"+NORM);
  return 1;
}
