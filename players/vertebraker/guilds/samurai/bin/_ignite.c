#include "../def.h"

cmd_ignite(str)
{
  object head;
  string ql;
  if(TP->query_guild_rank() < 1) return 0;

  if(str != "head")
  {
    notify_fail("You can only ignite a head.\n");
    return 0;
  }
  if(!(head = present("head", TP))){
    notify_fail("You don't have a head to ignite.\n");
    return 0;
  }
  if(query_attribute("lit", head))
  {
    notify_fail(head->short()+" is already on fire.\n");
    return 0;
  }
  write("You call forth a mighty "+HIY+"lightning bolt"+NORM+".\n");
  say(TP->QN+" calls forth a mighty "+HIY+"lightning bolt"+NORM+".\n");
  
  emit_channel("junk", "(junk) You see "+HIY+"lightning"+NORM+" strike in the distance.\n");
  write("You set "+head->short()+" "+HIR+"AFLAME"+NORM+"!\n");
  say(TP->QN+" sets "+head->short()+" "+HIR+"AFLAME"+NORM+"!\n");
  ql = head->query_long();
  add_attribute("lit", head);
  head->set_short(head->query_short() + " "+HIY+"[blazing]"+NORM);
  head->set_long(ql + RED+"It is on fire.\n"+NORM);
  head->set_my_light(0);
  head->set_my_light(3);
  head->set_save_flag(1);
  return 1;
}
