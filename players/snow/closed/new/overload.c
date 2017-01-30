#include "../DEFS.h"
#include DEFS_ENHANCEMENTS
/* OVERLOAD DAMAGE ENHANCEMENT
 * Damages player in causing damage to opponent
  * Can kill player ! ! !
  * Does hit_player damage to player
  * Does heal_self damage to opponent
  * Chance of loss of str stat for player
  * Max damage to opponent is random(60)
  * Chance of double damage to player (very dangerous)
*/

status main(string str) {
  object meat;
  int mhp, hps;
  int damage, snum;

  if(!((status)IPTP->item_convert()) && !IPTP->guild_wiz()) return 0;
  hps  = (int)TP->query_hp();
  snum = (int)TP->query_attrib("str");
  if(!gotsp(TP, ENERGY_OVERLOAD)) return 1;
  damage = (int)IPTP->guild_lev() + random(snum);
  if(environment(TP)) tell_room(environment(TP),
    "***>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  write("You overload your matter converter!\n"+
        "Intense, burning pain rips through your musculature!\n");
  if(environment(TP)) tell_room(environment(TP), 
    TPN+" crumples in agony!\n");
  if(!TP->query_attack() ||
  (environment((object)TP->query_attack()) != environment(TP)) ) {
    TP->hit_player(damage+10);
    if(environment(TP)) tell_room(environment(TP),
      "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<***\n");
    return 1;
  }
  meat = (object)TP->query_attack();
  if(call_other(COMBATD, "valid_attack", meat, TP)) {
    write("You channel some excess energy into "+MEAN+"!\n");
    if(environment(TP)) tell_room(environment(TP),
      "Matter energy crashes into "+MEAN+"!\n");
    meat->heal_self(-random(damage*2));
    TP->hit_player(damage+10);
    if(random(snum)==0) TP->hit_player(damage);
  }
  if(snum > 10) {
    if(random(snum*5) == 1) {
      write("The conversion overload resulted in permanent damage!\n");
      call_other(TP,"add_attrib","str",-1);
      TP->save();
    }
  }
  if(environment(TP)) tell_room(environment(TP),
    "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<***\n");
  return 1;
}
