int cast(string str) {
  string spellname;
  object spellcode;
  if(!str) 
    return (notify_fail("Proper syntax: 'cast <spell> at/on/upon <target>'\n"), 0);
  if(sscanf(str, "%s at %s", spellname, arg) != 2)
    if(sscanf(str, "%s on %s", spellname, arg) != 2)
      if(sscanf(str, "%s upon %s" ,spellname, arg) != 2) 
        spellname = str;
  if(spellname == "spell") 
    return (notify_fail("What spell would you like to cast?\n"), 0);
  spellcode = "/players/forbin/closed/mages/cmds/spell_"+
    implode(explode(spellname, " "), "_")+".c";
  if(arg)
    spellcode->cast(arg, this_object(), this_player());  
  else
    spellcode->cast("", this_object(), this_player());  
    
}



    
