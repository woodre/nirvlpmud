#include "../DEFS.h"


status main(string str)
{
  if (!((status)IPTP->item_convert()) && !IPTP->guild_wiz()) return 0;
  if ((status)IPTP->query_equil())
  {
    write("Bodily equilibration discontinued.\n");
    IPTP->set_equil(0);
    return 1;
  }
  write("Bodily equilibration begun.\n");
  IPTP->set_equil(1);
  return 1;
}


equilibrate(object ob)
{
  int ohp, osp, speed;
  ohp = (int)ob->query_hp();
  osp = (int)ob->query_sp();

  speed = 2;
  /* nanoblood available only to guild leader (highest guild office) */
  if ((status)IPOB->item_nanoblood())   speed = 5;
  else if ((status)IPOB->item_blood())  speed = 3;

  if (osp - ohp <= speed && ohp - osp <= speed)
  {
    write("Body equilibrated. Process stopped.\n");
    IPOB->set_equil(0);
    return 1;
  }
  if (ohp > osp)
  {
    ob->add_hit_point(-speed);
    ob->add_spell_point(speed);
  }
  if (osp > ohp)
  {
    ob->add_hit_point(speed);
    ob->add_spell_point(-speed);
  }
  tell_object(ob, "Equilibrating...\n");
  return 1;
}
