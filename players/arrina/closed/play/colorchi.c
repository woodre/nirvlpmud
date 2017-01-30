#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

id(str) { return str == "colorob"; }

init()
{
  add_action("do_color","do_color");
}

do_color()
{
  find_player("tara")->set_title(MAG+"the Oathbreaker"+NORM);
  return 1;
}
