#include "../DEFS.h"


status main(string str)
{
  if (!((status)IPTP->item_corpse()) && !IPTP->guild_wiz()) return 0;
  if ((status)IPTP->query_rejuv())
  {
    write("You stop the rejuvenation process.\n");
    IPTP->set_rejuv(0);
    return 1;
  }
  write("Your molecules burn and begin releasing energy.\n");
  IPTP->set_rejuv(1);
  return 1;
}


void rejuvenate(object ob)
{
  int level, value, delay;
  if (!ob) return;
  if (!ob->query_interactive()) return;

  level = (int)IPOB->guild_lev();
  value = (level * 2) / 3;
  /* nanoblood available only to guild leader (highest guild office) */
  if ((status)IPOB->item_nanoblood())  value += 4;
  else if ((status)IPOB->item_blood()) value += 2;

  if ((int)ob->query_hp() < 50)
  {
    tell_object(ob, "You are too weak to continue rejuvenation.\n");
    tell_object(ob, "Rejuvenation terminated...\n");
    IPOB->set_rejuv(0);
    return;
  }
  if ((int)ob->query_sp() >= (int)ob->query_msp())
  {
    tell_object(ob, "You have fully rejuvenated.\n");
    tell_object(ob, "Rejuvenation terminated...\n");
    IPOB->set_rejuv(0);
    return;
  }
  tell_object(ob, "Rejuvenating...\n");
  ob->add_hit_point(-(value));
  if (random(10) >= 5) value = value / 2;  /* 50% chance of half recovery */
  value = (value*80)/100; /* always loose something -Bp */
  ob->add_spell_point(value);
  if ((int)ob->query_sp() >= (int)ob->query_msp())
  {
    tell_object(ob, "You have fully rejuvenated.\n");
    tell_object(ob, "Rejuvenation terminated...\n");
    IPOB->set_rejuv(0);
    return;
  }
  return;
}
