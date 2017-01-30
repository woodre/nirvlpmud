#include "../def.h"

id(str)
{
  return (str == "mageobj" || str == "forbin_mage_object" || 
          str == "GI" || str == "guild_object" || str == "gob" || 
          str == "spellbook" || str == "book" ||
          str == "player_attack_object" ||
          str == "generic_wc_bonus" ||
          str == "generic_sp_bonus" ||
          str == "sp_regen_object"); 
}

status drop() { return 1; }
status get()  { return 1; }

string short() 
{
  object a, e;
  if((a = this_player()) && (e = environment()) && (e == a)) 
  {
    return GuildColor+"Your magic spellbook ["+GuildColor+BOLD+"*"+GuildColor+"]"+NORM;
  }
  else
    return GuildColor+(string)environment()->query_name()+"'s magic spellbook ["+GuildColor+BOLD+"*"+GuildColor+"]"+NORM;
}

long()
{
  tell_object(this_player(),
    GuildColor+"The spellbook is the heart and soul of any magic wielder.\n"+
    "All your spells and powers are recorded in this tome.  You\n"+
    "are warmed by the unlimited powers of magic kept within this\n"+
    "this special book.  Type <"+GuildColor+BOLD+"mhelp"+GuildColor+"> for more.\n"+NORM);
  return 1;
}
