#include "../DEFS.h"

status main(string str)
{
  if (!((status)IPTP->item_corpse()) && !IPTP->guild_wiz()) return 0;
  if ((status)IPTP->query_regen())
  {
    write("You stop the regeneration process.\n");
    IPTP->set_regen(0);
    return 1;
  }
  write("Your molecules recombine and begin regenerating.\n");
  IPTP->set_regen(1);
  return 1;
}


void regenerate(object ob)
{
  int level, value, delay;
  if (!ob) return;
  if (!ob->query_interactive()) return;

  level = (int)IPOB->guild_lev();
  value = (level * 2) / 3;
  /* nanoblood available only to guild leader (highest guild office) */
  if ((status)IPOB->item_nanoblood())  value += 4;
  else if ((status)IPOB->item_blood()) value += 2;

  if ((int)ob->query_sp() < 50)
  {
    tell_object(ob, "You have no more energy to continue regeneration.\n");
    tell_object(ob, "Regeneration terminated...\n");
    IPOB->set_regen(0);
    return;
  }
  if ((int)ob->query_hp() >= (int)ob->query_mhp())
  {
    tell_object(ob, "You have fully regenerated.\n");
    tell_object(ob, "Regeneration terminated...\n");
    IPOB->set_regen(0);
    return;
  }
  tell_object(ob, "Regenerating...\n");
  ob->add_spell_point(-(value));
  if (random(10) >= 9) value = value / 2;  /* 10% chance of half recovery */
  value = (value*80) / 100;  /* ALWAYS lose something in the xfer -Bp */
  ob->add_hit_point(value);
  if ((int)ob->query_hp() >= (int)ob->query_mhp())
  {
    tell_object(ob, "You have fully regenerated.\n");
    tell_object(ob, "Regeneration terminated...\n");
    IPOB->set_regen(0);
    return;
  }
  return;
}
