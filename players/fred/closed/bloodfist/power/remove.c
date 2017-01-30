#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int a,b;
  object *ob;
  string dog;
  if(User->query_ghost()) return 0;
  if(str != "all") return 0;
  ob = all_inventory(User);
  b = sizeof(ob);
  TOU "You remove your worn armor...\n\n");
  for(a = 0; a < b; a++)
  {
    dog = (string)call_other(ob[a], "query_worn");
    if(dog && !ob[a]->id("guild_object"))
    {
      TOU ob[a]->short()+"...\n");
      command("remove "+(string)ob[a]->query_type(), User);
    }
  }
  return 1;
}
