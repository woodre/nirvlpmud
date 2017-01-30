#include "/players/tristian/lib/ClubFeddefine.h"

void
Add_Monster()
{
  if (random(2))
  {
    MOB_DAEMON->create_npc(file_name(this_object()));
  return;
  }
}

  
