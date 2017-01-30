#include "../defs.h"

string space_to_under(string str)
{
  return implode(explode(lower_case(str), " "),"_");
}

varargs status main(string str, object gob, object player) 
{
	string arg;
  string spellname;
  object spellcode;
  
  if(!str) 
    return (notify_fail("\nProper syntax: 'cast <spell> at/on/upon <target>'\n"+
                        "               'cast <spell>'\n"), 0);
   
   str = lower_case(str);
                        
  if(sscanf(str, "%s at %s", spellname, arg) != 2 &&
     sscanf(str, "%s on %s", spellname, arg) != 2 &&
     sscanf(str, "%s upon %s" ,spellname, arg) != 2)
  {
    spellname = str;
    sscanf(spellname, "%s at", spellname); 
    sscanf(spellname, "%s on", spellname);
    sscanf(spellname, "%s upon", spellname);
  }    
    
  if(spellname == "spell") 
    return (notify_fail("What spell would you like to cast?\n"), 0);
  
  if(file_size((spellcode = SPELLS+space_to_under(spellname)+".c")) > -1)      
  {
    if(arg)
       spellcode->main(arg, gob, player); 
    else
      spellcode->main(0, gob, player);
    return 1;
  }
  else 
    return (notify_fail("You know of no such spell named \""+
            capitalize(spellname)+"\".\n"), 0);
}