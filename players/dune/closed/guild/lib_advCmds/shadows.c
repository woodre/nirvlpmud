#include "../DEFS.h"
#define LEVEL         8
#define DRAIN_PEACE  40
#define DRAIN_COMBAT 70


status main(string str)
{
  /* command to hide in shadows */
  object ob;
  if (!gotrank(TP, LEVEL)) return 0;

  if (TP->query_invis() && IPTP->query_shadows())
  {
    write("You are already hiding in shadows.\n");
    return 1;
  }
  if (TP->query_attack())
  {
    write("You cannot hide while fighting.\n");
    return 1;
  } 
  if (!gotsp(TP, 40)) return 1;
  TP->add_spell_point(-40);
  TP->set_invs_sp();
  IPTP->set_shadows(1);
  IPTP->save_me();
  say(TPN + " disappears into the shadows.\n");
  write("You hide in shadows.\n");
  return 1;
}
