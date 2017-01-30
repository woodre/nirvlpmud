#include "/players/forbin/define.h"
inherit "obj/treasure.c";

id(str) { return str == "no_quitter"; }
reset(arg)
{
  if(arg) return;
}
short()
{
  object a, e;
  if((a = this_player()) && (e = environment()) &&
     (e == a))
  return "NO QUITTER [no_quitter to dest]";
}
get() { return 0; }
init()
{
  add_action("niqme","doit");
}
niqme()
{
  this_player()->set_noidlequit();
    return 1; 
}


