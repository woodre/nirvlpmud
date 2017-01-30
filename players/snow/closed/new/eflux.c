#include "../DEFS.h"
#include DEFS_ENHANCEMENTS

status main(string who) {
  /* concentrated dmg enhancement */
  object ob;
  int dmg;

  if(!((status)IPTP->item_electricflux()) && !IPTP->guild_wiz()) 
    return 0;
  if(!gotsp(TP, ENERGY_EFLUX)) return 1;
  if(!who) {
    if(!TP->query_attack()) {
      write("Usage: eflux <target>\n"); 
      return 1; }
    else ob = (object)TP->query_attack(); 
  }
  if(who) {
    if(!present(who, environment(TP))) {
      write("There is no "+capitalize(who)+" here.\n"); 
      return 1; 
    }
    else ob = present(who,environment(TP)); 
  }
  if(!call_other(COMBATD, "valid_attack", ob, TP)) {
    write("You cannot flux that!\n");
    return 1;
  }
  if(!((int)IPTP->query_flux_charges())) {
    write("You must charge your FluX before you can use it.\n");
    return 1; 
  }
  IPTP->add_flux_charges(-1);
  if((int)IPTP->guild_lev() + 85 < random(100) ) {
    write("Your flux generator backfires!\n");
    if((int)TP->query_attrib("wil") < random(25)) {
      write("Electricity crackles through your body!\n");
      TP->hit_player(random((int)IPTP->guild_lev()) + 1); 
    }
    TP->add_spell_point(-(random(20)));
    return 1; 
  }

/* Cost of charging, failure, and enhancement are in addition */
   dmg = (int)IPTP->guild_lev() / 2;
   dmg = dmg * 10;
   TP->add_spell_point(-dmg);

  tell_room(environment(TP), 
    TPN+" releases a burst of electric flux into "+OPN+"\n\n");
  if(dmg <= 15) {
    tell_room(environment(TP),
"                  "+BLUE+"|"+OFF+"        \n"+
"                "+BLUE+"--*--"+OFF+"      \n"+
"                  "+BLUE+"|"+OFF+"        \n\n");
  }
  if(dmg >= 16 && dmg <= 29) {
    tell_room(environment(TP),
"                  "+BLUE+"|"+OFF+"        \n"+
"                  "+BLUE+"|"+OFF+"        \n"+
"            "+BLUE+"-- ---*--- --"+OFF+"  \n"+
"                  "+BLUE+"|"+OFF+"        \n"+
"                  "+BLUE+"|"+OFF+"        \n\n");
  }
  if(dmg >= 30) {
    tell_room(environment(TP),
"                 "+BLUE+"-|-"+OFF+"        \n"+
"                "+BLUE+"--|--"+OFF+"        \n"+
"       "+BLUE+"-- --- ----*---- --- --"+OFF+"\n"+
"                "+BLUE+"--|--"+OFF+"        \n"+
"                 "+BLUE+"-|-"+OFF+"        \n\n");
  }
  ob->hit_player(dmg);
  if(ob) {
    if(!TP->query_attack()) TP->attack_object(ob);
    if(!ob->query_attack()) ob->attack_object(TP);
  }
  return 1;
}
