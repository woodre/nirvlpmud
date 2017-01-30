#include "../def.h"

string s_spell_name()     { return "enchant armor"; }
string s_proper_name()    { return "Enchant Armor"; }
   int s_spell_level()    { return 4; } 
string s_spell_school()   { return "ench"; }
string s_primary_stat()   { return "intelligence"; }
string s_secondary_stat() { return "wisdom"; }

/* info() is used by guild NPC to inform player about spell */
status info(object gob, object player) 
{
  
}

/* help() is called from mhelp and is the help information about spell */
status help(object gob, object player) 
{
  
}

/* main is called from cast.c command and is the bulk of the spell */
status main(string str, object gob, object player) 
{
  
}