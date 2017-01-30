inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object me, gob;
int s, g;
int bft;

reset(arg){
   ::reset(arg);
   if(arg) return;

  bft = -1;
  set_name("amulet of blood");
  set_type("amulet");
  set_ac(0);
  set_weight(1);
  set_value(2200+random(500));
}

short()
{
  if(this_player()
    && this_player()->query_guild_name() == "bloodfist" && bft > -1)
  {
    string f;
    if(bft == 0) f = "agility";
    else if(bft == 1) f = "might";
    else if(bft == 2) f = "accuracy";
    else if(bft == 3) f = "vigor";
    else if(bft == 4) f = "wisdom";
    else if(bft == 5) f = "faith";
    short_desc = RED+"Amulet of Blood ["+NORM+f+" aura"+RED+"]"+NORM;
  }
  else 
    short_desc = RED+"Amulet of Blood"+NORM;
  return ::short();
}

long(str)
{
  string f;
  if(bft >= 0)
  {
    if(bft == 0) f = "agility";
    else if(bft == 1) f = "might";
    else if(bft == 2) f = "accuracy";
    else if(bft == 3) f = "vigor";
    else if(bft == 4) f = "wisdom";
    else if(bft == 5) f = "faith";
  }
  long_desc =
"The amulet of blood is silver and has a small red crystal embedded\n"+
"into the center of the body.  The engravings of the bloodfist are all\n"+
"around the crystal.\n";
  if(this_player()->query_guild_name() == "bloodfist" && f)
    long_desc += RED+"The amulet glows with an aura of "+f+".\n"+NORM;
  ::long();
}

/*
query_save_flag(){  return 1; }
*/

void set_bf_type(string str)
{
  if(str == "agl")       bft = 0;
  else if(str == "mit")  bft = 1;
  else if(str == "acc")  bft = 2;
  else if(str == "vig")  bft = 3;
  else if(str == "wis")  bft = 4;
  else if(str == "fai")  bft = 5;
  else bft = -1;
}

int set_random_bf_type(){ return (bft = random(6)); }

drop(silently)
{
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      if(bft >= 0 && bft <= 5)
      {
        gob->add_attribb(bft, -15);
        gob->advance_checks();
      }
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
      if(bft >= 0 && bft <= 5) 
      {
        gob->add_attribb(bft, 15);
        gob->advance_checks();
      }
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
      if(bft >= 0 && bft <= 5)
      {
        gob->add_attribb(bft, -15);
        gob->advance_checks();
      }
    }
  return g;
}

do_special(owner)
{
  if(!owner) return;
  if(!random(16) && bft >= 0)
  {
    tell_object(owner, 
      "You feel your heart race as your amulet glows softly.\n");
    owner->add_spell_point(random(2));
    return 1;
  }
  return 0;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", this_player())))
    {
      gob->add_attribb(bft, -15);
      gob->advance_checks();
    }
}

locker_arg(){ return ""+bft; }
locker_init(arg){ bft = atoi(arg); }
restore_thing(str){ restore_object(str); return 1; }
save_thing(str){ save_object(str); return 1; }
generic_object(){ return 1; }
