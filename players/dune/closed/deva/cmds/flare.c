/*
 * LIGHTNING attack spell for Ascension
 */

#include "../def.h"
#define  COST 25

status main(string str) {
  object ob;
  int dam, xdam;
  needsp(COST);

  if(!str) ob = ((object)TP->query_attack());
  if(str) ob = present(str, environment(TP));
  if(!ob) {
  write("You must flare an attacker or a present opponent.\n");
  return 1; }

  if(!living(ob)) {
    write("You can only flare living things.\n"); return 1; }

  if(ob->query_alignment() > 0) {
    write("You are punished for attempting to hurt a good creature!\n");
    TP->hit_player(100); return 1; }

  dam = ((int)IPTP->query_setting(CLASS)) * (random(5) + 1);
  xdam = 0;
  if(SHADOW->spec_mon(ob)) {
    xdam = random(((int)IPTP->query_setting(CLASS)) * 3); }

  write("You raise your hands to the heavens...\n"+
        "...Holy light gathers...\n");
  say(TPN+" raises "+GEN+" hands to the heavens...\n"+
      "...Light gathers...\n");
  if(IPTP->query_setting(COLOR)) write(BOLD);
  tell_room(environment(TP),
        "\n\t*\t*\t*\n\t\t*\n\t*\t*\t*\n\n"+
        "A\tSOLAR FLARE\t burns into "+ob->query_name()+"!\n\n");
  if(IPTP->query_setting(COLOR)) write(OFF);
  ob->heal_self(-dam);
  TP->add_spell_point(-dam*2);
  ob->heal_self(-xdam);
  if(TP->query_level() > 50) write("WIZ INFO DAMAGE: "+dam+"+"+xdam+"\n");
  if(!TP->query_attack()) TP->attack_object(ob);
  return 1;
}
