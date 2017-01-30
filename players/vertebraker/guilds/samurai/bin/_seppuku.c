#include "../def.h"
cmd_seppuku()
{
  object gob;
  gob = previous_object();
  write("You commit Seppuku.\n");
  this_player()->death("Seppuku - by "+possessive(TP)+" own hand");;
  command("id :commits Seppuku!", TP);
  if(TP->query_guild_rank() >= 1) {
    TP->add_guild_rank(-1);
  }
  gob->set_frozen(0);
  gob->add_shame(-(gob->query_shame()));
  return 1;
}
