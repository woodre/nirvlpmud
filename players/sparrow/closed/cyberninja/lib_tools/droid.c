#include "../DEFS.h"
#include DEFS_ENHANCEMENTS

status main(string str) {
  /* droid is not a pet, just a moving 'bag'... enhancement */
  object obdroid;

  if(!((status)IPTP->item_activate_droid()) && !IPTP->guild_wiz()) 
    return 0;
  if(!gotsp(TP, ENERGY_DROID)) return 1;
  write("This command removed due to regulations. - Snow\n");
  return 1;
  obdroid = clone_object(OBJDIR + "/droid.c");
  if(find_object((string)TP->query_real_name()+"droid")) {
    write("You already have a droid.\n");
    return 1; }
  TP->add_spell_point(-ENERGY_DROID);
  move_object(obdroid, environment(TP));
  obdroid->set_follname((string)TP->query_real_name());
  obdroid->set_droidid((string)TP->query_real_name()+"droid");
  write("Your droid's lights turn on.  It is active now.\n");
  say(TPN+" turns on "+TP->POS+" droid.\n");
  command("droidlink",TP);
  return 1;
}
