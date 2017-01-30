#include "/obj/ansi.h"

object targ;
int pts;

string short() { return (string)targ->short() + HIB+" ["+NORM+BOLD+"Blessed"+HIB+"]"+NORM; }

do_special(arg) {
  int bonus;
  bonus = targ->do_special(arg);
  if(pts > 0)
  {
    if(!random(10))
    {
      tell_object(arg, "You feel blessed with health.\n");
      arg->add_hit_point(2);
      pts--;
    }
    else if(!random(12))
    {
      tell_object(arg, "Your "+targ->query_name()+" protects you particularly well today.\n");
      bonus += 2;
      pts--;
    }
  }
  else
    call_out("stop_shadow", 3);
  return  bonus; 
}

int start_shadow(object t)
{
  int nStatus;
  targ = t;
  pts = 100+random(50);
  if((int)targ->query_shadowed())
    nStatus = 0;
  else if((int)targ->query_no_enchant())
    nStatus = 0;
  else if(!function_exists("do_special", targ))
    nStatus = 0;
  else
  {
    shadow(targ, 1);
    nStatus = 1;
  }
  call_out("stop_shadow", 1800);
  return nStatus;
}

int stop_shadow()
{
  object user;
  shadow(targ, 0);
  user = environment(targ);
  if(interactive(user))
    tell_object(user, "The blessing on "+(string)targ->short()+" fades.\n");
  destruct(this_object());
  return 1;
}

object query_shadow() { return this_object(); }

int query_shadowed() { return 1; }
