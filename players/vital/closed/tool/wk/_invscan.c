#include <ansi.h>

main(str)
{
  int i, x, y;
  object ob;
  object *ob2;
  if(!str) return write(get_help() + "\n");
  i = 0;
  ob = find_player(str);
  if(!ob) { write("That player does not exist\n"); return 1; }
  write("Playername: "+str+"\tLevel: "+ob->query_level()+"\n");        
  write("--------------------------------------\n");
  ob2 = deep_inventory(ob);
  y = sizeof(ob2);
  for(x = 0; x < y; x++)
  {
    write("Item: "+ob2[x]->short()+"\n");
    write(pad("(wc): "+ob2[x]->query_wc(), 10));
    write(pad("(ac): "+ob2[x]->query_ac(), 10));
    write("Valu: "+ob2[x]->query_value()+"\n");
    write("----------------------------------------------------\n");  
    i++;
  }
  write("Done. Number of items: "+i+"\n");
  return 1;
}

get_help()
{
  string help;
  help = "Scan a player's inventory";
  return help;
}
