#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User) {
  int plev, ptox, ptuf, psok;
  int mtox, msoak, mstuff;
  int sdel;
  int preg;

  plev = (int)User->query_level();
  ptox = (int)User->query_intoxination();
  ptuf = (int)User->query_stuffed();
  psok = (int)User->query_soaked();
  mtox = (int)User->query_max_intox();
  msoak = (int)User->query_max_soak();
  mstuff = (int)User->query_max_stuff();
  sdel = (int)PO->query_spell_delay();
  write((string)User->short()+"\n");
  write(pad("Level: "+(int)User->query_level(), 32));
  write("Extra Level: "+(int)User->query_extra_level()+"\n");
  write(pad("Coins: "+(int)User->query_money(), 32));
  write("Experience: "+(int)User->query_exp()+"\n");
  write(pad("Hit Points: "+
    (int)User->query_hp()+"/"+(int)User->query_mhp(), 32));
  write("Energy: "+
    (int)User->query_sp()+"/"+(int)User->query_msp()+"\n");
  write("Spell Delay: ["+sdel+"]\n");
  write("Quest points: "+(int)User->query_quest_point()+"\n");
  (int)User->show_age();
  write("Time (EST): "+ctime(time())+"\n");
  write("Intox ["+(ptox*100)/mtox+"%]   "+
        "Soak ["+(psok*100)/msoak+"%]   "+
      "Stuff ["+(ptuf*100)/mstuff+"%]   "+
      "Infuse ["+(((int)User->query_infuse()*100)/((int)User->query_infuse_limit()))+"%]\n\n");
  TP->recalc_carry();
  write("Carrying "+User->query_pct_weight()+"% of capacity.\n");
  write("\n");
  if((int)User->query_pregnancy()) {
    preg = (int)User->query_age() - (int)User->query_pregnancy();
  if(preg > 4000)
    write("Pregnant: "+preg*100/16300+"%\n");
  }
  if(User->query_level() > 16) {
    write("\nCurrent Area Creator: ");
    if(creator(environment(User))) write(capitalize(creator(environment(User))));
    else write("None");
    write(".\n");
  }
  return 1;
}