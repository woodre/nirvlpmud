#include "../defs.h"

id(str)
{
  return (str == "dmgob" || str == "forbin_dm_object" || 
          str == "GI" || str == "guild_object" || str == "gob" || 
          str == "dark_sight_object" ||
          str == "generic_wc_bonus" ||
          str == "generic_sp_bonus" ||
          str == "sp_regen_object"); 
}

status drop() { return 1; }
status get()  { return 1; }

string short() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) 
    return CYN+"DarkMage Guild Object "+HIW+"["+NORM+"invis"+HIW+"]"+NORM;
}

long()
{
	object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) 
  tell_object(a,
    "This is the Dark Mage Guild Object - nothing fancy here.\n");
  return 1;
}
