inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g;

reset(arg){
   ::reset(arg);

  set_name("greyhorn wall");
  set_alias("wall");
  set_short(HIW+"GreyHorn Wall"+NORM);
  set_type("shield");
  set_ac(2);
  set_weight(3);
  set_value(7800+random(500));
}

id(str){ return (::id(str) || str == "greyhorn_zeq"); }

long(str)
{
  long_desc =
"This large metal tower shield is part of the magical equipment forged\n"+
"for the mighty warrior Sir Drevalus.  The tower is quite a few feet\n"+
"tall and curves back slightly at the edges to protect your hands.  A\n"+
"yellow crest is painted on the front of the shield.\n";
  if(this_player()->query_guild_name() == "bloodfist")
    long_desc += HIW+"This shield glows with an aura of might.\n"+NORM;
  ::long();
}

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -20); /* -20 to might */
  return g;
}

wear(str)
{
  s = worn;
  g = ::wear(str);
  if(!s && worn_by == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, 20); /* +20 to might */
  return g;
}

remove(str)
{
  me = worn_by;
  g = ::remove(str);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -20); /* -20 to might */
  return g;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(1, -20); /* might */
      gob->advance_checks();
    }
}
