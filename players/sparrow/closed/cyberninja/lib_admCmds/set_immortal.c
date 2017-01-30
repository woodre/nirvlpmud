#include "../DEFS.h"


status main(string str)
{
  string who, what, sphere;
  object ob;
  
  if (!IPTP->guild_manager()) return 0;

  if (!str || 
      !sscanf(str, "%s %s", who, what) ||
      !find_player(who) || 
      !present(GUILD_ID, find_player(who)))
  {
    write("Usage: set_immortal <wizard> <sphere>\n"+
          "   Where type is:\n");
    call_other(OFFICED, "listSpheres");
    return 1;
  }

  ob = find_player(who);

  sphere = ((string)call_other(OFFICED, "findSphere", ob, what));
  if (!sphere)
  {
    write("Usage: set_immortal <wizard> <sphere>\n"+
          "   Where type is:\n");
    call_other(OFFICED, "listSpheres");
    return 1; 
  }
  
  IPOB->set_sphere(what);
  IPOB->set_stone("adamantium");
  IPOB->save_me();

  call_other(OFFICED, "set_officers_updated", 0);

  write_file(LOGDIR + "/SET_IMMORTAL",
    ORN+" was set to " + what + " by "+TRN+". ("+ctime()+")\n");

  write("\nYou set " + OPN + "'s sphere to " + capitalize(what) + ".\n");
  write("You may view the guild 'ladder' to verify your changes.\n");

  write("Done.\n\n");

  return 1;
}