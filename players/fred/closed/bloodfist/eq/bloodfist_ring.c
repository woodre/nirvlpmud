inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g;

reset(arg){
   ::reset(arg);

  set_name("bloodfist ring");
  set_alias("ring");
  set_short(HIR+"Bloodfist Ring"+NORM);
  set_type("ring");
  set_ac(0);
  set_weight(1);
  set_value(600+random(500));
}

long(str)
{
  long_desc =
"This small red ring is made of silver and has a small red crystal\n"+
"fragment embedded in the surface of it.  Small etchings are visible\n"+
"all around the crystal.  Only members of the Bloodfist guild are\n"+
"allowed to wear these rings.\n";
  if(this_player()->query_guild_name() == "bloodfist")
    long_desc += HIR+"The ring glows with an aura of faith.\n"+NORM;
  ::long();
}

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(5, -12); /* faith */
      gob->advance_checks();
    }
  return g;
}

wear(str)
{
  s = worn;
  if(this_player() && this_player()->query_guild_name() != "bloodfist")
    return (notify_fail("You can not wear this ring.\n"), 0);
  g = ::wear(str);
  if(!s && worn_by == this_player())
  {
    if((gob = present("bloodfist_gob", this_player())))
    {
      if(gob->query_glevel() > 6)
        ac = 2;
      else if(gob->query_glevel() > 2)
        ac = 1;
      gob->add_attribb(5, 12); /* faith */
      gob->advance_checks();
    }
    else
      ac = 0;
  }
  return g;
}

remove(str)
{
  me = worn_by;
  g = ::remove(str);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(5, -12); /* faith */
      gob->advance_checks();
    }
  return g;
}

do_special(owner)
{
  if(!owner) return;
  if(!random(16))
    tell_object(owner,
      "Your thirst for bloodshed grows stronger.\n");
  return 0;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(5, -12); /* faith */
      gob->advance_checks();
    }
}