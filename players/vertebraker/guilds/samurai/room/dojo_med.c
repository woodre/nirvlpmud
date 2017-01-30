#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Meditation Room");
  set_long("\
Dojo - Meditation Room\n\
An aura of serenity surrounds this place.\n\
On the ground you see several meditation mats, unfurled and resting.\n\
Several large candles surround a Laughing Buddha in the center of\n\
the room. A small bonsai plant grows alongside the northern wall.\n\
From here, you can \"fargaze\" on other players.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_shomen","south",
  });
  call_out("heal_em", 2);
}

heal_em()
{
  object *inv;
  int    x;
  x = sizeof(inv = all_inventory(this_object()));
  
  while(x--)
  {
    if(!random(20))
    {
      tell_object(inv[x],"You feel at peace.\n");
    }
    inv[x]->heal_self(10+random(10));
  }
  call_out("heal_em", 2);
}

init()
{
  ::init();
  add_action("cmd_fargaze","fargaze");
}

cmd_fargaze(str)
{
  object ob, *obs;
  int   x, y;
  
  if(!str){
    write("fargaze on whom?\n");
    return 1;
  }
  
  ob = find_player(str);
  
  if(!ob || ob->query_level() >= 21) {
    write("Not logged on!\n");
    return 1;
  }   
  
  write("\n\t"+capitalize(str)+"\n\n");
  write("Equipment:\n");
  y = sizeof(obs = all_inventory(ob));
  for(x = 0; x < y; x ++)
  {
    string sh;
    if(sh = obs[x]->short())
      write(sh+".\n");
  }
  write("\n");
  write("Environment: "+environment(ob)->short()+"\n");
  return 1;
}