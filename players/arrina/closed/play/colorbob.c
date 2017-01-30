#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

id(str) { return str == "colorob"; }

init()
{
  add_action("do_color","do_color");
}

do_color()
{
  find_player("oolabob")->set_title(BLU+"`OO-luh-BOB [Nahuatl] n, see"+NORM);
  return 1;
}
