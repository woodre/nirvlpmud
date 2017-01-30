#include "../def.h"

string main(string str, object gob, object player) 
{
	string arg;
  string spellname;
  object spellcode;
  
  if(!str) 
    return (notify_fail("\nProper syntax: 'cast <spell> at/on/upon <target>'\n"+
                        "               'cast <spell>'"), 0);
                        
  if(sscanf(str, "%s at %s", spellname, arg) != 2 &&
     sscanf(str, "%s on %s", spellname, arg) != 2 &&
     sscanf(str, "%s upon %s" ,spellname, arg) != 2)
    spellname = lower_case(str);
    
  if(spellname == "spell") 
    return (notify_fail("What spell would you like to cast?\n"), 0);
    
  spellcode = SPELLS+implode(explode(spellname, " "), "_")+".c";
    
  if(arg)
    spellcode->cast(arg, this_object(), this_player()); 
     
  else
    spellcode->cast("", this_object(), this_player());
  
  if(!spellcode)
    return "Command Failed.";    
    
  return "";
    
}