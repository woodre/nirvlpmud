#include "../DEFS.h"


status main(string str)
{
  int hps, sps;
   string name, loc, mon;
  int b, mod, mstatus;
  object * ob;
  object gob, mob;

if (!IPTP->guild_manager()) return 0;

  ob = users();
  for (b=0; b<sizeof(ob); b+=1)
  {
    gob = present(AFFILIATE, ob[b]);
    if (!((int)ob[b]->query_invis() > TP->query_level()))
    {
      if (gob)
      {
        name = (string)ob[b]->query_real_name();
        loc  = creator(environment(ob[b]));
        hps = (int)ob[b]->query_hp();
        sps = (int)ob[b]->query_sp();
        mon = "none";
        mob = (object)ob[b]->query_attack();
        if (mob)
        {
          mon = (string)ob[b]->query_attack()->query_real_name();
          mstatus = ((int)mob->query_hp() * 10) / ((int)mob->query_mhp());
          mon += " "+mstatus;
          mon += "0%";
        }
        mod = (int)gob->query_attack_mode();
        write(capitalize(name)+" | "+loc+" | "+mon+"\n"+
          "->"+hps+"/"+(int)ob[b]->query_mhp()+" | "+
        sps+"/"+(int)ob[b]->query_msp()+" | ");
        if (mod == 1) write(upper_case(ATTACK_MODE1)+"\n\n");
        if (mod == 2) write(upper_case(ATTACK_MODE2)+"\n\n");
        if (!mod) write(upper_case(ATTACK_MODE0)+"\n\n");
      }
    }
  }
  write(LINE);
  return 1;
}
