#include "/obj/ansi.h"

object targ;

string short() { return (string)targ->short() + HIB+" ["+NORM+BOLD+"Blessed"+HIB+"]"+NORM; }

weapon_class() {
  return targ->weapon_class() + 1; 
}

int start_shadow(object t)
{
  int nStatus;
  targ = t;
  if((int)targ->query_shadowed())
    nStatus = 0;
  else if((int)targ->query_bloodcount())
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
