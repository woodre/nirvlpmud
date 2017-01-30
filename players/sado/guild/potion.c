#include "/players/sado/guild/std.h"

inherit "/obj/treasure.c";

#define COLOR 0
#define ACTIONFILE 1
#define COST 2
mapping typeinfo;

string color;
string type;

reset(arg)
{
  if(arg) return;
  set_weight(1);
  set_id("potion");

  typeinfo = (["water":({"colorless",WATER,0}),
	      "haste":({"ice blue",HASTE,20})]);
  set_type("water");
}

query_cost()
{
  return typeinfo[type][COST];
}

set_color(str)
{
  color = str;
  set_alias(color+" potion");
  set_short("A small phial of " + color + " liquid");
}

set_type(str)
{
  type = str;
  set_color(typeinfo[type][COLOR]);
}

init()
{
  ::init();
  add_action("drink","drink");
}

id(str)
{
  return (str==color+" potion" || ::id(str));
}

drink(str)
{
  object act;
  write("You chug the potion...\n");
  say(tpname+" uncorks a phial, and chugs the contents.\n");
  move_object(act = clone_object(typeinfo[type][ACTIONFILE]),tp);
  act->action();
  destruct(this_object());
  return 1;
}

query_color()
{
  return color;
}

have_reqs(who,str)
{
  switch(str)
  {
  case "haste": return who->query_money()>100;
  default: return 0;
  }
}

rm_reqs(who,str)
{
  switch(str)
  {
  case "haste": who->add_money(-100); write("You drop 100 coins into your portable cauldron.\n"); break;
  default: return;
  }
}
