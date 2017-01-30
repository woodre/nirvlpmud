#define MYFILE "/players/feldegast/heals/myrm-blood.c"
#define STRENGTH 10
#include "/players/feldegast/defines.h"

inherit "obj/treasure";

int charges;

void reset(int arg)
{
  set_id("blood");
  set_alias("myrmidar blood");
  set_short(BOLD+BLK+"Myrmidar"+HIR+" Blood"+NORM);
  set_long("A quart of blackish blood in a bladder.\n");
  set_weight(1);
  set_value(800);
  charges=2;
}
void init()
{
  add_action("cmd_drink","drink");
  add_action("cmd_drink","sip");
  add_action("cmd_drink","slam");
}
int cmd_drink(string str)
{
  notify_fail("Drink what?\n");
  if(!id(str)) return 0;
  if(!this_player()->drink_soft(STRENGTH))
  {
    notify_fail("Drink what?\n");
    return 0;
  }
  charges--;
  this_player()->add_hit_point(20);
  this_player()->add_spell_point(60);
  write("You cough and hack as you force yourself to drink the foul\n"+
       "concoction.\n");
  say(TPN+" drinks "+short()+".\n");
  if(!random(9)) call_other(MYFILE,"call_bad_drink",this_player());
  if(charges<=0)
  {
    write("You finish off the "+short()+" and toss the bladder aside.\n");
    destruct(this_object());
    this_player()->recalc_carry();
  }
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

query_value() { return 500*charges; }
