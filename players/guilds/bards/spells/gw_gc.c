#include "/players/guilds/bards/def.h"

status main(string str) {
  object peep;
  object gpp;
  if(!str)
    FAIL("Make who a gc?\n");
  peep = present(str, environment(TP));
  if(!peep)
    FAIL("Your choice for GC is not here.\n");
  gpp = present("bard_obj", peep);
  if(!gpp)
    FAIL("They are not a bard.\n");
  gpp->set_is_gc(1);
  write("You have made "+str+" a GC.\n");
  tell_object(peep,
  "Congratulations! You are now a Guild Commander for the Bards!\n"
  +"clean_instrument to gain your new powers.\n");
  CHANNEL->guild_broadcast( NAME(peep)+" is now a Guild Commander!\n",1 );
  return 1;
}

