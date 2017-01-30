#include <ansi.h>
inherit "obj/newtreasure";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("mushroom");
  set_alias("mushrooms");
  set_value("200");
  set_short("a " + BOLD + "mushroom" + NORM);
  set_long(format("This is a beautiful white mushroom. It looks like it \
has been freshly picked. It looks list most other white mushrooms that \
you have seen before. Perhaps you could eat it."));
  set_read("Are you insane? Reading a mushroom? What where you thinking?\n");
  set_weight(1);
}

init()
{
  ::init();
  add_action("eat_me","eat");
}

eat_me(string str)
{
  if (!str && str != id() )
  {
    notify_fail("What are you trying to eat?\n");
    return 0;
  }
  else
  {
  write("  You\n\t" + HIB + "s\n\t " + HIR + "e\n\t  " + HIG + "e\n\t\t\
" + HIW + "R a i N b O w s\n" + HIM + "||||||||||\n " + HIB + "   ||||||\
||||\n" + HIC + "      ||||||||||\n" + HIG + "         ||||||||||\n" +
HIY + "            ||||||||||\n" + HIR + "               ||||||||||\n" +
NORM + "And then they are all gone.\n");
  }
  return 1;
}
