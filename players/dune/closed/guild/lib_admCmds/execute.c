#include "../DEFS.h"


status main(string str)
{
  string file, name;
  int guild_xp, guild_rank, real_exp;
  object corpse, ob;

  if (!IPTP->guild_manager()) return 0;

  if (!str)
  {
    write("Execute who?\n");
    write("Note: This is to be done in only drastic circumstances.\n");
    write("Use the 'suspend' command for lighter situations.\n");
    return 1;
  }
  if (!find_player(str) || !present(GUILD_ID, find_player(str)))
  {
    write("User "+capitalize(str)+" is not valid.\n");
    return 1;
  }
  ob = find_player(str);
  if (!call_other(MEMBERD, "leave_ninjas", ob))
  {
    write("Error, you were not able to execute "+capitalize(str)+"\n");
    return 1;
  }
  name = OPN;
  tell_room(environment(ob), 
    name+"'s cyberlinks are disconnected.\n"+
    name+"'s implants are removed, painfully.\n"+
    name+" is forced to kneel upon a small platform.\n"+
    "With one quick swing, "+TPN+" chops "+name+"'s head clean off.\n");
  call_other(CHANNELD, "overchannel", name+
    " has been banished with great dishonor from the guild.\n");
  write_file(LOGDIR + "/EXECUTE", capitalize(str)+
    " was executed by "+TRN+". (" + ctime() + "\n");
  return 1;
}
