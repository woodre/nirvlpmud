/*
 * eq|item rot for Undead..
 * ffear it.
 */

#include "../lib/guild_defs.h"
#include <ansi.h>

object shadowee;
int    condition;

#define NR_OF_TIMES 3
int eq;
int SECS;

void start_rot_shadow(object ob)
{
  shadowee = ob;
  condition = 0;
  shadow(ob, 1);
  call_out("chg_me", SECS);
}

int query_rotting() { return 1; }

void end_rot_shadow()
{
  if(shadowee)
    remove_shadow(shadowee);
  destruct(this_object());
}

void chg_me()
{
  object x, env;
  if(!shadowee)
    return destruct(this_object());
  if((++ condition) == NR_OF_TIMES)
  {
    if(shadowee->queryKept())
      shadowee->deShadow(); /* for kept items */
    if((x=ENV(shadowee)) && x->is_player())
    {
      int moo;
      tell_object(x, "\n\
Your "+(string)shadowee->short()+" is now entirely useless.\n");
      if(env = ENV(x))
      {
        tell_room(env,
(string)x->QN+"'s "+(string)shadowee->short()+" \
rots away...\n", ({x}));
        x->drop_one_item(shadowee);
      }
      destruct(shadowee);
      /* recalc weight, need this separated in player obj */
      if(x->query_fight_area())
        moo = 1;
      x->reset(1);
      if(moo)
        x->set_fight_area();
      /* end recalc */
      return end_rot_shadow();
    }
    else
    {
      if(living(shadowee) && x)
        tell_room(x, (string)shadowee->short() + " rots away...\n");
      else
        tell_room(x, (string)shadowee->short()+" rots away...\n");
      destruct(shadowee);
      return end_rot_shadow();
    }
  }
  call_out("chg_me", SECS);
}

string short()
{
  string tag, sh, col;
  switch(random(3))
  {
    case 0:
      col = GRN;
      break;
    case 1:
      col = HIG;
      break;
    case 2:
      col = HIK;
      break;
  }
  switch(condition)
  {
    case 0:
      tag = "corroding";
      break;
    case 1:
      tag = "rotting";
      break;
    case 2:
      tag = "crumbling";
      break;
  }
  if(sh=(string)shadowee->short())
    return sh+" ["+col+tag+NORM+"]";
}

void set_rot_time(int x){ SECS = x; }

void set_eq(status x) { eq = x; }
void set_rot_status(int x){ condition = x; }
int query_rot_status() { return condition; }
int query_rot_time() { return SECS; }

query_value() { return (shadowee->query_value()/(condition+1)); }


query_save_flag() { return 1; }
