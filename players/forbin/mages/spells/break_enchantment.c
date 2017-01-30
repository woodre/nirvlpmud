#include "../def.h"

string s_spell_name()     { return "break enchantment"; }
string s_proper_name()    { return "Break Enchantment"; }
   int s_spell_level()    { return 3; } 
string s_spell_school()   { return "abju"; }
string s_primary_stat()   { return "intelligence"; }
string s_secondary_stat() { return "will power"; }

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