/* This is to be inherited by all rooms in my mansion
   Provides services for shielding, etc. */

#include "/players/sado/rooms/mansion.h"

/* Lordy!  A sensible room.c which lets you do stuff */
inherit "/players/sado/rooms/room.c";

init()
{
  object it;
  ::init();
  it = this_player();
  if(!it) return;
  if(!SHIELDS->query_slip_thru(it->query_real_name())) return SHIELDS->toss_em(it);
if(it->query_real_name() == "sado" || it->query_real_name() == "esoterica")
    {
      add_action("shields","shields");
      add_action("sallow","sallow");
      add_action("sdeny","sdeny");
    }
}

static shields(str)
{
  if(!str)
    {
      write("Shield status: " + (SHIELDS->query_shields() ? "ON\n" : "OFF\n"));
      return 1;
    }
  if(str == "on") return SHIELDS->set_shields();
  if(str == "off") return SHIELDS->reset_shields();
  return 0;
}

static sallow(str)
{
  if(SHIELDS->add_sneaky(str)) write("Added to shields exemption list.\n");
  else write("They're already on the list!\n");
  return 1;
}

static sdeny(str)
{
  if(SHIELDS->remove_sneaky(str)) write("Removed from shields exemption list.\n");
  else write("They're not on the list!\n");
  return 1;
}
