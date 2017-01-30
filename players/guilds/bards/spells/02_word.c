#include "/players/guilds/bards/def.h"

status main(string str) {
  int cost;
  object opp;
  int damage;
  if(TP->query_spell_dam()) {
    FAIL("You have already cast a spell.\n");
  }
  if (!str && !this_player()->query_attack()) {
    write("You must invoke the words of pain against an opponent.\n");
    return 1;
  }
  else if (!str && this_player()->query_attack()) {
    opp = (object)TP->query_attack();
  }
  else {
    opp = present(str, environment(this_player()));
  }
  if(!opp){
    write("That opponent is not present.\n");
    return 1;
  }
  
  if (attack_spell(-50, 2, 10, opp) == -1)
  return 0;
  damage = random(16);
  if (damage > opp->query_hp())
  damage = (int)opp->query_hp() - 1;
  write("Extending one hand towards " + opp->query_name() +
    ", you weave the "+HIB+"Words "+NORM+
    "Of "+HIR+"Pain"+NORM+" into\n" +
    "song lyrics and channel the "+HIY+"energy"+NORM+
  " into " + OBJE(opp) + ".\n");
  say(tp + " extends a hand towards " + opp->query_name() + ".\n");
  say(tp +
    " weaves an invocation into lyrics and channels "+HIY+"energy"+NORM+
  " into "+ OBJE(opp) +".\n");
  if((int)GOB->check_skill("spellcraft")==1)
    cost=9;
  else
    cost=10;
  TP->spell_object(opp, "word of pain", damage, cost, "","","");
  TP->set_spell_dtype("magical");
  
  tell_room(environment(TP), opp->query_name() + " staggers.\n");
  return 1;
}
