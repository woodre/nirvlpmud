/*  Emote:  weapon salute     by: Eurale   */

#include "../DEFS.h"


status main(string str)
{
  string wep;
  object ob;

  wep = (string)IPTP->query_weapon();
  if (!wep || wep == "unarmed") wep = "fist";

  if (!str)
  {
    write("You raise your "+wep+" in a formal salute.\n");
    say(TPN+" raises "+TP->POS+" "+wep+" in a formal salute.\n");
  }
  else
  {
    str = lower_case(str);
    ob = find_player(str);
    if (!ob || !present(ob, environment(this_player())))
    {
      write(capitalize(str)+" is not here.\n");
      return 1;
    }
    write("You raise your "+wep+" in a formal salute to "+capitalize(str)+".\n");
    say(TPN+" raises "+TP->POS+" "+wep+" in a formal salute to "+capitalize(str)+".\n");
  }

  return 1;
}
