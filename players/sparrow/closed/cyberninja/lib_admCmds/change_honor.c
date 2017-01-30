#include "../DEFS.h"
#include DEFS_HLEVELS


status main(string str)
{
  object ob;
  string who, new_honor_name;
  int amount, current_honor, maxHonor;

  if (!IPTP->guild_manager()) return 0;

  if (!str || !sscanf(str, "%s %d", who, amount) || 
     !find_player(who) || 
     !present(GUILD_ID, find_player(who)))
  {
    write("Usage: change_honor <ninja> <amount>.\n");
    return 1;
  }

  ob = present(GUILD_ID, find_player(who));

  if (amount == 0)
  {
    write("You must specify a non-zero amount.\n");
    return 1;
  }

  if (amount > HONOR_LEVEL_MAX)
  {
    write("Maxmimum honor is " + HONOR_LEVEL_MAX + ".\n");
    return 1;
  }

  maxHonor = HONOR_LEVEL_MD7;
  if (amount > maxHonor && find_player(who)->query_level() >= 21)
  {
    write("\nPROBLEM!!! You are granting a wizard very high honor.\n"+
          "Only Tier 1 & 2 guild wizards may have honor set this high.\n"+
          "Please reset "+capitalize(who)+"'s honor to "+maxHonor+".\n\n");
  }

  new_honor_name = (string)call_other(HLEVELD, "honor_title", amount);
  current_honor  = (int)ob->query_honor();
  write("You change "+capitalize(who)+"'s honor from "+current_honor+
        " to "+amount+"\n");

  if((string)call_other(HLEVELD, "honor_title", current_honor) != new_honor_name) 
    tell_object(environment(ob), 
      "Your honor has been changed to "+new_honor_name+" by "+TPN+".\n");
  else
    tell_object(environment(ob), 
      "Your honor has been slightly adjusted by "+TPN+".\n");

  write_file(LOGDIR + "/HONOR",
    TPN+" set "+capitalize(who)+"'s honor from "+
    current_honor+" to "+amount+". ("+ctime()+")\n");

  ob->set_honor(amount);
  ob->save_me();
  move_object(ob, find_player(who)); /* force init */
  return 1;
}
