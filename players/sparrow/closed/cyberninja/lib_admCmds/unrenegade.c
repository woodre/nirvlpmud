#include "../DEFS.h"


status main(string str)
{
/* Process for becoming a CyberNinja Renegade */
  object ob;
  string name, capName, option;
  string *strToks;

  if (!call_other(OFFICED,"checkStone", TP, "diamond sapphire"))
    return 0;

  if (!str)
  {
    write("Usage: unrenegade <ninja> [commit].\n");
    return 1; 
  }

  strToks = explode(str, " ");
  if (sizeof(strToks) >= 2)
  {
    name = strToks[0];
    option = strToks[1];
  }
  else
  {
    name = str;
    option = 0;
  }

  capName = capitalize(name);

  if (!find_player(name) || !present(GUILD_ID, find_player(name)))
  {
    write("User " + capName + " is not valid.\n");
    return 1;
  }

  ob = find_player(name);

  write("Current mode for " + capName + ": "+BOLD);
  if ((int)IPOB->query_nohonor() == 0) write("HONORABLE");
  if ((int)IPOB->query_nohonor() == 1) write("RENEGADE");
  write(OFF+"\n");

  if (option && option == "commit")
  {
    if (!IPOB->query_nohonor())
    {
      write(capName + " already follows the Path.\n");
      return 1;
    }
    IPOB->remove_nohonor();
    IPOB->set_honor(0);
    IPOB->save_me();
    write(BOLD + "\n" + capName + " returns to the Path of Honor.\n\n" + OFF);
    call_other(CHANNELD, "overchannel", capName + " has returned to the Path!\n");
    return 1;
  }

  return 1;
}
