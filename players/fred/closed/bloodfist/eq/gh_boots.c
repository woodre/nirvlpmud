inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g;

reset(arg){
   ::reset(arg);

  set_name("greyhorn light plated boots");
  set_short(HIW+"GreyHorn Light Plated Boots"+NORM);
  set_type("boots");
  set_ac(1);
  set_weight(2);
  set_value(1200+random(500));
}

long(str)
{
  long_desc =
"These pair of boots were forged for the mighty warrior Sir Drevalus.\n"+
"Each boot is plated with light metal and provides good protection in\n"+
"combat.  The boots are not particularly comfortable but look beautiful.\n";
  if(this_player()->query_guild_name() == "bloodfist")
    long_desc += HIW+"These boots glow with an aura of might.\n"+NORM;
  ::long();
}

id(str){ return (::id(str) || str == "greyhorn_zeq"); }

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -10); /* might */
  return g;
}

wear(str)
{
  s = worn;
  g = ::wear(str);
  if(!s && worn_by == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, 10); /* might */
  return g;
}

remove(str)
{
  me = worn_by;
  g = ::remove(str);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -10); /* might */
  return g;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(1, -10); /* might */
      gob->advance_checks();
    }
}

