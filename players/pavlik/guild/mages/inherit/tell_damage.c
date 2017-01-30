#include "/players/pavlik/guild/mages/defs.h"

/*
 * Give indicator of how much damage was done
 */
tell_damage(amount, obj)
{
  string what;

  if(amount >= 60) what = HIR+"ANNIHILATES"+NORM;
  else if(amount >= 50) what = HIR+"devastates"+NORM;
  else if(amount >= 40) what = RED+"crushes"+NORM;
  else if(amount >= 30) what = MAG+"pulverizes"+NORM;
  else if(amount >= 20) what = HIW+"smashes"+NORM;
  else if(amount >= 10) what = "hits";
  else if(amount >= 4)  what = "nicks";
  else what = "annoys";

  write("Your spell "+what+" "+IT);
  say(ME+"'s spell "+what+" "+IT);

  if(amount > 20)
  {
	write("!");
	say("!\n");
  }
  else
  {
	write(".");
	say(".\n");
  }

  if(tp->query_level() > 20)
  {
	write(" ["+amount+"]\n");
  }
  else
  {
	write("\n");
  }

  return;
}


/*
 * Alternate version for use with call_outs and such...
 */
tell_damage2(amount, obj, me)
{
  string what;

  if(amount >= 60) what = HIR+"ANNIHILATES"+NORM;
  else if(amount >= 50) what = HIR+"devastates"+NORM;
  else if(amount >= 40) what = RED+"crushes"+NORM;
  else if(amount >= 30) what = MAG+"pulverizes"+NORM;
  else if(amount >= 20) what = HIW+"smashes"+NORM;
  else if(amount >= 10) what = "hits";
  else if(amount >= 4)  what = "nicks";
  else what = "annoys";

  tell_object(me, "Your spell "+what+" "+IT);
  tell_room(environment(me), capitalize(me->query_name())+"'s spell "+what+" "+IT, ({me}));

  if(amount > 20)
  {
	tell_object(me, "!");
	tell_room(environment(me), "!\n", ({me}));
  }
  else
  {
	tell_object(me, ".");
	tell_room(environment(me), ".\n", ({me}));
  }

  if(me->query_level() > 20)
  {
	tell_object(me, " ["+amount+"]\n");
  }
  else
  {
	tell_object(me, "\n");
  }

  return;
}

