inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g, c;

reset(arg){
   ::reset(arg);
   if(arg) return;

   set_name("greyhorn gothic plate");
   set_alias("plate");
   set_short(HIW+"GreyHorn Gothic Plate"+NORM);
   set_type("armor");
   set_ac(4);
   set_weight(4);
   set_value(7120);
}

query_save_flag(){  return 1; }
query_dest_flag(){  return 1; }

long(str)
{
  long_desc =
"This is a beautiful gothic plate of armor forged for the mighty warrior\n"+
"Sir Drevalus.  The armor is perfectly smooth and made from a gray metal\n"+
"that emits a very soft glow.  The armor is incredibly durable and simply\n"+
"breathtaking to behold.\n";
  if(this_player()->query_guild_name() == "bloodfist")
    long_desc += HIW+"This armor glow with an aura of might.\n"+NORM;
  ::long();
}

id(str){ return (::id(str) || str == "greyhorn_zeq"); }

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -25); /* might */
  return g;
}

wear(str)
{
  s = worn;
  g = ::wear(str);
  if(!s && worn_by == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, 25); /* might */
  return g;
}

remove(str)
{
  me = worn_by;
  g = ::remove(str);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
      gob->add_attribb(1, -25); /* might */
  return g;
}

do_special(owner) {
  object *all;
  int a,b;
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  if(!random(4))
  {
    c--;
    b = 0;
    if(c < 0)
    {
      all = all_inventory(owner);
      for(a = 0; a < sizeof(all); a++)
      {
        if(all[a]->id("greyhorn_zeq"))
          b++;
      }
      if(b > 4)
        c = 5;
    }
    if(b > 4 || c >= 0)
    {
      tell_object(owner, 
        HIW+"You are bathed in a magical gray light.\n"+NORM);
      tell_room(environment(owner), HIW+owner->query_name()+
        " is bathed in a magical gray light.\n"+NORM, ({ owner }));
      owner->heal_self(2);
    }
  }
  return 0; 
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(1, -25); /* might */
      gob->advance_checks();
    }
}
