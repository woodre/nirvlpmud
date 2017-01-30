inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g;

reset(arg){
   ::reset(arg);

  set_name("combat boots");
  set_short(GRN+"Combat Boots"+NORM);
  set_type("boots");
  set_ac(0);
  set_weight(2);
  set_value(1200+random(500));
}

long(str)
{
  long_desc =
"These rather cumbersome looking combat boots look very comfortable\n"+
"because the insides are lined with a very soft material.";
"The Desert Wall is a very sturdy tower shield.  A yellow crest is\n"+
"painted on the front of the shield, however it has faded with time.\n"+
"Overall the shield is in very good condition, despite the constant\n"+
"exposure to the whipping winds of the desert.\n";
  if(this_player()->query_guild_name() == "bloodfist")
  {
    long_desc += "  The boots\n"+
"look as though they would provide you with an excellent boost in\n"+
"combat.\n"+GRN+"The boots glow with a soft green aura.\n"+NORM;
  }
  else
    long_desc += "\n";
  ::long();
}

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(0, -4); /* agility */
      gob->add_attribb(2, -4); /* accuracy */
      gob->add_attribb(3, -4); /* vigor */
      gob->advance_checks();
    }
  return g;
}

wear(str)
{
  s = worn;
  g = ::wear(str);
  if(!s && worn_by == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(0, 4); /* agility */
      gob->add_attribb(2, 4); /* accuracy */
      gob->add_attribb(3, 4); /* vigor */
      gob->advance_checks();
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
      gob->add_attribb(0, -4); /* agility */
      gob->add_attribb(2, -4); /* accuracy */
      gob->add_attribb(3, -4); /* vigor */
      gob->advance_checks();
    }
  return g;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(0, -4); /* agility */
      gob->add_attribb(2, -4); /* accuracy */
      gob->add_attribb(3, -4); /* vigor */
      gob->advance_checks();
    }
}
  