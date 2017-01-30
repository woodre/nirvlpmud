#include "../def.h"
inherit POWERBASE;

/* NOTE:  This is a fairly useless spell - spend 100 exp and 500 coins to give the target a tiny boost to one heal?
   Needs to be updated.
   Ideas: 
    fortify is sustained until all the exp is used up
    cost scales to healer level
   
*/
   

void reset() {
  spell_name = "fortify";
  difficulty = 20;
  difficulty_type = "level";
  difficulty_multiplier = 2;
  fail_message = "Your fortify spell failed!\n";
  requirements = ([ 
    "living_target" : ({ "0", "You may only cast fortify upon other Healers.\n" }),
    "not_self" : ({ "0", "You may only cast fortify upon other Healers.\n" }),
    "level" : ({ 6, "You must be at least level 6 to cast this spell.\n" }),
    "sp" : ({ 10, "You are low on energy.\n" }),
    "exp" : ({  100, "You are low on light.\n" }),
    "coins" : ({ 500, "You are low on coins.\n" }),
    "target_healer_check" : ({ 0, "You may only cast fortify upon other Healers.\n" }),
  ]);
  costs = ([ "sp" : 10, "exp" : 100, "coins" : 500 ]);
}

status main(string str, object target, object usr, object gob)
{
  int lvl;
  object target_gob;
  lvl = (int)gob->query_guild_level();
  target_gob = present(GUILD_OB_ID,target);
  
  target_gob->add_fortify(lvl);
  gob->do_emote("You close your eyes and intone for a moment.  You have fortified #TN#!\n",
    "#MN# closes #MP# eyes and intones for a moment.  Your healing ability has been fortified!\n",
    "#MN# closes #MP# eyes and intones for a moment.\n",
    usr, target);
  return 1;
}

target_healer_check(str, usr, gob, target) {
  if(!present(GUILD_OB_ID,target))
    return 0;
}
