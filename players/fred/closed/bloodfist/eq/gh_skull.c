inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g;

reset(arg){
   ::reset(arg);

  set_name("greyhorn skull");
  set_alias("skull");
  set_short(HIW+"GreyHorn Skull"+NORM);
  set_type("helmet");
  set_ac(1);
  set_weight(2);
  set_value(1200+random(500));
}

long(str)
{
  long_desc =
"This metal helmet is fashioned in the shape of a narrow skull.  It\n"+
"has two small holes for the eyes and a grated cover for the mouth.\n"+
"It seems to glow with a soft gray aura of light.\n";
  if(this_player()->query_guild_name() == "bloodfist")
    long_desc += HIW+"This helmet glows with an aura of might.\n"+NORM;
  ::long();
}

id(str){ return (::id(str) || str == "greyhorn_zeq"); }

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -15); /* might */
  return g;
}

wear(str)
{
  s = worn;
  g = ::wear(str);
  if(!s && worn_by == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, 15); /* might */
  return g;
}

remove(str)
{
  me = worn_by;
  g = ::remove(str);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -15); /* might */
  return g;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(1, -15); /* might */
      gob->advance_checks();
    }
}
