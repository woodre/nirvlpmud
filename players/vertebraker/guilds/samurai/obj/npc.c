#include "../def.h"

inherit "/players/vertebraker/closed/std/monster";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("samurai");
  set_short("A disciplined samurai");
  set_alias("disciplined samurai");
  set_long("\
A Japanese man standing about 5'9\" with a short black beard\n\
and hair wrapped up in a ponytail. He stares at you as you\n\
approach him.\n\
You can \"list\" or \"buy\" from him.\n");
  set_hp(1000);
  {
   object obj;

   obj = clone_object("/players/vertebraker/guilds/samurai/gob");
   move_object(obj, this_object());
   obj = clone_object("/players/mythos/awep/katana");
   move_object(obj, this_object());
   obj = clone_object("/players/mythos/awep/wakizashi");
   move_object(obj, this_object());
   command("wield katana", this_object());
   command("offwield wakizashi", this_object());
  }
  set_wc(50);
  set_ac(20);
}

query_attrib()
{
  return 30;
}

init()
{
    add_action("cmd_buy","buy");
    add_action("cmd_buy","purchase");
    add_action("cmd_list","list");
}

cmd_list()
{
  write("\n\n");
  write("\tSake\n");
  write("\tGreen tea\n");
  write("\tRice\n");
  write("\n");
  write("\tAll items are 1,800 coins.\n");
  write("\n");
  return 1;
}

cmd_buy(str)
{
  object obj;
  if(TP->query_money() < 1800)
  {
    write("You don't have enough money.\n");
    return 1;
  }
  if(str =="rice")
  {
    obj = clone_object(OBJDIR+"rice");
  }
  else if(str=="sake")
  {
    obj = clone_object(OBJDIR+"sake");
  }
  else if(str=="tea"||str=="green tea")
  {
    obj = clone_object(OBJDIR+"tea");
  }
  else
  {
    write("The samurai shakes his head at you.\n");
    return 1;
  }
  if(!TP->add_weight(1))
  {
    write("You can't carry any more heals.\n");
    return 1;
  }
  move_object(obj, TP);
  
  TP->add_money(-1800);
  write("Ok.\n");
  say(TP->QN+" purchases \""+str+"\" from the samurai.\n");
  return 1;
}