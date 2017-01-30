inherit "/obj/generic_heal.c";
#include <ansi.h>
/******************************************************************************
 * Program: meth.c
 * Path: /players/dragnar/WalkingDead/heals/mons
 * Type: Heal
 * Created: June 13th, 2014 by Dragnar
 *
 * Purpose: A detox heal that lowers soak/stuff. If it is used while the
 *          player is not very soaked/stuffed it causes random 250 damage
 *          to the player. Even when damage is not done it costs the
 *          player random 125 sps. Heals are found randomly on walkers,
 *          and on a few of the mobs in town. Walkers have a 1/6 chance
 *          of having this, and walker has to be killed just to check to
 *          see if they have it.
 * History:
 *          06/13/2014 - Dragnar
 *            Created
 ******************************************************************************/

#include "../../defs.h"

#define rand_val (random(125))

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("methamphetamine");
  add_alias("shard");
  add_alias("shards");
  add_alias("methamphetamine shard");
  add_alias("methamphetamine shards");
  add_alias("meth");
  set_short(HIW+"Methamphetamine"+NORM+"");
  set_long("These shards of methamphetamine may amp you up and reduce your thirst\n\
and fullness. Do not take on an empty stomach or they could cause\n\
a very deadly "+HIR+BRED+"Cerebral Hemorrhage"+NORM+".\n");
  set_type("shard");
  set_msg("You swallow a shard of "+HIW+"Methamphetamine"+NORM+".\n");
  set_msg2(" swallows a shard of "+HIW+"Methamphetamine"+NORM+".\n");
  add_cmd("eat");
  add_cmd("gulp");
  add_cmd("swallow");
  set_heal(0,-rand_val);
  set_charges(1+random(3));
  set_stuff(-50);
  set_soak(-50);
  set_value(700);
}

void
init()
{
  ::init();
  add_action("cmd_doheal", "swallow");
  add_action("cmd_doheal", "gulp");
  add_action("cmd_doheal", "pop");
}

int cmd_imbibe(string str)
{
  int soa, stu;
  object me;

  me = this_player();

  if(environment() != me)
  {
    notify_fail("You may only " + query_verb() + " from " +
      short() + " when you are carrying it.\n");
    return 0;
  }
  if(!str)
  {
    notify_fail(capitalize(query_verb())+" what?" + "\n");
    return 0;
  }
  if(!id(str))
  {
    notify_fail("You may only " + query_verb() + " from " + short() + ".\n");
    return 0;
  }
  
  soa = (int) this_player()->query_soaked();
  stu = (int) this_player()->query_stuffed();
  hp_heal = 0;
  if( (soa + stu) < 75 ) {
    write("The Methamphetamine causes a massive "+HIR+BRED+"Cerebral Hemorrhage"+NORM+"!\n");
    say(this_player()->query_name()+" stumbles as they are hit with a massive "+HIR+BRED+"Cerebral Hemorrhage"+NORM+"!\n");
    hp_heal= -rand_val - rand_val;
    sp_heal= -rand_val;
  }
  return ::cmd_imbibe(str);
}

int cmd_doheal(string arg)
{
  return cmd_imbibe("methamphetamine");
}

query_save_flag() { return 1; }
