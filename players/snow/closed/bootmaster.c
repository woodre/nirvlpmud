#define TP this_player()
#define TO this_object()
#define TPL TP->query_level()
#define TPN TP->query_name()
#define PRE present
#define CAP capitalize
#define GEN TP->query_possessive()
#define TPI TP->query_intoxination()
#define TPS TP->query_stuffed()
#define TPHP TP->query_hp()
#define TPSP TP->query_sp()
#define TPMHP TP->query_mhp()
#define TPMSP TP->query_msp()
#define BOOTS PRE("boots of the wanderer",TP)
#define MEAT TP->query_attack()
 
pub_commands(arg) {
  if(!arg) { pub_list(); return 1; }
  if(arg == "beer") { pub_beer(); return 1; }
}
 
wander_commands(arg) {
  if(!arg) { wander_list(); return 1; }
  if(!query_guild(TP)) {
    if(arg == "heal") { wander_heal(); return 1; }
    if(arg == "who") { wander_who(); return 1; }
    if(arg == "mon") { wander_toggle(); return 1; }
  }
}
 
wander_heal() {
  int hpnum, spnum, dam, mag;
  dam = (TPHP * 100) / TPMHP;
  mag = (TPSP * 100) / TPMSP;
  hpnum = 20;
  spnum = 20;
  if(MEAT) {
    if(TPMHP > 200) {
      if(dam < 20) hpnum = 100;
      if(dam > 19 && dam < 50) hpnum = 50;
      if(dam > 90) hpnum = 10;
    }
    spnum = (hpnum * 5) / 4;
    if(spnum > TPSP) { hpnum = TPSP; spnum = TPSP; }
    TP->add_spell_point(-spnum);
    TP->add_hit_point(hpnum);
    write("Wander battle heal applied.\n");
    return 1;
  }
  TP->add_spell_point(-spnum);
  TP->add_hit_point(hpnum);
  write("Wander heal applied.\n");
  return 1;
} 
 
wander_toggle() {
  if(BOOTS->query_mon()) {
    BOOTS->set_mon(0);
    write("Wander monitor toggled off.\n");
    return 1;
  }
  BOOTS->set_mon(1);
  BOOTS->fake_beat();
  write("Wander monitor toggled on.\n");
  return 1;
}
  
wander_mon(object ob) {
  int hp, sp, mhp, msp, in, min, st, mst;
  hp = ob->query_hp();
  mhp = ob->query_mhp();
  sp = ob->query_sp();
  msp = ob->query_msp();
  in = ob->query_intoxination();
  min = ob->query_level() + 8;
  st = ob->query_stuffed();
  mst = ob->query_level() * 8;
  tell_object(ob,"...HP: "+hp+"/"+mhp);
  tell_object(ob,"...SP: "+sp+"/"+msp);
  if(!ob->query_attack()) {
    tell_object(ob,"...DRUNK: "+(in * 100)/min+"%");
    tell_object(ob,"...FULL: "+(st * 100)/mst+"%");
  }
  tell_object(ob,"\n");
  return 1;
}

query_guild(object ob) {
  if(ob->query_guild_name() || ob->query_guild_file() ) return 0;
  return 1;
}
