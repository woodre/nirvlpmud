#include "../DEFS.h"


status main(string str)
{
  int guild_xp, guild_rank, real_exp;
  object corpse, ob;

  if (!call_other(OFFICED, "checkStone", TP, "diamond sapphire")) return 0;

  if (!str || !find_player(str) ||
     !present(GUILD_ID, find_player(str)))
  {
    write("Suspend which guild member?\n");
    return 1;
  }

  ob = find_player(str);
  IPOB->set_suspended(1);

  ob->set_title("is suspended from the guild");
  tell_object(ob, "You have been suspended from the guild.\n");
  call_other(CHANNELD, "overchannel", 
OPN+" has been suspended from the guild by "+TPN+".\n");
  write_file(LOGDIR + "/SUSPEND",
    capitalize(str)+" was suspended by "+TRN+". ("+ctime()+")\n");
  IPOB->save_me();
  move_object(IPOB, ob); /* force init */
  return 1;
}
