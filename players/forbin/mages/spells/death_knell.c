#include "../def.h"

string s_spell_name()     { return "death knell"; }
string s_proper_name()    { return "Death Knell"; }
   int s_spell_level()    { return 1; } 
string s_spell_school()   { return "necr"; }
string s_primary_stat()   { return "wisdom"; }
string s_secondary_stat() { return "power"; }

/* info() is used by guild NPC to inform player about spell */
status info(object gob, object player) 
{
  tell_object(player,"\n"+
  ""+SGC+"["+PGC+"*"+SGC+"]"+PGC+
  "======================================="+
  SGC+"["+PGC+"*"+SGC+"]"+PGC+"\n"+
  TGC+"                 Death Knell                 \n"+           
  ""+SGC+"["+PGC+"*"+SGC+"]"+PGC+
  "======================================="+
  SGC+"["+PGC+"*"+SGC+"]"+QGC+"\n"+
  "     With the use of a soulcatcher as the\n"+
  "   focusing object, a Mage is able to\n"+
  "   capture the energy from the soul of a\n"+
  "   creature near death, instantly killing\n"+
  "   the target and harnessing the enery for\n"+
  "   future use.\n"+
  ""+SGC+"["+PGC+"*"+SGC+"]"+PGC+
  "======================================="+
  SGC+"["+PGC+"*"+SGC+"]"+QGC+"\n");
  return 1;     
}

/* help() is called from mhelp and is the help information about spell */
status help(object gob, object player) 
{
  
}

/* main is called from cast.c command and is the bulk of the spell */
status main(string str, object gob, object player) 
{
  
}