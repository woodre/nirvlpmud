#include "/players/forbin/define.h"

status main(string str) {
  object who;
  if(!str) 
    return (notify_fail("INV [target]\n"), 0);
    
  who = find_player(str);
  
  if(!who) 
    return (notify_fail(capitalize(str)+" is not online.\n"), 1);

  full_inventory(who, "");
  return 1;
}

void full_inventory(object ob, string indent) {  
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
      full_inventory(inv[x], indent+"  ");
  return;
}