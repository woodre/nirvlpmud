/* BANE
 * Attack spell for Ascension by Dune and Snow
 * Specialized banes are earned through questing
 */
 
#include "../def.h"
#define  COST 100
 
status main(string str) {
  object ob, etp;
  string obn;
  int align, dam1, dam2;
 
  needsp(COST);
 
  if(!str) {
    write("You need to name a target for your Bane of Power.\n");
    return 1; }
  if(str != "demon" && str != "infernal" && str != "undead" &&
     str != "shadow") {
    write("You know of no such Bane.\n"); return 1; }
  etp = environment(TP);
  if(str == "demon") {
    if(!IPTP->query_setting(DEMONBANE)) {
      write("You have not learned the Bane of Demon yet.\n"); return 1; }
    ob = present("demon", etp);
    if(!ob) {
      write("You invoke the BANE of DEMON in vain.\n");
      TP->add_spell_point(-25); return 1; }
    align = (int)(ob->query_alignment());
    if(align > 0) {
      write("Your attempt to hurt a good creature causes you pain!\n");
      TP->hit_player(100); return 1; }
    obn = (string)(ob->query_name());
    dam1 = random(((int)IPTP->query_setting(CLASS)) * 5) + 20;
    dam2 = random(dam1) + 15;
    if(IPTP->query_setting(COLOR)) write(BOLD);
    write("\n\tYou invoke the BANE of DEMONS.\n");
    TR(etp,"\n\tA thousand tiny beams of light flash before your eyes!\n");
    TR(etp,"\n\t\t"+obn+" screams as its DEMONIC essence is exposed!\n");
    ob->heal_self(-dam1);
    ob->hit_player(dam2);
    TP->add_spell_point(-100);
    if(!ob->query_ghost()) TR(etp,"\n"+obn+" collapses to the ground.\n");
    if(IPTP->query_setting(COLOR)) write(OFF);
  }
  if(str == "infernal") {
    if(!IPTP->query_setting(INFERNALBANE)) {
      write("You have not learned the Bane of the Infernal yet.\n");
      return 1; }
    ob = present("devil", etp);
    if(!ob) ob = present("daemon", etp);
    if(!ob) ob = present("spirit", etp);
    if(!ob) {
      write("You invoke the BANE of the INFERNAL in vain.\n");
      TP->add_spell_point(-25); return 1; }
    align = (int)(ob->query_alignment());
    if(align > 0) {
      write("Your attempt to hurt a good creature causes you pain!\n");
      TP->hit_player(100); return 1; }
    obn = (string)(ob->query_name());
    dam1 = random(((int)IPTP->query_setting(CLASS)) * 5) + 20;
    dam2 = random(dam1) + 15;
    if(IPTP->query_setting(COLOR)) write(BOLD);
    write("\n\tYou invoke the BANE of the INFERNAL.\n");
    TR(etp,"\n\tA thousand tiny beams of light flash before your eyes!\n");
    TR(etp,"\n\t\t"+obn+" screams as its INFERNAL essence is exposed!\n");
    ob->heal_self(-dam1);
    ob->hit_player(dam2);
    TP->add_spell_point(-100);
    if(!ob->query_ghost()) TR(etp,"\n"+obn+" collapses to the ground.\n");
    if(IPTP->query_setting(COLOR)) write(OFF);
  }
  if(str == "undead") {
    if(!IPTP->query_setting(UNDEADBANE)) {
      write("You have not learned the Bane of Undead yet.\n"); return 1; }
    ob = present("undead", etp);
    if(!ob) ob = present("ghoul", etp);
    if(!ob) ob = present("ghost", etp);
    if(!ob) ob = present("wraith", etp);
    if(!ob) ob = present("vampire", etp);
    if(!ob) ob = present("spectre", etp);
    if(!ob) ob = present("skeleton", etp);
    if(!ob) {
      write("You invoke the BANE of UNDEAD in vain.\n");
      TP->add_spell_point(-25); return 1; }
    align = (int)(ob->query_alignment());
    if(align > 0) {
      write("Your attempt to hurt a good creature causes you pain!\n");
      TP->hit_player(100); return 1; }
    obn = (string)(ob->query_name());
    dam1 = random(((int)IPTP->query_setting(CLASS)) * 5) + 20;
    dam2 = random(dam1) + 15;
    if(IPTP->query_setting(COLOR)) write(BOLD);
    write("\n\tYou invoke the BANE of UNDEAD.\n");
    TR(etp,"\n\tA thousand tiny beams of light flash before your eyes!\n");
    TR(etp,"\n\t\t"+obn+" screams as its UNDEAD essence is exposed!\n");
    ob->heal_self(-dam1);
    ob->hit_player(dam2);
    TP->add_spell_point(-100);
    if(!ob->query_ghost()) TR(etp,"\n"+obn+" collapses to the ground.\n");
    if(IPTP->query_setting(COLOR)) write(OFF);
  }
  if(str == "shadow") {
    if(!IPTP->query_setting(SHADOWBANE)) {
      write("You have not learned the Bane of Shadow yet.\n"); return 1; }
    ob = present("shadow", etp);
    if(!ob) ob = present("shade", etp);
    if(!ob) ob = present("shadowcreature", etp);
    if(!ob) {
      write("You invoke the BANE of SHADOW in vain.\n");
      TP->add_spell_point(-25); return 1; }
    align = (int)(ob->query_alignment());
    if(align > 0) {
      write("Your attempt to hurt a good creature causes you pain!\n");
      TP->hit_player(100); return 1; }
    obn = (string)(ob->query_name());
    dam1 = random(((int)IPTP->query_setting(CLASS)) * 5) + 20;
    dam2 = random(dam1) + 15;
    if(IPTP->query_setting(COLOR)) write(BOLD);
    write("\n\tYou invoke the BANE of SHADOW.\n");
    TR(etp,"\n\tA thousand tiny beams of light flash before your eyes!\n");
    TR(etp,"\n\t\t"+obn+" screams as its SHADOW essence is exposed!\n");
    ob->heal_self(-dam1);
    ob->hit_player(dam2);
    TP->add_spell_point(-100);
    if(!ob->query_ghost()) TR(etp,"\n"+obn+" collapses to the ground.\n");
    if(IPTP->query_setting(COLOR)) write(OFF);
  }
  if(TP->query_level() > 50) write("WIZ DAMAGE: "+dam1+"+"+dam2+"\n");
  ob->attack_object(TP);
    TP->attack_object(ob);
  return 1;
}
