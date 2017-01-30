/*
//  Created:      Forbin@Nirvana
//  Realm:        Bloodfist Guild
//  Function:     BF Equipment Base Inherit
//  Create Date:  2005.08.11
//  Last Edit:    2005.08.11 -Forbin
//  Notes:        Use to make anyones items modify the Bloodfist
//                guild attributes using only a couple lines of
//                code in the object
//                  Agility   Bonuses[0]
//                  Might     Bonuses[1]
//                  Accuracy  Bonuses[2] 
//                  Vigor     Bonuses[3] 
//                  Wisdom    Bonuses[4]
//                  Faith     Bonuses[5]
*/

#include "/players/fred/closed/bloodfist/defs.h"

inherit "/obj/armor.c";

object me, gob;
int s, g;
int *Bonuses;

void reset(int arg)
{
  if(arg) return;
  ::reset();  
  Bonuses = ({ 0,0,0,0,0,0 });
}  

void set_bf_guild_bonus(int x, int y) { Bonuses[x] = y; }

int query_bf_guild_bonus(int x) { return Bonuses[x]; }

int query_bf_guild_bonuses()
{
  return (Bonuses[0] + Bonuses[1] + Bonuses[2] +
          Bonuses[3] + Bonuses[4] + Bonuses[5]);
}

drop(silently)
{
  if(!living(environment())) return;
  me = worn_by;
  g = ::drop(silently);
  if(worn_by == 0 && me == environment())
    if((gob = present("bloodfist_gob", environment())))
    {
      int x;
      for(x = 0; x < 6; x++)
      {
        if(Bonuses[x] != 0)
          gob->add_attribb(x, -Bonuses[x]);
      }
      gob->advance_checks();
    }
  return g;
}

wear(str)
{
  if(!environment()) return 0;
  if(!living(environment())) return 0;
  s = worn;
  g = ::wear(str);
  if(!s && worn_by == this_player())
    if((gob = present("bloodfist_gob", environment())))
    {
      int x;
      for(x = 0; x < 6; x++)
      {
        if(Bonuses[x] != 0)
          gob->add_attribb(x, Bonuses[x]);
      }
      gob->advance_checks();
    }
  return g;
}

remove(str)
{
  if(!living(environment())) return 0;
  me = worn_by;
  g = ::remove(str);
  if(worn_by == 0 && me == environment())
    if((gob = present("bloodfist_gob", environment())))
    {
      int x;
      for(x = 0; x < 6; x++)
      {
        if(Bonuses[x] != 0)
          gob->add_attribb(x, -Bonuses[x]);
      }
      gob->advance_checks();
    }
  return g;
}

xfer_special()
{
  me = worn_by;
  if(worn_by == 0 && me == this_player())
    if((gob = present("bloodfist_gob", environment())))
    {
      int x;
      for(x = 0; x < 6; x++)
      {
        if(Bonuses[x] != 0)
          gob->add_attribb(x, -Bonuses[x]);
      }
      gob->advance_checks();
    }
}
