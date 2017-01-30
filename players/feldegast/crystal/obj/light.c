#include "../defs.h"

inherit "/obj/treasure.c";

object OWNER;

int id(string str)
{
  return ::id(str) || str=="light crystal";
}

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  set_id("crystal");
  set_alias("light");
  set_short("A "+HIY+"light"+NORM+" crystal");
  set_long(
    "This is a small, brightly lit crystal that is small enough to fit in the palm of\n"+
    "your hand.  You may "+BOLD+"dismiss"+NORM+" it.\n"
  );
  set_weight(1);
  set_value(0);
}

int drop() { return 1; }

void init()
{
  if(!OWNER && environment()==TP)
  {
    OWNER = environment();
  }
  if(this_player() == OWNER)
  {
    add_action("cmd_dismiss", "dismiss");
    if(find_call_out("upkeep") == -1)
      call_out("upkeep", 30+random(60));
  }
}

int cmd_dismiss(string str)
{
  if(id(str))
  {
    write(HIY+"With a wave of your hand, you dismiss the light crystal.\n"+NORM);
    destruct(this_object());
    TP->add_weight(-1);
    return 1;
  }
  notify_fail("Dismiss what?\n");
  return 0;
}

void upkeep()
{
  int cost;
  cost = 1 + random(3);
  if((int)OWNER->query_sp() < cost)
  {
    tell_object(OWNER, "You can no longer afford to pay the upkeep on your light crystal.\n");
    cmd_dismiss("light crystal");
    return;
  }
  else
  {
    tell_object(OWNER, HIY+"You touch your index finger to the light crystal and recharge its power.\n"+NORM);
    OWNER->add_spell_point(-cost);
  }
  call_out("upkeep", 30 + random(60));
}
