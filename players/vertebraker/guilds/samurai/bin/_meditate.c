#include "../def.h"
cmd_meditate()
{
  object gob;
  gob = previous_object();
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 2) {
    write("You must master your current skills first.\n");
    return 1;
  }
  if(TP->query_attack())
  {
    write("You must first clear your mind.\n");
    return 1;
  }
  if(gob->query_meditate())
  {
    write("You are already meditating.\n");
    return 1;
  }
  write("You sit down and begin to meditate.\n");
  say(TP->QN+" sits down and begins to meditate.\n");
  gob->set_meditate(ENV(TP));
  return 1;
}
