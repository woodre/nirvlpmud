#include "../def.h"

string s_spell_name()     { return "faerie fire"; }
string s_proper_name()    { return "Faerie Fire"; }
   int s_spell_level()    { return 1; } 
string s_spell_school()   { return "evoc"; }
string s_primary_stat()   { return "will power"; }
string s_secondary_stat() { return "power"; }

/* info() is used by guild NPC to inform player about spell */
status info(object gob, object player) 
{
  tell_object(player,"\n"+
    SHORTLINE+"\n"+NORM+                            
    "                  "+HIW+"Faerie Fire"+NORM+"                   \n"+
    SHORTLINE+"\n\n"+
    "         Using this spell, a Mage can call forth\n"+
    "     a minor aura that will surround a target,\n"+
    "     causing them to glow, and thereby making\n"+
    "     them much easier to hit.\n\n"+
    SHORTLINE+"\n");
}

/* help() is called from mhelp and is the help information about spell */
status help(object gob, object player) 
{
  tell_object(player,"\n"+
    SHORTLINE+"\n"+LOGO+                            
    "                  Faerie Fire                   \n"+
    LOGO+SHORTLINE+"\n"+
    "     School: Evocation\n"+
    "     Level:  One\n"+
    "     Cost:   Medium\n\n"+
    "         With this spell, you can summon a dim\n"+
    "     glow to surround your current or a potential\n"+
    "     target, causing them to give off a pale light\n"+
    "     similar in strength to candlelight.  This\n"+
    "     lighted aura will make your target much, much\n"+
    "     easier to hit.\n"+
    SHORTLINE+"\n");  
}

/* main is called from cast.c command and is the bulk of the spell */
status main(string str, object gob, object player) 
{
  
}