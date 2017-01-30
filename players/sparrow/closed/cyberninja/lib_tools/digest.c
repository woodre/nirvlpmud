#include "../DEFS.h"

#define USE_DELAY 6

void digestion(object ob);


status main(string str)
{
  if (!((status)IPTP->item_corpse()) && !IPTP->guild_wiz()) return 0;

  if ((status)IPTP->query_digest())
  {
    write("Metabolic amelioration stopped.\n");
    IPTP->set_digest(0);
    return 1;
  }

  write("Metabolic amelioration begun.\n");
  IPTP->set_digest(1);
  call_out("digestion", USE_DELAY, TP);
  return 1;
}


int digestion(object ob)
{
  int INUM, in, st, SNUM, restored;

  if(!ob) return 0;
  if(!ob->query_interactive()) return 0;

  remove_call_out("digestion");

  st = (int)ob->query_stuffed();
  in = (int)ob->query_soaked();
  INUM = (in * 10) / ((int)ob->query_level() * 8);
  SNUM = (st * 10)/((int)ob->query_level() * 8); 
 
  if(!((status)IPOB->query_digest())) return 0;
  if((int)ob->query_spell_point() < 1) return 0;

  tell_object(ob, "Digesting...\n");

  restored = random(3);
  /* nanoblood available only to guild leader (highest guild office) */
  if ((status)IPOB->item_nanoblood())   restored += 2;
  else if ((status)IPOB->item_blood())  restored += random(2);

  if (in > 2)
  {
    ob->add_soaked(-restored);
  }
  if (st > 2)
  {
    ob->add_stuffed(-restored);
  }
  if (!in && !st)
  {
    tell_object(ob,"No matter to metabolize.\n");
    IPOB->set_digest(0);
    return 1;
  }
  ob->add_spell_point(-1);
  call_out("digestion", USE_DELAY, ob);
  return 1;
}
