#include "/players/snow/dervish/def.h"

dervish_score() {
  int plev, ptox, ptuf, psok;
  int mtox, msoak, mstuff;
  int sdel;
  int preg;

  plev = (int)TP->query_level();
  ptox = (int)TP->query_intoxination();
  ptuf = (int)TP->query_stuffed();
  psok = (int)TP->query_soaked();
  mtox = (int)TP->query_max_intox();
  msoak = (int)TP->query_max_soak();
  mstuff = (int)TP->query_max_stuff();
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
  write("Time (EST): "+ctime(time())+"\n");
  write("Intox ["+(ptox*100)/mtox+"%]   "+
        "Soak ["+(psok*100)/msoak+"%]   "+
      "Stuff ["+(ptuf*100)/mstuff+"%]   "+
      "Infuse ["+TP->query_infuse()*100/TP->query_infuse_limit()+"%]\n\n");
  TP->recalc_carry();
  write("Carrying "+this_player()->query_pct_weight()+"% of capacity.\n");
  write("\n");
  if((int)TP->query_pregnancy()) {
    preg = (int)TP->query_age() - (int)TP->query_pregnancy();
  if(preg > 4000)
    write("Pregnant: "+preg*100/16300+"%\n");
  }
  if(TP->query_level() > 16) {
    write("\nCurrent Area Creator: ");
    if(creator(environment(TP))) write(capitalize(creator(environment(TP))));
    else write("None");
    write(".\n");
  }
  if(TP->query_level() > 50) show_weapons();
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

show_weapons() {
  int gob;
  string fwep, owep;
  gob = present(GID, TP);
  if(gob->query_firstwep()) fwep = gob->query_firstwep()->short();
  if(gob->query_offwep()) owep = gob->query_offwep()->short();
  if(!fwep) fwep = "none or not offwielding";
  if(!owep) owep = "none";
  write("Wielding "+fwep+"\nOffwielding "+owep+"\n");
  return 1; }
