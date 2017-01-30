#define MYFILE "/players/feldegast/heals/myrm-heart.c"
#define STRENGTH 10
#include "/players/feldegast/defines.h"

inherit "obj/treasure";

void reset(int arg)
{
  set_id("heart");
  set_alias("myrm-heart");
  set_short(BOLD+BLK+"Myrmidar"+HIR+" Heart"+NORM);
  set_long("A black myrmidar heart.\n");
  set_weight(1);
  set_value(750);
}
void init()
{
  add_action("cmd_eat","eat");
  add_action("cmd_eat","chew");
}
int cmd_eat(string str)
{
  notify_fail("Eat what?\n");
  if(!id(str)) return 0;
  if(!this_player()->eat_food(STRENGTH))
  {
    notify_fail("Eat what?\n");
    return 0;
  }
  this_player()->add_hit_point(80);
  this_player()->add_spell_point(20);
  write("You eat the myrmidar's heart whole.\n");
  say(TPN+" eats "+short()+".\n");
  if(!random(9)) call_other(MYFILE,"call_bad_drink",this_player());
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}

void call_bad_drink(object targ)
{
  call_out("bad_drink",5+random(10),targ);
}
void bad_drink(object targ)
{
  tell_object(targ,"Your guts churn as you vomit the contents of your stomach onto the ground.\n");
  tell_room(environment(targ),targ->query_name()+" vomits on the ground.\n",({ targ }));
  targ->add_hit_point(-random(60));
}
