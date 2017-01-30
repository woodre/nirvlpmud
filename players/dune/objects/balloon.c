inherit "obj/treasure";
#include <ansi.h>

int i;
string type;

reset(arg)
{
  if(arg) return;
  i = random(5)+1;
  if (i == 1)
  {
type = "A "+BOLD+RED+"red balloon"+OFF;
set_short(type);
set_value(0);
  }
  if (i == 2)
  {
type = "A "+BOLD+BLUE+"blue balloon"+OFF;
set_short(type);
set_value(0);
  }
  if (i == 3)
  {
type = "A "+BOLD+GREEN+"green balloon"+OFF;
set_short(type);
set_value(0);
  }
  if (i == 4)
  {
type = "A "+BOLD+YELLOW+"yellow balloon"+OFF;
set_short(type);
set_value(0);
  }
  if (i == 5)
  {
type = "A "+BOLD+"white balloon"+OFF;
set_short(type);
set_value(0);
  }
  set_long("This is a balloon. Perhaps you could pop it.\n"+
           "It has a fearsome terminator skull logo on the front.\n");
  set_weight(1);
}


id(str)
{
return str == "balloon";
}


init()
{
  ::init();
  add_action("pop", "pop");
}


pop()
{
  write("You pop "+type+"!\n");
  say(capitalize((string)this_player()->query_name())+" pops "+type+".\n");
  destruct(this_object());
  return 1;
}
