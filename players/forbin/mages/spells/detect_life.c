#include "../def.h"

string s_spell_name()     { return "detect life"; }
string s_proper_name()    { return "Detect Life"; }
   int s_spell_level()    { return 6; } 
string s_spell_school()   { return "divi"; }
string s_primary_stat()   { return "wisdom"; }
string s_secondary_stat() { return "intelligence"; }

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