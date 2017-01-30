#include "../def.h"
cmd_leave_guild()
{
  object gob;
  gob = previous_object();
  write("\n\tYou leave the guild.\n\n");
  command("seppuku", TP);
  TP->set_guild_name(0);
  TP->set_home("/room/vill_green");
  TP->set_guild_rank(0);
  TP->set_guild_file(0); /* 10/23/07 Earwax */
  command("id :has left the guild.", TP);
  destruct(gob);
  /*
  move_object(clone_object(OBJDIR+"mark"), TP);
  */
  return 1;
}
