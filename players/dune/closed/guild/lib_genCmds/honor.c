#include "../DEFS.h"
#include DEFS_HLEVELS


status main(string str)
{
/* Used to give honor points to a player */
  int new_honor;
  string who, amount, reason, honors, action, pre;
  string *honor_array;
  object ob;

  if (IPTP->query_nohonor())
  {
    write("As a Renegade, you cannot honor or dishonor.\n");
    return 1;
  }

  honors = (string)call_other(HLEVELD, "findRangeNames", TP);
  if (!honors) return 0;
  if (!str)
  {
    write("Usage: honor [award/punish] <member> <amount> <reason>.\n");
    write("Your honor range is:\n\t"+honors+"\n");
    return 1;
  }
  if (sscanf(str, "%s %s %s %s", action, who, amount, reason) != 4)
  {
    write("Usage: honor [award/punish] <member> <amount> <reason>.\n");
    write("Your honor range is:\n\t"+honors+"\n");
    return 1;
  }
  if (!(action == "award" || action == "punish"))
  {
    write("Either award or punish with honor.\n");
    return 1;
  }
  pre = "";
  if (action == "punish") pre = "dis";
  if (reason == "")
  {
    write("You must also state a reason.\n");
    return 1;
  }

  ob = find_player(who);
  if (!ob || !present(GUILD_ID, ob))
  {
    write("No ninja named "+who+" is logged on.\n");
    return 1;
  }

  if ((int)TP->query_level() < 20                      && 
      capitalize((string)ob->query_real_name()) == TRN &&
      action == "award")
  {
    write("You cannot honor yourself.\n");
    return 1;
  }

/* added by wocket */
  honor_array = explode(honors,", ");
  if (member_array(amount,honor_array) == -1)
  {
    write("You cannot honor outside of your range.\n"+
          "Seek a higher ninja to approve your honor request.\n");
    write("Your honor range is:\n\t"+honors+"\n");
    return 1;
  }
/* end addition */

  if (!((int)call_other(HLEVELD, "get_points", amount)))
  {
    write("You have entered an invalid amount.\n");
    write("Your range of honoring is:\n\t"+honors+"\n");
    return 1;
  }

  new_honor = (int)call_other(HLEVELD, "get_points", amount);
  write_file(LOGDIR + "/HONOR", 
    TRN+" "+pre+"honored "+ORN+" in a "+amount+
    " manner. Reason: "+reason+". ("+ctime()+")\n");
  write("You "+pre+"honor "+OPN+" in a "+amount+" manner.\n");
  tell_object(ob, "You have been "+pre+"honored in a "+amount+
    " manner by "+TPN+".\n");
  call_other(CHANNELD, "overchannel", 
    OPN+" has been "+pre+"honored in a "+amount+" manner by "+TPN+"!\n"+
    RED+"("+OFF+BOLD+"Justification"+OFF+RED+")"+OFF+" "+reason+".\n");
  if (action == "award") IPOB->add_honor(new_honor);
  else                   IPOB->add_honor(-new_honor);
  IPOB->save_me();
  move_object(IPOB, ob); /* force init */
  return 1;
}
