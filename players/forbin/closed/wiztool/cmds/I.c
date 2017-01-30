/*
// Modeled after fakir's inv tool
*/

#include "/players/forbin/define.h"

status main(string arg) {
  string flag, temp;
  object who;
  if(!arg) 
    return (notify_fail("I [target]\n"), 0);

  if(sscanf(arg, "-%s %s", flag, temp)) {
    if(!temp)
      return (notify_fail("I -flag [target]\n"), 0);
    else
      str = temp;  
  }    
  else
    str = arg;
            
  who = find_player(str);
  
  if(!who) 
    return (notify_fail(capitalize(str)+" is not online.\n"), 1);
  switch(flag) {
    case "s" : 
    case "S" :
    case "short" :
    case "Short" :
      short_inv(who, ""); break;
    case "l" : 
    case "L" :
    case "long" :
    case "Long" :
      long_inv(who, ""); break;      
    default : 
      short_inv(who, ""); break;
  }
  return 1;
}

void long_inv(object ob, string indent) {  
  object *inv;
  int size, x;
  string sh;
  if(!indent) indent = "";
  inv = all_inventory(ob);
  size = sizeof(inv);
  sh = (string)ob->short();
  write(indent+(sh ? sh : WTC+"i]")+NORM+" ["+file_name(ob)+"]\n");
  if(!size)
    return;
  else
    for(x = 0; x < size; x++)
      long_inv(inv[x], indent+"  ");
  return;
}

void short_inv(object ob, string indent) {
  string sh, fn, trash;
  object *inv;  
  mapping things;
  
  inv = deep_inventory(ob);
  size = sizeof(inv);
  
  things = ([ ]);
  for(x = 0; x < size; x++) {
    sscanf(file_name(inv[x]), "%s#%s", fn, trash);
    sh = (string)inv[x]->short();
    if(!sh) {
      things[fn] 
    }
    else {
      things[sh] ++;
      bling ++;
    }
  }


  
  
  
}