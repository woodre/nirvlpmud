/*
 * LIGHTNING attack spell for Ascension
 */

#include "../def.h"
#define  COST 25

status main(string str) {
  object ob;
  needsp(COST);

  if(!str) ob = ((object)TP->query_attack());
  if(str) ob = present(str, environment(TP));
  if(!ob) {
  write("You must call lightning on an attacker or a present opponent.\n");
  return 1; }

  if(ob->query_alignment() > 0) {
    write("You are punished for attempting to hurt a good creature!\n");
    TP->hit_player(100); return 1; }

  TP->spell_object(ob,"Lightning",random(20)+15,25,
    "You call a bolt of lightning down from the heavens...\n",
    TPN+" calls a bolt of lightning down upon you!\n",
    TPN+" calls a bolt of lightning down upon "+ob->query_name()+".\n");
return 1;
}
