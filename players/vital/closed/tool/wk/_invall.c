#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

status main(string mode)
{
  object *Users, *Items;
  string *Creators, *Data;
  string Tmp;
  int x, i, y, z;
  Users = users(); Creators = ({ });
  for(x = 0; x < sizeof(Users); x ++)
  {
    Items = deep_inventory(Users[x]);
    if(mode)
    {
      for(y = 0; y < sizeof(Items); y ++)
      {
        string log;
        log = Items[y]->query_short() + "\n\t" + file_name(Items[y]) + "\n";
        write(log);
/*         write("/players/vital/logs/invall.log written.\n"); */
/*         write_file("/players/vital/logs/invall.log",log); */
      }
    }
    for(y = 0; y < sizeof(Items); y ++)
    {
      Tmp = creator(Items[y]);
      if(!Tmp) Tmp = "None";
      else Tmp = capitalize(Tmp);
      if((i = member_array(Tmp, Creators)) == -1)
        Creators += ({ Tmp, 1 });
      else Creators[i + 1] = ((Creators[i + 1]) + 1);
    }
  }
  for(z = 0; z < sizeof(Creators); z +=2)
  {
    write(pad(Creators[z], 15) + " " + Creators[z + 1] + "\n");
  }
  return 1;
}

get_help()
{
  string help;
  help = "Shows how many objects each developer has in the game.";
  return help;
}