#include "/players/anshar/newsage/def.h"

sage_score() {
  int plev, ptox, ptuf, psok;
  int sdel, car, myweight;
  int preg;

  plev = (int)TP->query_level();
  ptox = (int)TP->query_intoxination();
  ptuf = (int)TP->query_stuffed();
  psok = (int)TP->query_soaked();
  sdel = present(GID, TP)->query_spell_delay();
  write((string)TP->short()+"\n");
  write(pad("Level: "+(int)TP->query_level(), 32));
  write("Extra Level: "+(int)TP->query_extra_level()+"\n");
  write(pad("Coins: "+(int)TP->query_money(), 32));
  write("Experience: "+(int)TP->query_exp()+"\n");
  write(pad("Hit Points: "+
    (int)TP->query_hp()+"/"+(int)TP->query_mhp(), 32));
  write("Energy: "+
    (int)TP->query_sp()+"/"+(int)TP->query_msp()+"\n");
  write("Spell Delay: ["+sdel+"]\n");
  write("Quest points: "+(int)TP->query_quest_point()+"\n");
  (int)TP->show_age();
  write("Time (CST): "+ctime(time())+"\n");
  write("Intox ["+(ptox*100)/(plev+3)+"%]   "+
        "Soak ["+(psok*100)/(plev*8)+"%]   "+
      "Stuff ["+(ptuf*100)/(plev*8)+"%]    "+
      "Infuse ["+TP->query_infuse()*100/TP->query_infuse_limit()+"%]\n\n");
  TP->recalc_carry();
  car = (int)TP->query_level();
  car += 6;
  car += (int)TP->query_attrib("str")/5;
  myweight= (int)this_object()->get_my_weight(TP);
  write("Carrying "+myweight*100/car+
  "% of capacity.\n");
  write("\n");
  if((int)TP->query_pregnancy()) {
    preg = (int)TP->query_age() - (int)TP->query_pregnancy();
    write("Pregnant: "+preg*100/16300+"%\n"); 
  }
  return 1;
}

int get_my_weight(object ob) {
  int total;
  object one;
  if(!ob) return 1;
  one = first_inventory(ob);
  while(one) {
    total += (int)one->query_weight();
    one = next_inventory(one); }
  return total;
}

